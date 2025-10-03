#include "m_print.hpp"
#include "print.hpp"

namespace std_aliases {
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
    pqg<int> pq;
    // Push some elements
    pq.push(5);
    pq.push(1);
    pq.push(8);
    pq.push(3);
    // Print using your print function
    print(pq);
    print(pq);

    return 0;
}