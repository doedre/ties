# Install configuration

### Target options
ARCH := x86_64

### Source locations
SRC := src
INC := arch/$(ARCH)
TEST := tests

### Artifacts
OUT := build_$(ARCH)
OBJ := $(OUT)/.obj
PCM := $(OUT)/.pcm
LIB := $(OUT)/lib

### Compilation options
CXX := clang++
COMPILE_ARGS := \
		-std=c++20 \
		-nodefaultlibs \
		-fno-rtti \
		-fno-exceptions \
		-nostdlib \
		-fPIC

PRECOMPILE_ARGS := \
		-xc++-module \
		--precompile \
		-fprebuilt-module-path=./$(PCM) \
		$(COMPILE_ARGS)

LDFLAGS := \
		-L$(LIB) -lties \
		-fprebuilt-module-path=$(PCM)

