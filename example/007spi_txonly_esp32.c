
/*
 * PB15 --> SPI2_MOSI
 * PB14 --> SPI2_MISO
 * PB13 --> SPI2_SCLK
 * PB12 --> SPI2_NSS
 * ALT function mode : 5
 */
#include "stm32f401xx.h"
#include <string.h>
#define LOW					0
#define BTN_PRESSED 		LOW
void delay (void)
{
	for(uint32_t i=0; i<500000/2;i++);
}


void SPI2_GPIOInits (void)
{
	GPIO_Handle_t SPIPins;
	SPIPins.pGPIOx = GPIOB;
	SPIPins.pGPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	SPIPins.pGPIO_PinConfig.GPIO_PinAltFunMode = 5;
	SPIPins.pGPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	SPIPins.pGPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	SPIPins.pGPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	//SCKL
	SPIPins.pGPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	GPIO_Init(&SPIPins);
	//MOSI
	SPIPins.pGPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;
	GPIO_Init(&SPIPins);
	//MISO
	//SPIPins.pGPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
	//GPIO_Init(&SPIPins);
	//NSS
	SPIPins.pGPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GPIO_Init(&SPIPins);
}

void SPI2_Inits(void)
{
	SPI_Handle_t SPI2handle;
	SPI2handle.pSPIx = SPI2;
	SPI2handle.SPIConfig.SPI_BusConfig = SPI_BUS_CONFIG_FD;
	SPI2handle.SPIConfig.SPI_DeviceMode = SPI_DEVICE_MODE_MASTER;
	SPI2handle.SPIConfig.SPI_SclkSpeed = SPI_SCLK_SPEED_DIV32;//Generates sclk of 2MHz
	SPI2handle.SPIConfig.SPI_DFF = SPI_DFF_8BITS;
	SPI2handle.SPIConfig.SPI_CPOL = SPI_CPOL_LOW;
	SPI2handle.SPIConfig.SPI_CPHA = SPI_CPHA_LOW;
	SPI2handle.SPIConfig.SPI_SSM = SPI_SSM_DI;//hardware slave management enabled for NSS pin

	SPI_Init(&SPI2handle);

}
void GPIO_ButtonInit (void)
{
	GPIO_Handle_t GpioBtn;
	//this is btn gpio configuration
	GpioBtn.pGPIOx = GPIOC;
	GpioBtn.pGPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	GpioBtn.pGPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GpioBtn.pGPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioBtn.pGPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_Init(&GpioBtn);
}
int main(void)
{
	GPIO_ButtonInit();
	char user_data[] = "Hello World";
	//this function is used to initialize the GPIO pins to behave as SPI2 pins
	SPI2_GPIOInits();

	//this function is used to initialize the SPI2 peripheral parameters
	SPI2_Inits();

	/*
	 * making SSOE 1 does NSS output enable
	 * The NSS pin is automatically managed by the hardware
	 * i.e when SPE = 1, NSS will be pulled to low
	 * and NSS pin will be high when SPE = 0
	 */
	SPI_SSOEConfig(SPI2, ENABLE);
	while(1)
	{
		//wait till button is pressed
		while ( GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_NO_13) )

		//to avoid button de-bouncing related issues 200ms of delay
		delay();

		//enabled the SPI2 peripheral
		SPI_PeripheralControl(SPI2, ENABLE);

		//first send length information
		uint8_t dataLen = strlen(user_data);
		SPI_SendData(SPI2, &dataLen,1);

		//to send data
		SPI_SendData(SPI2,(uint8_t *)user_data,strlen(user_data));

		//lets confirm SPI is not busy
		while (SPI_GetFlagStatus(SPI2, SPI_BUSY_FLAG));
		//disabled the SPI2 peripheral
		SPI_PeripheralControl(SPI2, DISABLE);
	}
	return 0;
}


