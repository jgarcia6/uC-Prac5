#ifndef _MY_GPIO_H_
#define _MY_GPIO_H_

typedef enum {
    eGpioNumNc = -1,    /*!< Use to signal not connected to S/W */
    eGpioNum0 = 0,     /*!< GPIO0, input and output */
    eGpioNum1 = 1,     /*!< GPIO1, input and output */
    eGpioNum2 = 2,     /*!< GPIO2, input and output */
    eGpioNum3 = 3,     /*!< GPIO3, input and output */
    eGpioNum4 = 4,     /*!< GPIO4, input and output */
    eGpioNum5 = 5,     /*!< GPIO5, input and output */
    eGpioNum6 = 6,     /*!< GPIO6, input and output */
    eGpioNum7 = 7,     /*!< GPIO7, input and output */
    eGpioNum8 = 8,     /*!< GPIO8, input and output */
    eGpioNum9 = 9,     /*!< GPIO9, input and output */
    eGpioNum10 = 10,   /*!< GPIO10, input and output */
    eGpioNum11 = 11,   /*!< GPIO11, input and output */
    eGpioNum12 = 12,   /*!< GPIO12, input and output */
    eGpioNum13 = 13,   /*!< GPIO13, input and output */
    eGpioNum14 = 14,   /*!< GPIO14, input and output */
    eGpioNum15 = 15,   /*!< GPIO15, input and output */
    eGpioNum16 = 16,   /*!< GPIO16, input and output */
    eGpioNum17 = 17,   /*!< GPIO17, input and output */
    eGpioNum18 = 18,   /*!< GPIO18, input and output */
    eGpioNum19 = 19,   /*!< GPIO19, input and output */
    eGpioNum20 = 20,   /*!< GPIO20, input and output */
    eGpioNum21 = 21,   /*!< GPIO21, input and output */
    eGpioNum22 = 22,   /*!< GPIO22, input and output */
    eGpioNum23 = 23,   /*!< GPIO23, input and output */
    eGpioNum24 = 24,   /*!< GPIO24, input and output */
    eGpioNum25 = 25,   /*!< GPIO25, input and output */
    eGpioNum26 = 26,   /*!< GPIO26, input and output */
    eGpioNum27 = 27,   /*!< GPIO27, input and output */
    eGpioNum28 = 28,   /*!< GPIO28, input and output */
    eGpioNum29 = 29,   /*!< GPIO29, input and output */
    eGpioNum30 = 30,   /*!< GPIO30, input and output */
    eGpioNum31 = 31,   /*!< GPIO31, input and output */
    eGpioNum32 = 32,   /*!< GPIO32, input and output */
    eGpioNum33 = 33,   /*!< GPIO33, input and output */
    eGpioNum34 = 34,   /*!< GPIO34, input mode only */
    eGpioNum35 = 35,   /*!< GPIO35, input mode only */
    eGpioNum36 = 36,   /*!< GPIO36, input mode only */
    eGpioNum37 = 37,   /*!< GPIO37, input mode only */
    eGpioNum38 = 38,   /*!< GPIO38, input mode only */
    eGpioNum39 = 39,   /*!< GPIO39, input mode only */
    eGpioNumMax,
} gpioNum_t;

typedef enum {
    eInput = 0,         /*!< GPIO mode : enables input only */
    eInputPullUp,       /*!< GPIO mode : enables input with pull-up */
    eOutput,            /*!< GPIO mode : enables input-output functionality */
    eGpioModeMax,
} gpioMode_t;

typedef enum {
    eLow = 0,           /*!< GPIO Level : Low */
    eHigh,              /*!< GPIO Level : High */
    eMaxLevel
} gpioLevel_t;

typedef enum {
    eGpioInitError = 0, /*!< GPIO Init : Error */
    eGpioInitSuccess,   /*!< GPIO Init : Success */
} gpioInitError_t;

gpioInitError_t gpio_init(gpioNum_t gpioNum, gpioMode_t gpioMode);
void            gpio_write(gpioNum_t gpioNum, gpioLevel_t gpioLevel); 
gpioLevel_t     gpio_read(gpioNum_t gpioNum);

#endif