#include <stdio.h>
#include <stdlib.h>

#include <dlist.h>

#define QTD 10

void print_el(dlist_node *node) {
	printf("(");
	if (node != NULL) {
		if (node->prev != NULL) {
			printf("%d", *((int *) node->prev->data));
		} else {
			printf("NULL");
		}
		
		printf(", '%d', ", *((int *) node->data));
		
		if (node->next != NULL) {
			printf("%d", *((int *) node->next->data));
		} else {
			printf("NULL");
		}
	} else {
		printf("NULL");
	}
	printf(") ");
}

void print_list(dlist_root *list) {
	dlist_node *node = list->head;
	printf("List size: %d. Items: [", list->size);
	if (dlist_size(list) > 0) {
		do {
			print_el(node);
			node = node->next;
		} while (node != NULL);
	}
	printf("]\n");
}

int main() {
	dlist_root *a;
	int *num;
	
	a = (dlist_root *) malloc(sizeof(dlist_root));
	dlist_create(a, &free);
	
	printf("##### Test 1 - Insert in the head of the list (without current param)\n");
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		*num = i;
		dlist_insert_el_next(a, NULL, num);
	}
	print_list(a);
	
	printf("##### Test 2 - Insert in the middle of the list (with current param = head)\n");
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		*num = i + QTD;
		dlist_insert_el_next(a, a->head, num);
	}
	print_list(a);
	
	printf("##### Test 3 - Insert in the tail of the list (with current param = tail)\n");
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		*num = i + (QTD * 2);
		dlist_insert_el_next(a, a->tail, num);
	}
	print_list(a);
	
	printf("##### Test 4 - Insert in the tail of the list (without current param)\n");
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		*num = i;
		dlist_insert_el_prev(a, NULL, num);
	}
	print_list(a);
	
	printf("##### Test 5 - Insert in the middle of the list (with current param = tail)\n");
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		*num = i + QTD;
		dlist_insert_el_prev(a, a->tail, num);
	}
	print_list(a);
	
	printf("##### Test 6 - Insert in the head of the list (with current param = head)\n");
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		*num = i + (QTD * 2);
		dlist_insert_el_prev(a, a->head, num);
	}
	print_list(a);
	
	printf("##### Test 7 - Move head item to middle of the list\n");
	dlist_move_el_next(a, a->head, a->head->next->next);
	print_list(a);
	
	printf("##### Test 8 - Move item to tail of the list\n");
	dlist_move_el_next(a, a->head->next, a->tail);
	print_list(a);
	
	printf("##### Test 9 - Move item to another position\n");
	dlist_move_el_next(a, a->head->next->next->next, a->head->next);
	print_list(a);
	
	printf("##### Test 10 - Move head to tail (and back again)\n");
	dlist_move_el_next(a, a->head, a->tail);
	print_list(a);
	dlist_move_el_next(a, a->tail, a->head);
	print_list(a);
	
	printf("##### Test 11 - Remove from the head of the list\n");
	dlist_rem_el(a, a->head, (void *) &num);
	print_list(a);
	free(num);
	
	printf("##### Test 12 - Remove from the middle of the list\n");
	dlist_rem_el(a, a->head->next->next, (void *) &num);
	print_list(a);
	free(num);
	
	printf("##### Test 13 - Remove from the tail of the list\n");
	dlist_rem_el(a, a->tail, (void *) &num);
	print_list(a);
	free(num);
	
	printf("##### Test 14 - Destroy list (call destroyfunc for every member)\n");
	dlist_destroy(a);
	print_list(a);
	
	free(a);
	return EXIT_SUCCESS;
}
