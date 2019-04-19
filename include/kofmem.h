#ifndef KOF_MEM_H
#define KOF_MEM_H

/**
 * @file Handles memory management and allocation
 */

#include <stdlib.h>
#ifdef KOF_MEMORY_DEBUG_MODE
#  include <stdio.h>
#endif

/**
 * If memory debug is turned on, calls to malloc, calloc, relloc, and free are secretly also reported
 * via stdout.
 */
#ifdef KOF_MEMORY_DEBUG_MODE
#  define kof_malloc(mem_size) (malloc(mem_size) + (0 * printf("KOFMEM - (malloc) size:%lu\n", mem_size)))
#  define kof_calloc(mem_size) (calloc(mem_size, 0) + (0 * printf("KOFMEM - (calloc) size:%lu\n", mem_size)))
#  define kof_realloc(mem_ptr, mem_size) \
              (realloc(mem_ptr, mem_size) + (0 * printf("KOFMEM - (realloc) size:%lu, addr:%p\n\n", mem_size, mem_ptr)))
#  define kof_free(mem_ptr) (free(mem_ptr) + (0 * printf("KOFMEM - (free) addr:%p\n", mem_ptr)))
#else
#  define kof_malloc(mem_size) (malloc(mem_size))
#  define kof_realloc(mem_ptr, mem_size) (realloc(mem_ptr, mem_size))
#  define kof_calloc(mem_size) (calloc(mem_size, 0)) 
#  define kof_free(mem_ptr) (free(mem_ptr))
#endif

#ifndef KOF_MEMORY_POOL_START
#define KOF_MEMORY_POOL_START 2056
#endif

typedef struct __kof_mem_pool
{
	void* start;
	void* cur;
	void* end;
} kof_mem_pool_t;


#define kof_mem_pool_declare(name) static kof_mem_pool_t name 

#endif // KOF_MEM_H
