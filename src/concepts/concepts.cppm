export module ties.concepts;

namespace ties::concepts::impl {
  template<typename T1, typename T2>
  inline constexpr bool same_types = false;

  template<typename T>
  inline constexpr bool same_types<T, T> = true;

  template<typename T>
  inline constexpr bool lvalue_reference = false;

  template<typename T>
  inline constexpr bool lvalue_reference<T&> = true;

  template<typename T>
  inline constexpr bool rvalue_reference = false;

  template<typename T>
  inline constexpr bool rvalue_reference<T&&> = true;

  template<typename T>
  inline constexpr bool const_qualified = false;

  template<typename T>
  inline constexpr bool const_qualified<const T> = true;

  template<typename T>
  inline constexpr bool const_qualified<const volatile T> = true;

  template<typename T>
  inline constexpr bool volatile_qualified = false;

  template<typename T>
  inline constexpr bool volatile_qualified<volatile T> = true;

  template<typename T>
  inline constexpr bool volatile_qualified<const volatile T> = true;
}

export namespace ties::concepts {
  template<typename T1, typename T2>
  concept same_types = impl::same_types<T1, T2>;

  template<typename From, typename To>
  concept convertible_types = requires(From from, To to) {
    static_cast<To>(from);
  };

  template<typename T>
  concept pointer = requires(T p) {
    *p;
    p == nullptr;
  };

  template<typename T>
  concept lvalue_reference = impl::lvalue_reference<T>;

  template<typename T>
  concept rvalue_reference = impl::rvalue_reference<T>;

  template<typename T>
  concept const_qualified = impl::const_qualified<T>;

  template<typename T>
  concept volatile_qualified = impl::volatile_qualified<T>;
}

