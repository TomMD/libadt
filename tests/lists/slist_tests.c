#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <slist.h>

#define QTD 20

void print_list(slist_root *list) {
	slist_node *node = list->head;
	printf("[");
	if (slist_size(list) > 0) {
		do {
			printf("%d, ", *((int *) node->data));
			node = node->next;
		} while (node != list->tail && node->next != NULL);
	}
	printf("]\n");
	//sleep(1);
}

int main() {
	slist_root *a;
	int *num;
	
	a = (slist_root *) malloc(sizeof(slist_root));
	slist_create(a, &free);
	
	printf("##### Test 1 - Insert in the head of the list (without current param)\n");
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		*num = i;
		slist_insert_el_next(a, NULL, num);
	}
	print_list(a);
	
	printf("##### Test 2 - Insert in the middle of the list (with current param = head)\n");
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		*num = i + QTD;
		slist_insert_el_next(a, a->head, num);
	}
	print_list(a);
	
	printf("##### Test 3 - Insert in the tail of the list (with current param = tail)\n");
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		*num = i + (QTD * 2);
		slist_insert_el_next(a, a->tail, num);
	}
	print_list(a);
	
	printf("##### Test 4 - Move head item to middle of the list\n");
	slist_move_el(a, a->head, a->head->next->next);
	print_list(a);
	
	printf("#####  Test 5 - Move item to tail of the list\n");
	slist_move_el(a, a->head->next, a->tail);
	print_list(a);
	
	printf("##### Test 6 - Move item to another position\n");
	slist_move_el(a, a->head->next->next->next, a->head->next);
	print_list(a);
	
	printf("##### Test 7 - Move head to tail (and back again)\n");
	slist_move_el(a, a->head, a->tail);
	print_list(a);
	slist_move_el(a, a->tail, a->head);
	print_list(a);
	
	printf("##### Test 8 - Swap two items on the list\n");
	slist_swap_el(a, a->head->next->next, a->head->next->next->next->next);
	print_list(a);
	slist_swap_el(a, a->head, a->head->next->next->next);
	print_list(a);
	slist_swap_el(a, a->head->next->next, a->tail);
	print_list(a);
	
	printf("##### Test 9 - Swap head and tail on the list\n");
	slist_swap_el(a, a->head, a->tail);
	print_list(a);
	slist_swap_el(a, a->tail, a->head);
	print_list(a);
	
	printf("##### Test 10 - Remove from the head of the list\n");
	slist_rem_el(a, a->head, (void *) &num);
	free(num);
	
	printf("##### Test 11 - Remove from the middle of the list\n");
	slist_rem_el(a, a->head->next->next, (void *) &num);
	print_list(a);
	free(num);
	
	printf("##### Test 12 - Remove from the tail of the list\n");
	slist_rem_el(a, a->tail, (void *) &num);
	print_list(a);
	free(num);
	
	printf("##### Test 13 - Destroy list (call destroyfunc for every member)\n");
	slist_destroy(a);
	print_list(a);
	
	free(a);
	return EXIT_SUCCESS;
}
