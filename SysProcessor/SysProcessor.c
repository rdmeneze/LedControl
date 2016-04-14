#include "SysProcessor.h"
#include <driverlib/sysctl.h>

/*----------------------------------------------------------------------------*/

static DWORD g_ulSystemClock = 0;

/*----------------------------------------------------------------------------*/

DWORD SetSystemClock( void )
{
#ifdef  PART_TM4C123GH6PGE
    SysCtlClockSet(SYSCTL_SYSDIV_3 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
    g_ulSystemClock = SysCtlClockGet();
#elif   PART_TM4C1294NCPDT
    g_ulSystemClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ  |
                                             SYSCTL_OSC_MAIN |
                                             SYSCTL_USE_PLL  |
                                             SYSCTL_CFG_VCO_480), 120000000);
#endif
    return g_ulSystemClock;
}

/*----------------------------------------------------------------------------*/

DWORD GetSystemClock( void )
{
    return g_ulSystemClock;
}

/*----------------------------------------------------------------------------*/
