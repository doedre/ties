export module ties.memory;

import ties.meta;
import ties.concepts;

export namespace ties::memory {
  template<typename T>
  [[nodiscard]] constexpr auto move(T&& val) noexcept
      -> meta::remove_reference<T>&&
  {
    using return_type = meta::remove_reference<T>&&;

    return static_cast<return_type>(val);
  }

  template<typename T>
  [[nodiscard]] constexpr auto forward(meta::remove_reference<T>& val) noexcept
      -> T&&
  {
    return static_cast<T&&>(val);
  }

  template<typename T>
  requires (not concepts::lvalue_reference<T>)
  [[nodiscard]] constexpr auto forward(meta::remove_reference<T>&& val) noexcept
      -> T&&
  {
    return static_cast<T&&>(val);
  }
}
