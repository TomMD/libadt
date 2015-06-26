#ifndef _LIBADT_SL_QUEUE_H
#define _LIBADT_SL_QUEUE_H

#include <slist.h>

typedef slist_root sl_queue_root;

void sl_queue_create(sl_queue_root *list, t_destroyfunc destroyfunc);

int sl_queue_push(sl_queue_root *list, slist_node *current, void *data);

int sl_queue_peek(sl_queue_root *list, slist_node *current, void **data);

int sl_queue_pop(sl_queue_root *list, slist_node *current, void **data);

void slist_destroy(sl_queue_root *list);

#endif
