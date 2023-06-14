import ties.type_traits;
import ties.concepts;
import ties.memory;
import ties.types;
import ties.types.maybe;

using namespace ties;

struct not_copy_constructible {
  not_copy_constructible(const not_copy_constructible&) = delete;
};

struct copy_constructible {
};

int main()
{
  static_assert(not concepts::copy_constructible<not_copy_constructible>);
  types::maybe<not_copy_constructible> uncopyable{};

  static_assert(concepts::lvalue_reference<type_traits::add_lvalue_reference<int>>);

  static_assert(concepts::copy_constructible<copy_constructible>);
  const types::maybe<copy_constructible> copyable{};
  const types::maybe<copy_constructible> try_copy = copyable;

}

