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
/**
 * Internal writing function used to consolidate
 * code from write and append.
 */
static void _kof_io_write(const char* path, 
	                      const char* data, 
	                      const char* mode, 
	                      int* err)
{
	FILE* fp;
	*err = 0;
	fp = fopen(path, mode);
	if(fp == NULL) {
		*err = 1;
		return;
	}
	fputs(data, fp);
	fclose(fp);
}

extern int kof_io_write_str(const char* path, const char* data)
{
	int erri = 0;
	_kof_io_write(path, data, "w", &erri);
	return erri;
}

extern int kof_io_append_str(const char* path, const char* data)
{
	int erri = 0;
	_kof_io_write(path, data, "a", &erri);
	return erri;
}

extern int kof_io_read_chunk(FILE* fp, kof_io_read_cb callback, void** arr)
{
	char read_buf[KOF_IO_CHUNK_READING_SIZE];
	if(fgets(read_buf, KOF_IO_CHUNK_READING_SIZE, fp) == NULL)
		return 0;
	callback(read_buf, arr); //todo
	return 1;
}
