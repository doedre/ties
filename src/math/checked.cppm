export module ties.math.checked;

export import ties.types;
export import ties.types.tuple;
export import ties.types.maybe;

import ties.concepts;

export namespace ties::math::checked {
  template<typename T>
  requires concepts::integral<T>
  [[nodiscard]] constexpr auto abs(T val) noexcept -> types::maybe<T>
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
}
