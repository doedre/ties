ties_module_names := \
		concepts \
		functional \
		math \
		meta.concepts \
		meta.cast \
		meta.types \
		memory \
		type_traits \
		types \
		types.tuple \
		types.maybe

ties_modules := $(ties_module_names:%=$(OBJ)/ties.%.o)

$(OBJ)/ties.concepts.o: $(SRC)/concepts/concepts.cppm $(OBJ)/ties.type_traits.o $(OBJ)/ties.types.o
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.types-aliases.o: $(SRC)/types/aliases.cppp $(INC)/fundamental_types.hpp
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.types-limits.o: $(SRC)/types/limits.cppp $(OBJ)/ties.types-aliases.o
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.types.tuple.o: $(SRC)/types/tuple.cppm $(OBJ)/ties.types.o $(OBJ)/ties.memory.o $(OBJ)/ties.functional.monad.o
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.types.maybe.o: $(SRC)/types/maybe.cppm $(OBJ)/ties.types.o $(OBJ)/ties.memory.o $(OBJ)/ties.concepts.o $(OBJ)/ties.type_traits.o $(OBJ)/ties.functional.monad.o
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.types.o:  $(SRC)/types/types.cppm $(OBJ)/ties.types-aliases.o $(OBJ)/ties.types-limits.o
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.functional.o: $(SRC)/functional/functional.cppm $(OBJ)/ties.functional.functor.o $(OBJ)/ties.functional.monad.o
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.functional.functor.o: $(SRC)/functional/functor.cppm $(OBJ)/ties.memory.o
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.functional.monad.o: $(SRC)/functional/monad.cppm $(OBJ)/ties.memory.o
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.math.o: $(SRC)/math/math.cppm $(OBJ)/ties.types.o $(OBJ)/ties.concepts.o $(OBJ)/ties.types.tuple.o $(OBJ)/ties.types.maybe.o
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.type_traits.o: $(SRC)/type_traits/type_traits.cppm
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.memory.o: $(SRC)/memory/memory.cppm $(OBJ)/ties.type_traits.o $(OBJ)/ties.concepts.o
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.meta.types.o: $(SRC)/meta/types/types.cppm
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.meta.cast-references.o: $(SRC)/meta/cast/references.cppp $(OBJ)/ties.meta.types.o
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.meta.cast-cv_qualifiers.o: $(SRC)/meta/cast/cv_qualifiers.cppp
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.meta.cast-pointers.o: $(SRC)/meta/cast/pointers.cppp $(OBJ)/ties.meta.types.o
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.meta.cast.o: $(SRC)/meta/cast/cast.cppm $(OBJ)/ties.meta.cast-references.o $(OBJ)/ties.meta.cast-cv_qualifiers.o $(OBJ)/ties.meta.cast-pointers.o
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.meta.concepts.o: $(SRC)/meta/concepts/concepts.cppm $(OBJ)/ties.meta.cast.o $(OBJ)/ties.types.o
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.test_types.o: $(TEST)/test_types.cppm $(OBJ)/ties.types.o
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(BIN)/$(TEST)/types/types: $(TEST)/types/types.cpp $(OBJ)/ties.types.o $(OBJ)/ties.types.tuple.o
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(BIN)/$(TEST)/types
	@$(CXX) $(COMPILE_ARGS) $< -o $@

$(BIN)/$(TEST)/types/maybe: $(TEST)/types/maybe.cpp $(OBJ)/ties.types.o $(OBJ)/ties.concepts.o $(OBJ)/ties.types.maybe.o
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(BIN)/$(TEST)/types
	@$(CXX) $(COMPILE_ARGS) $< -o $@

$(BIN)/$(TEST)/math/math: $(TEST)/math/math.cpp $(OBJ)/ties.math.o
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(BIN)/$(TEST)/math
	@$(CXX) $(COMPILE_ARGS) $< -o $@

$(BIN)/$(TEST)/meta/concepts/concepts_static: $(TEST)/meta/concepts/concepts_static.cpp $(OBJ)/ties.meta.concepts.o $(OBJ)/ties.test_types.o
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(BIN)/$(TEST)/meta/concepts
	@$(CXX) $(COMPILE_ARGS) $< -o $@

$(BIN)/$(TEST)/meta/cast/cast_static: $(TEST)/meta/cast/cast_static.cpp $(OBJ)/ties.meta.concepts.o $(BIN)/$(TEST)/meta/concepts/concepts_static
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(BIN)/$(TEST)/meta/cast
	@$(CXX) $(COMPILE_ARGS) $< -o $@

$(BIN)/$(TEST)/functional/functor: $(TEST)/functional/functor.cpp $(OBJ)/ties.functional.o
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(BIN)/$(TEST)/functional
	@$(CXX) $(COMPILE_ARGS) $< -o $@

