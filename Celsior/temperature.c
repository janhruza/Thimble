#include <ctype.h>
#include "temperature.h"

double CtoK(double tempc)
{
    return KELVIN_BASE + tempc;
}

double FtoK(double tempf)
{
    return (tempf - 32) * 5/9 + KELVIN_BASE;
}

double FtoC(double tempf)
{
    return (tempf - 32) * 5/9;
}

double KtoC(double tempk)
{
    return tempk - KELVIN_BASE;
}

double CtoF(double tempc)
{
    return (tempc * 9/5) + 32;
}

double KtoF(double tempk)
{
    return (tempk - KELVIN_BASE) * 9/5 + 32;
}

double TempConvert(int src_temp, int target_temp, double value)
{
    double temp_k = TEMP_ERROR;

    switch (src_temp)
    {
        case TEMP_CELSIUS:
            temp_k = CtoK(value);
            break;

        case TEMP_FAHRENHEIT:
            temp_k = FtoK(value);
            break;

        case TEMP_KELVIN:
            temp_k = value;
            break;

        default:
            return temp_k;
    }

    // conversion check
    if (temp_k == TEMP_ERROR) return temp_k;


    switch (target_temp)
    {
        // already converted
        case TEMP_KELVIN: return temp_k;

        // convert to celsius
        case TEMP_CELSIUS: return KtoC(temp_k);

        // convert to fahrenheit
        case TEMP_FAHRENHEIT: return KtoF(temp_k);

        // invalid option
        default: break;
    }

    return TEMP_ERROR;
}

int GetTempUnit(char c)
{
    switch (toupper(c))
    {
        case 'C': return TEMP_CELSIUS;
        case 'F': return TEMP_FAHRENHEIT;
        case 'K': return TEMP_KELVIN;
        default: return TEMP_INVALID;
    }
}