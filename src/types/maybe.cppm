export module ties.types.maybe;

import ties.concepts;
import ties.meta;
import ties.memory;
import ties.functional.monad;

export namespace ties::types {
  // libstdc++ impl
  struct none_t {
    enum class construct { token };

    explicit constexpr none_t(construct) noexcept { }

    constexpr operator bool() const noexcept
    {
      return false;
    }
  };

  inline constexpr none_t none { none_t::construct::token };
}

namespace ties::types::impl {
  template<typename T>
  union maybe_uninitialized;

  template<typename T>
  requires concepts::trivially_destructible<T>
  union maybe_uninitialized<T> {
    T value;
    none_t empty;

    constexpr maybe_uninitialized() noexcept :
        empty(none)
    { }

    constexpr maybe_uninitialized(none_t) noexcept :
        empty(none)
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
        empty(none)
    { }

    constexpr maybe_uninitialized(none_t) noexcept :
        empty(none)
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

    constexpr maybe_storage(none_t) noexcept :
        value { none },
        valid { false }
    { }

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

    constexpr maybe_storage(none_t) noexcept :
        value { none },
        valid { false }
    { }

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
      not concepts::array<T> and
      not concepts::same_types<meta::remove_cv_qualifiers<T>, none_t>
  )
  class maybe {
    impl::maybe_storage<T> m_storage;

   public:
    using value_type = T;
    using none_type = none_t;

    constexpr maybe() noexcept :
        m_storage { none }
    { }

    constexpr maybe(none_type) noexcept :
        m_storage { none }
    { }

    maybe(const maybe& other)
    requires (not concepts::copy_constructible<T>)
    = delete;

    constexpr maybe(const maybe& other) noexcept
    requires concepts::copy_constructible<T> :
        m_storage { other.m_storage }
    { }

    maybe(maybe&& other) noexcept :
        m_storage { memory::move(other) }
    { }

    template<typename U = T>
    requires (
        concepts::constructible<T, meta::add_rvalue_reference<U>> and
        concepts::convertible_types<meta::add_rvalue_reference<U>, T>
    )
    constexpr maybe(U&& val) noexcept :
        m_storage { memory::forward<U>(val) }
    { }

    template<typename U = T>
    requires (
        concepts::constructible<T, meta::add_rvalue_reference<U>> and
        not concepts::convertible_types<meta::add_rvalue_reference<U>, T>
    )
    explicit constexpr maybe(U&& val) noexcept :
        m_storage { memory::forward<U>(val) }
    { }

    constexpr ~maybe() noexcept = default;

    [[nodiscard]] constexpr operator bool() const noexcept
    {
      return m_storage.valid;
    }

    [[nodiscard]] constexpr T& join() & noexcept
    {
      return m_storage.value.value;
    }

    [[nodiscard]] constexpr const T& join() const & noexcept
    {
      return m_storage.value.value;
    }

    [[nodiscard]] constexpr T&& join() && noexcept
    {
      return m_storage.value.value;
    }

    [[nodiscard]] constexpr const T&& join() const && noexcept
    {
      return m_storage.value.value;
    }

    template<typename Func>
    [[nodiscard]] constexpr auto chain(Func func) const noexcept
        -> decltype(func(join()))
    {
      if (m_storage.valid) {
        return func(m_storage.value.value);
      } else {
        return none;
      }
    }
  };
}

export template<typename T>
struct ties::functional::monad::make_trait<ties::types::maybe<T>> {
  template<typename... Args>
  static constexpr auto make(Args&&... args) noexcept
  {
    return types::maybe<T>(ties::memory::forward<Args>(args)...);
  }
};

export namespace ties::functional::monad {
  template<typename T>
  struct join_trait<types::maybe<T>> {
    template<typename U = T>
    static constexpr auto join(const types::maybe<U>& mb) noexcept
    {
      return mb.join();
    }
  };

  template<typename T>
  struct chain_trait<types::maybe<T>> {
    template<typename U = T, typename Func>
    static constexpr auto chain(const types::maybe<U>& mb, Func func) noexcept
        -> decltype(func(mb.join()))
    {
      if (mb) {
        return mb.chain(func);
      } else {
        return types::none;
      }
    }
  };
}

