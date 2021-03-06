## Build target for doubly-list-backed deque

deque_tests: dl_deque_tests
deque_vg_tests: dl_deque_vg

# Deques
$(addprefix $(BUILD_DIR), dl_deque_tests.o): $(addprefix $(TESTS_DIR), deques/dl_deque_tests.c) | build
	$(CC) $(CFLAGS) -c $^ -o $@

$(addprefix $(BUILD_DIR), dl_deque_tests): $(addprefix $(BUILD_DIR), dl_deque_tests.o dl_iterator.o dl_deque.a)
	$(CC) $(CFLAGS) $^ -o $@

dl_deque_tests: $(addprefix $(BUILD_DIR), dl_deque_tests)

dl_deque_time: dl_deque_tests
	/usr/bin/time -v $(addprefix $(BUILD_DIR), $^)

dl_deque_vg: dl_deque_tests
	@echo "\nDoubly-list-backed Deque Valgrind Test"
	@valgrind -v --leak-check=full $(addprefix $(BUILD_DIR), $^) 2>&1 | grep -i -e "total heap usage" -e "All heap" -e "definitely lost" -e "indirectly lost" -e "ERROR SUMMARY" -e "LEAK SUMMARY" -e "HEAP SUMMARY"
	@echo
