import ties.concepts;

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

  static_assert(ties::concepts::pointer<int*>);
}
