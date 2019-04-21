#ifndef KOF_UTILS_IO_H
#define KOF_UTILS_IO_H

#include <stdio.h>
#include <stdlib.h>

static const char* KOF_IO_FILE_EXTENSION = ".kof";

extern void kof_io_size_file(FILE* fp, size_t* sz);

extern int kof_io_write_str(const char* path, const char* data); 

#endif // KOF_UTILS_IO_H
