export module ties.memory;

import ties.type_traits;
import ties.concepts;

export namespace ties::memory {
  template<typename T>
  [[nodiscard]] constexpr auto rvalue_cast(T&& val) noexcept
      -> type_traits::remove_reference<T>&&
  {
    using return_type = type_traits::remove_reference<T>&&;

    return static_cast<return_type>(val);
  }

  template<typename T>
  [[nodiscard]] constexpr auto forward(type_traits::remove_reference<T>& val) noexcept
      -> T&&
  {
    return static_cast<T&&>(val);
  }

  template<typename T>
  requires (not concepts::lvalue_reference<T>)
  [[nodiscard]] constexpr auto forward(type_traits::remove_reference<T>&& val) noexcept
      -> T&&
  {
    return static_cast<T&&>(val);
  }
}
