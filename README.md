**ties** -- tiny modules C++ library that provides the most "modern" experience.

## Why?

**Produce lightweight static builds**

- Modules provide highly configurable builds that include only what's needed

**Reduce complexity of C++**

- No exceptions and RTTI
- No preprocessing macros
- Similar design patterns for every module
- Do not overwhelmes with a lot of side things

## Goals

While C++ standard library provides support for a broad range of cases **ties**
give you the essentials that let you focus on getting things done.

I am always frustrated with the amount of work I need to do when I start a new
project in C++. Build system, dependency management, testing, documentation
tools, bringing existing code from libraries to uniform coding style... The core
of this problem is in vagueness and versatility of C++ -- you can solve one
problem in such a different ways that it's hard to standartize one true way,
especially taking into account original goals of C++ and it's standard library.

The goals of this library interfere with the goals of standard library. However,
the order of goals is somewhat different (may change until any reasonable
release is made)

1. Resource and type safety (more restricted and unforgiving environment)
2. Uniform interface and design
3. Suited for static builds
4. Low runtime overhead
5. Wide range of architecture and OS support
6. Easy to fit in one's head

Ideally, this library should fit small and portable projects.

## Dependencies

- libc

### Supported compilers

- clang-16 and newer

### Supported architecture

- x86_64

### Supported OS

- linux

## Build

You'll need `make` and `clang` with base UNIX utils to build static library
from source:

```sh
$ make
```

## Examples

Look in [examples](/examples/)

### Desired

#### Hello world!

```cpp
import ties.core;
import ties.fmt;

using namespace ties;

int ties::main()
{
    if (core::argc == 0) {
        fmt::println("Hello, world!");
    } else {
        fmt::println("Hello, {}!", core::argv[1]);
    }

    return 0;
}
```

