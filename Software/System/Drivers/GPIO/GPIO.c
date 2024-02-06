/**
 * Copyright © 2024 
 *
 * @file    GPIO.c
 * @note
 *        ______________      
 *        Eduardo
 *        Heredia Gonzalez
 *        Diseñador           
 *
 * @brief   GPIO 
 * @version No oficial
 *     
 */
/* system headers */
#include "PLATFORM_TYPES_def.h"
#include "STD_VALUES_def.h"

/* used headers */
#include "ASSERT_def.h"
#include "ASSERT.h"
#ifdef _SWDEVELOPMENT_
#include "VMEMORY.h"
#endif

/* own headers */
#include "GPIO_cfg.h"
#include "GPIO_def.h"
#include "GPIO.h"

/*[EXPORTED]****************************************************************************/

/* public_variables */

/*[INTERNAL]****************************************************************************/

/* internal__pre-processor macros */
#define GPIO_s_nOUTPUT_MODE_VALUE			(1U)
#define GPIO_s_nAF_MODE_VALUE				(2U)
#define GPIO_s_nANALOG_MODE_VALUE			(3U)
#define GPIO_s_nINPUT_MODE_VALUE			(3U)
#define GPIO_s_n2BITS_OFFSET				(2U)
#define GPIO_s_n4BITS_OFFSET				(4U)
#define GPIO_s_nPULL_UP_VALUE				(1U)
#define GPIO_s_nPULL_DOWN_VALUE    			(2U)
#define GPIO_s_nNO_PULLS_VALUE				(3U)
#define GPIO_s_nPUSH_PULL_VALUE				(1U)
#define GPIO_s_nOPEN_DRAIN_VALUE			(1U)
#define GPIO_s_nLOW_SPEED_VALUE				(3U)
#define GPIO_s_nALTERNATE_FUNCTION0_VALUE	(15U)
#define GPIO_s_nLOCK_BIT_SHIFT				(16U)
#define GPIO_s_nRESET_BIT_SHIFT				(16U)
#define GPIO_s_nLOCK_ALL_PINS_VALUE			(0x0000FFFFU)
/* Macros to manipulate the register of RCC module that enable the clocks of all the ports of the GPIO module.
 *  @TODO #Eduardo Heredia Gonzalez# 01/20/2024 - Remove all this macros when the RCC component is implemented. */
#if defined _UNITTESTS_ || defined _SWDEVELOPMENT_
#define RCC_s_nAHB1_ENA_REG_ADDRESS			(&VMEMORY_u32RCCEnaAHB1Reg)
#else
#define RCC_s_nAHB1_ENA_REG_ADDRESS			(0x40023830U)
#endif
#define RCC_s_nENA_ALL_GPIO_PORTS_VALUE		(0x0000009FU)
#define RCC_s_ENA_AHB1_CLKS	(	\
		*((uint32*)RCC_s_nAHB1_ENA_REG_ADDRESS) |= (uint32)RCC_s_nENA_ALL_GPIO_PORTS_VALUE	\
)

/* internal__types */
typedef struct
{
	uint32 MODER;	/* Mode reg */
	uint32 OTYPER;	/* Output type reg */
	uint32 OSPEEDR;	/* Output speed reg */
	uint32 PUPDR;	/* Pull-up/Pull-down reg */
	uint32 IDR;		/* Input data reg */
	uint32 ODR;		/* Output data reg */
	uint32 BSRR;	/* Bit set/reset reg */
	uint32 LCKR;	/* Configuration lock reg */
	uint32 AFRL;	/* Alternate function low reg */
	uint32 AFRH;	/* Alternate function high reg */
}volatile GPIO_s_tstRegisters;

/* private__variables */
static GPIO_tstPortConfig GPIO_s_astPortConfig[GPIO_enTotalOfPorts] = GPIO_PORTS_CONFIG_TABLE_cfg;
static void* GPIO_s_apvPortAddress[GPIO_enTotalOfPorts] = GPIO_PORTS_ADDRESSES_TABLE_cfg;
static GPIO_s_tstRegisters* GPIO_s_pstPortReg = (GPIO_s_tstRegisters*)NULL;

