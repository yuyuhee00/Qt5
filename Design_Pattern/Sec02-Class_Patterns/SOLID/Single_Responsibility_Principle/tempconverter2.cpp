#include "tempconverter2.h"

tempconverter2::tempconverter2()
{

}

int tempconverter2::celsiusToFahrenheit(int value)
{
    auto o = (value * 9.0) / 5.0 + 32;
    return o;
}

int tempconverter2::fahrenheitToCelsius(int value)
{
    auto o = (value - 32) * 5.0 / 9.0;
    return o;
}
