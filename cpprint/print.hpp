#pragma once
#include "concepts.hpp"
#include <iostream>
#include <vector>
#include <string>

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

#define cpprint(x)                                            \
    std::cout << #x << " : Line " << __LINE__ << std::endl; \
    print_recursively(x);                                   \
    std::cout << std::endl;
