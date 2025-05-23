/*
 * stm32f401xx.h
 *
 *  Created on: Apr 17, 2025
 *      Author: Admin
 */

#ifndef INC_STM32F401XX_H_
#define INC_STM32F401XX_H_

#include <stdint.h>
#include <stddef.h>
#define __vo volatile
#define __weak __attribute__((weak))

/*****************************START:Processor Specific Details*******************************/

/*
 * ARM Cortex Mx Processor NVIC ISERx register Addresses
 */

#define NVIC_ISER0					( (__vo uint32_t*)0xE000E100)
#define NVIC_ISER1					( (__vo uint32_t*)0xE000E104)
#define NVIC_ISER2					( (__vo uint32_t*)0xE000E108)
#define NVIC_ISER3					( (__vo uint32_t*)0xE000E10C)

/*
 * ARM Cortex Mx Processor NVIC ICERx register Addresses
 */

#define NVIC_ICER0					( (__vo uint32_t *)0xE000E180)
#define NVIC_ICER1					( (__vo uint32_t *)0xE000E184)
#define NVIC_ICER2					( (__vo uint32_t *)0xE000E188)
#define NVIC_ICER3					( (__vo uint32_t *)0xE000E18C)

/*
 * ARM Cortex Mx Processor Priority Register Addresses Calculation
 */

#define NVIC_PR_BASE_ADDR			( (__vo uint32_t *)0xE000E400)

/*
 * ARM Cortex Mx Processor number of priority bits implemented in Priority Register
 */

#define NO_PR_BITS_IMPLEMENTED		4

/*
 * base addresses of Flash and Sram memory
 */

#define FLASH_BASEADDR				0x08000000U 	//flash(main memory) address
#define SRAM1_BASEADDR				0x20000000U 	//sram1 memory address
#define ROM_BASEADDR				0x1FFF0000U		//rom(system memory) address
#define SRAM 						SRAM1_BASEADDR	//main sram

/*
 * AHBx and APBx Bus peripheral base addresses
 */

#define PERIPH_BASEADDR				0x40000000U
#define APB1PERIPH_BASEADDR			PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR			0x40010000U
#define AHB1PERIPH_BASEADDR			0x40020000U
#define AHB2PERIPH_BASEADDR			0x50000000U

/*
 * Base addresses of peripherals which are hanging on AHB1 bus
 */

#define GPIOA_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR				(AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOH_BASEADDR				(AHB1PERIPH_BASEADDR + 0x1C00)
#define RCC_BASEADDR				(AHB1PERIPH_BASEADDR + 0x3800)

/*
 * Base addresses of peripherals which are hanging on APB1 bus
 */

#define I2C1_BASEADDR				(APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR				(APB1PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR				(APB1PERIPH_BASEADDR + 0x5C00)

#define USART2_BASEADDR				(APB1PERIPH_BASEADDR + 0x4400)

#define SPI2_BASEADDR				(APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR				(APB1PERIPH_BASEADDR + 0x3C00)
/*
 * Base addresses of peripherals which are hanging on APB2 bus
 */

#define EXTI_BASEADDR				(APB2PERIPH_BASEADDR + 0x3C00)

#define USART1_BASEADDR				(APB2PERIPH_BASEADDR + 0x1000)
#define USART6_BASEADDR				(APB2PERIPH_BASEADDR + 0x1400)

#define SPI1_BASEADDR				(APB2PERIPH_BASEADDR + 0x3000)

#define SYSCFG_BASEADDR				(APB2PERIPH_BASEADDR + 0x3800)

/*****************************peripheral register definition structures*******************************/

/*
 * Note: Registers of a peripheral are specific to MCU
 */
