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


template <typename reg, int start_index, int stop_index=start_index>
struct bitfield_t
{
    static constexpr const int start = start_index;
    static constexpr const int stop = stop_index;
    static constexpr const typename reg::type mask = details::compute_mask<typename reg::type, start, stop>();

    inline bitfield_t& operator=(const int& value) noexcept
    {
        reg::value() = (reg::value() & mask)|(value<<start);
        return *this;
    }

    constexpr operator int() noexcept { return (int(reg::value())& mask)>>start; }
    constexpr operator int() const noexcept { return (int(reg::value())& mask)>>start; }
};

template <int start_index, int stop_index, typename reg, std::size_t N>
struct bitfield_array_t: reg
{
    template<std::size_t i>
    static constexpr auto get() noexcept
    {
        constexpr bool width=stop_index-start_index+1;
        return bitfield_t<reg, (i*width)+start_index, ((i+1)*width)+start_index-1>{};
    }
};

}
