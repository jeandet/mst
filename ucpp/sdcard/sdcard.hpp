#pragma once
#include "../strong_types.hpp"
#include "./commands.hpp"
#include <cstdint>
#include <optional>
#include <type_traits>

namespace ucpp::sdcard {

using namespace ucpp::strong_types;
struct block_address_t
    : strong_type<uint32_t, ops::plus<int, ops::self_t, ops::self_t, true>,
                  ops::unary_plus<int, ops::self_t>,
                  ops::minus<int, ops::self_t, ops::self_t, true>,
                  ops::unary_minus<int, ops::self_t>> {
  using strong_type::strong_type;
};

namespace {
template <typename sdcard> inline bool set_block_size(uint32_t size) {
  using namespace commands;
  if (sdcard::template send_cmd<CMD16>(size))
    return true;
  return false;
}
} // namespace

template <typename bus> struct Sdcard {
  uint16_t RCA = 0;

  bool init() {
    using namespace commands;
    Sdcard::send_cmd<CMD0>();
    for (volatile int i = 0; i < 1024; i++)
      ;
    auto r = Sdcard::send_cmd<CMD8>(0x1aa);
    if (!r) // SD SC
    {
      return false;
    } else if (r->value != 0x1aa) {
      return false;
    } // SD HC
    else {
      do {
        // 0x80100000U
        r = Sdcard::send_cmd<ACMD41>(0x40000000 | 0x80100000);
        volatile int v = r->value;
        v = r->value;
      } while (r->value >> 31 == 0);
    }
    auto cid_r = Sdcard::send_cmd<CMD2>();
    r = Sdcard::send_cmd<CMD3>();
    if (r) {
      bus::set_speed(10000000);
      RCA = r->value >> 16;
      return true;
    }
    return false;
  }

  template <typename CMD>
  inline static constexpr auto send_cmd(uint32_t argument = 0) {
    using namespace commands;
    if constexpr (is_application_specific_v<CMD>) {
      auto r = bus::template send_cmd<CMD55>(0);
      if (!r)
        return std::optional<typename CMD::response_type>{std::nullopt};
    }
    return bus::template send_cmd<CMD>(argument);
  }

  inline constexpr auto select() {
    using namespace commands;
    return send_cmd<CMD7>(RCA << 16);
  }

  inline constexpr auto read_block(block_address_t address, char *data) {
    using namespace commands;
    return bus::read_block(address, data);
    return false;
  }
};

} // namespace ucpp::sdcard
