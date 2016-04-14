#include "util.h"
#include "ttimer.h"
#include "BoardLeds.h"
#include <driverlib/sysctl.h>
#include <driverlib/gpio.h>
#include <inc/hw_memmap.h>

/* definitions of board leds configurations  */
#ifdef DK_TM4C123G

    #define SYSCTL_PERIPH_USR_LED   SYSCTL_PERIPH_GPIOG
    #define GPIO_BASE_USR_LED       GPIO_PORTG_BASE
    #define GPIO_PIN_USR_LED        GPIO_PIN_2

#elif EK_TM4C1294XL

    #define SYSCTL_PERIPH_USR_LED1  SYSCTL_PERIPH_GPION
    #define GPIO_BASE_USR_LED1      GPIO_PORTN_BASE
    #define GPIO_PIN_USR_LED1       GPIO_PIN_1

    #define SYSCTL_PERIPH_USR_LED2  SYSCTL_PERIPH_GPION
    #define GPIO_BASE_USR_LED2      GPIO_PORTN_BASE
    #define GPIO_PIN_USR_LED2       GPIO_PIN_0

    #define SYSCTL_PERIPH_USR_LED3  SYSCTL_PERIPH_GPIOF
    #define GPIO_BASE_USR_LED3      GPIO_PORTF_BASE
    #define GPIO_PIN_USR_LED3       GPIO_PIN_4

    #define SYSCTL_PERIPH_USR_LED4  SYSCTL_PERIPH_GPIOF
    #define GPIO_BASE_USR_LED4      GPIO_PORTF_BASE
    #define GPIO_PIN_USR_LED4       GPIO_PIN_0

#endif

/* local data type definitions                         */

/**
 *  @struct STGPIOOutputConfig
 *  @brief  struct to represent the GPIO configurations
 */
struct STGpioOutputConfig
{
    DWORD dwSYSCTL;     /**< the SYSCTL value   */
    DWORD dwBase;       /**< the PortBase value */
    DWORD dwPin;        /**< the Pin value      */
};


/**********************************************************************************/

/* GPIOs struct configuration                                                     */
static const struct STGpioOutputConfig stUserLedCfg[] = 
{
#ifdef DK_TM4C123G
    [0] = 
    {
        .dwSYSCTL   = SYSCTL_PERIPH_USR_LED,
        .dwBase     = GPIO_BASE_USR_LED,
        .dwPin      = GPIO_PIN_USR_LED,
    }
#elif EK_TM4C1294XL
    [0] = 
    {
        .dwSYSCTL   = SYSCTL_PERIPH_USR_LED1,
        .dwBase     = GPIO_BASE_USR_LED1,
        .dwPin      = GPIO_PIN_USR_LED1,
    },
    [1]=
    {
        .dwSYSCTL   = SYSCTL_PERIPH_USR_LED2,
        .dwBase     = GPIO_BASE_USR_LED2,
        .dwPin      = GPIO_PIN_USR_LED2,
    },
    [2]=
    {
        .dwSYSCTL   = SYSCTL_PERIPH_USR_LED3,
        .dwBase     = GPIO_BASE_USR_LED3,
        .dwPin      = GPIO_PIN_USR_LED3,
    },
    [3]=
    {
        .dwSYSCTL   = SYSCTL_PERIPH_USR_LED4,
        .dwBase     = GPIO_BASE_USR_LED4,
        .dwPin      = GPIO_PIN_USR_LED4,
    },
#endif    
};

static uint8_t bInit = 0;

/**********************************************************************************/

uint32_t BrdLedsInit( void )
{
    uint32_t dwRet = (uint32_t)-1;
    
    if ( !bInit )
    {
		uint8_t bCounter;
        
		for ( bCounter = 0; bCounter < GET_ARRAY_LEN( stUserLedCfg ); bCounter++ )
        {
            SysCtlPeripheralEnable( stUserLedCfg[bCounter].dwSYSCTL );
            GPIOPinTypeGPIOOutput( stUserLedCfg[bCounter].dwBase, stUserLedCfg[bCounter].dwPin );
        }
        dwRet= 0;
    }
    
    return dwRet;
}

/**********************************************************************************/

uint32_t BrdLedsSetState( UsrLedType led, uint8_t bState )
{
    struct STGpioOutputConfig* p;
    uint8_t bChange = 1;

    switch( led )
    {
        case USR_LED0: 
        case USR_LED1: 
        case USR_LED2: 
        case USR_LED3:
            p = (struct STGpioOutputConfig*)&stUserLedCfg[led];
            break;
        
        default:
            bChange = 0;
    }
    
    if ( bChange )
    {    
        if ( bState & 1 )
        {
            GPIOPinWrite( p->dwBase, p->dwPin, p->dwPin );
        }
        else
        {
            GPIOPinWrite( p->dwBase, p->dwPin, ~p->dwPin );
        }
    }
    
    return !(bChange == 1);
}

/**********************************************************************************/


