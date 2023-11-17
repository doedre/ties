module;

#include <syscall.h>

namespace ties {
  int main();
}

static __inline long __syscall1(long n, long a1)
{
	unsigned long ret;
	__asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(n), "D"(a1) : "rcx", "r11", "memory");
	return ret;
}

extern "C" void start_linux() {
  int ret = ties::main();
  __syscall1(SYS_exit_group, ret);
  for (;;)
    __syscall1(SYS_exit, ret);
}

export module ties.rt;

export namespace ties {
  using ties::main;
}

