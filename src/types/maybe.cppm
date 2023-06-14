export module ties.types.maybe;

import ties.concepts;
import ties.type_traits;
import ties.memory;
// import ties.funcitonal;

export namespace ties::types {
  // libstdc++ impl
  struct none_t {
    enum class construct { token };
    explicit constexpr none_t(construct) noexcept { };
  };

  inline constexpr none_t none = none_t { none_t::construct::token };
}

namespace ties::types::impl {
  template<typename T>
  union maybe_uninitialized;

  template<typename T>
  requires concepts::trivially_destructible<T>
  union maybe_uninitialized<T> {
    T value;
    none_t empty;

    constexpr maybe_uninitialized() :
        empty { none }
    { }

    template<typename... Args>
    constexpr maybe_uninitialized(Args&&... args) noexcept :
        value { memory::forward<Args>(args)... }
    { }
  };

  template<typename T>
  requires (not concepts::trivially_destructible<T>)
  union maybe_uninitialized<T> {
    T value;
    none_t empty;

    constexpr maybe_uninitialized() noexcept :
        empty { none }
    { }

    template<typename... Args>
    constexpr maybe_uninitialized(Args&&... args) noexcept :
        value { memory::forward<Args>(args)... }
    { }

    constexpr ~maybe_uninitialized() noexcept { }
  };

  template<typename T>
  struct maybe_storage;

  template<typename T>
  requires concepts::trivially_destructible<T>
  struct maybe_storage<T> {
    maybe_uninitialized<T> value;
    bool valid;

    constexpr maybe_storage() noexcept = default;

    template<typename... Args>
    constexpr maybe_storage(Args&&... args) noexcept :
        value { memory::forward<Args>(args)... },
        valid { true }
    { }

    constexpr ~maybe_storage() noexcept = default;
  };

  template<typename T>
  requires (not concepts::trivially_destructible<T>)
  struct maybe_storage<T> {
    maybe_uninitialized<T> value;
    bool valid;

    constexpr maybe_storage() noexcept = default;

    template<typename... Args>
    constexpr maybe_storage(Args&&... args) noexcept :
        value { memory::forward<Args>(args)... },
        valid { true }
    { }

    ~maybe_storage() noexcept
    {
      if (valid) {
        value.~T();
      }
    }
  };
}

export namespace ties::types {
  // http://www.club.cc.cmu.edu/%7Eajo/disseminate/2017-02-15-Optional-From-Scratch.pdf
  template<typename T>
  requires (
      concepts::destructible<T> and
      not concepts::reference<T> and
      not concepts::array<T>
  )
  class maybe {
    impl::maybe_storage<T> m_storage;

   public:
    using value_type = T;
    using none_type = none_t;

    constexpr maybe() noexcept :
        m_storage()
    { }

    constexpr maybe(none_type) noexcept :
        m_storage()
    { }

    constexpr maybe(const maybe& other) noexcept
    requires concepts::copy_constructible<T> :
        m_storage { other.m_storage }
    { }

    maybe(const maybe& other)
    requires (not concepts::copy_constructible<T>)
    = delete;

    constexpr ~maybe() = default;
  };
}
