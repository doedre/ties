import ties.libc;

#include <assert.h>

using namespace ties;

#pragma STDC FENV_ACCESS ON

int main()
{
  assert(libc::isalnum('a'));

  libc::feclearexcept(libc::FE_ALL_EXCEPT);
  float r = 1.0 / 0.0;
  assert(libc::fetestexcept(libc::FE_DIVBYZERO));
  assert(libc::fesetenv(libc::FE_DFL_ENV) == 0);

  libc::int_fast16_t i8 = libc::INT8_MAX;
  assert(i8 != 100);

  assert(libc::fpclassify(0.0) == libc::FP_ZERO);

  return 0;
}
