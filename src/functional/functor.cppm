export module ties.functional.functor;

import ties.memory;

export namespace ties::functional::functor {
  template<typename T>
  struct transform_trait {
    template<typename TransformedT, typename Func>
    static constexpr auto transform(TransformedT&& val, Func&& f) noexcept
    {
      return f(memory::forward<TransformedT>(val));
    }
  };

  template<typename T, typename Func>
  constexpr auto transform(const T& val, Func&& f) noexcept
  {
    return transform_trait<T>::template transform(val, memory::forward<Func>(f));
  }

  template<typename T, typename Func>
  constexpr auto map(Func&& f, const T& val) noexcept
  {
    return transform_trait<T>::template transform(val, memory::forward<Func>(f));
  }
}
