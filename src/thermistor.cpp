/**
 * @file thermistor.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#define TEMPERATURENOMINAL 25
#define ADC_RESOLUTION 0xFFF


#include "thermistor.hpp"


/**
 * @brief Construct a new Thermistor:: Thermistor object
 * 
 * @param channel 
 * @param Beta 
 * @param R0 
 * @param T0 
 */
Thermistor::Thermistor(adc1_channel_t adcChannel, uint32_t NominalResistence, uint32_t SerialResistence, uint32_t BetaCoeficient)
        :adcChannel(adcChannel),NominalResistence(NominalResistence), SerialResistence(SerialResistence), BetaCoeficient(BetaCoeficient)
{

}

float Thermistor::read()
{

        float samples_average=0;
        
        uint32_t sample;
        for (size_t i = 0; i < DEFAULT_NUM_SAMPLES; i++)
        {
                sample = adc1_get_raw(adcChannel);
                samples_average += sample;
        }

        samples_average /=DEFAULT_NUM_SAMPLES;

        // convert the value to resistance
        samples_average = ADC_RESOLUTION / samples_average - 1;
        samples_average = SerialResistence * samples_average;

        float steinhart;
        steinhart = samples_average/NominalResistence;   // (R/Ro)
        steinhart = log(steinhart);                  // ln(R/Ro)
        steinhart /= BetaCoeficient;                   // 1/B * ln(R/Ro)
        steinhart += 1.0 / (TEMPERATURENOMINAL + 273.15); // + (1/To)
        steinhart = 1.0 / steinhart;                 // Invert  
        steinhart -= 273.15;                         // convert to C
        return steinhart;
}