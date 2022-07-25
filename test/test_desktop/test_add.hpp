#include <unity.h>
#include "add.hpp"

void test_add_two_values(void)
{
    int expected = 4;
    TEST_ASSERT_EQUAL_INT32(expected , add(1,3));

}