typedef struct
{
	__vo uint32_t MODER;				/*!< GPIO port mode register,					address offset:0x00			*/
	__vo uint32_t OTYPER;				/*!< GPIO port output type register,			address offset:0x04			*/
	__vo uint32_t OSPEEDR;				/*!< GPIO port output speed register,			address offset:0x08			*/
	__vo uint32_t PUPDR;				/*!< GPIO port pull-up/pull-down register,		address offset:0x0C			*/
	__vo uint32_t IDR;					/*!< GPIO port input data register,				address offset:0x10			*/
	__vo uint32_t ODR;					/*!< GPIO port output data register,			address offset:0x14			*/
	__vo uint32_t BSRR;					/*!< GPIO port bit set/reset register,			address offset:0x18			*/
	__vo uint32_t LCKR;					/*!< GPIO port configuration lock register,		address offset:0x1C			*/
	__vo uint32_t AFR[2];				/*!< AFR[0] low, AFR[1] high					address offset:0x20 & 0x24	*/

}GPIO_RegDef_t;

typedef struct
{
	__vo uint32_t CR;					/*!< RCC clock control register,				address offset:0x00			*/
	__vo uint32_t PLLCFGR;				/*!< RCC PLL configuration register,			address offset:0x04			*/
	__vo uint32_t CFGR;					/*!< RCC clock configuration register,			address offset:0x08			*/
	__vo uint32_t CIR;					/*!< RCC clock interrupt register,				address offset:0x0C			*/
	__vo uint32_t AHB1RSTR;				/*!< RCC AHB1 peripheral reset register,		address offset:0x10			*/
	__vo uint32_t AHB2RSTR;				/*!< RCC AHB2 peripheral reset register,		address offset:0x14			*/
	uint32_t	  RESERVED0[2];			/*!< Reserved,									address offset:0x18 & 0x1C	*/
	__vo uint32_t APB1RSTR;				/*!< GPIO port mode register,					address offset:0x20			*/
	__vo uint32_t APB2RSTR;				/*!< GPIO port mode register,					address offset:0x24			*/
	uint32_t	  RESERVED1[2];			/*!< Reserved,									address offset:0x28 & 0x2C	*/
	__vo uint32_t AHB1ENR;				/*!< GPIO port mode register,					address offset:0x30			*/
	__vo uint32_t AHB2ENR;				/*!< GPIO port mode register,					address offset:0x34			*/
	uint32_t	  RESERVED2[2];			/*!< Reserved,									address offset:0x38 & 0x3C	*/
	__vo uint32_t APB1ENR;				/*!< GPIO port mode register,					address offset:0x40			*/
	__vo uint32_t APB2ENR;				/*!< GPIO port mode register,					address offset:0x44			*/
	uint32_t	  RESERVED3[2];			/*!< Reserved,									address offset:0x48 & 0x4C	*/
	__vo uint32_t AHB1LPENR;			/*!< GPIO port mode register,					address offset:0x50			*/
	__vo uint32_t AHB2LPENR;			/*!< GPIO port mode register,					address offset:0x54			*/
	uint32_t	  RESERVED4[2];			/*!< Reserved,									address offset:0x58 & 0x5C	*/
	__vo uint32_t APB1LPENR;			/*!< GPIO port mode register,					address offset:0x60			*/
	__vo uint32_t APB2LPENR;			/*!< GPIO port mode register,					address offset:0x64			*/
	uint32_t	  RESERVED5[2];			/*!< Reserved,									address offset:0x68 & 0x6C	*/
	__vo uint32_t BDCR;					/*!< GPIO port mode register,					address offset:0x70			*/
	__vo uint32_t CSR;					/*!< GPIO port mode register,					address offset:0x74			*/
	uint32_t	  RESERVED6[2];			/*!< Reserved,									address offset:0x78 & 0x7C	*/
	__vo uint32_t SSCGR;				/*!< GPIO port mode register,					address offset:0x80			*/
	__vo uint32_t PLLI2SCFGR;			/*!< GPIO port mode register,					address offset:0x84			*/
	uint32_t	  RESERVED7;			/*!< Reserved,									address offset:0x88			*/
	__vo uint32_t DCKCFGR;				/*!< GPIO port mode register,					address offset:0x8C			*/
}RCC_RegDef_t;



/*
 * peripheral register definitions structure for EXTI
 */

