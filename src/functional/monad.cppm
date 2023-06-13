export module ties.functional.monad;

import ties.memory;

export namespace ties::functional::monad {
  // Needs std::declval analog to try construct a value with make()
  /*
  template<typename T>
  concept monad = requires(T mon) {
  };
  */

  // https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p0338r3.pdf
  template<typename T>
  struct make_trait {
    template<typename MadeT, typename... Args>
    static constexpr auto make(Args&&... args) noexcept
    {
      return MadeT(memory::forward<Args>(args)...);
    }
  };

  template<typename T, typename... Args>
  constexpr auto make(Args&&... args) noexcept
  {
    return make_trait<T>::template make(memory::forward<Args>(args)...);
  }

  template<
      template<typename...> typename T,
      typename... Args
  >
  constexpr auto make(Args&&... args) noexcept
  {
    using made_type = T<Args...>;
    return make_trait<made_type>::template make(memory::forward<Args>(args)...);
  }

  /*
  template<typename T>
  struct chain_trait {
    template<typename X, typename Func>
    static constexpr auto chain(
  };
  */

  template<typename T>
  struct join_trait {
    static constexpr auto join(const T& val) noexcept
    {
      return val.join();
    }
  };

  template<
      template<typename> typename T,
      typename X
  >
  constexpr auto join(T<X>&& val) noexcept
  {
    return join_trait<T<X>>::template join(memory::forward<T<X>>(val));
  }
}

