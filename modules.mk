ties_module_names := \
		concepts \
		functional \
		math \
		meta \
		memory \
		types \
		types.tuple \
		types.maybe

ties_modules := $(ties_module_names:%=$(OBJ)/ties.%.o)

ties_tests_static := \
		concepts/concepts_static.cpp \
		math/math_static.cpp \
		meta/meta_static.cpp \
		types/types_static.cpp \
		types/maybe_static.cpp

ties_tests_static := $(ties_tests_static:%.cpp=$(BIN)/$(TEST)/%)

$(OBJ)/ties.concepts.o: $(SRC)/concepts/concepts.cppm $(OBJ)/ties.meta.o $(OBJ)/ties.types.o
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

$(OBJ)/ties.types.maybe.o: $(SRC)/types/maybe.cppm $(OBJ)/ties.types.o $(OBJ)/ties.memory.o $(OBJ)/ties.concepts.o $(OBJ)/ties.meta.o $(OBJ)/ties.functional.monad.o
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

$(OBJ)/ties.memory.o: $(SRC)/memory/memory.cppm $(OBJ)/ties.meta.o $(OBJ)/ties.concepts.o
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.meta-static_constant_type.o: $(SRC)/meta/static_constant_type.cppp
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.meta-utility.o: $(SRC)/meta/utility.cppp
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.meta-traits.o: $(SRC)/meta/traits.cppp $(OBJ)/ties.meta-utility.o $(OBJ)/ties.meta-static_constant_type.o
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.meta.o: $(SRC)/meta/meta.cppm $(OBJ)/ties.meta-traits.o $(OBJ)/ties.meta-static_constant_type.o $(OBJ)/ties.meta-utility.o
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.test_types.o: $(TEST)/test_types.cppm $(OBJ)/ties.types.o
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -I$(INC) -c $< -o $@

$(BIN)/$(TEST)/types/types_static: $(TEST)/types/types_static.cpp $(OBJ)/ties.types.o $(OBJ)/ties.types.tuple.o
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(BIN)/$(TEST)/types
	@$(CXX) $(COMPILE_ARGS) $< -o $@

$(BIN)/$(TEST)/types/maybe_static: $(TEST)/types/maybe_static.cpp $(OBJ)/ties.types.o $(OBJ)/ties.concepts.o $(OBJ)/ties.types.maybe.o
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(BIN)/$(TEST)/types
	@$(CXX) $(COMPILE_ARGS) $< -o $@

$(BIN)/$(TEST)/math/math_static: $(TEST)/math/math_static.cpp $(OBJ)/ties.math.o
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(BIN)/$(TEST)/math
	@$(CXX) $(COMPILE_ARGS) $< -o $@

$(BIN)/$(TEST)/concepts/concepts_static: $(TEST)/concepts/concepts_static.cpp $(OBJ)/ties.concepts.o $(OBJ)/ties.test_types.o
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(BIN)/$(TEST)/concepts
	@$(CXX) $(COMPILE_ARGS) $< -o $@

$(BIN)/$(TEST)/meta/meta_static: $(TEST)/meta/meta_static.cpp $(OBJ)/ties.meta.o
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(BIN)/$(TEST)/meta
	@$(CXX) $(COMPILE_ARGS) $< -o $@

$(BIN)/$(TEST)/functional/functor: $(TEST)/functional/functor.cpp $(OBJ)/ties.functional.o
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(BIN)/$(TEST)/functional
	@$(CXX) $(COMPILE_ARGS) $< -o $@

