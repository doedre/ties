export module ties.type_traits;

namespace ties::type_traits::impl {
  template<typename T>
  struct type_identity {
    using type = T;
  };

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

  template<typename T>
  struct remove_pointer {
    using type = T;
  };

  template<typename T>
  struct remove_pointer<T*> {
    using type = T;
  };

  template<typename T>
  struct remove_pointer<const T*> {
    using type = T;
  };

  template<typename T>
  struct remove_pointer<volatile T*> {
    using type = T;
  };

  template<typename T>
  struct remove_pointer<const volatile T*> {
    using type = T;
  };
}

export namespace ties::type_traits {
  template<typename T, T val>
  struct static_constant_type {
    static constexpr T value = val;
    using value_type = T;

    consteval operator value_type() const noexcept
    {
      return value;
    }

    consteval value_type operator()() const noexcept
    {
      return value;
    }
  };

  using true_type = static_constant_type<bool, true>;
  using false_type = static_constant_type<bool, false>;

  template<typename...>
  using void_t = void;

  template<typename T>
  using type_identity = typename impl::type_identity<T>::type;

  template<typename T>
  using remove_reference = typename impl::remove_reference<T>::type;

  template<typename T>
  using remove_cv_qualifiers = typename impl::remove_cv_qualifiers<T>::type;

  template<typename T>
  using remove_const = typename impl::remove_const<T>::type;

  template<typename T>
  using remove_volatile = typename impl::remove_volatile<T>::type;

  template<typename T>
  using remove_pointer = typename impl::remove_pointer<T>::type;
}

namespace ties::type_traits::impl {
  template<typename T, typename = void>
  struct add_lvalue_reference {
    using type = T;
  };

  template<typename T>
  struct add_lvalue_reference<T, void_t<T&>> {
    using type = T&;
  };

  template<typename T, typename = void>
  struct add_rvalue_reference {
    using type = T;
  };

  template<typename T>
  struct add_rvalue_reference<T, void_t<T&&>> {
    using type = T&&;
  };

  template<typename T>
  struct add_const_qualifier {
    using type = const T;
  };

  template<typename T>
  struct add_volatile_qualifier {
    using type = volatile T;
  };

  template<typename T>
  struct add_const_volatile_qualifier {
    using type = const volatile T;
  };

  template<typename T, typename = void>
  struct add_pointer {
    using type = T;
  };

  template<typename T>
  struct add_pointer<T, void_t<T*>> {
    using type = T*;
  };

  template<typename T>
  struct add_pointer<T&> {
    using type = T*;
  };

  template<typename T>
  struct add_pointer<T&&> {
    using type = T*;
  };
}

export namespace ties::type_traits {
  template<typename T>
  using add_lvalue_reference = typename impl::add_lvalue_reference<T>::type;

  template<typename T>
  using add_rvalue_reference = typename impl::add_rvalue_reference<T>::type;

  template<typename T>
  using add_const_qualifier = typename impl::add_const_qualifier<T>::type;

  template<typename T>
  using add_volatile_qualifier = typename impl::add_volatile_qualifier<T>::type;

  template<typename T>
  using add_const_volatile_qualifier = typename impl::add_const_volatile_qualifier<T>::type;

  template<typename T>
  using add_pointer = typename impl::add_pointer<T>::type;
}

