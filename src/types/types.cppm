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

  enum class float_rounding_direction {
    downward = libc::FE_DOWNWARD,
    to_nearest = libc::FE_TONEAREST,
    toward_zero = libc::FE_TOWARDZERO,
    upward = libc::FE_UPWARD
  };

  enum class float_denorm {
    indeterminable = -1,
    absent = 0,
    present = 1
  };

  template<typename T>
  struct numeric_limits
  {
    /// Signed type of the same size if exists.
    using signed_type = T;
    /// Unsigned type of the same size if exists.
    using unsigned_type = T;

    /// Size of type in bits.
    static constexpr u16 bits = 0;
    /// Smalles finite value.
    static constexpr T min = 0;
    /// Biggest finite value.
    static constexpr T max = 0;

    /// Radix of exponent representation.
    static constexpr u32 radix = 0;
    /// Number of significant bits in base 2.
    static constexpr u32 mantissa_bits = 0;
    /// Machine epsilon value.
    static constexpr T epsilon = 0;
    /// Smallest positive normal value.
    static constexpr T min_positive = 0;

    /// Minimum possible normal power of 2 exponent.
    static constexpr i32 min_exponent = 0;
    /// Maximum possible normal value of 2 exponent.
    static constexpr i32 max_exponent = 0;

    /// Minimum possible normal power of 10 exponent.
    static constexpr i32 min_10_exponent = 0;
    /// Maximum possible normal value of 10 exponent.
    static constexpr i32 max_10_exponent = 0;

    /// Infinity.
    static constexpr T infinity = 0;
    /// Not a Number.
    static constexpr T NaN = 0;
    static constexpr T quiet_NaN = 0;
    static constexpr T signalling_NaN = 0;

    static constexpr float_rounding_direction rounding_direction =
        float_rounding_direction::toward_zero;
    static constexpr float_denorm denorm = float_denorm::absent;

    static constexpr bool is_exact = false;
    static constexpr bool has_quiet_NaN = false;
    static constexpr bool has_signaling_NaN = false;
    static constexpr bool has_denorm = false;
    static constexpr bool has_denorm_loss = false;
    static constexpr bool is_IEEE754 = false;
    static constexpr bool is_bounded = false;
    static constexpr bool is_modulo = false;
    static constexpr bool traps = false;
  };
}

