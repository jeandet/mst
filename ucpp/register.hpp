#pragma once
#include <stdint.h>
#include <utility>
#include <tuple>

namespace ucpp::registers {
template <typename T, const uint32_t address>
struct reg_t
{
    using type = T;
    static inline volatile T& value()noexcept
    {
       return *reinterpret_cast<volatile T*>(address);
    }

    inline constexpr reg_t operator=(const T& value) const noexcept
    {
        reg_t::value() = value;
        return reg_t<T,address>{};
    }

    constexpr operator volatile T&() noexcept { return value(); }
    constexpr operator const volatile T&() const noexcept { return *reinterpret_cast<volatile T*>(address); }
};

namespace details {
    template<typename T,int start, int stop>
    constexpr T compute_mask()
    {
        if constexpr(start == stop)
        {
                return static_cast<T>(1<<stop);
        }else
        {
            return static_cast<T>((static_cast<unsigned long long>(-1)<<(stop+1)) xor (static_cast<unsigned long long>(-1)<<start));
        }
    }
}

template <typename reg_t, int start_index, int stop_index=start_index, typename value_t=int>
struct bitfield_t
{
    using type = typename reg_t::type;
    static constexpr const int start = start_index;
    static constexpr const int stop = stop_index;
    static constexpr const typename reg_t::type mask = details::compute_mask<typename reg_t::type, start, stop>();

    inline constexpr bitfield_t operator=(const value_t& value) const noexcept
    {
        typename reg_t::type tmp = ((static_cast<int>(value)<<start) & mask);
        reg_t::value() = (reg_t::value() &  ~mask)|tmp;
        return bitfield_t<reg_t,start_index,stop_index,value_t>{};
    }

    constexpr operator value_t() noexcept { return value_t((int(reg_t::value())& mask)>>start); }
    constexpr operator value_t() const noexcept { return value_t((int(reg_t::value())& mask)>>start); }
};


template <std::size_t start_index, std::size_t width, typename reg_t, std::size_t count, typename value_t=int>
struct bitfield_array_t
{
    static constexpr const typename reg_t::type field_mask = details::compute_mask<typename reg_t::type, start_index, start_index + width-1>();
    static constexpr const typename reg_t::type mask = details::compute_mask<typename reg_t::type, start_index, start_index + (width*count)-1>();
    template<std::size_t i>
    static constexpr auto get() noexcept
    {
        static_assert ((i>=0)and(i<count), "Bitfield index is out of bounds");
        return bitfield_t<reg_t, (i*width)+start_index, ((i+1)*width)+start_index-1, value_t>{};
    }

    template<typename T>
    inline constexpr bitfield_array_t operator=(const T& value) const noexcept
    {
        if constexpr(std::is_same_v<typename reg_t::type,T>)
            reg_t::value() = field_mask & (value << start_index);
        else if constexpr(std::conjunction_v<std::is_same<value_t,T>,std::negation<std::is_integral<T>>>)
        {
            //reg_t::value() = field_mask & (value << start_index);
        }
        return bitfield_array_t<start_index,width,reg_t,count,value_t>{};
    }

    constexpr operator typename reg_t::type() noexcept { return typename reg_t::type((int(reg_t::value())& mask)>>start_index); }
    constexpr operator typename reg_t::type() const noexcept { return typename reg_t::type((int(reg_t::value())& mask)>>start_index); }
};

}
