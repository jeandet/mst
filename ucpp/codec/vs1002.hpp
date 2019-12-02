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

template <typename spi, typename io_pins, uint32_t osc=24576000> struct vs1002 {
  static uint16_t model;
  static constexpr void init()
  {
    spi::init();
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
    write_reg(registers::vol, 0x2020);
    uint16_t clkf=0;
    if constexpr (osc<15000000)
            clkf =(osc/2000)+0x8000;
    else
        clkf =osc/2000;
    write_reg(registers::clockf, clkf);
  }

  static constexpr uint16_t read_reg(registers reg)
  {
      io_pins::xcs(0);
      for(volatile int i=0;i<16;i++);
      spi::write(static_cast<uint16_t>(0x300 | static_cast<uint16_t>(reg)));
      auto reg_value = spi::read(static_cast<uint16_t>(0xffff));
      io_pins::xcs(1);
      return reg_value;
  }

  static constexpr void write_reg(registers reg, uint16_t value)
  {
      io_pins::xcs(0);
      for(volatile int i=0;i<16;i++);
      spi::write(static_cast<uint16_t>(0x200 | static_cast<uint16_t>(reg)));
      spi::write(value);
      io_pins::xcs(1);
  }

  static constexpr void write_data(char* data)
  {
      while (io_pins::dreq()==0);
      io_pins::xdcs(0);
      for(volatile int i=0;i<16;i++);
      for(int i=0;i<32;i++)
        spi::write(data[i]);
      io_pins::xdcs(1);
  }
};
} // namespace ucpp::codec
