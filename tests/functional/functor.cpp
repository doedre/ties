import ties.types;
import ties.memory;
import ties.functional.functor;

using namespace ties::functional;

template<typename T>
struct wrap {
  T value;
};

constexpr int func(const wrap<int>& val)
{
  return val.value;
}

int main()
{
  static_assert(functor::transform(wrap<int>(10), func) == 10);
  static_assert(functor::map(func, wrap<int>(10)) == 10);
}
