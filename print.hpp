#pragma once
#include <bits/stdc++.h>

namespace print_concepts {
    template<typename T>
    concept Streamable = requires(T a, std::ostream &os)
    {
        { os << a } -> std::same_as<std::ostream &>;
    };

    template<typename T>
    concept TupleLike = requires
    {
        std::tuple_size<T>::value; // tuple_size exists
    };

    template<typename T>
    concept MapContainer = requires(T a)
                           {
                               typename T::value_type;
                           } && requires(T a)
                           {
                               typename T::value_type::first_type;
                               typename T::value_type::second_type;
                           };

    template<typename T>
    concept Container = requires(T a)
    {
        typename T::value_type;
        { a.size() } -> std::convertible_to<std::size_t>;
        { a.begin() };
        { a.end() };
    };
}


template<typename T>
void print_recursively(const T &x,int indent = 0) {
    using namespace std;
    using namespace print_concepts;
    if constexpr (Streamable<T>) {
        cout << x;
    } else if constexpr (TupleLike<T>) {
        cout << "(";
        std::apply([&](auto&&... args){
            // fold expression to print each element recursively
            size_t n = 0;
            ((print_recursively(args), ++n < sizeof...(args) ? cout << ", " : cout), ...);
        }, x);
        cout << ")";
    }
    else if constexpr (MapContainer<T>) {
        std::cout << "{" << std::endl;
        for (auto it = x.begin(); it != x.end(); ++it) {
            cout << string(indent+2,' ');
            print_recursively(it->first, indent + 2);
            std::cout << ": ";
            print_recursively(it->second, indent + 2);
            std::cout << std::endl;
        }
        std::cout << "}";
    } else if constexpr (Container<T>) {
        cout << "[ ";
        for (auto it = x.begin(); it != x.end(); ++it) {
            print_recursively(*it);
            cout << " ";
        }
        cout << " ]";
    } else {
        std::cout << "Unstreamable";
    }
}


#define print(x) \
std::cout << #x << " : Line " << __LINE__ << std::endl; \
print_recursively(x); \
std::cout << std::endl;
