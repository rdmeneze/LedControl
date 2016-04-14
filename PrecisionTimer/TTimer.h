/***
 *  \file ttimer.h
 *  \brief  definitions for the TTimer operations
 *  \author Rafael Dias <rdmeneze@gmail.com>
 *  \date    jul/2014
 */

#ifndef __TTIMER_H__
#define __TTIMER_H__

#include "defs.h"

#define TTIMER_1MS_INTERVAL     (1000U)
#define TTIMER_1SEC_INTERVAL    (1000*TTIMER_1MS_INTERVAL)
#define TTIMER_1MIN_INTERVAL    (60*TTIMER_1SEC_INTERVAL)

/**
 * @typedef callbacktimer_func 
 * @brief   declare a data type for callback functions to TTimer 
 */
typedef uint32_t (*callbacktimer_func)( void* );

/**
 * @enum  TimerType
 * @brief definition of the types of timers
 */
typedef enum
{
    TimerOneShot = 0,
    TimerPeriodic
} TimerType;

/**
 *  \brief      configure the time out of the timer
 *  \param[in]  dwTimeMicro the timer timeout value in us
 */
void TTimerCfgTimeOut( DWORD dwTimeMicro );

/**
 *  \brief      get the time base value
 *  \return     time base value
 */
DWORD TTimerGetTimeBase( void );

/**
 *   \brief      register a function callback timer
 *   \param[in]  delay delay to call the callback funtion. Delay units us
 *   \param[in]  type function timer type
 *   \param[in]  callback_func function timer callback
 *   \param[in]  lpParam function timer param
 *   \param[out] cbHandle function timer handle
 *   \return callback function creation success
 */
DWORD TTimerRegisterCallBack( DWORD dwDelay, TimerType type, callbacktimer_func callback_func, void* lpParam, DWORD* cbHandle );

/**
 *  \brief  unregister a callback timer
 *  \param  dwHandle handle of the timer
 *  \return success or fail
 */
DWORD TTimerUnregisterCallBack( DWORD dwHandle );

/**
 *  \brief  start a software timer
 *  \param[in]  dwHandle handle of the timer to start
 *  \return     success or fail
 */
DWORD TTimerStart( DWORD dwHandle );

/**
 *  \brief  stop a software timer
 *  \param[in]  dwHandle handle of the timer to stop
 *  \return     success or fail
 */
DWORD TTimerStop( DWORD dwHandle );

/** 
 *  \brief  restart the timer
 *  \param[in]  dwHandle handle of the timer to stop
 *  \return     success or fail
 */
DWORD TTimerRestart( DWORD dwHandle );

DWORD TTimerSetTime( DWORD dwHandle, DWORD dwNewDelay );

#endif
