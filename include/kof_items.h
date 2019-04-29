#ifndef KOF_ITEMS_H
#define KOF_ITEMS_H

#include "kof-mem.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct __kof_item {
	const char* left_val;
	const char* connection;
	const char* right_val;
} kof_item_t;

static const unsigned KOF_ITEM_FLAG_EQ_L = 1; /* Used to compare the left values*/
static const unsigned KOF_ITEM_FLAG_EQ_R = 2; /* Used to compare the right values*/
static const unsigned KOF_ITEM_FLAG_EQ_C = 4; /* Used to compare the conneciton */

extern int kof_item_equals(const kof_item_t* i1, 
	                       const kof_item_t* i2, 
	                       unsigned flags);

#ifdef __cplusplus
}
#endif


#endif // KOF_ITEMS_H
