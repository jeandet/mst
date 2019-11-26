#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <cstdint>
#include <register.hpp>

template <int address, typename T = uint32_t>
struct reg_mock
{
    using type = T;
    static inline type p_value = 0;
    static inline volatile type& value() noexcept { return reg_mock::p_value; }

    inline constexpr reg_mock operator=(const type& value) const noexcept
    {
        reg_mock::value() = value;
        return reg_mock<address> {};
    }

    template <typename U>
    inline constexpr auto operator=(const U& bit_field_value) const noexcept -> decltype(
        std::declval<U>().value, std::declval<U>().mask, std::declval<reg_mock<address, T>>())
    {
        reg_mock::value() = (reg_mock::value() & ~bit_field_value.mask) | bit_field_value.value;
        return reg_mock<address, T> {};
    }

    constexpr operator volatile type&() noexcept { return value(); }
    constexpr operator const volatile type&() const noexcept { return p_value; }
};

enum class field_values
{
    value0 = 0,
    value1 = 1
};

TEST_CASE("Full size bitfield", "[bitfield]")
{
    using reg = reg_mock<0>;
    REQUIRE(reg::p_value == 0);
    ucpp::registers::bitfield_t<reg, 0, 31> field;
    SECTION("Can set int")
    {
        field = 0xA5f00f5A;
        REQUIRE(field == 0xA5f00f5A);
        REQUIRE(reg::p_value == 0xA5f00f5A);
        field = 0;
        REQUIRE(field == 0);
        REQUIRE(reg::p_value == 0);
    }
}


TEST_CASE("right aligned bitfield", "[bitfield]")
{
    using reg = reg_mock<1>;
    ucpp::registers::bitfield_t<reg, 0, 7> field;
    SECTION("Can set int")
    {
        field = 0;
        REQUIRE(field == 0);
        REQUIRE(reg::p_value == 0);
        field = 0xff;
        REQUIRE(field == 0xff);
        REQUIRE(reg::p_value == 0xff);
    }
    SECTION("Masks too big integer")
    {
        field = 0x123;
        REQUIRE(field == 0x23);
        REQUIRE(reg::p_value == 0x23);
    }
    SECTION("does not ovewrite neighbour bits")
    {
        reg::p_value = 0x654321;
        field = 0x0;
        REQUIRE(field == 0);
        REQUIRE(reg::p_value == 0x654300);
    }
}

TEST_CASE("left aligned bitfield", "[bitfield]")
{
    using reg = reg_mock<2>;
    ucpp::registers::bitfield_t<reg, 24, 31> field;
    SECTION("Can set int")
    {
        field = 0xff;
        REQUIRE(field == 0xff);
        REQUIRE(reg::p_value == 0xff000000);
        field = 0;
        REQUIRE(field == 0);
        REQUIRE(reg::p_value == 0);
    }
    SECTION("Masks too big integer")
    {
        field = 0x123;
        REQUIRE(field == 0x23);
        REQUIRE(reg::p_value == 0x23000000);
    }
}

TEST_CASE("centered bitfield", "[bitfield]")
{
    using reg = reg_mock<3>;
    ucpp::registers::bitfield_t<reg, 8, 23> field;
    SECTION("Can set int")
    {
        field = 0xaff5;
        REQUIRE(field == 0xaff5);
        REQUIRE(reg::p_value == 0x00aff500);
        field = 0;
        REQUIRE(field == 0);
        REQUIRE(reg::p_value == 0);
    }
    SECTION("Masks too big integer")
    {
        field = 0x12345678;
        REQUIRE(field == 0x5678);
        REQUIRE(reg::p_value == 0x00567800);
    }
}


TEST_CASE("bitfield_array", "[bitfield_array]")
{
    using reg = reg_mock<4>;
    using field_t = ucpp::registers::bitfield_array_t<8, 1, reg, 16, field_values>;
    field_t fields;
    SECTION("Can set int")
    {
        fields = 0xaff5;
        REQUIRE(fields == 0xaff5);
        REQUIRE(reg::p_value == 0x00aff500);
        fields = 0;
        REQUIRE(fields == 0);
        REQUIRE(reg::p_value == 0);
    }
    SECTION("Can set single field")
    {
        reg::p_value = 0;
        fields.get<0>() = field_values::value1;
        REQUIRE(fields == 1);
        REQUIRE(reg::p_value == 0x00000100);
        reg::p_value = 0;
        fields.get<15>() = field_values::value1;
        REQUIRE(fields == 1 << 15);
        REQUIRE(reg::p_value == 0x00800000);
    }
    SECTION("Masks too big integer")
    {
        reg::p_value = 0;
        fields = 0x12345678;
        REQUIRE(fields == 0x5678);
        REQUIRE(reg::p_value == 0x00567800);
    }
    SECTION("Can set all fields at once")
    {
        reg::p_value = 0;
        fields = field_values::value1;
        REQUIRE(fields == 0xffff);
        REQUIRE(reg::p_value == 0x00ffff00);
    }
}


TEST_CASE("Set several bit fields at once", "[bitfield]")
{
    using namespace ucpp::registers;
    struct my_reg_t : reg_mock<5>
    {
        bitfield_t<reg_mock<5>, 0, 3> field1;
        bitfield_t<reg_mock<5>, 4, 7> field2;
        bitfield_t<reg_mock<5>, 8, 31> field3;
        using reg_mock<5>::operator=;
    } my_reg = {};

    my_reg = my_reg.field1.shift(2) | my_reg.field2.shift(0xf) | my_reg.field3.shift(0xA5ff5A);
    REQUIRE(my_reg.field1 == 2);
    REQUIRE(my_reg.field2 == 0xf);
    REQUIRE(my_reg.field3 == 0xA5ff5A);
    REQUIRE(my_reg == 0xA5ff5AF2);
}
