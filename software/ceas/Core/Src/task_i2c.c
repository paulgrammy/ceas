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

#define NUM_COLLUMNS 128

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

static void send_data(uint8_t* buffer)
{
	HAL_I2C_Master_Transmit(&hi2c1, DISPLAY_I2C_ADDRESS, buffer, sizeof(buffer), HAL_MAX_DELAY);
}

static void send_command(uint8_t buffer)
{
	current_command.command[1] = buffer;
	HAL_I2C_Master_Transmit(&hi2c1, DISPLAY_I2C_ADDRESS, current_command.command, sizeof(current_command.command), HAL_MAX_DELAY);
}

static void write_data()
{
	uint8_t buffer[NUM_COLLUMNS+1] = {0};
	buffer[0] = DATA_START;

	//modify data
	for(uint8_t page = 0; page < 16; page++)
	{
		send_command(COMMAND_SET_PAGE_ADDRESS + page);

		send_command(COMMAND_SET_LOWER_COLUMN_ADDRESS);
		send_command(COMMAND_SET_HIGHER_COLUMN_ADDRESS);

		for(uint16_t column = 1; column < 129; column++)
		{
			if((column % 2) == 0)
			{
				buffer[column] = 0xAA;
			} else buffer[column] = 0x55;
		}

		HAL_I2C_Master_Transmit(&hi2c1, DISPLAY_I2C_ADDRESS, buffer, sizeof(buffer), HAL_MAX_DELAY);
	}
}

void clear_screen()
{
	uint8_t buffer[NUM_COLLUMNS+1] = {0};
	buffer[0] = DATA_START;

	//fill the buffer with 0s
	for(int i = 1; i < 128; i++)
	{
		buffer[i] = 0;
	}

	//write 0s
	for(uint8_t page = 0; page < 16; page++)
	{
		send_command(COMMAND_SET_PAGE_ADDRESS + page);

		send_command(COMMAND_SET_LOWER_COLUMN_ADDRESS);
		send_command(COMMAND_SET_HIGHER_COLUMN_ADDRESS);

		HAL_I2C_Master_Transmit(&hi2c1, DISPLAY_I2C_ADDRESS, buffer, sizeof(buffer), HAL_MAX_DELAY);
	}

	vTaskDelay(pdMS_TO_TICKS(10));
}

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

		  send_command(0x00);
		  send_command(0x10);
	      send_command(COMMAND_SET_ENTIRE_DISPLAY_NORMAL);

	      return pdPASS;
	  }
  	}else return pdFAIL;

	return pdFAIL;
}

void task_i2c(void* pvParameters)
{
	//notification from clock task, for now, always enter it
	while(1)
	{
		write_data();
		vTaskDelay(pdMS_TO_TICKS(10));
	}
}
