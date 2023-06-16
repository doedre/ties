import ties.type_traits;
import ties.concepts;
import ties.memory;
import ties.types;
import ties.types.maybe;
import ties.functional.monad;

import ties.test_types;

using namespace ties;
using namespace ties::types;
using namespace ties::functional;

static_assert(concepts::copy_constructible<types::maybe<test_types::trivial>>);
static_assert(not concepts::copy_constructible<types::maybe<test_types::not_copy_constructible>>);
static_assert(concepts::trivially_destructible<types::maybe<test_types::trivial>>);
static_assert(not concepts::trivially_destructible<types::maybe<test_types::non_trivial_destructor>>);

constexpr types::maybe<types::i32> mb_none = types::none;
constexpr types::maybe<types::i32> mb_empty { };
static_assert(not mb_none);
static_assert(not mb_empty);

constexpr types::maybe<types::i32> mb_i32 = 32;
static_assert(mb_i32);

constexpr auto mb_made = monad::make<maybe>(32_i32);
static_assert(concepts::same_types<decltype(mb_made)::value_type, i32>);
static_assert(mb_made);

constexpr auto mb_made_none = monad::make<maybe<int>>(none);
static_assert(not mb_made_none);

int main()
{
  return 0;
}

