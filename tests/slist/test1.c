#include <stdio.h>
#include <stdlib.h>

#include <slist.h>

#define QTD 5

int main() {
	slist_root *a;
	int *num;
	
	a = (slist_root *) malloc(sizeof(slist_root));
	slist_create(a, &free);
	
	// Case 1 - Insert in the head of the list (without current param);
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		slist_insert_el(a, NULL, num);
	}
	
	// Test 2 - Insert in the middle of the list (with current param = head);
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		slist_insert_el(a, list->head, num);
	}
	
	// Test 3 - Insert in the tail of the list (with current param = tail);
	for (int i = 0; i < QTD; i++) {
		num = (int *) malloc(sizeof(int));
		slist_insert_el(a, list->tail, num);
	}
	
	// Test 4 - Remove from the head of the list (without current param);
	
	// Test 5 - Remove from the middle of the list (with current param = head);
	
	// Test 6 - Remove from the end of the list (with current param = tail);
	
	// Test 7 - Destroy list (call destroyfunc for every member);
	
	free(a);
	return EXIT_SUCCESS;
}
