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

#include "task_i2c.h"

/************************************
 * EXTERN VARIABLES
 ************************************/

TaskHandle_t handle_task_i2c;

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



/************************************
 * STATIC FUNCTIONS
 ************************************/



/************************************
 * GLOBAL FUNCTIONS
 ************************************/

BaseType_t task_i2c_init()
{
	if(HAL_I2C_IsDeviceReady(&hi2c1, DISPLAY_I2C_ADDRESS, 3, 100) == HAL_OK)
	{
	  HAL_StatusTypeDef status = HAL_I2C_Master_Transmit(&hi2c1, DISPLAY_I2C_ADDRESS, init_command.command, sizeof(init_command.command), HAL_MAX_DELAY);
	  if (status == HAL_OK)
	  {
	      HAL_GPIO_WritePin(LD4_GPIO_Port, LD4_Pin, 1); // initialization acked!
	  }
  	}

	if(HAL_I2C_Master_Transmit(&hi2c1, DISPLAY_I2C_ADDRESS, init_command.command, sizeof(init_command.command), HAL_MAX_DELAY) == HAL_OK)
	{
		return pdPASS;
	}else return pdFAIL;

	return pdFAIL;
}

void task_i2c(void* pvParameters)
{
	//notification from clock task, for now, always enter it
	while(1)
	{
		HAL_GPIO_TogglePin(LD5_GPIO_Port, LD5_Pin);
		vTaskDelay(1000);
	}
}
