#include <unity.h>
#include "BlinkLedBuildInEsp32.hpp"


extern "C" void app_main(void);

void app_main(void)
{
     vTaskDelay(pdMS_TO_TICKS(1000));
    UNITY_BEGIN();
    RUN_TEST(gpio_master_test);
    UNITY_END();

}