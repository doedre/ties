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

$(PCM)/ties.libc-errno.pcm: $(SRC)/libc/errno.cppp
	@printf ' PCM\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(PCM)
	@$(CXX) $(PRECOMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.libc-errno.o: $(PCM)/ties.libc-errno.pcm
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -c $< -o $@

$(PCM)/ties.libc-fenv.pcm: $(SRC)/libc/fenv.cppp
	@printf ' PCM\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(PCM)
	@$(CXX) $(PRECOMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.libc-fenv.o: $(PCM)/ties.libc-fenv.pcm
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -c $< -o $@

$(PCM)/ties.libc-flt.pcm: $(SRC)/libc/flt.cppp
	@printf ' PCM\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(PCM)
	@$(CXX) $(PRECOMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.libc-flt.o: $(PCM)/ties.libc-flt.pcm
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -c $< -o $@

$(PCM)/ties.libc-limits.pcm: $(SRC)/libc/limits.cppp
	@printf ' PCM\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(PCM)
	@$(CXX) $(PRECOMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.libc-limits.o: $(PCM)/ties.libc-limits.pcm
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -c $< -o $@

$(PCM)/ties.libc-locale.pcm: $(SRC)/libc/locale.cppp
	@printf ' PCM\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(PCM)
	@$(CXX) $(PRECOMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.libc-locale.o: $(PCM)/ties.libc-locale.pcm
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -c $< -o $@

$(PCM)/ties.libc-math.pcm: $(SRC)/libc/math.cppp
	@printf ' PCM\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(PCM)
	@$(CXX) $(PRECOMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.libc-math.o: $(PCM)/ties.libc-math.pcm
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -c $< -o $@

$(PCM)/ties.libc-setjmp.pcm: $(SRC)/libc/setjmp.cppp
	@printf ' PCM\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(PCM)
	@$(CXX) $(PRECOMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.libc-setjmp.o: $(PCM)/ties.libc-setjmp.pcm
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -c $< -o $@

$(PCM)/ties.libc-signal.pcm: $(SRC)/libc/signal.cppp
	@printf ' PCM\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(PCM)
	@$(CXX) $(PRECOMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.libc-signal.o: $(PCM)/ties.libc-signal.pcm
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -c $< -o $@

$(PCM)/ties.libc-stdarg.pcm: $(SRC)/libc/stdarg.cppp
	@printf ' PCM\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(PCM)
	@$(CXX) $(PRECOMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.libc-stdarg.o: $(PCM)/ties.libc-stdarg.pcm
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -c $< -o $@

$(PCM)/ties.libc-stddef.pcm: $(SRC)/libc/stddef.cppp
	@printf ' PCM\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(PCM)
	@$(CXX) $(PRECOMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.libc-stddef.o: $(PCM)/ties.libc-stddef.pcm
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -c $< -o $@

$(PCM)/ties.libc-stdint.pcm: $(SRC)/libc/stdint.cppp
	@printf ' PCM\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(PCM)
	@$(CXX) $(PRECOMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.libc-stdint.o: $(PCM)/ties.libc-stdint.pcm
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -c $< -o $@

$(PCM)/ties.libc-stdio.pcm: $(SRC)/libc/stdio.cppp
	@printf ' PCM\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(PCM)
	@$(CXX) $(PRECOMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.libc-stdio.o: $(PCM)/ties.libc-stdio.pcm
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -c $< -o $@

$(PCM)/ties.libc-stdlib.pcm: $(SRC)/libc/stdlib.cppp
	@printf ' PCM\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(PCM)
	@$(CXX) $(PRECOMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.libc-stdlib.o: $(PCM)/ties.libc-stdlib.pcm
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -c $< -o $@

$(PCM)/ties.libc-string.pcm: $(SRC)/libc/string.cppp
	@printf ' PCM\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(PCM)
	@$(CXX) $(PRECOMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.libc-string.o: $(PCM)/ties.libc-string.pcm
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -c $< -o $@

$(PCM)/ties.libc-threads.pcm: $(SRC)/libc/threads.cppp
	@printf ' PCM\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(PCM)
	@$(CXX) $(PRECOMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.libc-threads.o: $(PCM)/ties.libc-threads.pcm
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -c $< -o $@

$(PCM)/ties.libc-time.pcm: $(SRC)/libc/time.cppp
	@printf ' PCM\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(PCM)
	@$(CXX) $(PRECOMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.libc-time.o: $(PCM)/ties.libc-time.pcm
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -c $< -o $@

$(PCM)/ties.libc.pcm: $(SRC)/libc/libc.cppm $(PCM)/ties.libc-ctype.pcm $(PCM)/ties.libc-flt.pcm $(PCM)/ties.libc-limits.pcm $(PCM)/ties.libc-locale.pcm $(PCM)/ties.libc-math.pcm $(PCM)/ties.libc-setjmp.pcm $(PCM)/ties.libc-signal.pcm $(PCM)/ties.libc-stdarg.pcm $(PCM)/ties.libc-stddef.pcm $(PCM)/ties.libc-fenv.pcm $(PCM)/ties.libc-stdint.pcm $(PCM)/ties.libc-stdio.pcm $(PCM)/ties.libc-stdlib.pcm $(PCM)/ties.libc-string.pcm $(PCM)/ties.libc-threads.pcm $(PCM)/ties.libc-time.pcm
	@printf ' PCM\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(PCM)
	@$(CXX) $(PRECOMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.libc.o: $(PCM)/ties.libc.pcm $(OBJ)/ties.libc-ctype.o $(OBJ)/ties.libc-flt.o $(OBJ)/ties.libc-limits.o $(OBJ)/ties.libc-locale.o $(OBJ)/ties.libc-math.o $(OBJ)/ties.libc-setjmp.o $(OBJ)/ties.libc-signal.o $(OBJ)/ties.libc-stdarg.o $(OBJ)/ties.libc-stddef.o $(OBJ)/ties.libc-fenv.o $(OBJ)/ties.libc-stdint.o $(OBJ)/ties.libc-stdio.o $(OBJ)/ties.libc-stdlib.o $(OBJ)/ties.libc-string.o $(OBJ)/ties.libc-threads.o $(OBJ)/ties.libc-time.o
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -c $< -o $@

