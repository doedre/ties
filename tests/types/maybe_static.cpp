import ties.meta;
import ties.concepts;
import ties.math;
import ties.memory;
import ties.types;
import ties.types.maybe;
import ties.functional.monad;

import ties.test_types;

using namespace ties;
using namespace ties::types;
using namespace ties::functional;

int main()
{
  {
    static_assert(concepts::copy_constructible<maybe<test_types::trivial>>);
    static_assert(not concepts::copy_constructible<maybe<test_types::not_copy_constructible>>);
    static_assert(concepts::trivially_destructible<maybe<test_types::trivial>>);
    static_assert(not concepts::trivially_destructible<maybe<test_types::non_trivial_destructor>>);
  }

  {
    constexpr maybe<i32> mb_none = types::none;
    constexpr maybe<i32> mb_empty { };
    static_assert(not mb_none);
    static_assert(not mb_empty);
  }

  {
    constexpr maybe<i32> mb_i32 = 32;
    static_assert(mb_i32);
  }

  {
    constexpr auto mb_made = monad::make<maybe>(-32_i32);
    static_assert(concepts::same_types<decltype(mb_made)::value_type, i32>);
    static_assert(mb_made);
    static_assert(monad::join(mb_made) == -32_i32);
    static_assert(monad::chain(mb_made, math::abs<i32>) == 32_i32);
  }

  {
    constexpr auto mb_made_none = monad::make<maybe<int>>(none);
    static_assert(not mb_made_none);
  }

  {
    constexpr maybe<i32> mb_i32 = 64;
    constexpr maybe<i64> mb_i64 = mb_i32;
    constexpr maybe<u8> mb_u8 = mb_i64;
    static_assert(mb_i64);
    static_assert(mb_u8);
  }

  return 0;
}

