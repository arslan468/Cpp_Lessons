#include "donusum.h"

double celsiusToFahrenheit(double c)
{
    double f = (c*(9.0/5.00))+32;
    return f;
}

double fahrenheitToCelsius(double f)
{
    double c = (f-32) * (5.00/9.00);
    return c;
}

double celsiusToKelvin(double c)
{
    return (c+273.15);
}cel