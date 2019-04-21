#ifndef KOF_UTILS_IO_H
#define KOF_UTILS_IO_H

#include <stdio.h>
#include <stdlib.h>
#include "het-array.h"
/**
 * File used for IO tools and utils
 */


#ifndef KOF_IO_CHUNK_READING_SIZE
#define KOF_IO_CHUNK_READING_SIZE 1024
#endif
/**
 * These act as call backs that are used to process a read chunk.
 * the void** is a heterogenous list of objects in memory
 */
typedef void (*kof_io_read_cb)(const char*, void**); 

static const char* KOF_IO_FILE_EXTENSION = ".kof";
/**
 * Gets the file size of an already open file.
 */
extern void kof_io_size_file(FILE* fp, size_t* sz);
/**
 * Opens a file, writes the entire string, then closes the file.
 * Returns 0 if file could not be opened, 1 otherwise
 */
extern int kof_io_write_str(const char* path, const char* data);

extern int kof_io_read_chunk(FILE* fp, kof_io_read_cb callback, void** arr);

extern int kof_io_append_str(const char* path, const char* data);

#endif // KOF_UTILS_IO_H
