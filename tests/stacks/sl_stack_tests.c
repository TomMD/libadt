#include <stdio.h>
#include <stdlib.h>

#include <sl_stack.h>

#define QTD 10

void print_list(sl_stack_root *stack) {
	slist_node *node = stack->head;
	printf("[");
	if (sl_stack_size(stack) > 0) {
		do {
			printf("%d, ", *((int *) node->data));
			node = node->next;
		} while (node != NULL);
	}
	printf("]\n");
}

int main() {
	sl_stack_root *a;
	int *num;
	
	a = (sl_stack_root *) malloc(sizeof(sl_stack_root));
	sl_stack_create(a, &free);
	
	printf("##### Test 1 - sl_stack_push - Insert element in the stack.\n");
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		*num = i;
		sl_stack_push(a, num);
	}
	print_list(a);
	
	printf("##### Test 2 - sl_stack_peek - View the top element without pop it from the stack.\n");
	sl_stack_peek(a, (void *) &num);
	printf("Peeked item: %d\n", *num);
	
	printf("##### Test 3 - sl_stack_pop - Remove the top element without pop it from the stack.\n");
	for (int i = 0; i < 5; i++) {
		sl_stack_pop(a, (void *) &num);
		printf("Popped item: %d\n", *num);
		free(num);
	}
	print_list(a);
	
	printf("##### Test 2 - sl_stack_destroy - Destroy stack (call destroyfunc for every member).\n");
	sl_stack_destroy(a);
	print_list(a);
	
	free(a);
	return EXIT_SUCCESS;
}
