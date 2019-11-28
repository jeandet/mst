#pragma once

#include <type_traits>
#include <cstdint>

namespace ucpp::sdcard::commands {
struct no_response {};
struct short_response {
  uint32_t value;
};
struct long_response {
  uint32_t value[4];
};

template<typename CMD>
struct is_no_response:std::is_same<typename CMD::response_type, no_response>{};
template<typename CMD>
using is_no_response_t = typename is_no_response<CMD>::type;
template<typename CMD>
inline constexpr bool is_no_response_v = is_no_response<CMD>::value;

template<typename CMD>
struct is_short_response:std::is_same<typename CMD::response_type, short_response>{};
template<typename CMD>
using is_short_response_t = typename is_short_response<CMD>::type;
template<typename CMD>
inline constexpr bool is_short_response_v = is_short_response<CMD>::value;

template<typename CMD>
struct is_long_response:std::is_same<typename CMD::response_type, long_response>{};
template<typename CMD>
using is_long_response_t = typename is_long_response<CMD>::type;
template<typename CMD>
inline constexpr bool is_long_response_v = is_long_response<CMD>::value;

namespace  {
struct normal_cmd{};
struct application_specific_cmd{};
struct check_crc{};
struct ignore_crc{};
}

template<typename CMD>
struct is_application_specific:std::is_same<typename CMD::cmd_type, application_specific_cmd>{};
template<typename CMD>
using is_application_specific_t = typename is_application_specific<CMD>::type;
template<typename CMD>
inline constexpr bool is_application_specific_v = is_application_specific<CMD>::value;

template<typename CMD>
struct has_crc:std::is_same<typename CMD::crc, check_crc>{};
template<typename CMD>
using has_crc_t = typename has_crc<CMD>::type;
template<typename CMD>
inline constexpr bool has_crc_v = has_crc<CMD>::value;

template <int CMD, typename resp_t, typename cmd_t = normal_cmd, typename crc_t = check_crc>
struct SD_CMD {
  static inline constexpr int index = CMD;
  using response_type = resp_t;
  using cmd_type = cmd_t;
  using crc = cmd_t;
};

using CMD0 = SD_CMD<0, no_response>;
using CMD8 = SD_CMD<8, short_response>;
using CMD55 = SD_CMD<55, short_response>;
using ACMD41 = SD_CMD<41, short_response, application_specific_cmd, ignore_crc>;
}
