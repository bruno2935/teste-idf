
#include <stdio.h>
#include <stdlib.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"
#include "thermistor.hpp"


#define BUTTON GPIO_NUM_15

static esp_adc_cal_characteristics_t adc1_chars;

extern "C" void app_main(void);

esp_err_t set_adc(void);

static const char *TAG = "nct thermistor test\n";



void app_main(void)
{
    
    ESP_LOGW(TAG, "Init main\n");
    gpio_config_t config_button =
     {
         .pin_bit_mask = 1UL << BUTTON,
         .mode = GPIO_MODE_INPUT,
         .pull_up_en = GPIO_PULLUP_ENABLE,
         .pull_down_en = GPIO_PULLDOWN_DISABLE,
         .intr_type = GPIO_INTR_DISABLE
     };
     gpio_config(&config_button);


    float voltage;
    Thermistor termistor(ADC1_CHANNEL_6, DEFAULT_NOMINAL_RES, 100000, DEFAULT_BCOEF);
    set_adc();

    bool button_is_pressed;
    while (1) 
    {
        button_is_pressed= !gpio_get_level(BUTTON);
        if(button_is_pressed)
        {
            
            voltage = termistor.read();
            ESP_LOGW(TAG, "Thermistor: %f C \n", voltage);
            // printf("Thermistor: %f C \n", voltage);
            vTaskDelay(pdMS_TO_TICKS(400));
        }
    }
}

esp_err_t set_adc(void)
{
    ESP_ERROR_CHECK(adc1_config_width(ADC_WIDTH_BIT_12));
    ESP_ERROR_CHECK(adc1_config_channel_atten(ADC1_CHANNEL_6, ADC_ATTEN_DB_11));
    return ESP_OK;
}