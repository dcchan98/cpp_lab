#pragma once
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

