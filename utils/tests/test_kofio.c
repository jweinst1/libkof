#include "kof-io.h"
#include "test-tools.h"

static const char* TEST_PATH_FILE = "abcdefghijk.txt";

static FILE* 
_create_temp_file(const char* data)
{
	FILE* fp;
	fp = tmpfile();
	fputs(data, fp);
	rewind(fp);
	return fp;
}


void test_io_callback(const char* data, void** args)
{
	int* iptr = args[0];
	sscanf(data, "%d", iptr);
}

static void test_kof_io_read_chunk(void)
{
	FILE* testfp;
	const char* writ = "100";
	int readint = 0;
	void* args[] = {&readint, NULL};
	kof_io_read_cb reader = &test_io_callback;
	testfp = _create_temp_file(writ);
	TEST_CHECK_POINT(kof_io_read_chunk(testfp, reader, args));
	TEST_CHECK_POINT(readint == 100);
}

int main(int argc, char const *argv[])
{
	test_kof_io_read_chunk();
	return 0;
}
