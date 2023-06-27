import ties.meta;
import ties.concepts;

using namespace ties;

static_assert(not concepts::reference<meta::remove_reference<int>>);
static_assert(not concepts::reference<meta::remove_reference<int&>>);
static_assert(not concepts::reference<meta::remove_reference<int&&>>);

static_assert(not concepts::const_qualified<meta::remove_const<const int>>);
static_assert(not concepts::const_qualified<meta::remove_cv_qualifiers<const int>>);
static_assert(not concepts::volatile_qualified<meta::remove_volatile<const volatile int>>);
static_assert(not concepts::volatile_qualified<meta::remove_cv_qualifiers<const volatile int>>);

static_assert(not concepts::pointer<meta::remove_pointer<int>>);
static_assert(not concepts::pointer<meta::remove_pointer<int*>>);
static_assert(not concepts::pointer<meta::remove_pointer<const int*>>);
static_assert(not concepts::pointer<meta::remove_pointer<volatile int*>>);
static_assert(not concepts::pointer<meta::remove_pointer<const volatile int*>>);
static_assert(concepts::pointer<meta::remove_pointer<int**>>);
static_assert(not concepts::pointer<meta::remove_pointer<meta::remove_pointer<int**>>>);

static_assert(concepts::lvalue_reference<meta::add_lvalue_reference<int>>);
static_assert(concepts::lvalue_reference<meta::add_lvalue_reference<int&>>);
static_assert(concepts::lvalue_reference<meta::add_lvalue_reference<int&&>>);
static_assert(concepts::same_types<meta::add_lvalue_reference<void>, void>);

static_assert(concepts::rvalue_reference<meta::add_rvalue_reference<int>>);
static_assert(concepts::lvalue_reference<meta::add_rvalue_reference<int&>>);
static_assert(concepts::rvalue_reference<meta::add_rvalue_reference<int&&>>);

static_assert(concepts::const_qualified<meta::add_const_qualifier<int>>);
static_assert(concepts::const_qualified<meta::add_const_volatile_qualifier<int>>);
static_assert(concepts::volatile_qualified<meta::add_volatile_qualifier<int>>);
static_assert(concepts::volatile_qualified<meta::add_const_volatile_qualifier<int>>);

static_assert(concepts::pointer<meta::add_pointer<int>>);
static_assert(concepts::pointer<meta::add_pointer<int&>>);
static_assert(concepts::pointer<meta::add_pointer<int&&>>);
static_assert(concepts::pointer<meta::add_pointer<void>>);

struct ac {
  template<typename... Ts>
  using invoke = void;
};

static_assert(concepts::same_types<meta::invoke<ac, char, int>, void>);

template<typename... Ts>
struct nc : meta::id<void> { };

static_assert(concepts::same_types<meta::invoke<meta::quote<nc>, char, int>, void>);

int main()
{
  return 0;
}
