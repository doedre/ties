module;

#include <stdint.h>
#include <syscall.h>

namespace ties {
  int main();
}

inline int64_t argc = 0;
inline char** argv = nullptr;
inline char** envp = nullptr;

static __inline long __syscall1(long n, long a1)
{
	unsigned long ret;
	__asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(n), "D"(a1) : "rcx", "r11", "memory");
	return ret;
}

extern "C" void start_linux(uintptr_t** iv) {
  argc = reinterpret_cast<int64_t>(iv[0]);
  argv = reinterpret_cast<char**>(&iv[1]);
  envp = reinterpret_cast<char**>(&argv[argc + 1]);

  int ret = ties::main();
  __syscall1(SYS_exit_group, ret);
  for (;;)
    __syscall1(SYS_exit, ret);
}

export module ties.rt;

namespace ties {
  export using ties::main;

  export namespace rt {
    using ::argc;
    using ::argv;
    using ::envp;
  }
}

