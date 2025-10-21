#pragma once

// Automatically generated cpp file

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <tuple>

#include <concepts>
#include <ostream>

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
    } && (Streamable<typename T::value_type>);

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


#include <algorithm>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <tuple>


namespace cpprint {
    template<typename T>
    std::string generate_container_string_recursively(const T &x, int indent = 0) {
        using namespace print_concepts;
        std::stringstream ss;
        if constexpr (Streamable<T>) {
            ss << x;
            return ss.str();
        }
        // TODO improve indentation if tuple contains containers or maps
        else if constexpr (TupleLike<T>) {
            ss << "(";
            std::apply(
                [&](auto&&... args) {
                    size_t n = 0;
                    ((ss << generate_container_string_recursively(args)
                         << (++n < sizeof...(args) ? ", " : "")), ...);
                },
                x);
            ss << ")";
            return ss.str();
        }
        else if constexpr (MapContainer<T>) {
            ss << std::string(indent, ' ');
            ss << "{\n";
            for (auto it = x.begin(); it != x.end(); ++it) {
                ss << std::string(indent + 2, ' ');
                ss << generate_container_string_recursively(it->first, indent + 2);
                ss << ": ";
                ss << generate_container_string_recursively(it->second, indent + 2);
                ss << "\n";
            }
            ss << std::string(indent, ' ');
            ss << "}";
            return ss.str();
        }
        else if constexpr (Container1D<T>) {
            ss << std::string(indent, ' ');
            ss << "[ ";
            for (auto elem: x) {
                ss << generate_container_string_recursively(elem);
                ss << " ";
            }
            ss << " ]";
            return ss.str();
        }
        else if constexpr (Container<T>) {
            ss << std::string(indent, ' ');
            ss << "[\n";
            for (auto it = x.begin(); it != x.end(); ++it) {
                ss << generate_container_string_recursively(*it, indent + 2) << "\n";
            }
            ss << "]";
            return ss.str();
        }
        else if constexpr (Adaptor<T>) {
            T copy = x;
            ss << std::string(indent, ' ') << "priority_queue#[ ";
            while (!copy.empty()) {
                ss << generate_container_string_recursively(copy.top(), indent + 2);
                copy.pop();
                if (!copy.empty()) ss << ", ";
            }
            ss << " ]";
            return ss.str();
        }
        else {
            return "Unstreamable";
        }
    }

    template<typename... Args>
    void pprint(const Args &... args) { ((std::cout << generate_container_string_recursively(args) << "\n"), ...); }

    template<typename... Args>
    void pprint_inline(const Args&... args) {
        auto flatten = [](const auto& obj) {
            std::string s = generate_container_string_recursively(obj);
            std::replace(s.begin(), s.end(), '\n', ' ');
            return s;
        };
        ((std::cout << flatten(args) << " "), ...);
        std::cout << std::endl;
    }
}

// End of generated cpp file
