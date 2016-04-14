#include "util.h"
#include <driverlib/sysctl.h>

/*----------------------------------------------------------------------------*/

BYTE HINIBBLE( BYTE bValue )
{
    return bValue >> 4;
}

/*----------------------------------------------------------------------------*/

BYTE LONIBBLE( BYTE bValue )
{
    return (bValue & 0x0F);
}

/*----------------------------------------------------------------------------*/

BYTE HIBYTE( WORD wValue )
{
    return (wValue >> 8);
}

/*----------------------------------------------------------------------------*/

BYTE LOBYTE( WORD wValue )
{
    return (wValue & 0x00FF);
}

/*----------------------------------------------------------------------------*/

WORD HIWORD( DWORD dwValue )
{
    return (dwValue >> 16);
}

/*----------------------------------------------------------------------------*/

WORD LOWORD( DWORD dwValue )
{
    return (dwValue & 0x0000FFFF);
}

/*----------------------------------------------------------------------------*/

BYTE MAKEBYTE( BYTE bLow,  BYTE bHigh )
{
    return ((BYTE)bHigh << 4) | (bLow);
}

/*----------------------------------------------------------------------------*/

WORD MAKEWORD( BYTE bLow,  BYTE bHigh )
{
    return ((WORD)bHigh << 8) | (bLow);
}

/*----------------------------------------------------------------------------*/

DWORD MAKEDWORD( WORD wLow,  WORD wHigh )
{
    return ((DWORD)wHigh << 16) | (wLow);
}

/*----------------------------------------------------------------------------*/

void SwapByte( BYTE *bDir, BYTE *bEsq )
{
    BYTE bTmp;
    bTmp = *bDir;
    *bDir = *bEsq;
    *bEsq = bTmp;
}

/*----------------------------------------------------------------------------*/

BYTE BCDtoDec( BYTE bBCD )
{
    return (HINIBBLE( bBCD )*10) + LONIBBLE( bBCD );
}

/*----------------------------------------------------------------------------*/

BYTE DectoBCD( BYTE bDec )
{
    return ((bDec / 10) << 4) | (bDec % 10);
}

/*----------------------------------------------------------------------------*/

void delay( int ms )
{
    SysCtlDelay( (SysCtlClockGet()/(3*1000))*ms ) ;
}

/*----------------------------------------------------------------------------*/