/* private__functions */
static void GPIO_s_vSetInputPull(uint8 u8PortIndex, uint8 u8PinIndex)
{
	if(GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Mode == (uint8)GPIO_enIn_PU)
	{
		GPIO_s_pstPortReg->PUPDR |= ((uint32)GPIO_s_nPULL_UP_VALUE << (GPIO_s_n2BITS_OFFSET * GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Number));
	}
	else if(GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Mode == (uint8)GPIO_enIn_PD)
	{
		GPIO_s_pstPortReg->PUPDR |= ((uint32)GPIO_s_nPULL_DOWN_VALUE << (GPIO_s_n2BITS_OFFSET * GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Number));
	}
	else
	{
		GPIO_s_pstPortReg->PUPDR &= ~(uint32)((uint32)GPIO_s_nNO_PULLS_VALUE << (GPIO_s_n2BITS_OFFSET * GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Number));
	}
}

static void GPIO_s_vSetOutputPull(uint8 u8PortIndex, uint8 u8PinIndex)
{
	if(GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Mode == (uint8)GPIO_enOut_PP_PU
	   || GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Mode == (uint8)GPIO_enOut_OD_PU)
	{
		GPIO_s_pstPortReg->PUPDR |= ((uint32)GPIO_s_nPULL_UP_VALUE << (GPIO_s_n2BITS_OFFSET * GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Number));
	}
	else if(GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Mode == (uint8)GPIO_enOut_PP_PD
			|| GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Mode == (uint8)GPIO_enOut_OD_PD)
	{
		GPIO_s_pstPortReg->PUPDR |= ((uint32)GPIO_s_nPULL_DOWN_VALUE << (GPIO_s_n2BITS_OFFSET * GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Number));
	}
	else
	{
		GPIO_s_pstPortReg->PUPDR &= ~(uint32)((uint32)GPIO_s_nNO_PULLS_VALUE << (GPIO_s_n2BITS_OFFSET * GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Number));
	}
}

static void GPIO_s_vSetAlternateFunctionPull(uint8 u8PortIndex, uint8 u8PinIndex)
{
	if(GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Mode == (uint8)GPIO_enAF_PP_PU
	   || GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Mode == (uint8)GPIO_enAF_OD_PU)
	{
		GPIO_s_pstPortReg->PUPDR |= ((uint32)GPIO_s_nPULL_UP_VALUE << (GPIO_s_n2BITS_OFFSET * GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Number));
	}
	else if(GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Mode == (uint8)GPIO_enAF_PP_PD
			|| GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Mode == (uint8)GPIO_enAF_OD_PD)
	{
		GPIO_s_pstPortReg->PUPDR |= ((uint32)GPIO_s_nPULL_DOWN_VALUE << (GPIO_s_n2BITS_OFFSET * GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Number));
	}
	else
	{
		GPIO_s_pstPortReg->PUPDR &= ~(uint32)((uint32)GPIO_s_nNO_PULLS_VALUE << (GPIO_s_n2BITS_OFFSET * GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Number));
	}
}

static void GPIO_s_vSetSpeed(uint8 u8PortIndex, uint8 u8PinIndex)
{
	if(GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Speed == (uint8)GPIO_enLowSpeed)
	{
		GPIO_s_pstPortReg->OSPEEDR &= ~(uint32)((uint32)GPIO_s_nLOW_SPEED_VALUE << (GPIO_s_n2BITS_OFFSET * GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Number));
	}
	else
	{
		GPIO_s_pstPortReg->OSPEEDR |= ((uint32)GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Speed << (GPIO_s_n2BITS_OFFSET * GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Number));
	}
}

