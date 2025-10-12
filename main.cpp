#include "m_print.hpp"
#include "print.hpp"

namespace type_aliases {
    /// Tuple shortcut. Usage: tpl<int,int,int> t = {1,2,3};
    template<typename T1, typename T2, typename T3>
    using tpl = std::tuple<T1, T2, T3>;
    /// 1D vector shortcut. Usage: vec<int> v = {1,2,3,4}; vec<vec<int>>  dp(m ,vec<int>(n,-1));
    template<typename T>
    using vec = std::vector<T>;
    /// 2D deque shortcut. Usage: dq<vec<int>> matrix = {{1,2},{3,4}};
    template<typename T>
    using dq = std::deque<T>;
    /// Unordered map shortcut. Usage: umap<int,string> m = {{1,"a"},{2,"b"}};
    template<typename K, typename V>
    using umap = std::unordered_map<K, V>;
    /// Unordered set shortcut. Usage: uset<int> s = {1,2};
    template<typename T>
    using uset = std::unordered_set<T>;
    /// Max-heap priority queue. Usage: pq<int> pq; pq.push(5);
    template<typename T>
    using pq = std::priority_queue<T>;
    /// Min-heap priority queue. Usage: pqg<int> pq; pq.push(5);
    template<typename T>
    using pqg = std::priority_queue<T, std::vector<T>, std::greater<T> >;
}

using namespace type_aliases;

#include <bits/stdc++.h>
using namespace std;

const vec<pair<int, int> > DIR = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// Util funcs

// TODO change int to template

/// generates powerset
vector<vector<int> > combinations(vector<int> vec) {
    int n = vec.size();
    ranges::sort(vec);
    // recursively modified states
    vector<vector<int> > res;
    vector<int> taken;
    auto recurse = [&](this auto func, int startIndex = 0)-> void {
        res.push_back(taken);
        for (int i = startIndex; i < n; i++) {
            if (i > startIndex && vec[i] == vec[i - 1]) continue; // prune for unique elements
            taken.push_back(vec[i]);
            func(i + 1); // populate next element recursively, limited by index
            taken.pop_back();
        }
    };
    recurse();
    return res;
}

/// generate permutations
vector<vector<int> > permutations(vector<int> vec) {
    int n = vec.size();
    ranges::sort(vec);
    // recursively modified states
    vector<int> visited(n); // marks if index has been visited
    vector<vector<int> > res;
    vector<int> taken;
    auto recurse = [&](this auto func)-> void {
        if (taken.size() == n) {
            res.push_back(taken);
            return;
        };
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            if (i> 0 && vec[i]==vec[i-1] && !visited[i-1]) continue; // prune for unique elements
            visited[i] = true;
            taken.push_back(vec[i]);
            func(); // populate next element recursively
            visited[i] = false;
            taken.pop_back();
        }
    };
    recurse();
    return res;
}

class ufds {
    vector<int> rank, parent;

public:
    // Constructor to initialize sets
    ufds(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        // Initially, each element is in its own set
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int i) {
        int root = parent[i];
        if (parent[root] != root) {
            return parent[i] = find(root);
        }
        return root;
    }

    // Union of sets containing x and y
    void unionSets(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        // If they are in the same set, no need to union
        if (xRoot == yRoot) return;
        // Union by rank
        if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
        } else if (rank[yRoot] < rank[xRoot]) {
            parent[yRoot] = xRoot;
        } else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }
};

// Modify code below
int main() {
    // useful syntax for recursive lambdas
    auto fib = [&](this auto func, int n) -> int {
        if (n == 1) { return 0; }
        if (n == 2) { return 1; }
        return func(n - 1) + func(n - 2);
    };
    print(fib(5));

    // Flatten 2d vector to 1d -> use formula i*n+j for access
    int m = 5, n = 6, i = 2, j = 3;
    vector<int> dp1d(m * n, -INFINITY);
    print(dp1d[i*n+j]);
    // this removes the need for dp2d below
    vector<vector<int> > dp2d(m, vector<int>(n, -INFINITY));
    return 0;
}