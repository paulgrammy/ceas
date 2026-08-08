/**
 ********************************************************************************
 * @file    ${file_name}
 * @author  ${user}
 * @date    ${date}
 * @brief
 ********************************************************************************
 */

#ifndef TASK_I2C_H
#define TASK_I2C_H

/************************************
 * INCLUDES
 ************************************/

#include "i2c.h"
#include "sh1107_driver.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

/************************************
 * MACROS AND DEFINES
 ************************************/



/************************************
 * TYPEDEFS
 ************************************/



/************************************
 * GLOBAL VARIABLES
 ************************************/

extern TaskHandle_t handle_task_i2c;

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/
BaseType_t task_i2c_init();
extern void clear_screen(void);
void task_i2c(void* pvParameters);
void write_command(uint8_t buffer);

#endif //TASK_I2C_H
