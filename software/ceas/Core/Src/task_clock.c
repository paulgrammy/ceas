/**
 ********************************************************************************
 * @file    ${file_name}
 * @author  ${user}
 * @date    ${date}
 * @brief
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/

#include "task_clock.h"
#include "task_i2c.h"

/************************************
 * EXTERN VARIABLES
 ************************************/

TaskHandle_t handle_task_clock;

extern volatile new_second_ready;
extern RTC_HandleTypeDef hrtc;

/************************************
 * PRIVATE MACROS AND DEFINES
 ************************************/



/************************************
 * PRIVATE TYPEDEFS
 ************************************/



/************************************
 * STATIC VARIABLES
 ************************************/



/************************************
 * GLOBAL VARIABLES
 ************************************/



/************************************
 * STATIC FUNCTION PROTOTYPES
 ************************************/

static uint8_t oldTime = 0;

/************************************
 * STATIC FUNCTIONS
 ************************************/



/************************************
 * GLOBAL FUNCTIONS
 ************************************/

BaseType_t task_clock_init()
{
	vTaskDelay(pdMS_TO_TICKS(10));
	return pdPASS;
}

void task_clock(void* pvParameters)
{
	RTC_TimeTypeDef sTime = {0};
	RTC_DateTypeDef sDate = {0};

	while(1)
	{
	  if(new_second_ready == 1)
	  {
		  new_second_ready = 0;

		  HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BCD);
		  HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BCD);

		  HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
	  }
		vTaskDelay(pdMS_TO_TICKS(10));
	}
}
