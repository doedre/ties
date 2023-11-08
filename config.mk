# Install configuration

### Target options
ARCH := x86_64

### Source locations
SRC := src
INC := arch/$(ARCH)
TEST := tests

### Artifacts
OBJ := .obj
PCM := .pcm
BIN := bin

### Compilation options
CXX := clang++
COMPILE_ARGS := \
		-std=c++20 \
		-nodefaultlibs \
		-fno-rtti \
		-fno-exceptions \
		-fPIC \

PRECOMPILE_ARGS := \
		-xc++-module \
		--precompile \
		-fprebuilt-module-path=./$(OBJ) \
		$(COMPILE_ARGS)


