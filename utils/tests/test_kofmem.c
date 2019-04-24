#include "kof-mem.h"
#include "test-tools.h"

static void test_kof_calloc(void)
{
	unsigned char* membyt = kof_calloc(10);
	TEST_CHECK_POINT(membyt[0] == 0);
	kof_free(membyt);
}

static void test_kof_mem_pool_init(void)
{
	kof_mem_pool_t pool;
	KOF_MEM_POOL_INIT(pool, 1000);
	TEST_CHECK_POINT(pool.begin != NULL);
	TEST_CHECK_POINT((pool.end - pool.begin) == 1000);
	TEST_CHECK_POINT(KOF_MEM_POOL_SPACE(pool) == 1000);
	KOF_MEM_POOL_DESTROY(pool);
}

static void test_kof_mem_pool_grow(void)
{
	kof_mem_pool_t pool;
	KOF_MEM_POOL_INIT(pool, 100);
	KOF_MEM_POOL_GROW(pool);
	TEST_CHECK_POINT(pool.begin != NULL);
	TEST_CHECK_POINT(KOF_MEM_POOL_SPACE(pool) == (100 * 100));
	KOF_MEM_POOL_DESTROY(pool);
}

static void test_kof_mem_pool_alloc(void)
{
	kof_mem_pool_t pool;
	char* foo;
	char written;
	KOF_MEM_POOL_INIT(pool, 100);
	KOF_MEM_POOL_ALLOC(pool, foo, 10);
	foo[0] = 'g';
	TEST_CHECK_POINT(foo != NULL);
	TEST_CHECK_POINT(KOF_MEM_POOL_SPACE(pool) == 90);
	written = *(char*)(pool.begin);
	TEST_CHECK_POINT(written == 'g');
	KOF_MEM_POOL_DESTROY(pool);
}

static void test_kof_mem_pool_new(void)
{
	kof_mem_pool_t pool;
	int* foo;
	int written;
	KOF_MEM_POOL_INIT(pool, 100);
	KOF_MEM_POOL_NEW(pool, foo, int, 50);
	foo[0] = 6;
	TEST_CHECK_POINT(foo != NULL);
	TEST_CHECK_POINT(KOF_MEM_POOL_CAP(pool) == (100 * 100));
	TEST_CHECK_POINT(KOF_MEM_POOL_LEN(pool) == (50 * sizeof(int)));
	written = *(int*)(pool.begin);
	TEST_CHECK_POINT(written == 6);
	KOF_MEM_POOL_DESTROY(pool);
}

int main(int argc, char const *argv[])
{
	test_kof_calloc();
	test_kof_mem_pool_init();
	test_kof_mem_pool_grow();
	test_kof_mem_pool_alloc();
	test_kof_mem_pool_new();
	return 0;
}
