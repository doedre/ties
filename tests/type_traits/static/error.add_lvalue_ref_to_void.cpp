import ties.type_traits;
import ties.concepts;

using namespace ties;

int main()
{
  const type_traits::add_lvalue_reference<void&> error;
  return 0;
}
