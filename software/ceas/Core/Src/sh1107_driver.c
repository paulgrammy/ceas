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
					    0x00,                                 // Control byte: Following bytes are commands
					    COMMAND_SET_DISPLAY_OFF,              // 0xAE
					    COMMAND_SET_DISPLAY_START_LINE, 0x00, // 0xDC, 0x00
					    COMMAND_SET_CONTRAST, 0x7F,           // 0x81, 0x7F (Mid-contrast value)
					    COMMAND_SET_SEGMENT_REMAP_DOWN,       // 0xA0
					    COMMAND_SET_OUTPUT_DIRECTION,         // 0xC0
					    COMMAND_SET_MULTIPLEX_RATIO, 0x7F,    // 0xA8, 0x7F (For 128x128 screens)
					    COMMAND_SET_DCDC_CONTROL, COMMAND_SET_CHARGE_PUMP, // 0xAD, 0x8A (Turn on internal charge pump)
					    COMMAND_SET_ENTIRE_DISPLAY_NORMAL,    // 0xA4 (Read and display pixel data from RAM)
						COMMAND_SET_DISPLAY_NORMAL,           // 0xA6 (Normal colors: 1 = pixel on, 0 = pixel off)
					    COMMAND_SET_DISPLAY_ON                // 0xAF (Activate display output)
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
