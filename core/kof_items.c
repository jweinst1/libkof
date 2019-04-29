#include "kof_items.h"
#include <string.h>

extern kof_item_t* kof_item_new(const char* left_val,
	                              const char* connection,
	                              const char* right_val)
{
	kof_item_t* item = kof_calloc(sizeof(kof_item_t));
	return item;
}

extern int kof_item_equals(const kof_item_t* i1, 
	                       const kof_item_t* i2, 
	                       unsigned flags)
{
	int is_eq = 0;
	return is_eq;
}


