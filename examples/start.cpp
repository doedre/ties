#include <syscall.h>

extern "C" int main();

static __inline long __syscall1(long n, long a1)
{
	unsigned long ret;
	__asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(n), "D"(a1) : "rcx", "r11", "memory");
	return ret;
}

extern "C" void _start() {
  int ret = main();
  __syscall1(SYS_exit_group, ret);
  for (;;)
    __syscall1(SYS_exit, ret);
}

