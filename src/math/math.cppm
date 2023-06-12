export module ties.math;

export import ties.types;

import ties.concepts;

export namespace ties::math {

  template<typename T>
  requires types::integral<T>
  [[nodiscard]] constexpr auto abs(T val) noexcept -> T
  {
    if (val < 0) {
      return -val;
    } else {
      return val;
    }
  }

  template<typename T>
  requires types::floating_point<T>
  [[nodiscard]] constexpr auto abs(T val) noexcept -> T
  {
    return 0;
  }

  template<typename T>
  requires types::signed_integral<T>
  [[nodiscard]] constexpr auto sign(T val) noexcept -> T
  {
    return (val > 0) - (val < 0);
  }

  template<typename T>
  requires types::unsigned_integral<T>
  [[nodiscard]] constexpr auto sign(T val) noexcept -> T
  {
    return val != 0;
  }

  template<typename T>
  requires types::floating_point<T>
  [[nodiscard]] constexpr auto sign(T val) noexcept -> T
  {
    return 0;
  }

  template<typename T>
  requires types::integral<T>
  [[nodiscard]] constexpr auto all_ones() noexcept -> T
  {
    if constexpr (types::signed_integral<T>) {
      return -1;
    } else {
      return types::limits<T>::max;
    }
  }

  // Mula et al(2018)
  template<typename T>
  requires types::integral<T>
  [[nodiscard]] constexpr auto count_ones(T val) noexcept -> types::u32
  {
    types::u32 res = 0;
    for (types::u32 i = 0; i < types::info<T>::bits; ++i) {
      res += (val >> i) & 1;
    }
    return res;
  }

  template<typename T>
  requires types::integral<T>
  [[nodiscard]] constexpr auto count_zeros(T val) noexcept -> types::u32
  {
    return types::info<T>::bits - count_ones(val);
  }

  // http://graphics.stanford.edu/~seander/bithacks.html#ZerosOnRightLinear
  template<typename T>
  requires types::integral<T>
  [[nodiscard]] constexpr auto trailing_zeros(T val) noexcept -> types::u32
  {
    if (val) {
      val = (val ^ (val - 1)) >> 1;
      types::u32 res = 0;
      for (; val; ++res) {
        val >>= 1;
      }
      return res;
    } else {
      return types::info<T>::bits;
    }
  }

  template<typename T>
  requires types::integral<T>
  [[nodiscard]] constexpr auto trailing_ones(T val) noexcept -> types::u32
  {
    if (val != all_ones<T>()) {
      val = (val ^ (val + 1)) >> 1;
      types::u32 res = 0;
      for (; val; ++res) {
        val >>= 1;
      }
      return res;
    } else {
      return types::info<T>::bits;
    }
  }

  // http://graphics.stanford.edu/~seander/bithacks.html#IntegerLogObvious
  template<typename T>
  requires types::integral<T>
  [[nodiscard]] constexpr auto leading_zeros(T val) noexcept -> types::u32
  {
    if (val != all_ones<T>()) {
      types::u32 res = 0;
      for (; val; ++res) {
        val >>= 1;
      }
      return types::info<T>::bits - res;
    } else {
      return 0;
    }
  }

  template<typename T>
  requires types::integral<T>
  [[nodiscard]] constexpr auto leading_ones(T val) noexcept -> types::u32
  {
    if (val != all_ones<T>()) {
      return 0;
    } else {
      return types::info<T>::bits;
    }
  }

  // Look for Hare's implementation
  template<typename T>
  requires types::integral<T>
  [[nodiscard]] constexpr auto carrying_add(T x, T y, bool carry)
      -> types::tuple<T, bool>
  {
    const T sum = x + y + static_cast<T>(carry);
    const bool carry_out = ((x & y) | ((x | y) & ~sum)) >> (types::info<T>::bits - 1);
    return { sum, carry_out };
  }

  template<typename T>
  requires types::integral<T>
  [[nodiscard]] constexpr auto borrowing_sub(T x, T y, bool borrow)
      -> types::tuple<T, bool>
  {
    const T diff = x - y - static_cast<T>(borrow);
    const bool borrow_out = ((~x & y) | (~(x ^ y) & diff)) >> (types::info<T>::bits - 1);
    return { diff, borrow_out };
  }
}