static void GPIO_s_vSetAlternateFunction(uint8 u8PortIndex, uint8 u8PinIndex)
{
	if(GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Number <= (uint8)GPIO_enPin7)
	{
		if(GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8AlternateFunction == (uint8)GPIO_enAF0)
		{
			GPIO_s_pstPortReg->AFRL &= ~(uint32)((uint32)GPIO_s_nALTERNATE_FUNCTION0_VALUE << (GPIO_s_n4BITS_OFFSET * GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Number));
		}
		else
		{
			GPIO_s_pstPortReg->AFRL |= ((uint32)GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8AlternateFunction << (GPIO_s_n4BITS_OFFSET * GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Number));
		}
	}
	else
	{
		if(GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8AlternateFunction == (uint8)GPIO_enAF0)
		{
			GPIO_s_pstPortReg->AFRH &= ~(uint32)((uint32)GPIO_s_nALTERNATE_FUNCTION0_VALUE << (GPIO_s_n4BITS_OFFSET * GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Number));
		}
		else
		{
			GPIO_s_pstPortReg->AFRH |= ((uint32)GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8AlternateFunction << (GPIO_s_n4BITS_OFFSET * GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Number));
		}
	}
}

/* public_functions */
void GPIO_vInit(void)
{
	uint8 u8PortIndex;
	uint8 u8PinIndex;

	/* Macro to manipulate the register of RCC module that enable the clocks of all the ports of the GPIO module.
	 *  @TODO #Eduardo Heredia Gonzalez# 01/20/2024 - Replace this macros when the RCC component is implemented with the correspond interface. */
	RCC_s_ENA_AHB1_CLKS;

	for(u8PortIndex = (uint8)STD_nZERO; u8PortIndex < (uint8)GPIO_enTotalOfPorts; u8PortIndex++)
	{
		ASSERT((uint8)(GPIO_s_apvPortAddress[u8PortIndex] != (void*)NULL), (sint8)ASSERT_nNULL_POINTER);

		for(u8PinIndex = (uint8)STD_nZERO; u8PinIndex < (uint8)GPIO_enTotalOfPins; u8PinIndex++)
		{
			ASSERT((GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Number < (uint8)GPIO_enTotalOfPins), (sint8)ASSERT_nINVALID_CONFIG);
			ASSERT((GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Mode < (uint8)GPIO_enTotalOfPinModes), (sint8)ASSERT_nINVALID_CONFIG);
			ASSERT((GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Speed < (uint8)GPIO_enTotalOfPinSpeeds), (sint8)ASSERT_nINVALID_CONFIG);
			ASSERT((GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8AlternateFunction < (uint8)GPIO_enTotalOfPinAlternateFunctions), (sint8)ASSERT_nINVALID_CONFIG);

			GPIO_s_pstPortReg = (GPIO_s_tstRegisters*)GPIO_s_apvPortAddress[u8PortIndex];

			if(GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Mode <= (uint8)GPIO_enIn_PD)
			{
				GPIO_s_pstPortReg->MODER &= ~(uint32)((uint32)GPIO_s_nINPUT_MODE_VALUE << (GPIO_s_n2BITS_OFFSET * GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Number));

				GPIO_s_vSetInputPull(u8PortIndex, u8PinIndex);
			}
			else if(GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Mode <= (uint8)GPIO_enOut_OD_PD)
			{
				GPIO_s_pstPortReg->MODER |= ((uint32)GPIO_s_nOUTPUT_MODE_VALUE << (GPIO_s_n2BITS_OFFSET * GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Number));

				if(GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Mode <= (uint8)GPIO_enOut_PP_PD)
				{
					GPIO_s_pstPortReg->OTYPER &= ~(uint32)((uint32)GPIO_s_nPUSH_PULL_VALUE << GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Number);

					GPIO_s_vSetOutputPull(u8PortIndex, u8PinIndex);
				}
				else
				{
					GPIO_s_pstPortReg->OTYPER |= ((uint32)GPIO_s_nOPEN_DRAIN_VALUE << GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Number);

					GPIO_s_vSetOutputPull(u8PortIndex, u8PinIndex);
				}

				GPIO_s_vSetSpeed(u8PortIndex, u8PinIndex);
			}
			else if(GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Mode <= (uint8)GPIO_enAF_OD_PD)
			{
				GPIO_s_pstPortReg->MODER |= ((uint32)GPIO_s_nAF_MODE_VALUE << (GPIO_s_n2BITS_OFFSET * GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Number));

				if(GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Mode <= (uint8)GPIO_enAF_PP_PD)
				{
					GPIO_s_pstPortReg->OTYPER &= ~(uint32)((uint32)GPIO_s_nPUSH_PULL_VALUE << GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Number);

					GPIO_s_vSetAlternateFunctionPull(u8PortIndex, u8PinIndex);
				}
				else
				{
					GPIO_s_pstPortReg->OTYPER |= ((uint32)GPIO_s_nOPEN_DRAIN_VALUE << GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Number);

					GPIO_s_vSetAlternateFunctionPull(u8PortIndex, u8PinIndex);
				}

				GPIO_s_vSetSpeed(u8PortIndex, u8PinIndex);
				GPIO_s_vSetAlternateFunction(u8PortIndex, u8PinIndex);
			}
			else
			{
				GPIO_s_pstPortReg->MODER |= ((uint32)GPIO_s_nANALOG_MODE_VALUE << (GPIO_s_n2BITS_OFFSET * GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Number));
				GPIO_s_pstPortReg->PUPDR &= ~(uint32)((uint32)GPIO_s_nNO_PULLS_VALUE << (GPIO_s_n2BITS_OFFSET * GPIO_s_astPortConfig[u8PortIndex].astPinConfig[u8PinIndex].u8Number));
			}
		}

		GPIO_s_pstPortReg->LCKR = (uint32)GPIO_s_nLOCK_ALL_PINS_VALUE;

		/* Sequence to lock the configuration of all the pins of the port */
		GPIO_s_pstPortReg->LCKR |= ((uint32)STD_nONE << GPIO_s_nLOCK_BIT_SHIFT);
		GPIO_s_pstPortReg->LCKR &= ~(uint32)((uint32)STD_nONE << GPIO_s_nLOCK_BIT_SHIFT);
		GPIO_s_pstPortReg->LCKR |= ((uint32)STD_nONE << GPIO_s_nLOCK_BIT_SHIFT);
	}
}

