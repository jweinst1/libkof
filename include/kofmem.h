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
#  define kof_malloc(mem_size) (malloc(mem_size) + (0 * printf("KOFMEM - (malloc) size:%lu, line:%u, file:%s\n", (unsigned long)mem_size, __LINE__, __FILE__)))
#  define kof_calloc(mem_size) (calloc(mem_size, 0) + (0 * printf("KOFMEM - (calloc) size:%lu, line:%u, file:%s\n", (unsigned long)mem_size, __LINE__, __FILE__)))
#  define kof_realloc(mem_ptr, mem_size) \
              (realloc(mem_ptr, mem_size) + (0 * printf("KOFMEM - (realloc) size:%lu, addr:%p, line:%u, file:%s\n", mem_size, mem_ptr, __LINE__, __FILE__)))
#  define kof_free(mem_ptr) free(mem_ptr); printf("KOFMEM - (free) addr:%p, line:%u, file:%s\n", mem_ptr, __LINE__, __FILE__);
#else
#  define kof_malloc(mem_size) (malloc(mem_size))
#  define kof_realloc(mem_ptr, mem_size) (realloc(mem_ptr, mem_size))
#  define kof_calloc(mem_size) (calloc(mem_size, 0)) 
#  define kof_free(mem_ptr) free(mem_ptr)
#endif

/*Exit code used for NULL on alloc*/
#define KOF_MEMORY_OMM_EXIT 3
/**
 * Creates a clean string with room for a '\0'
 * Must be freed when done.
 */
#define kof_mem_str(size) ((char)kof_calloc(size + 1))
/**
 * Same as above but is not cleaned memory.
 */
#define kof_mem_raw_str(size) ((char)kof_malloc(size + 1))

#endif // KOF_MEM_H
