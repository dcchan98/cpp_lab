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
    concept MapContainer = requires(T a) { typename T::value_type; } && requires(T a)
    {
        typename T::value_type::first_type;
        typename T::value_type::second_type;
        { a.size() } -> std::convertible_to<std::size_t>;
        { a.begin() };
        { a.end() };
    };

    template<typename T>
    concept Container1D = requires(T a)
    {
        typename T::value_type; // has value_type
        { a.size() } -> std::convertible_to<std::size_t>;
        { a.begin() };
        { a.end() };
    } && (!requires { typename T::value_type::value_type; });

    template<typename T>
    concept Container = requires(T a)
    {
        typename T::value_type;
        { a.size() } -> std::convertible_to<std::size_t>;
        { a.begin() };
        { a.end() };
    };

    template<typename T>
    concept Adaptor = requires(T a)
    {
        typename T::value_type;     // must have value_type
        { a.size() } -> std::convertible_to<std::size_t>;
        { a.empty() } -> std::convertible_to<bool>;
        { a.pop() };                // must support pop()
    } && (
        requires(T a) { a.top(); } ||  // stack / priority_queue
        requires(T a) { a.front(); }   // queue
    );
}

template<typename T>
void print_recursively(const T &x, int indent = 0) {
    using namespace std;
    using namespace print_concepts;
    if constexpr (Streamable<T>) {
        cout << x;
    }
    // TODO improve indentation if tuple contains containers or maps
    else if constexpr (TupleLike<T>) {
        cout << "(";
        std::apply(
            [&](auto &&... args) {
                // fold expression to print each element recursively
                size_t n = 0;
                ((print_recursively(args), ++n < sizeof...(args) ? cout << ", " : cout), ...);
            },
            x);
        cout << ")";
    }
    else if constexpr (MapContainer<T>) {
        cout << string(indent , ' ');
        std::cout << "{" << std::endl;
        for (auto it = x.begin(); it != x.end(); ++it) {
            cout << string(indent + 2, ' ');
            print_recursively(it->first, indent + 2);
            std::cout << ": ";
            print_recursively(it->second, indent + 2);
            std::cout << std::endl;
        }
        cout << string(indent , ' ');
        std::cout << "}";
    }
    else if constexpr(Container1D<T>) {
       cout << string(indent , ' ');
       cout << "[ " ;
       for (auto elem: x) {
           print_recursively(elem);
           cout <<" ";
       }
        cout << " ]";
    }
    else if constexpr (Container<T>) {
        cout << string(indent , ' ');
        cout << "[ "<<endl;
        for (auto it = x.begin(); it != x.end(); ++it) {
            print_recursively(*it,indent+2);
            cout << endl;
        }
        cout << "]";
    }
    else if constexpr (Adaptor<T>) {
        T copy = x;
        std::cout << string(indent, ' ') << "priority_queue#[ ";
        while (!copy.empty()) {
            print_recursively(copy.top(), indent + 2);
            copy.pop();
            if (!copy.empty()) std::cout << ", ";
        }
        std::cout << " ]";
    }
    else {
        std::cout << "Unstreamable";
    }
}

#define print(x)                                            \
    std::cout << #x << " : Line " << __LINE__ << std::endl; \
    print_recursively(x);                                   \
    std::cout << std::endl;