typedef struct
{
	__vo uint32_t IMR;				/*!< Give a short description						address offset:0x00			*/
	__vo uint32_t EMR;				/*!< TODO											address offset:0x04			*/
	__vo uint32_t RTSR;				/*!< 												address offset:0x08			*/
	__vo uint32_t FTSR;				/*!< 												address offset:0x0C			*/
	__vo uint32_t SWIER;			/*!< 												address offset:0x10			*/
	__vo uint32_t PR;				/*!< 												address offset:0x14			*/

}EXTI_RegDef_t;

/*
 * peripheral register definitions structure for SPI
 */

typedef struct
{
	__vo uint32_t CR1;				/*!< Give a short description						address offset:0x00			*/
	__vo uint32_t CR2;				/*!< Give a short description						address offset:0x04			*/
	__vo uint32_t SR;				/*!< TODO											address offset:0x08			*/
	__vo uint32_t DR;				/*!< 												address offset:0x0C			*/
	__vo uint32_t CRCPR;			/*!< 												address offset:0x10			*/
	__vo uint32_t RXCRCR;			/*!< 												address offset:0x14			*/
	__vo uint32_t TXCRCR;			/*!< 												address offset:0x18			*/
	__vo uint32_t I2SCFGR;			/*!< 												address offset:0x1C			*/
	__vo uint32_t I2SPR;			/*!< 												address offset:0x20			*/
}SPI_RegDef_t;

/*
 * peripheral register definitions structure for SYSCFG
 */

typedef struct
{
	__vo uint32_t MEMRMP;			/*!< Give a short description						address offset:0x00			*/
	__vo uint32_t PMC;				/*!< TODO											address offset:0x04			*/
	__vo uint32_t EXTICR[4];		/*!< 												address offset:0x08-0x14	*/
	uint32_t RESERVED1[2];			/*!< 												address offset:0x18-0x1C	*/
	__vo uint32_t CMPCR;			/*!< 												address offset:0x14			*/
}SYSCFG_RegDef_t;

/*
 * peripheral register definitions structure for I2C
 */

typedef struct
{
	__vo uint32_t CR1;				/*!< Give a short description						address offset:0x00			*/
	__vo uint32_t CR2;				/*!< Give a short description						address offset:0x04			*/
	__vo uint32_t OAR1;				/*!< TODO											address offset:0x08			*/
	__vo uint32_t OAR2;				/*!< 												address offset:0x0C			*/
	__vo uint32_t DR;				/*!< 												address offset:0x10			*/
	__vo uint32_t SR1;				/*!< 												address offset:0x14			*/
	__vo uint32_t SR2;				/*!< 												address offset:0x18			*/
	__vo uint32_t CCR;				/*!< 												address offset:0x1C			*/
	__vo uint32_t TRISE;			/*!< 												address offset:0x20			*/
	__vo uint32_t FLTR;				/*!< 												address offset:0x24			*/
}I2C_RegDef_t;


/*
 * peripheral definitions ( Peripheral base addresses typecasted to xxx_RegDef_t)
 */

#define GPIOA 						((GPIO_RegDef_t *)GPIOA_BASEADDR)
#define GPIOB 						((GPIO_RegDef_t *)GPIOB_BASEADDR)
#define GPIOC 						((GPIO_RegDef_t *)GPIOC_BASEADDR)
#define GPIOD 						((GPIO_RegDef_t *)GPIOD_BASEADDR)
#define GPIOE 						((GPIO_RegDef_t *)GPIOE_BASEADDR)
#define GPIOH 						((GPIO_RegDef_t *)GPIOH_BASEADDR)

#define RCC							((RCC_RegDef_t *)RCC_BASEADDR)
#define EXTI						((EXTI_RegDef_t *)EXTI_BASEADDR)
#define SYSCFG						((SYSCFG_RegDef_t *)SYSCFG_BASEADDR)

#define SPI1						((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI2						((SPI_RegDef_t*)SPI2_BASEADDR)
#define SPI3						((SPI_RegDef_t*)SPI3_BASEADDR)

#define I2C1						((I2C_RegDef_t*)I2C1_BASEADDR)
#define I2C2						((I2C_RegDef_t*)I2C2_BASEADDR)
#define I2C3						((I2C_RegDef_t*)I2C3_BASEADDR)


/*
 * Clock Enable Macros for GPIOx peripherals
 */

