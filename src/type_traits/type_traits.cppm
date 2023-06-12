export module ties.type_traits;

namespace ties::type_traits::impl {
  template<typename T>
  struct remove_reference {
    using type = T;
  };

  template<typename T>
  struct remove_reference<T&> {
    using type = T;
  };

  template<typename T>
  struct remove_reference<T&&> {
    using type = T;
  };

  template<typename T>
  struct remove_const {
    using type = T;
  };

  template<typename T>
  struct remove_const<const T> {
    using type = T;
  };

  template<typename T>
  struct remove_volatile {
    using type = T;
  };

  template<typename T>
  struct remove_volatile<volatile T> {
    using type = T;
  };

  template<typename T>
  struct remove_cv_qualifiers {
    using type = T;
  };

  template<typename T>
  struct remove_cv_qualifiers<const T> {
    using type = T;
  };

  template<typename T>
  struct remove_cv_qualifiers<volatile T> {
    using type = T;
  };

  template<typename T>
  struct remove_cv_qualifiers<const volatile T> {
    using type = T;
  };

}

export namespace ties::type_traits {
  template<typename T, T val>
  struct static_constant_type {
    static constexpr T value = val;
    using value_type = T;

    constexpr operator value_type() const noexcept
    {
      return value;
    }

    constexpr value_type operator()() const noexcept
    {
      return value;
    }
  };

  using true_type = static_constant_type<bool, true>;
  using false_type = static_constant_type<bool, false>;

  template<typename T>
  using remove_reference = typename impl::remove_reference<T>::type;

  template<typename T>
  using remove_cv_qualifiers = typename impl::remove_cv_qualifiers<T>::type;

  template<typename T>
  using remove_const = typename impl::remove_const<T>::type;

  template<typename T>
  using remove_volatile = typename impl::remove_volatile<T>::type;
}
