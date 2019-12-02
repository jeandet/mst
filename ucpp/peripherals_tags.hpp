#pragma once
#include <type_traits>

namespace ucpp::tags {

struct no_tag;

template <typename T, typename tag>
struct has_tag : std::is_same<typename T::tag, tag>
{
};

template <typename T, typename tag>
inline constexpr bool has_tag_v = has_tag<T, tag>::value;

#define DECLARE_DEVICE(device) \
struct device##_tag{}; \
template <typename T> \
using is_##device = has_tag<T,device##_tag>; \
template <typename T> \
inline constexpr bool is_##device##_v = is_##device<T>::value;


DECLARE_DEVICE(uart)
DECLARE_DEVICE(gpio)
DECLARE_DEVICE(sdmmc)
DECLARE_DEVICE(spi)
DECLARE_DEVICE(pwr)
DECLARE_DEVICE(scb)
DECLARE_DEVICE(dma)
DECLARE_DEVICE(flash)
DECLARE_DEVICE(apb_bus)

}




