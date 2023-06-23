import ties.meta;
import ties.concepts;
import ties.test_types;

using namespace ties;

static_assert(concepts::same_types<int, int>);
static_assert(not concepts::same_types<float, int>);

static_assert(concepts::convertible_types<char, int>);
static_assert(not concepts::convertible_types<void, int>);

static_assert(not concepts::lvalue_reference<int>);
static_assert(concepts::lvalue_reference<int&>);
static_assert(not concepts::lvalue_reference<int&&>);

static_assert(not concepts::rvalue_reference<int>);
static_assert(not concepts::rvalue_reference<int&>);
static_assert(concepts::rvalue_reference<int&&>);

static_assert(not concepts::reference<int>);
static_assert(concepts::reference<int&>);
static_assert(concepts::reference<int&&>);

static_assert(concepts::const_qualified<const int>);
static_assert(not concepts::const_qualified<int>);
static_assert(not concepts::const_qualified<volatile int>);
static_assert(concepts::const_qualified<const volatile int>);
static_assert(concepts::volatile_qualified<volatile int>);
static_assert(not concepts::volatile_qualified<int>);
static_assert(not concepts::volatile_qualified<const int>);
static_assert(concepts::volatile_qualified<const volatile int>);

static_assert(concepts::enum_object<test_types::unscoped_enum>);
static_assert(concepts::enum_object<test_types::scoped_enum>);
static_assert(not concepts::scoped_enum_object<test_types::unscoped_enum>);
static_assert(concepts::scoped_enum_object<test_types::scoped_enum>);

static_assert(concepts::function<test_types::function_type>);

static_assert(concepts::pointer<int*>);
static_assert(concepts::pointer<const int*>);
static_assert(concepts::pointer<volatile int*>);
static_assert(concepts::pointer<const volatile int*>);
static_assert(not concepts::pointer<int>);

static_assert(concepts::union_object<test_types::union_object>);
static_assert(not concepts::union_object<test_types::trivial>);

static_assert(concepts::class_object<test_types::trivial>);
static_assert(not concepts::class_object<test_types::union_object>);

static_assert(concepts::array<int[]>);
static_assert(concepts::array<int[10]>);
static_assert(concepts::array_with_unknown_bounds<int[]>);
static_assert(not concepts::array_with_unknown_bounds<int[10]>);
static_assert(not concepts::array_with_known_bounds<int[]>);
static_assert(concepts::array_with_known_bounds<int[10]>);

static_assert(concepts::trivial<test_types::trivial>);
static_assert(concepts::trivially_copyable<test_types::trivial>);
static_assert(concepts::constructible<test_types::trivial>);
static_assert(concepts::trivially_constructible<test_types::trivial>);
static_assert(concepts::default_constructible<test_types::trivial>);
static_assert(concepts::trivially_default_constructible<test_types::trivial>);
static_assert(concepts::destructible<test_types::trivial>);
static_assert(concepts::trivially_destructible<test_types::trivial>);
static_assert(concepts::copy_constructible<test_types::trivial>);
static_assert(concepts::trivially_copy_constructible<test_types::trivial>);
static_assert(concepts::move_constructible<test_types::trivial>);
static_assert(concepts::trivially_move_constructible<test_types::trivial>);
static_assert(concepts::copy_assignable<test_types::trivial>);
static_assert(concepts::trivially_copy_assignable<test_types::trivial>);
static_assert(concepts::move_assignable<test_types::trivial>);
static_assert(concepts::trivially_move_assignable<test_types::trivial>);

static_assert(not concepts::trivial<test_types::non_trivial_constructor>);
static_assert(concepts::constructible<test_types::non_trivial_constructor>);
static_assert(not concepts::trivially_constructible<test_types::non_trivial_constructor>);

static_assert(not concepts::trivial<test_types::non_trivial_destructor>);
static_assert(concepts::destructible<test_types::non_trivial_destructor>);
static_assert(not concepts::trivially_destructible<test_types::non_trivial_destructor>);

static_assert(not concepts::trivial<test_types::non_trivial_copy>);
static_assert(concepts::copy_constructible<test_types::non_trivial_copy>);
static_assert(concepts::copy_assignable<test_types::non_trivial_copy>);
static_assert(not concepts::trivially_copy_constructible<test_types::non_trivial_copy>);
static_assert(not concepts::trivially_copy_assignable<test_types::non_trivial_copy>);

static_assert(not concepts::trivial<test_types::non_trivial_move>);
static_assert(concepts::move_constructible<test_types::non_trivial_move>);
static_assert(concepts::move_assignable<test_types::non_trivial_move>);
static_assert(not concepts::trivially_move_constructible<test_types::non_trivial_move>);
static_assert(not concepts::trivially_move_assignable<test_types::non_trivial_move>);

int main()
{
  return 0;
}
