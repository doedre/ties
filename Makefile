include config.mk
include modules.mk

.SUFFIXES: .cppm .cppp .pcm .o .cpp .hpp

all: $(ties_modules)

test: all $(ties_tests_static)

clean:
	@rm -rf gcm.cache
	@rm -rf $(OBJ)
	@rm -rf $(BIN)

.PHONY: clean test all

