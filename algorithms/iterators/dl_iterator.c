#include <dl_iterator.h>

#include <dl_list.h>

#include <stdio.h>
#include <stdlib.h>

struct iterator_d {
	list_node *current;
	dl_iter_direction flow;
};

iterator_d * dl_iter_create(list_root *list, dl_iter_direction d) {
	iterator_d *iter = NULL;
	if (list->head != NULL) {
		iter = (iterator_d *) malloc(sizeof(iterator_d));
		iter->flow = d;
		switch (iter->flow) {
			case FORWARD: iter->current = list->head; break;
			case BACKWARD: iter->current = list->tail; break;
			default: free(iter); return NULL;
		}
	}
	return iter;
}

int dl_iter_hasnext(iterator_d *iter) {
	if (iter != NULL) {
		switch (iter->flow) {
			case FORWARD: return (iter->current->next != NULL); break;
			case BACKWARD: return (iter->current->prev != NULL); break;
			default: return 0;
		}
	} else {
		return 0;
	}
}

int dl_iter_next(iterator_d *iter) {
	if (iter != NULL) {
		if (iter->current != NULL) {
			switch (iter->flow) {
				case FORWARD: iter->current = iter->current->next; break;
				case BACKWARD: iter->current = iter->current->prev; break;
				default: return 0;
			}
		}
		return (iter->current != NULL);
	}
	return 0;
}

void * dl_iter_item(iterator_d *iter) {
	if (iter != NULL) {
		if (iter->current != NULL) {
			return iter->current->data;
		}
	}
	return NULL;
}

void dl_iter_free(iterator_d *iter) {
	if (iter != NULL) {
		iter->current = NULL;
		free(iter);
	}
}
