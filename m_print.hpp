#pragma once
#include <bits/stdc++.h>

namespace trait_templates {
    namespace basic_type_traits {
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
void m_print_recurse(T x, const std::vector<int>& indices = {}) {
    using namespace std;
    using namespace trait_templates::basic_type_traits;
    using namespace trait_templates::sequence_type_traits;

    if constexpr (is_streamable<T>::value) {
        std::cout << x;
        return;
    }
    if constexpr (sequence_depth<T>::value) {
        if constexpr (sequence_depth<T>::value == 1) {
            const int n = x.size();
            cout << "[";
            for (int i = 0; i < n; ++i) {
                m_print_recurse(x[i]);
                if (i != n - 1) cout << ", ";
            }
            cout << "]";
        } else if constexpr (sequence_depth<T>::value == 2) {
            if (!indices.empty()) {
                cout << "-- Matrix ";
                m_print_recurse(indices);
                cout << " --" << endl;
            }
            const int n = x.size();
            cout << "[" << endl;
            for (int i = 0; i < n; ++i) {
                cout << "  ";
                m_print_recurse(x[i]);
                if (i != n - 1) cout << endl;
            }
            cout << endl << "]";
        } else {
            const int n = x.size();
            for (int i = 0; i < n; i++) {
                std::vector<int> newIndices = indices;
                newIndices.push_back(i);
                m_print_recurse(x[i], newIndices);
            }
        }
    }
}

// Macro to print variable name, value, line, and filename only
#define m_print(x) \
std::cout << #x << " : Line " << __LINE__ << std::endl; \
m_print_recurse(x); \
std::cout << std::endl;