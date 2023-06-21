import ties.meta.types;
import ties.meta.cast;
import ties.meta.concepts;

using namespace ties::meta;

static_assert(not concepts::reference<cast::remove_reference<int>>);
static_assert(not concepts::reference<cast::remove_reference<int&>>);
static_assert(not concepts::reference<cast::remove_reference<int&&>>);

static_assert(not concepts::const_qualified<cast::remove_const<const int>>);
static_assert(not concepts::const_qualified<cast::remove_cv_qualifiers<const int>>);
static_assert(not concepts::volatile_qualified<cast::remove_volatile<const volatile int>>);
static_assert(not concepts::volatile_qualified<cast::remove_cv_qualifiers<const volatile int>>);

static_assert(not concepts::pointer<cast::remove_pointer<int>>);
static_assert(not concepts::pointer<cast::remove_pointer<int*>>);
static_assert(not concepts::pointer<cast::remove_pointer<const int*>>);
static_assert(not concepts::pointer<cast::remove_pointer<volatile int*>>);
static_assert(not concepts::pointer<cast::remove_pointer<const volatile int*>>);
static_assert(concepts::pointer<cast::remove_pointer<int**>>);
static_assert(not concepts::pointer<cast::remove_pointer<cast::remove_pointer<int**>>>);

static_assert(concepts::lvalue_reference<cast::add_lvalue_reference<int>>);
static_assert(concepts::lvalue_reference<cast::add_lvalue_reference<int&>>);
static_assert(concepts::lvalue_reference<cast::add_lvalue_reference<int&&>>);
static_assert(concepts::same_types<cast::add_lvalue_reference<void>, void>);

static_assert(concepts::rvalue_reference<cast::add_rvalue_reference<int>>);
static_assert(concepts::lvalue_reference<cast::add_rvalue_reference<int&>>);
static_assert(concepts::rvalue_reference<cast::add_rvalue_reference<int&&>>);

static_assert(concepts::const_qualified<cast::add_const_qualifier<int>>);
static_assert(concepts::const_qualified<cast::add_const_volatile_qualifier<int>>);
static_assert(concepts::volatile_qualified<cast::add_volatile_qualifier<int>>);
static_assert(concepts::volatile_qualified<cast::add_const_volatile_qualifier<int>>);

static_assert(concepts::pointer<cast::add_pointer<int>>);
static_assert(concepts::pointer<cast::add_pointer<int&>>);
static_assert(concepts::pointer<cast::add_pointer<int&&>>);
static_assert(concepts::pointer<cast::add_pointer<void>>);

int main()
{
  return 0;
}
