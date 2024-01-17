/**
 * Copyright © 2024 
 *
 * @file    STM32F401_startup.c
 * @note
 *        ______________      
 *        Eduardo
 *        Heredia Gonzalez
 *        Diseñador           
 *
 * @brief   STM32F401_startup 
 * @version No oficial
 *     
 */
/* system headers */
#include <stdint.h>

/* used headers */

/* own headers */

/*[EXPORTED]****************************************************************************/

/* public_variables */
extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

/*[INTERNAL]****************************************************************************/

/* internal__pre-processor macros */
#define SRAM_START_ADDRESS	(0x20000000U)
#define SRAM_SIZE			(96*1024)	// 96KB
#define SRAM_END_ADDRESS	((SRAM_START_ADDRESS) + (SRAM_SIZE))
#define STACK_START_ADDRESS	(SRAM_END_ADDRESS)

/* internal__types */

/* private__variables */

/* private__functions */

/* public_functions */
int main(void);
void Reset_Handler(void);

void NMI_Handler(void) 					__attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler(void) 			__attribute__ ((weak, alias("Default_Handler")));
void MemManage_Handler(void) 			__attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler(void) 			__attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler(void) 			__attribute__ ((weak, alias("Default_Handler")));
void SVCall_Handler(void) 				__attribute__ ((weak, alias("Default_Handler")));
void DebugMonitor_Handler(void) 		__attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler(void) 				__attribute__ ((weak, alias("Default_Handler")));
void Systick_Handler(void) 				__attribute__ ((weak, alias("Default_Handler")));
void WWDG_Handler(void) 				__attribute__ ((weak, alias("Default_Handler")));
void EXTI16_PVD_Handler(void) 			__attribute__ ((weak, alias("Default_Handler")));
void EXTI21_TAMP_STAMP_Handler(void)	__attribute__ ((weak, alias("Default_Handler")));
void EXTI22_RTC_WKUP_Handler(void) 		__attribute__ ((weak, alias("Default_Handler")));
void FLASH_Handler(void) 				__attribute__ ((weak, alias("Default_Handler")));
void RCC_Handler(void) 					__attribute__ ((weak, alias("Default_Handler")));
void EXTI0_Handler(void) 				__attribute__ ((weak, alias("Default_Handler")));
void EXTI1_Handler(void) 				__attribute__ ((weak, alias("Default_Handler")));
void EXTI2_Handler(void) 				__attribute__ ((weak, alias("Default_Handler")));
void EXTI3_Handler(void) 				__attribute__ ((weak, alias("Default_Handler")));
void EXTI4_Handler(void) 				__attribute__ ((weak, alias("Default_Handler")));
void DMA1_STREAM0_Handler(void) 		__attribute__ ((weak, alias("Default_Handler")));
void DMA1_STREAM1_Handler(void) 		__attribute__ ((weak, alias("Default_Handler")));
void DMA1_STREAM2_Handler(void) 		__attribute__ ((weak, alias("Default_Handler")));
void DMA1_STREAM3_Handler(void) 		__attribute__ ((weak, alias("Default_Handler")));
void DMA1_STREAM4_Handler(void) 		__attribute__ ((weak, alias("Default_Handler")));
void DMA1_STREAM5_Handler(void) 		__attribute__ ((weak, alias("Default_Handler")));
void DMA1_STREAM6_Handler(void) 		__attribute__ ((weak, alias("Default_Handler")));
void ADC_Handler(void) 					__attribute__ ((weak, alias("Default_Handler")));
void EXTI9_5_Handler(void) 				__attribute__ ((weak, alias("Default_Handler")));
void TIM1_BRK_TIM9_Handler(void) 		__attribute__ ((weak, alias("Default_Handler")));
void TIM1_UP_TIM10_Handler(void) 		__attribute__ ((weak, alias("Default_Handler")));
void TIM1_TRG_COM_TIM11_Handler(void) 	__attribute__ ((weak, alias("Default_Handler")));
void TIM1_CC_Handler(void) 				__attribute__ ((weak, alias("Default_Handler")));
void TIM2_Handler(void) 				__attribute__ ((weak, alias("Default_Handler")));
void TIM3_Handler(void) 				__attribute__ ((weak, alias("Default_Handler")));
void TIM4_Handler(void) 				__attribute__ ((weak, alias("Default_Handler")));
void I2C1_EV_Handler(void) 				__attribute__ ((weak, alias("Default_Handler")));
void I2C1_ER_Handler(void) 				__attribute__ ((weak, alias("Default_Handler")));
void I2C2_EV_Handler(void) 				__attribute__ ((weak, alias("Default_Handler")));
void I2C2_ER_Handler(void) 				__attribute__ ((weak, alias("Default_Handler")));
void SPI1_Handler(void) 				__attribute__ ((weak, alias("Default_Handler")));
void SPI2_Handler(void) 				__attribute__ ((weak, alias("Default_Handler")));
void USART1_Handler(void) 				__attribute__ ((weak, alias("Default_Handler")));
void USART2_Handler(void) 				__attribute__ ((weak, alias("Default_Handler")));
void EXTI15_10_Handler(void) 			__attribute__ ((weak, alias("Default_Handler")));
void EXTI17_RTC_ALARM_Handler(void) 	__attribute__ ((weak, alias("Default_Handler")));
void EXTI18_OTG_FS_WKUP_Handler(void) 	__attribute__ ((weak, alias("Default_Handler")));
void DMA1_STREAM7_Handler(void) 		__attribute__ ((weak, alias("Default_Handler")));
void SDIO_Handler(void) 				__attribute__ ((weak, alias("Default_Handler")));
void TIM5_Handler(void) 				__attribute__ ((weak, alias("Default_Handler")));
void SPI3_Handler(void) 				__attribute__ ((weak, alias("Default_Handler")));
void DMA2_STREAM0_Handler(void) 		__attribute__ ((weak, alias("Default_Handler")));
void DMA2_STREAM1_Handler(void) 		__attribute__ ((weak, alias("Default_Handler")));
void DMA2_STREAM2_Handler(void) 		__attribute__ ((weak, alias("Default_Handler")));
void DMA2_STREAM3_Handler(void) 		__attribute__ ((weak, alias("Default_Handler")));
void DMA2_STREAM4_Handler(void) 		__attribute__ ((weak, alias("Default_Handler")));
void OTG_FS_Handler(void) 				__attribute__ ((weak, alias("Default_Handler")));
void DMA2_STREAM5_Handler(void) 		__attribute__ ((weak, alias("Default_Handler")));
void DMA2_STREAM6_Handler(void) 		__attribute__ ((weak, alias("Default_Handler")));
void DMA2_STREAM7_Handler(void) 		__attribute__ ((weak, alias("Default_Handler")));
void USART6_Handler(void) 				__attribute__ ((weak, alias("Default_Handler")));
void I2C3_EV_Handler(void) 				__attribute__ ((weak, alias("Default_Handler")));
void I2C3_ER_Handler(void) 				__attribute__ ((weak, alias("Default_Handler")));
void FPU_Handler(void) 					__attribute__ ((weak, alias("Default_Handler")));
void SPI4_Handler(void) 				__attribute__ ((weak, alias("Default_Handler")));


