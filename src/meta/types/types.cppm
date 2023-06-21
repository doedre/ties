export module ties.meta.types;

export namespace ties::meta::types {
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
}