#define GPIOA_PCLK_EN()				(RCC->AHB1ENR |= (1<<0))
#define GPIOB_PCLK_EN()				(RCC->AHB1ENR |= (1<<1))
#define GPIOC_PCLK_EN()				(RCC->AHB1ENR |= (1<<2))
#define GPIOD_PCLK_EN()				(RCC->AHB1ENR |= (1<<3))
#define GPIOE_PCLK_EN()				(RCC->AHB1ENR |= (1<<4))
#define GPIOH_PCLK_EN()				(RCC->AHB1ENR |= (1<<7))

/*
 * Clock Enable Macros for I2Cx peripherals
 */

#define I2C1_PCLK_EN()				(RCC->APB1ENR |= (1<<21))
#define I2C2_PCLK_EN()				(RCC->APB1ENR |= (1<<22))
#define I2C3_PCLK_EN()				(RCC->APB1ENR |= (1<<23))

/*
 * Clock Enable Macros for SPIx peripherals
 */

#define SPI1_PCLK_EN()				(RCC->APB2ENR |= (1<<12))
#define SPI2_PCLK_EN()				(RCC->APB1ENR |= (1<<14))
#define SPI3_PCLK_EN()				(RCC->APB1ENR |= (1<<15))

/*
 * Clock Enable Macros for USARTx peripherals
 */

#define USART1_PCLK_EN()			(RCC->APB2ENR |=(1<<4))
#define USART2_PCLK_EN()			(RCC->APB1ENR |=(1<<17))
#define USART6_PCLK_EN()			(RCC->APB2ENR |=(1<<5))

/*
 * Clock Enable Macros for SYSCFG peripherals
 */

#define SYSCFG_PCLK_EN()			(RCC->APB2ENR |=(1<<14))

/*
 * Clock Disable Macros for GPIOx peripherals
 */

#define GPIOA_PCLK_DI()				(RCC->AHB1ENR &= ~(1<<0))
#define GPIOB_PCLK_DI()				(RCC->AHB1ENR &= ~(1<<1))
#define GPIOC_PCLK_DI()				(RCC->AHB1ENR &= ~(1<<2))
#define GPIOD_PCLK_DI()				(RCC->AHB1ENR &= ~(1<<3))
#define GPIOE_PCLK_DI()				(RCC->AHB1ENR &= ~(1<<4))
#define GPIOH_PCLK_DI()				(RCC->AHB1ENR &= ~(1<<7))

/*
 * Clock Disable Macros for I2Cx peripherals
 */

#define I2C1_PCLK_DI()				(RCC->APB1ENR &= ~(1<<21))
#define I2C2_PCLK_DI()				(RCC->APB1ENR &= ~(1<<22))
#define I2C3_PCLK_DI()				(RCC->APB1ENR &= ~(1<<23))

/*
 * Clock Disable Macros for SPIx peripherals
 */

#define SPI1_PCLK_DI()				(RCC->APB2ENR &= ~(1<<12))
#define SPI2_PCLK_DI()				(RCC->APB1ENR &= ~(1<<14))
#define SPI3_PCLK_DI()				(RCC->APB1ENR &= ~(1<<15))

/*
 * Clock Disable Macros for USARTx peripherals
 */

#define USART1_PCLK_DI()			(RCC->APB2ENR &= ~(1<<4))
#define USART2_PCLK_DI()			(RCC->APB1ENR &= ~(1<<17))
#define USART6_PCLK_DI()			(RCC->APB2ENR &= ~(1<<5))

/*
 * Clock Disable Macros for SYSCFG peripherals
 */

#define SYSCFG_PCLK_DI()			(RCC->APB2ENR &= ~(1<<14))

/*
 * Macros to reset GPIOx peripherals
 */
