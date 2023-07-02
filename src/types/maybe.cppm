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
        concepts::constructible<T, meta::add_rvalue_reference<U>>
        and concepts::convertible_types<meta::add_rvalue_reference<U>, T>
    )
    constexpr maybe(U&& val) noexcept :
        m_value { memory::forward<U>(val) },
        m_engaged { true }
    { }

    template<typename U = T>
    requires (
        concepts::constructible<T, meta::add_rvalue_reference<U>>
        and not concepts::convertible_types<meta::add_rvalue_reference<U>, T>
    )
    explicit constexpr maybe(U&& val) noexcept :
        m_value { memory::forward<U>(val) },
        m_engaged { true }
    { }

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

