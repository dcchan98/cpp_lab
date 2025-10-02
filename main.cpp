#include <bits/stdc++.h>
using namespace std;

//#region using shortcuts
/// Usage: vec<int> v(n,-1); vec<vec<int>> dp(m,vec(n,-1));
template<typename T> using vec = std::vector<T>;
/// Usage: pr<int,int> p = {1,2};
template<typename T1, typename T2> using pr = std::pair<T1,T2>;
/// Usage: tpl<int,int,int> t = {1,2,3};
template<typename T1, typename T2, typename T3> using tpl = std::tuple<T1,T2,T3>;
/// Usage: umap<int,int> m; m[1]=10;
template<typename K, typename V> using umap = std::unordered_map<K,V>;
/// Usage: mmap<int,int> m; m[1]=10;
template<typename K, typename V> using mmap = std::map<K,V>;
/// Usage: q<int> qu; qu.push(5);
template<typename T> using q = std::queue<T>;
/// Usage: dq<int> d; d.push_back(5); d.push_front(1);
template<typename T> using dq = std::deque<T>;
/// Usage: st<int> s; s.push(5);
template<typename T> using st = std::stack<T>;
/// Usage: pq<int> pq; pq.push(10);
template<typename T> using pq = std::priority_queue<T>;
/// Usage: pqg<int> pq; pq.push(10);
template<typename T> using pqg = std::priority_queue<T, std::vector<T>, std::greater<T>>;
//#endregion

//#region template specialisation
// vector
template<typename T>
struct is_vector : std::false_type {};
template<typename T>
struct is_vector<std::vector<T>> : std::true_type {};
//#endregion
//#region print

/**
 * @brief Recursively prints vectors in a readable format.
 *
 * - 1D vectors: prints inline, e.g., [1, 2, 3]
 * - 4D vectors: prints each 2D slice with "Matrix" labels for nested matrices
 *
 * @tparam T Type of vector elements (can be nested vectors)
 * @param x The vector to print
 *
 * @code
 * // 1D example
 * vec<int> v1 = {1,2,3};
 * print(v1);
 * // Output:
 * [1, 2, 3]
 *
 * // 4D example
 * vec<vec<vec<vec<int>>>> v4 = {
 *     {{{1,2},{3,4}}, {{5,6},{7,8}}},
 *     {{{9,10},{11,12}}, {{13,14},{15,16}}}
 * };
 * print(v4);
 * // Output:
 * Matrix 0
 * Matrix 0
 * [[1, 2], [3, 4]]
 * Matrix 1
 * [[5, 6], [7, 8]]
 * Matrix 1
 * Matrix 0
 * [[9, 10], [11, 12]]
 * Matrix 1
 * [[13, 14], [15, 16]]
 * @endcode
 */
template<typename T>
void print(T x) {
    if constexpr (is_vector<T>::value) {
        int n = x.size();
        cout << "[";
        for (int i = 0; i < n; ++i) {
            print(x[i]);
            if (i!=n-1) cout << ", ";
        }
        cout << "]";
    } else {
       cout << x ;
    }
}
//#endregion


int main() {
    vec<vec<int>> dp(4,vec(5,-1));
    print(dp);
    print(1);
}