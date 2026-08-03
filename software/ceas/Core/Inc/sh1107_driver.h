/**
 ********************************************************************************
 * @file    sh1107_driver.h
 * @author  paulgrammy
 * @brief	driver for the SH1107 Display IC
 ********************************************************************************
 */

#ifndef SH1107_DRIVER_H
#define SH1107_DRIVER_H

/************************************
 * INCLUDES
 ************************************/
#include <stdio.h>
#include <stdint.h>
/************************************
 * MACROS AND DEFINES
 ************************************/
#define MAX_COMMAND_SIZE 32
#define DISPLAY_I2C_ADDRESS 0x78 //actually 0x3C but shifted left by one

//Commands, see datasheet
#define COMMAND_START 0x00
#define DATA_START 0x40

#define COMMAND_SET_MEMORY_ADDRESSING_MODE	0x20

#define COMMAND_SET_CONTRAST 0x81 //contrast data from 0x00 to 0xFF

#define COMMAND_SET_SEGMENT_REMAP_DOWN 0xA0 // 0xA0 for down, 0xA1 for up
#define COMMAND_SET_SEGMENT_REMAP_UP 0xA1 // 0xA0 for down, 0xA1 for up

#define COMMAND_SET_MULTIPLEX_RATIO 0xA8 // switches multiplex mode to any multiplex ratio from 1 to 128

#define COMMAND_SET_ENTIRE_DISPLAY_NORMAL 0xA4 //selects normal display
#define COMMAND_SET_ENTIRE_DISPLAY_ON 0xA5

#define COMMAND_SET_DISPLAY_NORMAL 0xA6
#define COMMAND_SET_DISPLAY_INVERSE 0xA7

#define COMMAND_SET_DISPLAY_OFFSET 0xD3 //double byte command, specifies mapping of display start line to one of COM0-127

#define COMMAND_SET_DCDC_CONTROL 0xAD
#define COMMAND_SET_CHARGE_PUMP	0x8A

#define COMMAND_SET_DISPLAY_OFF 0xAE
#define COMMAND_SET_DISPLAY_ON 0xAF

#define COMMAND_SET_PAGE_ADDRESS 0xB0 //specifies page address to load display RAM data to, first bit is address

#define COMMAND_SET_OUTPUT_DIRECTION 0xC0

#define COMMAND_SET_FREQUENY_DIVIDER 0xD5 //first bit is divide ration, second bit is oscillator frequency

#define COMMAND_SET_DISorPRE_CHARGE_PERIOD 0xD9 //first bit is precharge, second bit is discharge

#define COMMAND_SET_VCOM_LEVEL 0xDB //set common pad output voltage

#define COMMAND_SET_DISPLAY_START_LINE 0xDC //specify RAM Display line for COM0, follow by start line with max 255

#define COMMAND_READ_MODIFY_WRITE_START 0xE0 //start read-modify-write
#define COMMAND_READ_MODIFY_WRITE_END 0xE3 //end read-modify-write
/************************************
 * TYPEDEFS
 ************************************/
typedef struct
{
	uint8_t command[MAX_COMMAND_SIZE];
	uint8_t command_size;
}display_command_t;

typedef struct
{
	uint8_t data[MAX_COMMAND_SIZE];
	uint8_t data_size;
}display_data_t;
/************************************
 * GLOBAL VARIABLES
 ************************************/
extern display_command_t current_command;
extern display_data_t current_data;

extern display_command_t init_command;
/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/

#endif //SH1107_DRIVER_H
