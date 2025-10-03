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
    std::vector<int> v{1,2,3};
    std::vector<std::vector<int>> vv(3, std::vector<int>(3, -1));
    std::set<int> s{3,1,2};
    std::unordered_set<std::string> us{"apple","banana"};
    std::map<int,std::string> m{{1,"one"}, {2,"two"}};
    std::map<int,std::string> umap{{1,"one"}, {2,"two"}};
    std::pair<int,double> p{42, 3.14};
    std::tuple<int,std::string,double> t{1,"hello",2.5};

    print(v);
    print(vv);
    print(s);
    print(us);
    print(m);
    print(p);
    print(t);

}