uint8 GPIO_u8SetPinState(uint8 u8Port, uint8 u8Pin, uint8 u8State)
{
	uint8 u8PinState = (uint8)u8State;
	uint8 u8ReturnedValue = (uint8)STD_nUNDEFINED;
	GPIO_tstPinConfig stPinConfig = {0U};

	ASSERT((uint8)(u8Port < (uint8)GPIO_enTotalOfPorts), (sint8)ASSERT_nINVALID_ARGUMENT);
	ASSERT((uint8)(u8Pin < (uint8)GPIO_enTotalOfPins), (sint8)ASSERT_nINVALID_ARGUMENT);
	ASSERT((uint8)(u8State <= (uint8)STD_nHIGH), (sint8)ASSERT_nINVALID_ARGUMENT);

	GPIO_s_pstPortReg = (GPIO_s_tstRegisters*)GPIO_s_apvPortAddress[u8Port];
	GPIO_vGetPinConfig(u8Port, u8Pin, &stPinConfig);

	if((stPinConfig.u8Mode >= (uint8)GPIO_enOut_PP) && (stPinConfig.u8Mode <= (uint8)GPIO_enOut_OD_PD))
	{
		u8PinState = GPIO_u8GetPinState(u8Port, u8Pin);

		if(u8PinState != u8State)
		{
			if(u8State == (uint8)STD_nLOW)
			{
				GPIO_s_pstPortReg->BSRR |= ((uint32)(STD_nHIGH << (u8Pin + (uint8)GPIO_s_nRESET_BIT_SHIFT)));
			}
			else
			{
				GPIO_s_pstPortReg->BSRR |= ((uint32)(STD_nHIGH << u8Pin));
			}
		}
		else
		{
			/* Nothing to do */
		}

		u8ReturnedValue = (uint8)STD_nDEFINED;
	}
	else
	{
		/* Nothing to do */
	}

	return u8ReturnedValue;
}

