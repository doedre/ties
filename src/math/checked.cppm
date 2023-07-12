export module ties.math.checked;

export import ties.types;
export import ties.types.maybe;

import ties.concepts;

export namespace ties::math::checked {
  template<typename T>
  requires concepts::integral<T>
  [[nodiscard]] constexpr auto abs(const T val) noexcept -> types::maybe<T>
  {
    if constexpr (concepts::signed_integral<T>) {
      if (val == types::limits<T>::min) {
        return types::none;
      }

      if (val < 0) {
        return -val;
      } else {
        return val;
      }
    } else {
      return val;
    }
  }

  template<typename T>
  requires concepts::integral<T>
  [[nodiscard]] constexpr auto add(const T lhs, const T rhs) noexcept
      -> types::maybe<T>
  {
    if ((rhs > 0) && (lhs > (types::limits<T>::max - rhs))) {
      return types::none;
    } else if ((rhs < 0) && (lhs < (types::limits<T>::min - rhs))) {
      return types::none;
    } else {
      return static_cast<T>(lhs + rhs);
    }
  }

  template<typename T>
  requires concepts::signed_integral<T>
  [[nodiscard]] constexpr auto add(
      const T lhs,
      const typename types::info<T>::unsigned_type rhs
  ) noexcept -> types::maybe<T>
  {
    if (lhs > (types::limits<T>::max - rhs)) {
      return types::none;
    } else {
      return static_cast<T>(lhs + static_cast<T>(rhs));
    }
  }

  template<typename T>
  requires concepts::integral<T>
  [[nodiscard]] constexpr auto sub(const T lhs, const T rhs) noexcept
      -> types::maybe<T>
  {
    if ((rhs > 0) && (lhs < (types::limits<T>::min + rhs))) {
      return types::none;
    } else if ((rhs < 0) && (lhs > (types::limits<T>::max + rhs))) {
      return types::none;
    } else {
      return static_cast<T>(lhs - rhs);
    }
  }

  template<typename T>
  requires concepts::integral<T>
  [[nodiscard]] constexpr auto sub(
      const T lhs,
      const typename types::info<T>::unsigned_type rhs
  ) noexcept -> types::maybe<T>
  {
    if (lhs < (types::limits<T>::min + rhs)) {
      return types::none;
    } else {
      return static_cast<T>(lhs - rhs);
    }
  }

  template<typename T>
  requires concepts::integral<T>
  [[nodiscard]] constexpr auto div(
      const T lhs,
      const T rhs
  ) noexcept -> types::maybe<T>
  {
    if (rhs == 0) {
      return types::none;
    } else if ((lhs == types::limits<T>::min) && (rhs == -1)) {
      return types::none;
    } else {
      return static_cast<T>(lhs / rhs);
    }
  }

  template<typename T>
  requires concepts::integral<T>
  [[nodiscard]] constexpr auto mul(
      const T lhs,
      const T rhs
  ) noexcept -> types::maybe<T>
  {
    if constexpr (concepts::signed_integral<T>) {
      if ((rhs > 0) && (lhs > 0) && (lhs > (types::limits<T>::max / rhs))) {
        return types::none;
      } else if ((rhs > 0) && (lhs < 0) && (lhs < (types::limits<T>::min / rhs))) {
        return types::none;
      } else if ((rhs < -1) && (lhs > 0) && (lhs >= (types::limits<T>::min / rhs))) {
        return types::none;
      } else if ((rhs < 0) && (lhs < 0) && (lhs < (types::limits<T>::max / rhs))) {
        return types::none;
      } else {
        return static_cast<T>(rhs * lhs);
      }
    } else {
      if ((rhs != 0) && (lhs > (types::limits<T>::max / rhs))) {
        return types::none;
      } else {
        return static_cast<T>(rhs * lhs);
      }
    }
  }

  template<typename T>
  requires concepts::integral<T>
  [[nodiscard]] constexpr auto shift_left(
      const T lhs,
      const types::u32 rhs
  ) noexcept -> types::maybe<T>
  {
    if (rhs >= types::info<T>::bits) {
      return types::none;
    } else {
      return static_cast<T>(lhs << rhs);
    }
  }

  template<typename T>
  requires concepts::integral<T>
  [[nodiscard]] constexpr auto shift_right(
      const T lhs,
      const types::u32 rhs
  ) noexcept -> types::maybe<T>
  {
    if (rhs >= types::info<T>::bits) {
      return types::none;
    } else {
      return static_cast<T>(lhs >> rhs);
    }
  }
}