#define GPIOA_REG_RESET()			do{(RCC->AHB1RSTR |= (1<<0)); (RCC->AHB1RSTR &= ~(1<<0)); } while (0)
#define GPIOB_REG_RESET()			do{(RCC->AHB1RSTR |= (1<<1)); (RCC->AHB1RSTR &= ~(1<<1)); } while (0)
#define GPIOC_REG_RESET()			do{(RCC->AHB1RSTR |= (1<<2)); (RCC->AHB1RSTR &= ~(1<<2)); } while (0)
#define GPIOD_REG_RESET()			do{(RCC->AHB1RSTR |= (1<<3)); (RCC->AHB1RSTR &= ~(1<<3)); } while (0)
#define GPIOE_REG_RESET()			do{(RCC->AHB1RSTR |= (1<<4)); (RCC->AHB1RSTR &= ~(1<<4)); } while (0)
#define GPIOH_REG_RESET()			do{(RCC->AHB1RSTR |= (1<<7)); (RCC->AHB1RSTR &= ~(1<<7)); } while (0)

/*
 * Macros to reset SPIx peripherals
 */
#define SPI1_REG_RESET()			do{(RCC->APB2RSTR |= (1<<12)); (RCC->APB2RSTR &= ~(1<<12)); } while (0)
#define SPI2_REG_RESET()			do{(RCC->APB1RSTR |= (1<<14)); (RCC->APB1RSTR &= ~(1<<14)); } while (0)
#define SPI3_REG_RESET()			do{(RCC->APB1RSTR |= (1<<15)); (RCC->APB1RSTR &= ~(1<<15)); } while (0)

/*
 * Macros to reset I2Cx peripherals
 */

#define I2C1_REG_RESET()			do{(RCC->APB1RSTR |= (1<<21)); (RCC->APB1RSTR &= ~(1<<21)); } while (0)
#define I2C2_REG_RESET()			do{(RCC->APB1RSTR |= (1<<22)); (RCC->APB1RSTR &= ~(1<<22)); } while (0)
#define I2C3_REG_RESET()			do{(RCC->APB1RSTR |= (1<<23)); (RCC->APB1RSTR &= ~(1<<23)); } while (0)
/*
 * return port code for given GPIOx base address
 */

#define GPIO_BASEADDR_TO_CODE(x)		((x==GPIOA) ? 0 :\
										 (x==GPIOB) ? 1 :\
										 (x==GPIOC) ? 2 :\
										 (x==GPIOD) ? 3 :\
										 (x==GPIOE) ? 4 :\
										 (x==GPIOH) ? 7 :0)


/*
 * IRQ(Interrupt Request) Numbers of STM32F401x MCU
 * NOTE: update these macros with valid values according to your MCU
 * TODO: You may complete this list for other peripherals
 */

#define IRQ_NO_EXTI0		6
#define IRQ_NO_EXTI1		7
#define IRQ_NO_EXTI2		8
#define IRQ_NO_EXTI3		9
#define IRQ_NO_EXTI4		10
#define IRQ_NO_EXTI9_5		23
#define IRQ_NO_EXTI15_10	40

#define IRQ_NO_SPI1			35
#define IRQ_NO_SPI2			36
#define IRQ_NO_SPI3			51
#define IRQ_NO_SPI4			84
/*
 * Macros for all the possible priority levels
 */

#define NVIC_IRQ_PRI0		0
#define NVIC_IRQ_PRI1		1
#define NVIC_IRQ_PRI2		2
#define NVIC_IRQ_PRI3		3
#define NVIC_IRQ_PRI4		4
#define NVIC_IRQ_PRI5		5
#define NVIC_IRQ_PRI6		6
#define NVIC_IRQ_PRI7		7
#define NVIC_IRQ_PRI8		8
#define NVIC_IRQ_PRI9		9
#define NVIC_IRQ_PRI10		10
#define NVIC_IRQ_PRI11		11
#define NVIC_IRQ_PRI12		12
#define NVIC_IRQ_PRI13		13
#define NVIC_IRQ_PRI14		14
#define NVIC_IRQ_PRI15		15


/*****************************peripheral SPI register definition structures*******************************/



//some generic macros

#define ENABLE 				1
#define DISABLE 			0
#define SET					ENABLE
#define RESET				DISABLE
#define GPIO_PIN_SET		SET
#define GPIO_PIN_RESET		RESET
#define FLAG_RESET			RESET
#define FLAG_SET			SET

