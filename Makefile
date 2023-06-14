include config.mk
include modules.mk

.SUFFIXES: .cppm .cppp .pcm .o .cpp .hpp

all: $(ties_modules)

test: $(BIN)/$(TEST)/concepts/concepts $(BIN)/$(TEST)/types/types $(BIN)/$(TEST)/math/math $(BIN)/$(TEST)/functional/functor $(BIN)/$(TEST)/types/maybe
	./$(BIN)/$(TEST)/concepts/concepts
	./$(BIN)/$(TEST)/functional/functor
	./$(BIN)/$(TEST)/types/types
	./$(BIN)/$(TEST)/types/maybe
	./$(BIN)/$(TEST)/math/math

clean:
	@rm -rf gcm.cache
	@rm -rf $(OBJ)
	@rm -rf $(BIN)

.PHONY: clean test all

