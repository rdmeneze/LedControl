/**
 *  @file   BoardKeys.h
 *  @brief  declare the interface to BoardKeys module
 *  @author Rafael Dias <rdmeneze@gmail.com>
 *  @date   jul/2015 
 */

#ifndef BOARDKEYS_H
#define BOARDKEYS_H

#include "defs.h"

typedef enum
{
    USR_SW1,
    USR_SW2
} UsrSwType;


/**
 *  @brief initialize the Board key engine
 *  @return 0 on success
 *  @return != 0 on error
 */
uint32_t BrdKeyInit( void );

/**
 *  @brief read the keys
 *  @return 0 none
 *  @return 1 key pressed
 */
uint32_t BrdKeyRead( UsrSwType sw );

#endif
