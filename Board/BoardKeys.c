#include "BoardKeys.h"
#include "ttimer.h"
#include "util.h"
#include <driverlib/sysctl.h>
#include <driverlib/gpio.h>
#include <inc/hw_memmap.h>


#if     DK_TM4C123G

#elif   EK_TM4C1294XL
    #define SYSCTL_PERIPH_USR_SW1   SYSCTL_PERIPH_GPIOJ
    #define GPIO_BASE_USR_SW1       GPIO_PORTJ_BASE
    #define GPIO_PIN_USR_SW1        GPIO_PIN_0

    #define SYSCTL_PERIPH_USR_SW2   SYSCTL_PERIPH_GPIOJ
    #define GPIO_BASE_USR_SW2       GPIO_PORTJ_BASE
    #define GPIO_PIN_USR_SW2        GPIO_PIN_1
#endif

/**********************************************************************************************/

#define BUTTONS_TIME_REFRESH (5*TTIMER_1MS_INTERVAL)

/**********************************************************************************************/

/**
 *  @struct STGpioConfig
 *  @brief  struct to represent the GPIO configurations
 */
struct STGpioConfig
{
    uint32_t    dwSYSCTL;       /**< the SYSCTL value   */
    uint32_t    dwBASE;         /**< the PortBase value */
    uint32_t    dwPin;          /**< the Pin value      */
};

/**
 * @brief controls the status of the buttons
 */
struct STGpioInputStatus
{
    uint8_t     bState;
    uint8_t     bPrevState;
};

/**
 *  @struct STUserLedControl
 *  @brief  struct to represent the Led control structure
 */
//struct STUserSwitchControl
//{
//    uint32_t    dwCount;      /**< the count variable. Used to control the state of ON/OFF    */
//    uint32_t    dwID;         /**< ID of LED                                                  */
//    uint32_t    dwHandle;     /**< HANDLE of LED                                              */
//};

/**********************************************************************************************/

const struct STGpioConfig stSwitchConfig[] = 
{
    [USR_SW1] = 
    {
        .dwSYSCTL   = SYSCTL_PERIPH_USR_SW1,   
        .dwBASE     = GPIO_BASE_USR_SW1,       
        .dwPin      = GPIO_PIN_USR_SW1,        
    },
    [USR_SW2] = 
    {
        .dwSYSCTL   = SYSCTL_PERIPH_USR_SW2,   
        .dwBASE     = GPIO_BASE_USR_SW2,       
        .dwPin      = GPIO_PIN_USR_SW2,        
    }
};

struct STGpioInputStatus stSwitchStatus[] =
{
    [USR_SW1] = 
    {
        .bState     = 0,
        .bPrevState = 0,
    },
    [USR_SW2] = 
    {
        .bState     = 0,
        .bPrevState = 0,
    }    
};

static uint8_t bInit = 0;
volatile static uint8_t bBusy = 0;

/**********************************************************************************************/

uint32_t UserSwitchTask( void* pParam );

/**********************************************************************************************/

uint32_t BrdKeyInit( void )
{
    uint32_t    dwTimerHandle;
    uint32_t    dwRet = (DWORD)-1;
    
    if ( !bInit )
    {
		uint8_t     bCounter;
        
		for ( bCounter = 0; bCounter < GET_ARRAY_LEN( stSwitchConfig ); bCounter++ )
        {
            SysCtlPeripheralEnable( stSwitchConfig[bCounter].dwSYSCTL );
            GPIOPinTypeGPIOInput( stSwitchConfig[bCounter].dwBASE, stSwitchConfig[bCounter].dwPin );
            
#if     DK_TM4C123G

#elif   EK_TM4C1294XL
            //! enable the pull-up resistor of the PAD
            GPIOPadConfigSet( stSwitchConfig[bCounter].dwBASE, stSwitchConfig[bCounter].dwPin , GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU );
#endif
            
            stSwitchStatus[bCounter].bState = (GPIOPinRead( stSwitchConfig[bCounter].dwBASE, stSwitchConfig[bCounter].dwPin ) ? 0 : 1);
            stSwitchStatus[bCounter].bPrevState = stSwitchStatus[bCounter].bState;
        }
        
        dwRet = TTimerRegisterCallBack( BUTTONS_TIME_REFRESH, 
                                        TimerPeriodic, 
                                        UserSwitchTask, 
                                        stSwitchStatus, 
                                        &dwTimerHandle );
        if ( !dwRet )
        {
            TTimerStart( dwTimerHandle );
            bInit = 1;
        }
    }
    
    return dwRet;
}

/**********************************************************************************************/

uint32_t BrdKeyRead( UsrSwType sw )
{
    uint8_t bState      = 0;
    uint8_t bPrevState  = 0;
    
    while( bBusy );
    
    switch( sw )
    {
        case USR_SW1:
        case USR_SW2:
            bState      = stSwitchStatus[sw].bState;
            bPrevState  = stSwitchStatus[sw].bPrevState;
            break;
        
        default:
            bState = 0;
    }
    
    return bState & bPrevState;
}

/**********************************************************************************************/

uint32_t UserSwitchTask( void* lpParam )
{
    static  UsrSwType lblButton = USR_SW1;  //! local variable to control the current key to be read
    struct STGpioInputStatus* pSwitchStatus = &stSwitchStatus[lblButton];
    const struct STGpioConfig* pSwitchConfig = &stSwitchConfig[lblButton];
    
    bBusy = 1;

    switch( lblButton )
    {
        case USR_SW1: 
            lblButton = USR_SW2;
            break;
        
        case USR_SW2:
            lblButton = USR_SW1;
            break;
    }

    // save the previous state
    pSwitchStatus->bPrevState = pSwitchStatus->bState;
    
    // get the new switch status
    pSwitchStatus->bState = (GPIOPinRead( pSwitchConfig->dwBASE, pSwitchConfig->dwPin ) ? 0 : 1);

    bBusy = 0;

    return 0;
}

/**********************************************************************************************/
