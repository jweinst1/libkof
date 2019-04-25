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

extern kof_item_t* kof_item_new(const char* left_val,
	                              const char* connection,
	                              const char* right_val);


#ifdef __cplusplus
}
#endif


#endif // KOF_ITEMS_H
