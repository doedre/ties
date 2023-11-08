import ties.libc;

#include <assert.h>

using namespace ties;

#pragma STDC FENV_ACCESS ON

int main()
{
  assert(libc::isalnum('a'));

//  libc::feclearexcept(FE_INVALID);

  libc::feclearexcept(libc::FE_ALL_EXCEPT);
  float r = 1.0 / 0.0;
  assert(libc::fetestexcept(libc::FE_DIVBYZERO));
  assert(libc::fesetenv(libc::FE_DFL_ENV) == 0);

  return 0;
}
