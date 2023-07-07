export module ties.types.maybe;

import ties.concepts;
import ties.meta;
import ties.memory;
import ties.functional.monad;

namespace ties::types {
  export struct none_t;

  export template<typename T>
  requires (
      concepts::destructible<T> and
      not concepts::reference<T> and
      not concepts::array<T> and
      not concepts::same_types<meta::remove_cv_qualifiers<T>, none_t>
  )
  class maybe;

  template<typename T, typename U>
  concept constructible_from_maybe =
      concepts::constructible<T, const maybe<U>&>
      or concepts::constructible<T, maybe<U>&>
      or concepts::constructible<T, const maybe<U>&&>
      or concepts::constructible<T, maybe<U>&&>
      or concepts::convertible_types<T, const maybe<U>&>
      or concepts::convertible_types<T, maybe<U>&>
      or concepts::convertible_types<T, const maybe<U>&&>
      or concepts::convertible_types<T, maybe<U>&&>;

  template<typename T, typename U>
  concept assignable_from_maybe =
      concepts::assignable<T, const maybe<U>&>
      or concepts::assignable<T, maybe<U>&>
      or concepts::assignable<T, const maybe<U>&&>
      or concepts::assignable<T, maybe<U>&&>;
}

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

  // http://www.club.cc.cmu.edu/%7Eajo/disseminate/2017-02-15-Optional-From-Scratch.pdf
  template<typename T>
  requires (
      concepts::destructible<T> and
      not concepts::reference<T> and
      not concepts::array<T> and
      not concepts::same_types<meta::remove_cv_qualifiers<T>, none_t>
  )
  class maybe {
   public:
    using value_type = T;
    using none_type = none_t;

   private:
    union {
      none_type m_empty;
      meta::remove_const<value_type> m_value;
    };
    bool m_engaged;

   public:

    constexpr maybe() noexcept :
        m_empty { none },
        m_engaged { false }
    { }

    constexpr maybe(none_type) noexcept :
        m_empty { none },
        m_engaged { false }
    { }

    constexpr maybe(const maybe& other) noexcept
    requires (
        concepts::copy_constructible<T>
        and concepts::trivially_copy_constructible<T>
    ) = default;

    constexpr maybe(const maybe& other) noexcept
    requires concepts::copy_constructible<T>
    {
      if (other.m_engaged) {
        m_value = other.m_value;
        m_engaged = true;
      }
    }

    constexpr maybe(maybe&& other) noexcept
    requires (
        concepts::move_constructible<T>
        and concepts::trivially_move_constructible<T>
    ) = default;

    constexpr maybe(maybe&& other) noexcept
    requires concepts::move_constructible<T>
    {
      if (other.m_engaged) {
        m_value = memory::move(other.m_value);
        m_engaged = true;
      }
    }

    constexpr maybe& operator=(const maybe&)
    requires (
        concepts::copy_constructible<T>
        and concepts::copy_assignable<T>
        and concepts::trivially_copy_assignable<T>
    ) = default;

    constexpr maybe& operator=(const maybe& other)
    requires (
        concepts::copy_constructible<T>
        and concepts::copy_assignable<T>
    )
    {
      if (m_engaged && other.m_engaged) {
        m_value = other.m_value;
      } else if (other.m_engaged) {
        m_value = other.m_value;
        m_engaged = true;
      } else {
        m_value.~T();
        m_engaged = false;
      }
      return *this;
    }

    constexpr maybe& operator=(maybe&&)
    requires (
        concepts::move_constructible<T>
        and concepts::move_assignable<T>
        and concepts::trivially_move_assignable<T>
    ) = default;

    constexpr maybe& operator=(maybe&& other)
    requires (
        concepts::move_constructible<T>
        and concepts::move_assignable<T>
    )
    {
      if (m_engaged && other.m_engaged) {
        m_value = memory::move(other.m_value);
      } else if (other.m_engaged) {
        m_value = memory::move(other.m_value);
        m_engaged = true;
      } else {
        m_value.~T();
        m_engaged = false;
      }
      return *this;
    }

    template<typename U = T>
    requires (
        not concepts::same_types<maybe<T>, meta::clear<U>>
        and concepts::constructible<T, meta::add_rvalue_reference<U>>
    )
    explicit(not concepts::convertible_types<T, meta::add_rvalue_reference<U>>)
    constexpr maybe(U&& val) noexcept :
        m_value { memory::forward<U>(val) },
        m_engaged { true }
    { }

    template<typename U>
    requires (
        not concepts::same_types<T, U>
        and concepts::constructible<T, meta::add_const_qualifier<meta::add_lvalue_reference<U>>>
    )
    explicit(not concepts::convertible_types<meta::add_const_qualifier<meta::add_lvalue_reference<U>>, T>)
    constexpr maybe(const maybe<U>& other) noexcept
    {
      if (other) {
        m_value = other.join();
        m_engaged = true;
      } else {
        m_empty = none;
        m_engaged = false;
      }
    }

    template<typename U>
    requires (
        not concepts::same_types<T, U>
        and concepts::constructible<T, meta::add_rvalue_reference<U>>
    )
    explicit(not concepts::convertible_types<meta::add_rvalue_reference<U>, T>)
    constexpr maybe(maybe<U>&& other) noexcept
    {
      if (other) {
        m_value = memory::move(other.join());
        m_engaged = true;
      } else {
        m_empty = none;
        m_engaged = false;
      }
    }

    constexpr maybe& operator=(none_t) noexcept
    {
      if (m_engaged) {
        m_value.~T();
        m_engaged = false;
      }
    }

    template<typename U = T>
    requires (
        not concepts::same_types<maybe<T>, meta::clear<U>>
        and concepts::constructible<T, meta::add_rvalue_reference<U>>
    )
    explicit(not concepts::convertible_types<T, meta::add_rvalue_reference<U>>)
    constexpr maybe& operator=(U&& val) noexcept
    {
      m_value = memory::move(val);
      m_engaged = true;
      return *this;
    }

    template<typename U>
    requires (
        not concepts::same_types<T, U>
        and concepts::constructible<T, meta::add_const_qualifier<meta::add_lvalue_reference<U>>>
        and concepts::assignable<meta::add_lvalue_reference<T>, U>
    )
    explicit(not concepts::convertible_types<meta::add_const_qualifier<meta::add_lvalue_reference<U>>, T>)
    constexpr maybe& operator=(const maybe<U>& other) noexcept
    {
      if (other) {
        m_value = other.join();
        m_engaged = true;
      } else {
        m_empty = none;
        m_engaged = false;
      }
      return *this;
    }

    template<typename U>
    requires (
        not concepts::same_types<T, U>
        and concepts::constructible<T, meta::add_rvalue_reference<U>>
        and concepts::assignable<meta::add_lvalue_reference<T>, U>
    )
    explicit(not concepts::convertible_types<meta::add_rvalue_reference<U>, T>)
    constexpr maybe& operator=(maybe<U>&& other) noexcept
    {
      if (other) {
        m_value = memory::move(other.join());
        m_engaged = true;
      } else {
        m_empty = none;
        m_engaged = false;
      }
      return *this;
    }

    ~maybe() noexcept
    requires concepts::trivially_destructible<T>
    = default;

    constexpr ~maybe() noexcept
    {
      if (m_engaged) {
        m_value.~T();
      }
    }

    [[nodiscard]] constexpr operator bool() const noexcept
    {
      return m_engaged;
    }

    [[nodiscard]] constexpr T& join() & noexcept
    {
      return m_value;
    }

    [[nodiscard]] constexpr const T& join() const & noexcept
    {
      return m_value;
    }

    [[nodiscard]] constexpr T&& join() && noexcept
    {
      return m_value;
    }

    [[nodiscard]] constexpr const T&& join() const && noexcept
    {
      return m_value;
    }

    template<typename Func>
    [[nodiscard]] constexpr auto chain(Func func) const noexcept
        -> decltype(func(join()))
    {
      if (m_engaged) {
        return func(m_value);
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

