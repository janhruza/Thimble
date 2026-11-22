#ifndef TEMPERATURE_H
#define TEMPERATURE_H

enum
{
    TEMP_CELSIUS,
    TEMP_FAHRENHEIT,
    TEMP_KELVIN,
    TEMP_INVALID
};

#define KELVIN_BASE 273.15
#define ABS_ZERO -KELVIN_BASE
#define TEMP_ERROR (ABS_ZERO - 1)

// Conversions to Kelvin
double CtoK(double tempc);
double FtoK(double tempf);

// Conversion to Celsius
double FtoC(double tempf);
double KtoC(double tempk);

// Conversion to Fahrenheit
double CtoF(double tempc);
double KtoF(double tempk);

// Universal conversion
double TempConvert(int src_temp, int target_temp, double value);

// Get the correct temperature from a corresponding character.
int GetTempUnit(char c);

#endif