/*
 * 002led_button.c
 *
 *  Created on: Apr 22, 2025
 *      Author: Admin
 */
#include "stm32f401xx.h"
#include <string.h>
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
	memset(&GpioLed,0,sizeof(GpioLed));
	memset(&GpioBtn,0,sizeof(GpioBtn));
	GpioLed.pGPIOx = GPIOA;
	GpioLed.pGPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	GpioLed.pGPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.pGPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GpioLed.pGPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.pGPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&GpioLed);

	//this is btn gpio configuration
	GpioBtn.pGPIOx = GPIOC;
	GpioBtn.pGPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_8;
	GpioBtn.pGPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_FT;
	GpioBtn.pGPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioBtn.pGPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;

	GPIO_PeriClockControl(GPIOC, ENABLE);
	GPIO_Init(&GpioBtn);

	//IRQ configurations
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI9_5, NVIC_IRQ_PRI15);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI9_5, ENABLE);


	while(1);
}

void EXTI9_5_IRQHandler (void)
{
	delay();//200ms
	GPIO_IRQHandling(GPIO_PIN_NO_8); //clear the pending event from exti line
	GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);
}
