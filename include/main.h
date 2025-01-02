#ifndef MAIN_H
#define MAIN_H

#include "stm32f4xx_hal.h"

#define LED_PIN GPIO_PIN_5
#define LED_GPIO_PORT GPIOA
#define BUTTON_PIN GPIO_PIN_13
#define BUTTON_GPIO_PORT GPIOC

extern volatile uint8_t button_pressed;

#endif

