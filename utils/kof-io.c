#include "kof-io.h"

/**
 * Fast function for checking file size of open file.
 * Do not use on NULL
 */
extern void kof_io_size_file(FILE* fp, size_t* sz)
{
	fseek(fp, 0L, SEEK_END);
	*sz = ftell(fp);
	rewind(fp);
}

extern int kof_io_write_str(const char* path, const char* data)
{
	FILE* fp;
	fp = fopen(path, "w");
	if(fp == NULL)
		return 0;
	fputs(data, fp);
	fclose(fp);
	return 1;
}
