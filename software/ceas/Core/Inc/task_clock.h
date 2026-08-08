/**
 ********************************************************************************
 * @file    ${file_name}
 * @author  ${user}
 * @date    ${date}
 * @brief
 ********************************************************************************
 */

#ifndef TASK_CLOCK_H
#define TASK_CLOCK_H

/************************************
 * INCLUDES
 ************************************/

#include "rtc.h"
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

extern TaskHandle_t handle_task_clock;
extern QueueHandle_t clock_second_queue;

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/
BaseType_t task_clock_init();
void task_clock(void* pvParameters);

#endif //TASK_CLOCK_H