uint8 GPIO_u8GetPinState(uint8 u8Port, uint8 u8Pin)
{
	uint8 u8PinState = (uint8)STD_nUNDEFINED;
	GPIO_tstPinConfig stPinConfig = {0U};

	ASSERT((uint8)(u8Port < (uint8)GPIO_enTotalOfPorts), (sint8)ASSERT_nINVALID_ARGUMENT);
	ASSERT((uint8)(u8Pin < (uint8)GPIO_enTotalOfPins), (sint8)ASSERT_nINVALID_ARGUMENT);

	GPIO_s_pstPortReg = (GPIO_s_tstRegisters*)GPIO_s_apvPortAddress[u8Port];
	GPIO_vGetPinConfig(u8Port, u8Pin, &stPinConfig);

	if(stPinConfig.u8Mode <= (uint8)GPIO_enIn_PD)
	{
		u8PinState = (uint8)((GPIO_s_pstPortReg->IDR & ((uint32)STD_nONE << u8Pin)) >> u8Pin);
	}
	else if(stPinConfig.u8Mode <= (uint8)GPIO_enOut_OD_PD)
	{
		u8PinState = (uint8)((GPIO_s_pstPortReg->ODR & ((uint32)STD_nONE << u8Pin)) >> u8Pin);
	}
	else if(stPinConfig.u8Mode <= (uint8)GPIO_enAF_OD_PD)
	{
		/* TBD */
	}
	else
	{
		/* TBD */
	}

	return u8PinState;
}

void GPIO_vGetPinConfig(uint8 u8Port, uint8 u8Pin, GPIO_tstPinConfig *pstPinConfig)
{
	ASSERT((uint8)(u8Port < (uint8)GPIO_enTotalOfPorts), (sint8)ASSERT_nINVALID_ARGUMENT);
	ASSERT((uint8)(u8Pin < (uint8)GPIO_enTotalOfPins), (sint8)ASSERT_nINVALID_ARGUMENT);
	ASSERT((uint8)(pstPinConfig != (GPIO_tstPinConfig*)NULL), (sint8)ASSERT_nNULL_POINTER);

	pstPinConfig->u8Number = GPIO_s_astPortConfig[u8Port].astPinConfig[u8Pin].u8Number;
	pstPinConfig->u8Mode = GPIO_s_astPortConfig[u8Port].astPinConfig[u8Pin].u8Mode;
	pstPinConfig->u8Speed = GPIO_s_astPortConfig[u8Port].astPinConfig[u8Pin].u8Speed;
	pstPinConfig->u8AlternateFunction = GPIO_s_astPortConfig[u8Port].astPinConfig[u8Pin].u8AlternateFunction;
}

void GPIO_vGetPortConfig(uint8 u8Port, GPIO_tstPortConfig *pstPortConfig)
{
	uint8 u8PinIndex;

	ASSERT((uint8)(u8Port < (uint8)GPIO_enTotalOfPorts), (sint8)ASSERT_nINVALID_ARGUMENT);
	ASSERT((uint8)(pstPortConfig != (GPIO_tstPortConfig*)NULL), (sint8)ASSERT_nNULL_POINTER);

	for(u8PinIndex = (uint8)STD_nZERO; u8PinIndex < (uint8)GPIO_enTotalOfPins; u8PinIndex++)
	{
		pstPortConfig->astPinConfig[u8PinIndex] = GPIO_s_astPortConfig[u8Port].astPinConfig[u8PinIndex];
	}
}

/* EOF */
