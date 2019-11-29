#pragma once
#include <type_traits>
#include "utils.hpp"

namespace ucpp::spi {
struct w8bits{inline static constexpr std::size_t size = 8;};
struct w16bits{inline static constexpr std::size_t size = 16;};
struct w32bits{inline static constexpr std::size_t size = 32;};

template <typename T>
using is_8bits = std::is_same<T, w8bits>;
template <typename T>
inline constexpr bool is_8bits_v = is_8bits<T>::value;

template <typename T>
using is_16bits = std::is_same<T, w16bits>;
template <typename T>
inline constexpr bool is_16bits_v = is_16bits<T>::value;

template <typename T>
using is_32bits = std::is_same<T, w32bits>;
template <typename T>
inline constexpr bool is_32bits_v = is_32bits<T>::value;

template <typename T>
using is_16bits_or_less = ucpp::utils::is_one_of<T, w8bits, w16bits>;
template <typename T>
inline constexpr bool is_16bits_or_less_v = is_16bits_or_less<T>::value;

template <typename T>
using is_32bits_or_less = ucpp::utils::is_one_of<T, w8bits, w16bits, w32bits>;
template <typename T>
inline constexpr bool is_32bits_or_less_v = is_32bits_or_less<T>::value;

struct lsb_first{};
struct msb_first{};
template <typename T>
using is_msb_first = std::is_same<T, msb_first>;
template <typename T>
inline constexpr bool is_msb_first_v = is_msb_first<T>::value;

template <typename T>
using is_lsb_first = std::is_same<T, lsb_first>;
template <typename T>
inline constexpr bool is_lsb_first_v = is_lsb_first<T>::value;

}
