# Build target for singly-list-backed stack
$(addprefix $(BUILD_DIR), sl_stack.partial): $(addprefix $(LIB_DIR), stacks/sl_stack.c) $(addprefix $(INC_DIR), sl_stack.h slist.h) | build
	$(CC) $(CFLAGS) -c $< -o $@

$(addprefix $(BUILD_DIR), sl_stack.o): $(addprefix $(BUILD_DIR), sl_stack.partial slist.o)
	ld $(LDFLAGS) -r $^ -o $@

sl_stack.o: $(addprefix $(BUILD_DIR), sl_stack.o)
