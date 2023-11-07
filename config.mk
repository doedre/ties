# Install configuration

### Target options
ARCH := x86_64

### Source locations
SRC := src
INC := arch/$(ARCH)
TEST := tests

### Artifacts
OBJ := .obj
BIN := bin

### Compilation options
CXX := clang++
PRECOMPILE_ARGS := --precompile -fprebuilt-module-path=./$(OBJ)
COMPILE_ARGS := -std=c++20 \
		-nodefaultlibs \
		-fno-rtti \
		-fno-exceptions \
		-fPIC \
		-xc++ \
		$(PRECOMPILE_ARGS)

