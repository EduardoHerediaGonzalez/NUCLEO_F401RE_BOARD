/**
 * Copyright © 2024 
 *
 * @file    GPIO_cfg.h
 * @note
 *        ______________      
 *        Eduardo
 *        Heredia Gonzalez
 *        Diseñador           
 *
 * @brief   GPIO_cfg 
 * @version No oficial
 *     
 */

#ifndef GPIO_cfg_H_
#define GPIO_cfg_H_

/* system headers */

/*****************************************************************************/
/* exported configuration macros */
#if defined _UNITTESTS_ || defined _SWDEVELOPMENT_
#define GPIO_nPORTA_BASE_ADDRESS_cfg	(&VMEMORY_astPort[0])
#define GPIO_nPORTB_BASE_ADDRESS_cfg	(&VMEMORY_astPort[1])
#define GPIO_nPORTC_BASE_ADDRESS_cfg	(&VMEMORY_astPort[2])
#define GPIO_nPORTD_BASE_ADDRESS_cfg	(&VMEMORY_astPort[3])
#define GPIO_nPORTE_BASE_ADDRESS_cfg	(&VMEMORY_astPort[4])
#define GPIO_nPORTH_BASE_ADDRESS_cfg	(&VMEMORY_astPort[5])
#else
#define GPIO_nPORTA_BASE_ADDRESS_cfg	(0x40020000U)
#define GPIO_nPORTB_BASE_ADDRESS_cfg	(0x40020400U)
#define GPIO_nPORTC_BASE_ADDRESS_cfg	(0x40020800U)
#define GPIO_nPORTD_BASE_ADDRESS_cfg	(0x40020C00U)
#define GPIO_nPORTE_BASE_ADDRESS_cfg	(0x40021000U)
#define GPIO_nPORTH_BASE_ADDRESS_cfg	(0x40021C00U)
#endif

/**
 * @Brief -
 *
 * @Param1 -
 * @Param2 -
 *
 * @Note -
 *
 */
#define GPIO_PORTS_ADDRESSES_TABLE_cfg	\
{	\
	(void*)GPIO_nPORTA_BASE_ADDRESS_cfg,	\
	(void*)GPIO_nPORTB_BASE_ADDRESS_cfg,	\
	(void*)GPIO_nPORTC_BASE_ADDRESS_cfg,	\
	(void*)GPIO_nPORTD_BASE_ADDRESS_cfg,	\
	(void*)GPIO_nPORTE_BASE_ADDRESS_cfg,	\
	(void*)GPIO_nPORTH_BASE_ADDRESS_cfg,	\
}

/**
 * @Brief -
 *
 * @Param1 -
 * @Param2 -
 *
 * @Note -
 *
 */
#ifdef _DEBUG_
#define GPIO_PORTA_CONFIG_TABLE_cfg	\
{	\
	/* u8Number, 			u8Mode, 					u8Speed,	u8AlternateFunction */	\
	{(uint8)GPIO_enPin0, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin1, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin2, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin3, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin4, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin5, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin6, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin7, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin8, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin9, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin10, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin11, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin12, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
}
#else
#define GPIO_PORTA_CONFIG_TABLE_cfg	\
{	\
	/* u8Number, 			u8Mode, 					u8Speed,	u8AlternateFunction */	\
	{(uint8)GPIO_enPin0, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin1, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin2, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin3, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin4, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin5, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin6, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin7, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin8, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin9, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin10, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin11, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin12, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin13, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin14, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin15, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U}	\
}
#endif

/**
 * @Brief -
 *
 * @Param1 -
 * @Param2 -
 *
 * @Note -
 *
 */
#ifdef _DEBUG_
#define GPIO_PORTB_CONFIG_TABLE_cfg	\
{	\
	/* u8Number, 			u8Mode, 					u8Speed,	u8AlternateFunction */	\
	{(uint8)GPIO_enPin0, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin1, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin2, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin5, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin6, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin7, 	(uint8)GPIO_enIn_Floating,	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin8, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin9, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin10, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin11, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin12, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin13, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin14, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin15, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U}	\
}
#else
#define GPIO_PORTB_CONFIG_TABLE_cfg	\
{	\
	/* u8Number, 			u8Mode, 					u8Speed,	u8AlternateFunction */	\
	{(uint8)GPIO_enPin0, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin1, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin2, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin3, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin4, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin5, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin6, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin7, 	(uint8)GPIO_enIn_Floating,	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin8, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin9, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin10, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin11, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin12, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin13, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin14, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin15, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U}	\
}
#endif
/**
 * @Brief -
 *
 * @Param1 -
 * @Param2 -
 *
 * @Note -
 *
 */
#define GPIO_PORTC_CONFIG_TABLE_cfg	\
{	\
	/* u8Number, 			u8Mode, 					u8Speed,	u8AlternateFunction */	\
	{(uint8)GPIO_enPin0, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin1, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin2, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin3, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin4, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin5, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin6, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin7, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin8, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin9, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin10, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin11, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin12, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin13, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin14, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin15, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U}	\
}

/**
 * @Brief -
 *
 * @Param1 -
 * @Param2 -
 *
 * @Note -
 *
 */
#define GPIO_PORTD_CONFIG_TABLE_cfg	\
{	\
	/* u8Number, 			u8Mode, 					u8Speed,	u8AlternateFunction */	\
	{(uint8)GPIO_enPin0, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin1, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin2, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin3, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin4, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin5, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin6, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin7, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin8, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin9, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin10, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin11, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin12, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin13, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin14, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin15, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U}	\
}

/**
 * @Brief -
 *
 * @Param1 -
 * @Param2 -
 *
 * @Note -
 *
 */
#define GPIO_PORTE_CONFIG_TABLE_cfg	\
{	\
	/* u8Number, 			u8Mode, 					u8Speed,	u8AlternateFunction */	\
	{(uint8)GPIO_enPin0, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin1, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin2, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin3, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin4, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin5, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin6, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin7, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin8, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin9, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin10, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin11, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin12, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin13, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin14, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin15, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U}	\
}

/**
 * @Brief -
 *
 * @Param1 -
 * @Param2 -
 *
 * @Note -
 *
*/
#define GPIO_PORTH_CONFIG_TABLE_cfg	\
{	\
	/* u8Number, 			u8Mode, 					u8Speed,	u8AlternateFunction */	\
	{(uint8)GPIO_enPin0, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin1, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin2, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin3, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin4, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin5, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin6, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin7, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin8, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin9, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin10, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin11, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin12, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin13, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin14, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U},	\
	{(uint8)GPIO_enPin15, 	(uint8)GPIO_enIn_Floating, 	(uint8)0U, 	(uint8)0U}	\
}

/**
 * @Brief -
 *
 * @Param1 -
 * @Param2 -
 *
 * @Note -
 *
 */
#define GPIO_PORTS_CONFIG_TABLE_cfg	\
{	\
	/* astPin */	\
	{GPIO_PORTA_CONFIG_TABLE_cfg},	\
	{GPIO_PORTB_CONFIG_TABLE_cfg},	\
	{GPIO_PORTC_CONFIG_TABLE_cfg},	\
	{GPIO_PORTD_CONFIG_TABLE_cfg},	\
	{GPIO_PORTE_CONFIG_TABLE_cfg},	\
	{GPIO_PORTH_CONFIG_TABLE_cfg}	\
}

#endif /* GPIO_cfg_H_ */
