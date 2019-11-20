#pragma once
/*
 *
 * Taken from cppreference.com to have some basic features of STL
 *
*/
namespace ucpp::utils {

    template<class T, T v>
    struct integral_constant {
        static constexpr T value = v;
        typedef T value_type;
        typedef integral_constant type; // using injected-class-name
        constexpr operator value_type() const noexcept { return value; }
        constexpr value_type operator()() const noexcept { return value; } //since c++14
    };

    using false_type = integral_constant<bool, false>;
    using true_type  = integral_constant<bool, true>;

    template<class T, class U>
    struct is_same : false_type {};

    template<class T>
    struct is_same<T, T> : true_type {};

    template<bool B, class T = void>
    struct enable_if {};

    template<class T>
    struct enable_if<true, T> { typedef T type; };

    namespace detail {

    template <class T>
    struct type_identity { using type = T; }; // or use std::type_identity (since C++20)

    template <class T>
    auto try_add_lvalue_reference(int) -> type_identity<T&>;
    template <class T>
    auto try_add_lvalue_reference(...) -> type_identity<T>;

    template <class T>
    auto try_add_rvalue_reference(int) -> type_identity<T&&>;
    template <class T>
    auto try_add_rvalue_reference(...) -> type_identity<T>;

    } // namespace detail

    template <class T>
    struct add_lvalue_reference : decltype(detail::try_add_lvalue_reference<T>(0)) {};

    template <class T>
    struct add_rvalue_reference : decltype(detail::try_add_rvalue_reference<T>(0)) {};

    template<class T>
    typename add_rvalue_reference<T>::type declval() noexcept;

    template<bool B, class T, class F>
    struct conditional { typedef T type; };

    template<class T, class F>
    struct conditional<false, T, F> { typedef F type; };

}
