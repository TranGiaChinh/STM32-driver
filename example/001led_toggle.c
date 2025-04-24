/*
 * 001led_toggle.c
 *
 *  Created on: Apr 22, 2025
 *      Author: Admin
 */
#include "stm32f401xx.h"

void delay (void)
{
	for(uint32_t i=0; i<500000;i++);
}

int main (void)
{
	GPIO_Handle_t GpioLed;
	GpioLed.pGPIOx = GPIOA;
	GpioLed.pGPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	GpioLed.pGPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.pGPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.pGPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.pGPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PD;

	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&GpioLed);
	while (1)
	{
		GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);
		delay();
	}
	return 0;
}
