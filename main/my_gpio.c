#include "my_gpio.h"

gpioInitError_t gpio_init(gpioNum_t gpioNum, gpioMode_t gpioMode)
{
    return eGpioInitSuccess;
}

void gpio_write(gpioNum_t gpioNum, gpioLevel_t gpioLevel)
{
    return;
}

gpioLevel_t gpio_read(gpioNum_t gpioNum)
{
    return eMaxLevel; // invalid by default
}
