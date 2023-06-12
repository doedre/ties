# Install configuration

# Compilation configuration
CXX := musl-gcc
COMPILE_ARGS := -std=c++20 -nodefaultlibs -fno-rtti -fno-exceptions -fPIC -fconcepts -fmodules-ts -fcoroutines -fconcepts-diagnostics-depth=2 -xc++ -lc
ARCH := x86_64

# Source locations
SRC := src
INC := arch/$(ARCH)
TEST := tests

# Artifacts
OBJ := .obj
BIN := bin

