/*
 * 002led_button.c
 *
 *  Created on: Apr 22, 2025
 *      Author: Admin
 */
#include "stm32f401xx.h"
#define LOW					0
#define HIGH				1
#define BTN_PRESSED 		LOW

void delay (void)
{
	for(uint32_t i=0; i<500000/2;i++);
}

int main (void)
{
	//this is led gpio configuration
	GPIO_Handle_t GpioLed, GpioBtn;
	GpioLed.pGPIOx = GPIOA;
	GpioLed.pGPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	GpioLed.pGPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.pGPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.pGPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.pGPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&GpioLed);

	//this is btn gpio configuration
	GpioBtn.pGPIOx = GPIOC;
	GpioBtn.pGPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_8;
	GpioBtn.pGPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GpioBtn.pGPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioBtn.pGPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;

	GPIO_PeriClockControl(GPIOC, ENABLE);
	GPIO_Init(&GpioBtn);
	while (1)
	{
		if(GPIO_ReadFormInputPin(GPIOC, GPIO_PIN_NO_8) == BTN_PRESSED)
		{
			delay();
			GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);
		}

	}
	return 0;
}

