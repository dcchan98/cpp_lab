#include "m_print.hpp"

namespace std_aliases {
    /// Pair shortcut. Usage: pr<int,int> p = {1,2};
    template<typename T1, typename T2>
    using pr = std::pair<T1, T2>;
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
    /// Max-heap priority queue. Usage: pq<int> pq; pq.push(5);
    template<typename T>
    using pq = std::priority_queue<T>;
    /// Min-heap priority queue. Usage: pqg<int> pq; pq.push(5);
    template<typename T>
    using pqg = std::priority_queue<T, std::vector<T>, std::greater<T> >;
}

using namespace std_aliases;

#include <bits/stdc++.h>
using namespace std;

int main() {
    // 4D vector
    vec<vec<vec<vec<int> > > > dp4d(2, vec<vec<vec<int> > >(3, vec<vec<int> >(4, vec<int>(5))));
    int counter = 1;
    for (int a = 0; a < 2; ++a)
        for (int b = 0; b < 3; ++b)
            for (int c = 0; c < 4; ++c)
                for (int d = 0; d < 5; ++d)
                    dp4d[a][b][c][d] = counter++;
    m_print(dp4d);
    // 1D deque
    // 2D list
    dq<vec<int> > l2 = {{1, 2}, {3, 4}, {5, 6}};
    m_print(l2);

    int m = 1, n = 2;
    vec<vec<int> > dp(m, vec<int>(n, -1));
}
