export module ties.types.tuple;

import ties.types;
import ties.concepts;
import ties.memory;
import ties.type_traits;
import ties.functional.monad;

export namespace ties::types {
  template<typename T, T... Ints>
  requires concepts::integral<T>
  struct integer_list {
    using value_type = T;

    static consteval usize len() noexcept
    {
      return sizeof...(Ints);
    }
  };

  template<usize... Indices>
  using index_list = integer_list<usize, Indices...>;
}

namespace ties::types::impl {
  // https://stackoverflow.com/a/50000638
  template<typename Offset, typename Lhs, typename Rhs>
  struct merge;

  template<typename T, T Offset, T... Lhs, T... Rhs>
  struct merge<
      type_traits::static_constant_type<T, Offset>,
      integer_list<T, Lhs...>,
      integer_list<T, Rhs...>
  > {
    using type = integer_list<T, Lhs..., (Offset + Rhs)...>;
  };

  template<typename T, typename Num>
  struct log_make_sequence {
    using left = type_traits::static_constant_type<T, Num::value / 2>;
    using right = type_traits::static_constant_type<T, Num::value - left::value>;
    using type = typename merge<
        left,
        typename log_make_sequence<T, left>::type,
        typename log_make_sequence<T, right>::type
    >::type;
  };

  template<typename T>
  struct log_make_sequence<T, type_traits::static_constant_type<T, 0>> {
    using type = integer_list<T>;
  };

  template<typename T>
  struct log_make_sequence<T, type_traits::static_constant_type<T, 1>> {
    using type = integer_list<T, 0>;
  };
}

export namespace ties::types {
  template<typename T, T Len>
  requires concepts::integral<T>
  using integer_sequence =
      typename impl::log_make_sequence<T, type_traits::static_constant_type<T, Len>>::type;

  template<usize Len>
  using index_sequence = integer_sequence<usize, Len>;

  template<typename... Ts>
  using index_sequence_for = index_sequence<sizeof...(Ts)>;
}

namespace ties::types::impl {
  template<usize Index, typename T>
  struct tuple_element {
    T value;

    template<usize _Index>
    requires (_Index == Index) 
    [[nodiscard]] constexpr T& get() & noexcept
    {
      return value;
    }

    template<usize _Index>
    requires (_Index == Index)
    [[nodiscard]] constexpr const T& get() const & noexcept
    {
      return value;
    }

    template<usize _Index>
    requires (_Index == Index)
    constexpr T&& get() && noexcept
    {
      return value;
    }

    template<usize _Index>
    requires (_Index == Index)
    constexpr const T&& get() const && noexcept
    {
      return value;
    }
  };

  template<typename Index, typename... Ts>
  class tuple;

  template<usize... Indices, typename... Ts>
  class tuple<index_list<Indices...>, Ts...> : tuple_element<Indices, Ts>... {
   public:
    constexpr tuple(const Ts&... vals) : tuple_element<Indices, Ts>(vals)...
    {}

    using tuple_element<Indices, Ts>::get...;

    [[nodiscard]] static consteval usize len() noexcept
    {
      return sizeof...(Ts);
    }
  };
}

export namespace ties::types {
  template<typename... Ts>
  struct tuple : impl::tuple<index_sequence_for<Ts...>, Ts...> {
    using impl::tuple<index_sequence_for<Ts...>, Ts...>::tuple;
  };

  template<typename... Ts>
  tuple(const Ts&...) -> tuple<Ts...>;

  template<typename... Ts>
  tuple(Ts&&...) -> tuple<Ts...>;
}

namespace ties::functional::monad {
  template<typename... Ts>
  struct make_trait<types::tuple<Ts...>> {
    template<typename... Args>
    static constexpr auto make(Args&&... args) noexcept
    {
      return types::tuple(memory::forward<Args>(args)...);
    }
  };
}
