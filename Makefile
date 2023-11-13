include config.mk
include modules.mk

.SUFFIXES: .cppm .cppp .pcm .o .cpp .hpp

all: $(LIB)/libties.a $(OUT)/examples/main

test: all

$(LIB)/libties.a: $(ties_modules) $(ties_modules_objs)
	@printf ' AR\t%-40s\n' "$@"
	@mkdir -p $(LIB)
	@llvm-ar crv $@ $^

$(OUT)/examples/main: examples/main.cpp $(LIB)/libties.a
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OUT)/examples
	@$(CXX) $(COMPILE_ARGS) $< $(LDFLAGS) -o $@ -static -lc

clean:
	@rm -rf $(OUT)

.PHONY: clean test all

