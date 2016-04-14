/**
 *  @file   
 *  @brief  
 *  @author 
 *  @date   
 */

// https://github.com/wayoda/LedControl/blob/master/src/LedControl.h

#ifndef _LEDCTRL_H_
#define _LEDCTRL_H_

#include "defs.h"

typedef struct 
{
    uint32_t xSsiDev;
    uint32_t dwCS;
}
LedControl;

/* 
 * Create a new controler 
 * Params :
 * dataPin		pin on the Arduino where data gets shifted out
 * clockPin		pin for the clock
 * csPin		pin for selecting the device 
 * numDevices	maximum number of devices that can be controled
 */
uint32_t LedCtrlInit(int dataPin, int clkPin, int csPin, int numDevices);

/*
 * Gets the number of devices attached to this LedControl.
 * Returns :
 * int	the number of devices on this LedControl
 */
uint32_t LedCtrlGetDeviceCount(void);

/* 
 * Set the shutdown (power saving) mode for the device
 * Params :
 * addr	The address of the display to control
 * status	If true the device goes into power-down mode. Set to false
 *		for normal operation.
 */
void LedCtrlShutdown(int addr, uint8_t status);

/* 
 * Set the number of digits (or rows) to be displayed.
 * See datasheet for sideeffects of the scanlimit on the brightness
 * of the display.
 * Params :
 * addr	address of the display to control
 * limit	number of digits to be displayed (1..8)
 */
void LedCtrlSetScanLimit(int addr, int limit);

/* 
 * Set the brightness of the display.
 * Params:
 * addr		the address of the display to control
 * intensity	the brightness of the display. (0..15)
 */
void LedCtrlSetIntensity(int addr, int intensity);

/* 
 * Switch all Leds on the display off. 
 * Params:
 * addr	address of the display to control
 */
void LedCtrlClearDisplay(int addr);

/* 
 * Set the status of a single Led.
 * Params :
 * addr	address of the display 
 * row	the row of the Led (0..7)
 * col	the column of the Led (0..7)
 * state	If true the led is switched on, 
 *		if false it is switched off
 */
void LedCtrlSetLed(int addr, int row, int col, uint8_t state);

/* 
 * Set all 8 Led's in a row to a new state
 * Params:
 * addr	address of the display
 * row	row which is to be set (0..7)
 * value	each bit set to 1 will light up the
 *		corresponding Led.
 */
void LedCtrlSetRow(int addr, int row, uint8_t value);

/* 
 * Set all 8 Led's in a column to a new state
 * Params:
 * addr	address of the display
 * col	column which is to be set (0..7)
 * value	each bit set to 1 will light up the
 *		corresponding Led.
 */
void LedCtrlSetColumn(int addr, int col, uint8_t value);

/* 
 * Display a hexadecimal digit on a 7-Segment Display
 * Params:
 * addr	address of the display
 * digit	the position of the digit on the display (0..7)
 * value	the value to be displayed. (0x00..0x0F)
 * dp	sets the decimal point.
 */
void LedCtrlSetDigit(int addr, int digit, uint8_t value, uint8_t dp);

/* 
 * Display a character on a 7-Segment display.
 * There are only a few characters that make sense here :
 *	'0','1','2','3','4','5','6','7','8','9','0',
 *  'A','b','c','d','E','F','H','L','P',
 *  '.','-','_',' ' 
 * Params:
 * addr	address of the display
 * digit	the position of the character on the display (0..7)
 * value	the character to be displayed. 
 * dp	sets the decimal point.
 */
void LedCtrlSetChar(int addr, int digit, char value, uint8_t dp);

#endif
