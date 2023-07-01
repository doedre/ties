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
    make_trait() = delete;

    template<typename MadeT = T, typename... Args>
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
    return make_trait<T<Args...>>::template make(memory::forward<Args>(args)...);
  }

  template<typename T>
  struct chain_trait {
    template<typename Func>
    static constexpr auto chain(const T& val, Func func) noexcept
        -> decltype(func(val.join()))
    {
      if (val) {
        return func(val.join());
      } else {
        return T::none_type();
      }
    }
  };

  template<
      template<typename...> typename T,
      typename Func,
      typename... Xs
  >
  constexpr auto chain(const T<Xs...>& val, Func func) noexcept
  {
    return chain_trait<T<Xs...>>::template chain(val, func);
  }

  template<typename T>
  struct join_trait {
    static constexpr auto join(const T& val) noexcept
    {
      return val.join();
    }
  };

  template<
      template<typename...> typename T,
      typename... Xs
  >
  constexpr auto join(const T<Xs...>& val) noexcept
  {
    return join_trait<T<Xs...>>::template join(val);
  }
}

