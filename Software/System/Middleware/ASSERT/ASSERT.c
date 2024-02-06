/**
 * Copyright © 2024 
 *
 * @file    ASSERT.c
 * @note
 *        ______________      
 *        Eduardo
 *        Heredia Gonzalez
 *        Diseñador           
 *
 * @brief   ASSERT 
 * @version No oficial
 *     
 */
/* system headers */
#include "PLATFORM_TYPES_def.h"
#include "STD_VALUES_def.h"

/* used headers */

/* own headers */
#include "ASSERT_cfg.h"
#include "ASSERT_def.h"
#include "ASSERT.h"

/*[EXPORTED]****************************************************************************/

/* public_variables */

/*[INTERNAL]****************************************************************************/

/* internal__pre-processor macros */

/* internal__types */

/* private__variables */
static sint8 ASSERT_s_s8Error = (sint8)ASSERT_nNO_ERROR;
static uint8 ASSERT_s_u8AssertFnCnt = (uint8)STD_nZERO;

/* private__functions */

/* public_functions */
void ASSERT(uint8 u8Condition, sint8 s8Error)
{
	if(u8Condition == (uint8)STD_nZERO)
	{
		#if defined _UNITTESTS_ || defined _SWDEVELOPMENT_
		if(ASSERT_s_u8AssertFnCnt == (uint8)STD_nZERO)
		{
			ASSERT_s_s8Error = s8Error;
			ASSERT_s_u8AssertFnCnt++;
		}
		else
		{
			ASSERT_s_s8Error = (sint8)ASSERT_nNO_ERROR;
		}
		#else
		while(1);
		#endif
	}
	else
	{
		/* Nothing to do */
	}
}

/* EOF */
