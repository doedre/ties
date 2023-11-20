export module ties.types;

import ties.libc;

export namespace ties {
  using i8 = libc::int8_t;
  using i16 = libc::int16_t;
  using i32 = libc::int32_t;
  using i64 = libc::int64_t;

  using u8 = libc::uint8_t;
  using u16 = libc::uint16_t;
  using u32 = libc::uint32_t;
  using u64 = libc::uint64_t;

  using usize = libc::size_t;

  using f32 = float;
  using f64 = double;

  [[nodiscard]] consteval auto operator""_i8(unsigned long long i) noexcept -> i8
  {
    return static_cast<i8>(i);
  }

  [[nodiscard]] consteval auto operator""_i16(unsigned long long i) noexcept -> i16
  {
    return static_cast<i16>(i);
  }

  [[nodiscard]] consteval auto operator""_i32(unsigned long long i) noexcept -> i32
  {
    return static_cast<i32>(i);
  }

  [[nodiscard]] consteval auto operator""_i64(unsigned long long i) noexcept -> i64
  {
    return static_cast<i64>(i);
  }

  [[nodiscard]] consteval auto operator""_u8(unsigned long long i) noexcept -> u8
  {
    return static_cast<u8>(i);
  }

  [[nodiscard]] consteval auto operator""_u16(unsigned long long i) noexcept -> u16
  {
    return static_cast<u16>(i);
  }

  [[nodiscard]] consteval auto operator""_u32(unsigned long long i) noexcept -> u32
  {
    return static_cast<u32>(i);
  }

  [[nodiscard]] consteval auto operator""_u64(unsigned long long i) noexcept -> u64
  {
    return static_cast<u64>(i);
  }

  [[nodiscard]] consteval auto operator""_f32(long double f) noexcept -> f32
  {
    return static_cast<f32>(f);
  }

  [[nodiscard]] consteval auto operator""_f64(long double f) noexcept -> f64
  {
    return static_cast<f64>(f);
  }

  [[nodiscard]] consteval auto operator""_bool(unsigned long long i) noexcept -> bool
  {
    return static_cast<bool>(i);
  }

  [[nodiscard]] consteval auto operator""_usize(unsigned long long i) noexcept -> usize
  {
    return static_cast<usize>(i);
  }
}

