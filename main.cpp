#include <bits/stdc++.h>

//#region type aliases in main
/// Usage: pr<int,int> p = {1,2};
namespace trait_templates {
    namespace basic_type_traits {
        // check if  cout << t is valid
        template<typename T, typename = void>
        struct is_streamable : std::false_type {};

        template<typename T>
        struct is_streamable<
            T,
            std::void_t<decltype(std::declval<std::ostream &>() << std::declval<T>())>
        > : std::true_type {};
    }
    namespace sequence_type_traits {
        template<typename T>
        struct is_sequence_container : std::false_type {};

        template<typename T, typename Alloc>
        struct is_sequence_container<std::vector<T, Alloc>> : std::true_type {};

        template<typename T, typename Alloc>
        struct is_sequence_container<std::deque<T, Alloc>> : std::true_type {};

        template<typename T, std::size_t N>
        struct is_sequence_container<std::array<T, N>> : std::true_type {};

        template<typename T, typename Enable = void>
        struct sequence_depth : std::integral_constant<int, 0> {};

        template<typename T>
        struct sequence_depth<
            T,
            std::enable_if_t<is_sequence_container<T>::value>
        > : std::integral_constant<int, 1 + sequence_depth<typename T::value_type>::value> {};
    }
}
template<typename T>
void print_recurse(T x, const std::vector<int>& indices = {}) {
    using namespace std;
    using namespace trait_templates::basic_type_traits;
    using namespace trait_templates::sequence_type_traits;
    // Base case: T can be printed directly
    if constexpr (is_streamable<T>::value) {
        std::cout << x;
        return;
    }

    // Sequence container case
    if constexpr (sequence_depth<T>::value) {
        if constexpr (sequence_depth<T>::value == 1) {
            const int n = x.size();
            cout << "[";
            for (int i = 0; i < n; ++i) {
                print_recurse(x[i]);
                if (i != n - 1) cout << ", ";
            }
            cout << "]";
        } else if constexpr (sequence_depth<T>::value == 2) {
            if (!indices.empty()) {
                cout << "-- Matrix ";
                print_recurse(indices);
                cout << " --" << endl;
            }
            const int n = x.size();
            cout << "[" << endl;
            for (int i = 0; i < n; ++i) {
                cout << "  ";
                print_recurse(x[i]);
                if (i != n - 1) cout << endl;
            }
            cout << endl << "]";
        } else {
            const int n = x.size();
            for (int i = 0; i < n; i++) {
                std::vector<int> newIndices = indices;
                newIndices.push_back(i);
                print_recurse(x[i], newIndices);
            }
        }
    }
}

// Macro to print variable name, value, line, and filename only
#define print(x) \
cout << #x  << " : Line  " <<__LINE__ <<  endl; \
print_recurse(x); \
cout << endl;


namespace std_aliases {
    // Pair shortcut
    template<typename T1, typename T2>
    using pr = std::pair<T1, T2>;

    // Tuple shortcut
    template<typename T1, typename T2, typename T3>
    using tpl = std::tuple<T1, T2, T3>;

    // Vector shortcut
    template<typename T>
    using vec = std::vector<T>;

    // Deque shortcut
    template<typename T>
    using dq = std::deque<T>;

    // Unordered map shortcut
    template<typename K, typename V>
    using umap = std::unordered_map<K, V>;

    // Priority queue shortcut (max-heap)
    template<typename T>
    using pq = std::priority_queue<T>;

    // Priority queue shortcut (min-heap)
    template<typename T>
    using pqg = std::priority_queue<T, std::vector<T>, std::greater<T>>;
}

using namespace std_aliases;

#include <bits/stdc++.h>
using namespace std;
int main() {
    // 4D vector
    vec<vec<vec<vec<int>>>> dp4d(2, vec<vec<vec<int>>>(3, vec<vec<int>>(4, vec<int>(5))));
    int counter = 1;
    for (int a=0;a<2;++a) for(int b=0;b<3;++b) for(int c=0;c<4;++c) for(int d=0;d<5;++d)
        dp4d[a][b][c][d] = counter++;

    print(dp4d);

    // 1D deque

    // 2D list
    dq<vec<int>> l2 = {{1,2},{3,4},{5,6}};
    print(l2);

}