import ties.type_traits;
import ties.concepts;

using namespace ties;

static_assert(not concepts::reference<type_traits::remove_reference<int>>);
static_assert(not concepts::reference<type_traits::remove_reference<int&>>);
static_assert(not concepts::reference<type_traits::remove_reference<int&&>>);

static_assert(not concepts::const_qualified<type_traits::remove_const<const int>>);
static_assert(not concepts::const_qualified<type_traits::remove_cv_qualifiers<const int>>);
static_assert(not concepts::volatile_qualified<type_traits::remove_volatile<const volatile int>>);
static_assert(not concepts::volatile_qualified<type_traits::remove_cv_qualifiers<const volatile int>>);

static_assert(not concepts::pointer<type_traits::remove_pointer<int>>);
static_assert(not concepts::pointer<type_traits::remove_pointer<int*>>);
static_assert(not concepts::pointer<type_traits::remove_pointer<const int*>>);
static_assert(not concepts::pointer<type_traits::remove_pointer<volatile int*>>);
static_assert(not concepts::pointer<type_traits::remove_pointer<const volatile int*>>);
static_assert(concepts::pointer<type_traits::remove_pointer<int**>>);
static_assert(not concepts::pointer<type_traits::remove_pointer<type_traits::remove_pointer<int**>>>);

static_assert(concepts::lvalue_reference<type_traits::add_lvalue_reference<int>>);
static_assert(concepts::lvalue_reference<type_traits::add_lvalue_reference<int&>>);
static_assert(concepts::lvalue_reference<type_traits::add_lvalue_reference<int&&>>);
static_assert(concepts::same_types<type_traits::add_lvalue_reference<void>, void>);

static_assert(concepts::rvalue_reference<type_traits::add_rvalue_reference<int>>);
static_assert(concepts::lvalue_reference<type_traits::add_rvalue_reference<int&>>);
static_assert(concepts::rvalue_reference<type_traits::add_rvalue_reference<int&&>>);

static_assert(concepts::const_qualified<type_traits::add_const_qualifier<int>>);
static_assert(concepts::const_qualified<type_traits::add_const_volatile_qualifier<int>>);
static_assert(concepts::volatile_qualified<type_traits::add_volatile_qualifier<int>>);
static_assert(concepts::volatile_qualified<type_traits::add_const_volatile_qualifier<int>>);

static_assert(concepts::pointer<type_traits::add_pointer<int>>);
static_assert(concepts::pointer<type_traits::add_pointer<int&>>);
static_assert(concepts::pointer<type_traits::add_pointer<int&&>>);
static_assert(concepts::pointer<type_traits::add_pointer<void>>);

int main()
{
  return 0;
}
