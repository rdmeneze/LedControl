
#include "LedControl.h"

uint32_t LedCtrlInit(int dataPin, int clkPin, int csPin, int numDevices)
{
    return 0;
}

uint32_t LedCtrlGetDeviceCount(void)
{
    return 0;
}


void LedCtrlShutdown(int addr, uint8_t status)
{
    return;
}

void LedCtrlSetScanLimit(int addr, int limit)
{
    return;
}


void LedCtrlSetIntensity(int addr, int intensity)
{
    return;
}


void LedCtrlClearDisplay(int addr)
{
    return;
}


void LedCtrlSetLed(int addr, int row, int col, uint8_t state)
{
    return;
}


void LedCtrlSetRow(int addr, int row, uint8_t value)
{
    return;
}


void LedCtrlSetColumn(int addr, int col, uint8_t value)
{
    return;
}


void LedCtrlSetDigit(int addr, int digit, uint8_t value, uint8_t dp)
{
    return;
}

void LedCtrlSetChar(int addr, int digit, char value, uint8_t dp)
{
    return;
}

