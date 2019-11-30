#pragma once
#include <cstdint>

namespace ucpp::codec {
enum class registers {
  mode = 0,
  status = 1,
  bass = 2,
  clockf = 3,
  decode_time = 4,
  audata = 5,
  wram = 6,
  wramaddr = 7,
  hdat0 = 8,
  hdat1 = 9,
  aiaddr = 0xA,
  vol = 0xB,
  aictrl0 = 0xC,
  aictrl1 = 0xD,
  aictrl2 = 0xE,
  aictrl3 = 0xF
};

template <typename spi, typename io_pins> struct vs1002 {
  static uint16_t model;
  static constexpr void init()
  {
    io_pins::xcs(1);
    io_pins::xdcs(1);
    io_pins::reset(0);
    for (volatile int i = 0; i < 1024; i++)
      ;
    io_pins::reset(1);
    uint16_t status=0;
    do {
        status = read_reg(registers::status);
    }while(status==0xc);
  }

  static constexpr uint16_t read_reg(registers reg)
  {
      io_pins::xcs(0);
      spi::write(static_cast<uint16_t>(0x300 | static_cast<uint16_t>(reg)));
      io_pins::xcs(1);
      return spi::read(static_cast<uint16_t>(0xffff));
  }

  static constexpr void write_reg(registers reg, uint16_t value)
  {
      io_pins::xcs = 0;
      spi::write(static_cast<uint16_t>(0x200 | static_cast<uint16_t>(reg)));
      spi::write(value);
      io_pins::xcs = 1;
  }

  static constexpr void write_data(char* data)
  {
      while (!io_pins::dreq);
      io_pins::xdcs(0);
      for(int i=0;i<32;i++)
        spi::write(data[i]);
      io_pins::xdcs(1);
  }
};
} // namespace ucpp::codec
