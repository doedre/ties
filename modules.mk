ties_module_names := \
		libc

ties_modules := $(ties_module_names:%=$(OBJ)/ties.%.o)

ties_tests_static := \

ties_tests_static := $(ties_tests_static:%.cpp=$(BIN)/$(TEST)/%)

$(PCM)/ties.libc-ctype.pcm: $(SRC)/libc/ctype.cppp
	@printf ' PCM\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(PCM)
	@$(CXX) $(PRECOMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.libc-ctype.o: $(PCM)/ties.libc-ctype.pcm
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -c $< -o $@

$(PCM)/ties.libc.pcm: $(SRC)/libc/libc.cppm $(PCM)/ties.libc-ctype.pcm
	@printf ' PCM\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(PCM)
	@$(CXX) $(PRECOMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.libc.o: $(PCM)/ties.libc.pcm $(OBJ)/ties.libc-ctype.o
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -c $< -o $@

