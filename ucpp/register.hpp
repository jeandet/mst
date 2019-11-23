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

    inline reg_t& operator=(const T& value) noexcept
    {
        value() = value;
        return *this;
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
            return static_cast<T>((static_cast<T>(-1)<<(stop+1)) xor (static_cast<T>(-1)<<start));
        }
    }
}


template <typename reg, int start_index, int stop_index=start_index, typename value_t=int>
struct bitfield_t
{
    using type = typename reg::type;
    static constexpr const int start = start_index;
    static constexpr const int stop = stop_index;
    static constexpr const typename reg::type mask = details::compute_mask<typename reg::type, start, stop>();

    inline constexpr bitfield_t operator=(const value_t& value) const noexcept
    {
        typename reg::type tmp = ((static_cast<int>(value)<<start) & mask);
        reg::value() = (reg::value() &  ~mask)|tmp;
        return bitfield_t<reg,start_index,stop_index,value_t>{};
    }

    constexpr operator value_t() noexcept { return value_t((int(reg::value())& mask)>>start); }
    constexpr operator value_t() const noexcept { return value_t((int(reg::value())& mask)>>start); }
};

template <std::size_t start_index, std::size_t width, typename reg, std::size_t count, typename value_t=int>
struct bitfield_array_t: reg
{
    template<std::size_t i>
    static constexpr auto get() noexcept
    {
        static_assert ((i>=0)and(i<count), "Bitfield index is out of bounds");
        return bitfield_t<reg, (i*width)+start_index, ((i+1)*width)+start_index-1, value_t>{};
    }
};

}
