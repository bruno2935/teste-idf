#include <unity.h>
#include "test_add.hpp"
#include "test_multiply.hpp"





int main(int argc, char **argv)
{
    UNITY_BEGIN();
    RUN_TEST(test_add_two_values);
    RUN_TEST(test_multiply_multiply_two_values);
    UNITY_END();

return 0;
}