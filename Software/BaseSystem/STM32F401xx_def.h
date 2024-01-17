/**
 * Copyright © 2024 
 *
 * @file    STM32F401xx_def.h
 * @note
 *        ______________      
 *        Eduardo Heredia Gonzalez
 *        Diseñador           
 *
 * @brief   STM32F401xx_def 
 * @version No oficial
 *     Device Memory Map
 *     					Base Address	Size	Description
 *     					---------------------------------------------------
 *     					0x00000000		NA		Flash, system memory or SRAM depending of the BOOT pins.
 *     					0x08000000		NA		Flash memory.
 *     					0x1FFF0000		NA		System memory.
 *     					0x1FFFC000		NA		Option bytes.
 *     					0x20000000		NA		SRAM.
 *     					0x40000000		NA		APB1 bus.
 *     					0x40010000		NA		APB2 bus.
 *     					0x40020000		NA		AHB1 bus.
 *     					0x50000000		NA		AHB2 bus
 *     					0xE0000000		NA		Cortex-M4 internal peripherals.
 */

#ifndef STM32F401xx_def_H_
#define STM32F401xx_def_H_

/* system headers */
#include "stdint.h"

/* exported macros */
#define FLASH_SYS_SRAM_MEMORY_nBASE_ADDRESS			(0x00000000U)
#define FLASH_MEMORY_nBASE_ADDRESS					(0x08000000U)
#define SYSTEM_MEMORY_nBASE_ADDRESS					(0x1FFF0000U)
#define OPTION_BYTES_n_BASE_ADDRESS					(0x1FFFC000U)
#define SRAM_MEMORY_nBASE_ADDRESS					(0x20000000U)

/* Base addresses of the APBx and AHBx buses */
#define APB1_BUS_nBASE_ADDRESS						(0x40000000U)
#define APB2_BUS_nBASE_ADDRESS						(0x40010000U)
#define AHB1_BUS_nBASE_ADDRESS						(0x40020000U)
#define AHB2_BUS_nBASE_ADDRESS						(0x50000000U)

/* Base address of the CORTEX-M4 internal peripherals */
#define CORTEXM4_PERIPHERALS_nBASE_ADDRESS			(0xE0000000U)

/* Base addresses of the peripherals connected to the APB1 bus */
#define TIM2_PERIPHERAL_nBASE_ADDRESS				(0x40000000U)
#define TIM3_PERIPHERAL_nBASE_ADDRESS				(0x40000400U)
#define TIM4_PERIPHERAL_nBASE_ADDRESS				(0x40000800U)
#define TIM5_PERIPHERAL_nBASE_ADDRESS				(0x40000C00U)
#define RTC_BKP_PERIPHERAL_nBASE_ADDRESS			(0x40002800U)
#define WWDG_PERIPHERAL_nBASE_ADDRESS				(0x40002C00U)
#define IWDG_PERIPHERAL_nBASE_ADDRESS				(0x40003000U)
#define I2S2_EXT_PERIPHERAL_nBASE_ADDRESS			(0x40003400U)
#define SPI2_I2S2_PERIPHERAL_nBASE_ADDRESS			(0x40003800U)
#define SPI3_I2S3_PERIPHERAL_nBASE_ADDRESS			(0x40003C00U)
#define I2S3_EXT_PERIPHERAL_nBASE_ADDRESS			(0x40004000U)
#define USART2_PERIPHERAL_nBASE_ADDRESS				(0x40004400U)
#define I2C1_PERIPHERAL_nBASE_ADDRESS				(0x40005400U)
#define I2C2_PERIPHERAL_nBASE_ADDRESS				(0x40005800U)
#define I2C3_PERIPHERAL_nBASE_ADDRESS				(0x40005C00U)
#define PWR_PERIPHERAL_nBASE_ADDRESS				(0x40007000U)

/* Base addresses of the peripherals connected to the APB2 bus */
#define TIM1_PERIPHERAL_nBASE_ADDRESS				(0x40010000U)
#define USART1_PERIPHERAL_nBASE_ADDRESS				(0x40011000U)
#define USART6_PERIPHERAL_nBASE_ADDRESS				(0x40011400U)
#define ADC1_PERIPHERAL_nBASE_ADDRESS				(0x40012000U)
#define SDIO_PERIPHERAL_nBASE_ADDRESS				(0x40012C00U)
#define SPI1_PERIPHERAL_nBASE_ADDRESS				(0x40013000U)
#define SPI4_PERIPHERAL_nBASE_ADDRESS				(0x40013400U)
#define SYSCFG_PERIPHERAL_nBASE_ADDRESS				(0x40013800U)
#define EXTI_PERIPHERAL_nBASE_ADDRESS				(0x40013C00U)
#define TIM9_PERIPHERAL_nBASE_ADDRESS				(0x40014000U)
#define TIM10_PERIPHERAL_nBASE_ADDRESS				(0x40014400U)
#define TIM11_PERIPHERAL_nBASE_ADDRESS				(0x40014800U)

/* Base addresses of the peripherals connected to the AHB1 bus */
#define GPIOA_PERIPHERAL_nBASE_ADDRESS				(0x40020000U)
#define GPIOB_PERIPHERAL_nBASE_ADDRESS				(0x40020400U)
#define GPIOC_PERIPHERAL_nBASE_ADDRESS				(0x40020800U)
#define GPIOD_PERIPHERAL_nBASE_ADDRESS				(0x40020C00U)
#define GPIOE_PERIPHERAL_nBASE_ADDRESS				(0x40021000U)
#define GPIOH_PERIPHERAL_nBASE_ADDRESS				(0x40021C00U)
#define CRC_PERIPHERAL_nBASE_ADDRESS				(0x40023000U)
#define RCC_PERIPHERAL_nBASE_ADDRESS				(0x40023800U)
#define FLASH_INTERFACE_REGISTER_nBASE_ADDRESS		(0x40023C00U)
#define DMA1_PERIPHERAL_nBASE_ADDRESS				(0x40026000U)
#define DMA2_PERIPHERAL_nBASE_ADDRESS				(0x40026400U)

/* Base addresses of the peripherals connected to the AHB2 bus */
#define USB_OTG_FS_PERIPHERAL_nBASE_ADDRESS			(0x50000000U)

/* exported types */

#endif /* STM32F401xx_def_H_ */
