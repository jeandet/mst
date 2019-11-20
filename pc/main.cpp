#include <ucpp/strong_ops.hpp>
#include <ucpp/strong_types.hpp>
#include <stdint.h>
#include <iostream>

template<class resulst_t, class lhs_t, class rhs_t> struct add
{
  friend resulst_t operator+(lhs_t lhs, const rhs_t& rhs)
  {
    return resulst_t{lhs.value()+rhs.value()};
  }
};

struct test
{
    explicit test(int v):a{v}{}
private:
    int a;
};

using namespace ucpp::strong_types;
using offset_t = strong_type<uint32_t>;
using address_t = strong_type<uint32_t,
                    ops::plus<int, ops::self_t>,
                    ops::unary_plus<int, ops::self_t>,
                    ops::plus<offset_t, ops::self_t>,
                    ops::unary_plus<offset_t, ops::self_t>,
                    ops::minus<ops::self_t, offset_t>,
                    ops::minus<>>;

address_t operator"" _a32 (unsigned long long v )
{
    return address_t(v);
}

offset_t operator"" _o32 (unsigned long long v )
{
    return offset_t(v);
}

int main()
{
    auto add1 = 510_a32, add2 = 256_a32;
    add1 += 1;
    add1 += 1_o32;
    //std::cout << ucpp::strong_types::ops::is_strong<address_t>::value << std::endl;
    std::cout << (add1 - add2).value()<< std::endl;
    std::cout << ops::has_value<address_t>::value << std::endl;
    return 0;
}
