#include "kof_items.h"
#include <string.h>

extern int kof_item_equals(const kof_item_t* i1, 
	                       const kof_item_t* i2, 
	                       unsigned flags)
{
	int is_eq = 1;
	if(flags & KOF_ITEM_FLAG_EQ_L)
		is_eq = is_eq && (strcmp(i1->left_val, i2->left_val) == 0);
	if(flags & KOF_ITEM_FLAG_EQ_R)
		is_eq = is_eq && (strcmp(i1->right_val, i2->right_val) == 0);
	if(flags & KOF_ITEM_FLAG_EQ_C)
		is_eq = is_eq && (strcmp(i1->connection, i2->connection) == 0);	
	return is_eq;
}


