import ties.types;
import ties.types.tuple;
import ties.concepts;
import ties.functional.monad;

#include <limits.h>

static_assert(ties::types::I32_MIN == INT_MIN);

int main()
{
  using namespace ties::types;
  static_assert(1 <= sizeof(ties::types::i8));
  static_assert(sizeof(i8) <= sizeof(i16));
  static_assert(sizeof(i16) <= sizeof(i32));
  static_assert(sizeof(i32) <= sizeof(i64));
  static_assert(sizeof(usize) == sizeof(u64));
  static_assert(info<i128>::bits == 128);

  static_assert(sizeof(nullptr_t) == sizeof(void*));

  static_assert(limits<nullptr_t>::max == 0);

  static_assert(info<i8>::bits == 8);

  constexpr auto is = ties::types::index_list<0, 1>{};
  constexpr auto isf = ties::types::index_sequence<2>{};
  static_assert(ties::concepts::same_types<decltype(isf), decltype(is)>);

  constexpr tuple tp(8, 4);
  static_assert(tp.get<0>() == 8);
  static_assert(tp.get<1>() == 4);
  static_assert(tp.len() == 2);

  constexpr auto tup = ties::functional::monad::make<tuple<>>(10_u64, 1_bool);
  static_assert(ties::concepts::same_types<decltype(tup), const tuple<u64, bool>>);
  static_assert(tup.get<0>() == 10_u64);
  static_assert(tup.get<1>() == 1_bool);
  static_assert(tup.len() == 2);

  return 0;
}
