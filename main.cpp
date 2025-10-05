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

const vec<pair<int,int>> DIR  = {{1,0},{-1,0},{0,1},{0,-1}};

// Util funcs

// TODO change int to template

/// generates powerset
vector<vector<int>> combinations(vector<int> vec) {
    int n = vec.size();
    ranges::sort(vec);
    // recursively modified states
    vector<vector<int>> res;
    vector<int> taken;
    auto recurse = [&](this auto func,int startIndex=0)->void {
        res.push_back(taken);
        for (int i = startIndex ; i < n; i ++) {
            // prune for unique elements
            if (i>startIndex && vec[i]==vec[i-1]) continue;
            taken.push_back(vec[i]);
            func(i+1);
            taken.pop_back();
        }
    };
    recurse();
    return res;
}

// TODO implement permutations for unique vec

// Modify code below
int main() {
    // useful syntax for recursive lambdas
    auto fib = [&](this auto func, int n) -> int {
        if (n==1) {return 0;}
        if (n==2) {return 1;}
        return func(n-1)+func(n-2);
    };
    print(fib(5));

    // Flatten 2d vector to 1d -> use formula i*n+j for access
    int m = 5,  n = 6, i = 2, j = 3;
    vector<int> dp1d(m*n,-INFINITY);
    print(dp1d[i*n+j]);
    // this removes the need for dp2d below
    vector<vector<int>> dp2d(m,vector<int>(n,-INFINITY));
    return 0;
}