export module ties.test_types;

import ties.types;

using namespace ties;
using namespace ties::types;

void func()
{
}

export namespace ties::test_types {
  struct empty { };

  struct trivial {
    i32 integer;
  };

  struct non_trivial_constructor : trivial {
    non_trivial_constructor() : trivial() { }
  };

  struct non_trivial_destructor : trivial {
    ~non_trivial_destructor() { }
  };

  struct non_trivial_copy : trivial {
    non_trivial_copy(const non_trivial_copy& other) : trivial(other) { }
    non_trivial_copy& operator=(const non_trivial_copy& other)
    {
      *this = other;
      return *this;
    }
  };

  struct non_trivial_move : trivial {
    non_trivial_move(non_trivial_move&& other) : trivial(other) { }
    non_trivial_move& operator=(non_trivial_move&& other)
    {
      return *this;
    }
  };

  enum unscoped_enum { token };
  enum class scoped_enum { token };

  using function_type = decltype(func);

  union union_object {
    i32 s;
    u32 u;
  };
}