uint32_t vector_table[] __attribute__ ((section (".isr_vector"))) = {
		STACK_START_ADDRESS,
		(uint32_t)&Reset_Handler,
		(uint32_t)&NMI_Handler,
		(uint32_t)&HardFault_Handler,
		(uint32_t)&MemManage_Handler,
		(uint32_t)&BusFault_Handler,
		(uint32_t)&UsageFault_Handler,
		(uint32_t)0U,
		(uint32_t)0U,
		(uint32_t)0U,
		(uint32_t)0U,
		(uint32_t)&SVCall_Handler,
		(uint32_t)&DebugMonitor_Handler,
		(uint32_t)0U,
		(uint32_t)&PendSV_Handler,
		(uint32_t)&Systick_Handler,
		(uint32_t)&WWDG_Handler,
		(uint32_t)&EXTI16_PVD_Handler,
		(uint32_t)&EXTI21_TAMP_STAMP_Handler,
		(uint32_t)&EXTI22_RTC_WKUP_Handler,
		(uint32_t)&FLASH_Handler,
		(uint32_t)&RCC_Handler,
		(uint32_t)&EXTI0_Handler,
		(uint32_t)&EXTI1_Handler,
		(uint32_t)&EXTI2_Handler,
		(uint32_t)&EXTI3_Handler,
		(uint32_t)&EXTI4_Handler,
		(uint32_t)&DMA1_STREAM0_Handler,
		(uint32_t)&DMA1_STREAM1_Handler,
		(uint32_t)&DMA1_STREAM2_Handler,
		(uint32_t)&DMA1_STREAM3_Handler,
		(uint32_t)&DMA1_STREAM4_Handler,
		(uint32_t)&DMA1_STREAM5_Handler,
		(uint32_t)&DMA1_STREAM6_Handler,
		(uint32_t)&ADC_Handler,
		(uint32_t)0U,
		(uint32_t)0U,
		(uint32_t)0U,
		(uint32_t)0U,
		(uint32_t)&EXTI9_5_Handler,
		(uint32_t)&TIM1_BRK_TIM9_Handler,
		(uint32_t)&TIM1_UP_TIM10_Handler,
		(uint32_t)&TIM1_TRG_COM_TIM11_Handler,
		(uint32_t)&TIM1_CC_Handler,
		(uint32_t)&TIM2_Handler,
		(uint32_t)&TIM3_Handler,
		(uint32_t)&TIM4_Handler,
		(uint32_t)&I2C1_EV_Handler,
		(uint32_t)&I2C1_ER_Handler,
		(uint32_t)&I2C2_EV_Handler,
		(uint32_t)&I2C2_ER_Handler,
		(uint32_t)&SPI1_Handler,
		(uint32_t)&SPI2_Handler,
		(uint32_t)&USART1_Handler,
		(uint32_t)&USART2_Handler,
		(uint32_t)0U,
		(uint32_t)&EXTI15_10_Handler,
		(uint32_t)&EXTI17_RTC_ALARM_Handler,
		(uint32_t)&EXTI18_OTG_FS_WKUP_Handler,
		(uint32_t)0U,
		(uint32_t)0U,
		(uint32_t)0U,
		(uint32_t)0U,
		(uint32_t)&DMA1_STREAM7_Handler,
		(uint32_t)0U,
		(uint32_t)&SDIO_Handler,
		(uint32_t)&TIM5_Handler,
		(uint32_t)&SPI3_Handler,
		(uint32_t)0U,
		(uint32_t)0U,
		(uint32_t)0U,
		(uint32_t)0U,
		(uint32_t)&DMA2_STREAM0_Handler,
		(uint32_t)&DMA2_STREAM1_Handler,
		(uint32_t)&DMA2_STREAM2_Handler,
		(uint32_t)&DMA2_STREAM3_Handler,
		(uint32_t)&DMA2_STREAM4_Handler,
		(uint32_t)0U,
		(uint32_t)0U,
		(uint32_t)0U,
		(uint32_t)0U,
		(uint32_t)0U,
		(uint32_t)0U,
		(uint32_t)&OTG_FS_Handler,
		(uint32_t)&DMA2_STREAM5_Handler,
		(uint32_t)&DMA2_STREAM6_Handler,
		(uint32_t)&DMA2_STREAM7_Handler,
		(uint32_t)&USART6_Handler,
		(uint32_t)&I2C3_EV_Handler,
		(uint32_t)&I2C3_ER_Handler,
		(uint32_t)0U,
		(uint32_t)0U,
		(uint32_t)0U,
		(uint32_t)0U,
		(uint32_t)0U,
		(uint32_t)0U,
		(uint32_t)0U,
		(uint32_t)&FPU_Handler,
		(uint32_t)0U,
		(uint32_t)0U,
		(uint32_t)&SPI4_Handler
};

void Reset_Handler(void)
{
	uint8_t *pSrc = (uint8_t*)&_etext;
	uint8_t *pDst = (uint8_t*)&_sdata;
	uint32_t u32DataSectionSize = (uint32_t)(&_edata - &_sdata);
	uint32_t u32BssSectionSize = (uint32_t)(&_ebss - &_sbss);

	// Copy .data section to SRAM.

	for(uint32_t u32DataSectionCounter = (uint32_t)0U; u32DataSectionCounter < u32DataSectionSize; u32DataSectionCounter++)
	{
		*pDst++ = *pSrc++;
	}

	// Initialize the .bss section to zero in SRAM.
	pDst = (uint8_t*)&_sbss;

	for(uint32_t u32BssSectionCounter = (uint32_t)0U; u32BssSectionCounter < u32BssSectionSize; u32BssSectionCounter++)
	{
		*pDst++ = (uint8_t)0U;
	}

	// Call main function.
	main();
}

void Default_Handler(void)
{
	while(1);
}


/* EOF */
