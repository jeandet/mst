#ifndef STRONG_OPS_HPP
#define STRONG_OPS_HPP

#include "utils.hpp"

namespace ucpp::strong_types::ops
{
using namespace ucpp::utils::tinystl;
struct self_t{};

template<typename u, typename self_t_>
using resolve = conditional<is_same<u,self_t>::value, self_t_, u>;

template<typename u, typename self_t_>
using resolve_t = typename resolve<u,self_t_>::type;

template <typename T>
struct has_value {

    template <typename U>
    static constexpr
    decltype(declval<U>().value(), bool())
    test_value(int) {
        return true;
    }

    template <typename U>
    static constexpr bool test_value(...) {
        return false;
    }

    static constexpr bool value = test_value<T>(int());
};

template <typename T>
auto value(const T& obj)
{
    if constexpr(has_value<T>::value)
    {
        return obj.value();
    }
    else
    {
     return obj;
    }
}

template<typename lhs_t=self_t, typename rhs_t=self_t, typename result_t=self_t,  bool permutable=false> struct plus
{
    template<class Object> struct permutation
    {
        inline friend resolve_t<result_t, Object> operator+(const resolve_t<rhs_t, Object>& lhs, const resolve_t<lhs_t, Object>& rhs)
        {
            return resolve_t<result_t, Object>(value(lhs)+value(rhs));
        }
    };

    template<class Object> struct type : conditional<permutable, permutation<Object>, self_t>::type
    {
        inline friend resolve_t<result_t, Object> operator+(const resolve_t<lhs_t, Object>& lhs, const resolve_t<rhs_t, Object>& rhs)
        {
            return resolve_t<result_t, Object>(value(lhs)+value(rhs));
        }
    };
};

template<typename rhs_t=self_t, typename result_t=self_t> struct unary_plus
{
    template<class Object> struct type
    {
        inline friend Object& operator+=(Object& lhs,const resolve_t<rhs_t, Object>& other)
        {
            lhs.value() += value(other);
            return lhs;
        }
    };
};

template<typename lhs_t=self_t, typename rhs_t=self_t, typename result_t=self_t, bool permutable=false> struct minus
{
    template<class Object> struct permutation
    {
        inline friend resolve_t<result_t, Object> operator-(const resolve_t<rhs_t, Object>& lhs, const resolve_t<lhs_t, Object>& rhs)
        {
            return resolve_t<result_t, Object>(value(lhs)-value(rhs));
        }
    };

    template<class Object> struct type : conditional<permutable, permutation<Object>, self_t>::type
    {
        friend resolve_t<result_t, Object> operator-(const resolve_t<lhs_t, Object>& lhs, const resolve_t<rhs_t, Object>& rhs)
        {
            return resolve_t<result_t, Object>{value(lhs)-value(rhs)};
        }
    };
};

template<typename rhs_t=self_t, typename result_t=self_t> struct unary_minus
{
    template<class Object> struct type
    {
        inline friend Object& operator-=(Object& lhs,const resolve_t<rhs_t, Object>& other)
        {
            lhs.value() -= value(other);
            return lhs;
        }
    };
};


}
#endif // STRONG_OPS_HPP
