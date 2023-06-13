ties_module_names := \
		concepts \
		functional \
		math \
		memory \
		type_traits \
		types

ties_modules := $(ties_module_names:%=$(OBJ)/ties.%.o)

$(OBJ)/ties.concepts.o: $(SRC)/concepts/concepts.cppm $(OBJ)/ties.type_traits.o $(OBJ)/ties.types.o
	@printf ' CXX\t%s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.types-aliases.o: $(SRC)/types/aliases.cppp $(INC)/fundamental_types.hpp
	@printf ' CXX\t%s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.types-limits.o: $(SRC)/types/limits.cppp $(OBJ)/ties.types-aliases.o
	@printf ' CXX\t%s\t-> %s\n' "$<" "$@"
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.types.tuple.o: $(SRC)/types/tuple.cppm $(OBJ)/ties.types.o $(OBJ)/ties.memory.o $(OBJ)/ties.functional.monad.o
	@printf ' CXX\t%s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.types.o:  $(SRC)/types/types.cppm $(OBJ)/ties.types-aliases.o $(OBJ)/ties.types-limits.o
	@printf ' CXX\t%s\t-> %s\n' "$<" "$@"
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.functional.o: $(SRC)/functional/functional.cppm $(OBJ)/ties.functional.functor.o $(OBJ)/ties.functional.monad.o
	@printf ' CXX\t%s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.functional.functor.o: $(SRC)/functional/functor.cppm $(OBJ)/ties.memory.o
	@printf ' CXX\t%s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.functional.monad.o: $(SRC)/functional/monad.cppm $(OBJ)/ties.memory.o
	@printf ' CXX\t%s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.math.o: $(SRC)/math/math.cppm $(OBJ)/ties.types.o $(OBJ)/ties.concepts.o $(OBJ)/ties.types.tuple.o
	@printf ' CXX\t%s\t-> %s\n' "$<" "$@"
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.type_traits.o: $(SRC)/type_traits/type_traits.cppm
	@printf ' CXX\t%s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.memory.o: $(SRC)/memory/memory.cppm $(OBJ)/ties.type_traits.o $(OBJ)/ties.concepts.o
	@printf ' CXX\t%s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(BIN)/$(TEST)/types/types: $(TEST)/types/types.cpp $(OBJ)/ties.types.o $(OBJ)/ties.types.tuple.o
	@printf ' CXX\t%s\t-> %s\n' "$<" "$@"
	@mkdir -p $(BIN)/$(TEST)/types
	@$(CXX) $(COMPILE_ARGS) $< -o $@

$(BIN)/$(TEST)/math/math: $(TEST)/math/math.cpp $(OBJ)/ties.math.o
	@printf ' CXX\t%s\t-> %s\n' "$<" "$@"
	@mkdir -p $(BIN)/$(TEST)/math
	@$(CXX) $(COMPILE_ARGS) $< -o $@

$(BIN)/$(TEST)/concepts/concepts: $(TEST)/concepts/concepts.cpp $(OBJ)/ties.concepts.o
	@printf ' CXX\t%s\t-> %s\n' "$<" "$@"
	@mkdir -p $(BIN)/$(TEST)/concepts
	@$(CXX) $(COMPILE_ARGS) $< -o $@

$(BIN)/$(TEST)/functional/functor: $(TEST)/functional/functor.cpp $(OBJ)/ties.functional.o
	@printf ' CXX\t%s\t-> %s\n' "$<" "$@"
	@mkdir -p $(BIN)/$(TEST)/functional
	@$(CXX) $(COMPILE_ARGS) $< -o $@

