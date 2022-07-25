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
#include "math.h"

#ifdef __cplusplus
extern "C" {
#endif

#define VERBOSE_SENSOR_READ

#define DEFAULT_NUM_SAMPLES  10
#define DEFAULT_BCOEF        3950
#define DEFAULT_NOMINAL_RES 100000



class Thermistor
{
    /**
     * @brief 
     * 
     */
    private:
    
    adc1_channel_t adcChannel;

    uint32_t NominalResistence;

    uint32_t SerialResistence;

    uint32_t BetaCoeficient;

    /**
     * @brief 
     * 
     */
    public:
    
    Thermistor(adc1_channel_t adcChannel, uint32_t NominalResistence, uint32_t SerialResistence, uint32_t BetaCoeficient);
    float read(void);
    void configParams();





    Thermistor();
};









#ifdef __cplusplus
}
#endif