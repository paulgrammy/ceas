/**
 ********************************************************************************
 * @file    sh1107_driver.c
 * @author  paulgrammy
 * @brief	driver for the SH1107 Display IC
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include "sh1107_driver.h"
/************************************
 * EXTERN VARIABLES
 ************************************/
display_command_t current_command = {
				.command = {COMMAND_START, 0x00},
				.command_size = 2,
};

display_data_t current_data = {
				.data = {DATA_START, 0x00},
				.data_size = 2,
};


display_command_t test_command = {
				.command = {
						0x00,
						COMMAND_SET_DISPLAY_OFF,
						COMMAND_SET_DISPLAY_ON,
						COMMAND_SET_CONTRAST, 0x0A,
						COMMAND_SET_ENTIRE_DISPLAY_ON
				},
				.command_size = 6
		};

display_command_t init_command = {
				.command = {
						COMMAND_START,
					    0x80, 0xAE,  // Display OFF (good practice before changing settings)
//					    0x80, 0x81,  // Command: Set Contrast Control
//					    0x80, 0x7F,  // Parameter: Mid-level contrast brightness
//					    0x80, 0xA5,  // Command: Entire Display ON (Forces all pixels ON, bypassing RAM contents)
//					    0x80, 0xAF   // Command: Display ON
						COMMAND_SET_DISPLAY_START_LINE, 0x00,
						COMMAND_SET_MEMORY_ADDRESSING_MODE, 0x00,
						COMMAND_SET_CONTRAST, 0x70,
						COMMAND_SET_SEGMENT_REMAP_DOWN,
						COMMAND_SET_OUTPUT_DIRECTION,
						COMMAND_SET_MULTIPLEX_RATIO, 0x7F,
						COMMAND_SET_DISPLAY_OFFSET, 0x00,
						COMMAND_SET_FREQUENY_DIVIDER, 0x50,
						COMMAND_SET_DISorPRE_CHARGE_PERIOD, 0x22,
						COMMAND_SET_VCOM_LEVEL, 0x35,
						COMMAND_SET_DCDC_CONTROL,
						COMMAND_SET_CHARGE_PUMP,
						COMMAND_SET_DISPLAY_NORMAL,
						COMMAND_SET_DISPLAY_ON,
					},
				.command_size = 11
		};
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
