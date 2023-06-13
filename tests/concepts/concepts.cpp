import ties.type_traits;
import ties.concepts;

int func()
{
  return 0;
}

int main()
{
  static_assert(ties::concepts::same_types<int, int>);
  static_assert(!ties::concepts::same_types<float, int>);
  static_assert(ties::concepts::convertible_types<char, int>);

  static_assert(!ties::concepts::lvalue_reference<int>);
  static_assert(ties::concepts::lvalue_reference<int&>);
  static_assert(!ties::concepts::lvalue_reference<int&&>);

  static_assert(!ties::concepts::rvalue_reference<int>);
  static_assert(!ties::concepts::rvalue_reference<int&>);
  static_assert(ties::concepts::rvalue_reference<int&&>);

  static_assert(ties::concepts::trivially_destructible<int>);

  static_assert(ties::concepts::trivially_constructible<int>);
  static_assert(ties::concepts::trivially_default_constructible<int>);
  static_assert(!ties::concepts::enum_object<int>);

  static_assert(not ties::concepts::function<int>);
  static_assert(ties::concepts::function<decltype(func)>);
  static_assert(ties::concepts::function<decltype(func)>);
  static_assert(ties::concepts::incomplete<int[]>);

  static_assert(ties::concepts::array<int[]>);
  static_assert(ties::concepts::array<int[10]>);
}
