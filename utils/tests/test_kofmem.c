#include "kof-mem.h"
#include "test-tools.h"

static void test_kof_calloc(void)
{
	unsigned char* membyt = kof_calloc(10);
	TEST_CHECK_POINT(membyt[0] == 0);
	kof_free(membyt);
}

int main(int argc, char const *argv[])
{
	test_kof_calloc();
	return 0;
}
