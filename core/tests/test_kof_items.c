#include "kof_items.h"
#include "test-tools.h"



static void test_kof_item_equals(void)
{
	int result;
	unsigned test_flags = KOF_ITEM_FLAG_EQ_R | KOF_ITEM_FLAG_EQ_L;
	kof_item_t item_test1;
	kof_item_t item_test2;
	item_test1.left_val = "apple";
	item_test1.right_val = "red";
	item_test1.connection = "physical.color";
	item_test2.left_val = "apple";
	item_test2.right_val = "red";
	item_test2.connection = "look.color";
	result = kof_item_equals(&item_test1, &item_test2, test_flags);
	TEST_CHECK_POINT(result == 1);
}

int main(int argc, char const *argv[])
{
	test_kof_item_equals();
	return 0;
}