/*********************************************************************************************************
 * Bit position definitions of the SPI peripheral
 *********************************************************************************************************/
/*
 * Bit position definitions SPI_CR1
 */

#define SPI_CR1_CPHA		0
#define SPI_CR1_CPOL		1
#define SPI_CR1_MSTR		2
#define SPI_CR1_BR			3
#define SPI_CR1_SPE			6
#define SPI_CR1_LSBFIRST	7
#define SPI_CR1_SSI			8
#define SPI_CR1_SSM			9
#define SPI_CR1_RXONLY		10
#define SPI_CR1_DFF			11
#define SPI_CR1_CRCNEXT		12
#define SPI_CR1_CRCEN		13
#define SPI_CR1_BIDIOE		14
#define SPI_CR1_BIDIMODE	15

/*
 * Bit position definitions SPI_CR2
 */

#define SPI_CR2_RXDMAEN		0
#define SPI_CR2_TXDMAEN		1
#define SPI_CR2_SSOE		2
#define SPI_CR2_FRF			4
#define SPI_CR2_ERRIE		5
#define SPI_CR2_RXNEIE		6
#define SPI_CR2_TXEIE		7

/*
 * Bit position definitions SPI_SR
 */

#define SPI_SR_RXNE			0
#define SPI_SR_TXE			1
#define SPI_SR_CHSIDE		2
#define SPI_SR_UDR			3
#define SPI_SR_CRCERR		4
#define SPI_SR_MODF			5
#define SPI_SR_OVR			6
#define SPI_SR_BSY			7
#define SPI_SR_FRE			8


/*********************************************************************************************************
 * Bit position definitions of the I2C peripheral
 *********************************************************************************************************/

/*
 * Bit position definitions I2C_CR1
 */

#define I2C_CR1_PE			0
#define I2C_CR1_SMBUS		1
#define I2C_CR1_SMBTYPE		3
#define I2C_CR1_ENARP		4
#define I2C_CR1_ENPEC		5
#define I2C_CR1_ENGC		6
#define I2C_CR1_NOSTRETCH	7
#define I2C_CR1_START		8
#define I2C_CR1_STOP		9
#define I2C_CR1_ACK			10
#define I2C_CR1_POS			11
#define I2C_CR1_PEC			12
#define I2C_CR1_ALERT		13
#define I2C_CR1_SWRST		15

/*
 * Bit position definitions I2C_CR2
 */

#define I2C_CR2_FREQ		0
#define I2C_CR2_ITERREN		8
#define I2C_CR2_ITEVTEN		9
#define I2C_CR2_ITBUFEN		10
#define I2C_CR2_DMAEN		11
#define I2C_CR2_LAST		12

/*
 * Bit position definitions I2C_SR1
 */

#define I2C_SR1_SB			0
#define I2C_SR1_ADDR		1
#define I2C_SR1_BTF			2
#define I2C_SR1_ADD10		3
#define I2C_SR1_STOPF		4
#define I2C_SR1_RXNE		6
#define I2C_SR1_TXE			7
#define I2C_SR1_BERR		8
#define I2C_SR1_ARLO		9
#define I2C_SR1_AF			10
#define I2C_SR1_OVR			11
#define I2C_SR1_PECERR		12
#define I2C_SR1_TIMEOUT		14
#define I2C_SR1_SMBALERT	15

/*
 * Bit position definitions I2C_SR2
 */

#define I2C_SR2_MSL			0
#define I2C_SR2_BUSY		1
#define I2C_SR2_TRA			2
#define I2C_SR2_GENCALL		4
#define I2C_SR2_SMBDEFAULT	5
#define I2C_SR2_SMBHOST		6
#define I2C_SR2_DUALF		7
#define I2C_SR2_PEC			8

/*
 * Bit position definitions I2C_CCR
 */

#define I2C_CCR_CCR			0
#define I2C_CCR_DUTY		14
#define I2C_CCR_FS			15

#include "stm32f401xx_gpio_driver.h"
#include "stm32f401xx_spi_driver.h"
#include "stm32f401xx_i2c_driver.h"


#endif /* INC_STM32F401XX_H_ */
