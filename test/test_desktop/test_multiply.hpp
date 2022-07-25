#include "multiply.hpp"
#include "unity.h"

void test_multiply_multiply_two_values(void)
{   
    int expected = 10;
    int actual = mult(5, 2);
    TEST_ASSERT_EQUAL_INT32(expected, actual);
    
}