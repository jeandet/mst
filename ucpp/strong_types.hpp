#ifndef STRONG_TYPES_HPP
#define STRONG_TYPES_HPP
#include "strong_ops.hpp"
#include "utils.hpp"


namespace ucpp::strong_types
{
template <typename T, typename... operations>
struct strong_type: operations::template type<strong_type<T, operations...>>...
{
    struct is_strong{};
    using underlying_type = T;

    strong_type()=delete;
    explicit strong_type(const T& value):
        p_value{value}
    {}

    T& value(){return p_value;}
    const T& value() const{return p_value;}

    explicit operator T&() noexcept
    {
        return p_value;
    }

    explicit operator const T&() const noexcept
    {
        return p_value;
    }

private:
    T p_value;
};

}
#endif // STRONG_TYPES_HPP
