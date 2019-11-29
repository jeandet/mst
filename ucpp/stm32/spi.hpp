#pragma once

#include "../spi.hpp"
#include "../utils.hpp"
#include "./spi-regs.hpp"

namespace ucpp::stm32::spi {
using namespace ucpp::spi;

template <typename regs, typename word_size = w8bits,
          typename bit_order = msb_first>
struct SPI {
  // TODO make this configurable!
  static constexpr void init() {
    static_assert(!is_16bits_or_less_v<word_size>, "unsuported word size");
    regs::CR1 = regs::CR1.SPE.shift(1) | regs::CR1.MSTR.shift(1) |
                regs::CR1.LSBFIRST.shift(is_lsb_first_v<bit_order>);
    if constexpr (is_8bits_v<word_size>)
      regs::CR2 = regs::CR2.DS.shift(7);
    else if constexpr (is_16bits_v<word_size>)
      regs::CR2 = regs::CR2.DS.shift(0xf);
  }

  template <typename T> static constexpr T p_write(T data) {
    constexpr int N = word_size::size / (sizeof(T) * 8);
    T result = 0;
    for (int i = 0; i < N; i++) {
      if constexpr (is_msb_first_v<bit_order>)
        regs::DR = data >> (word_size::size * (N - 1 - i));
      else
        regs::DR = data >> (word_size::size * N);
      while (!regs::SR.RXNE)
        ;
      if constexpr (is_msb_first_v<bit_order>)
        result |= regs::DR << (word_size::size * (N - 1 - i));
      else
        result |= regs::DR << (word_size::size * N);
    }
    return result;
  }

  template <typename T> static constexpr T write(T data) {
    static_assert(
        !ucpp::utils::is_one_of<T, uint8_t, uint16_t, uint32_t>::value,
        "write function only accept uint8_t, uint16_t or uint32_t");
    return p_write(data);
  }

  template <typename T> static constexpr T read(T data) {
    static_assert(
        !ucpp::utils::is_one_of<T, uint8_t, uint16_t, uint32_t>::value,
        "read function only accept uint8_t, uint16_t or uint32_t");
    return write(data);
  }
};
} // namespace ucpp::stm32::spi
