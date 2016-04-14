/**
 *  @file   BoardLeds.h
 *  @brief  define the interface of board user leds
 *  @author Rafael Dias <rdmeneze@gmail.com>
 *  @date   Aug/2015
 */

#ifndef BOARD_LEDS_H
#define BOARD_LEDS_H

#include "defs.h"

typedef enum
{
    USR_LED0, 
    USR_LED1, 
    USR_LED2, 
    USR_LED3
} UsrLedType;    
    
/**
 *  @brief  initialize the leds peripherals
 *  @return status of success or fail
 */
uint32_t BrdLedsInit( void );

/**
 *  @brief  set the state of led
 *  @param[in]  led the led to change the status
 *  @param[in]  bState the new state
 *  @return     status of success or fail
 */
uint32_t BrdLedsSetState( UsrLedType led, uint8_t bState );

#endif 
