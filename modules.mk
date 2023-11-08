ties_module_names := \
		libc

ties_modules := $(ties_module_names:%=$(OBJ)/ties.%.o)

ties_tests_static := \

ties_tests_static := $(ties_tests_static:%.cpp=$(BIN)/$(TEST)/%)

$(PCM)/ties.libc.pcm: $(SRC)/libc/libc.cppm
	@printf ' PCM\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(PCM)
	@$(CXX) $(PRECOMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.libc.o: $(PCM)/ties.libc.pcm
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -c $< -o $@

