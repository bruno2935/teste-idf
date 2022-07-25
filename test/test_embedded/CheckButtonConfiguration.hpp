/**
 * @file thermistor.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"
#include "thermistor.hpp"
#include <unity.h>


#ifdef __cplusplus
extern "C" {
#endif

#define BUTTON GPIO_NUM_15

void gpio_master_test()
{
    
    gpio_config_t config_button =
     {
         .pin_bit_mask = 1UL << BUTTON,
         .mode = GPIO_MODE_INPUT,
         .pull_up_en = GPIO_PULLUP_ENABLE,
         .pull_down_en = GPIO_PULLDOWN_DISABLE,
         .intr_type = GPIO_INTR_DISABLE
     };
     gpio_config(&config_button);


    TEST_ASSERT(!gpio_get_level(BUTTON) == 0);
}






#ifdef __cplusplus
}
#endif