ties_module_names := \
		libc \
		rt

ties_modules := $(ties_module_names:%=$(OBJ)/ties.%.o)

ties_module_impl_libc := \
		ctype \
		fenv \
		flt \
		limits \
		locale \
		math \
		setjmp \
		signal \
		stdarg \
		stddef \
		stdint \
		stdio \
		stdlib \
		string \
		threads \
		time \
		uchar \
		wchar \
		wctype

ties_module_sources_libc := $(ties_module_impl_libc:%=$(SRC)/libc/%.cppp)
ties_module_pcms_libc := $(ties_module_impl_libc:%=$(PCM)/ties.libc-%.pcm)
ties_module_objs_libc := $(ties_module_impl_libc:%=$(OBJ)/ties.libc-%.o)

ties_module_sources_rt :=
ties_module_pcms_rt :=
ties_module_objs_rt :=

ties_modules_objs = \
		$(ties_module_objs_libc) \
		$(ties_module_objs_rt)

$(OBJ)/crti.o: $(SRC)/rt/crti.s
	mkdir -p $(OBJ)
	$(CXX) -c $< -o $@

$(OBJ)/crtn.o: $(SRC)/rt/crtn.s
	mkdir -p $(OBJ)
	$(CXX) -c $< -o $@

$(OBJ)/crt0.o: $(SRC)/rt/crt0.s
	mkdir -p $(OBJ)
	$(CXX) -c $< -o $@

$(PCM)/ties.rt.pcm: $(SRC)/rt/rt.cppm
	@printf ' PCM\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(PCM)
	@$(CXX) $(PRECOMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.rt.o: $(PCM)/ties.rt.pcm
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -c $< -o $@

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

$(PCM)/ties.libc-uchar.pcm: $(SRC)/libc/uchar.cppp
	@printf ' PCM\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(PCM)
	@$(CXX) $(PRECOMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.libc-uchar.o: $(PCM)/ties.libc-uchar.pcm
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -c $< -o $@

$(PCM)/ties.libc-wchar.pcm: $(SRC)/libc/wchar.cppp
	@printf ' PCM\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(PCM)
	@$(CXX) $(PRECOMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.libc-wchar.o: $(PCM)/ties.libc-wchar.pcm
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -c $< -o $@

$(PCM)/ties.libc-wctype.pcm: $(SRC)/libc/wctype.cppp
	@printf ' PCM\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(PCM)
	@$(CXX) $(PRECOMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.libc-wctype.o: $(PCM)/ties.libc-wctype.pcm
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -c $< -o $@

$(PCM)/ties.libc.pcm: $(SRC)/libc/libc.cppm $(ties_module_pcms_libc)
	@printf ' PCM\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(PCM)
	@$(CXX) $(PRECOMPILE_ARGS) -I$(INC) -c $< -o $@

$(OBJ)/ties.libc.o: $(PCM)/ties.libc.pcm $(ties_module_objs_libc)
	@printf ' CXX\t%-40s\t-> %s\n' "$<" "$@"
	@mkdir -p $(OBJ)
	@$(CXX) $(COMPILE_ARGS) -c $< -o $@

