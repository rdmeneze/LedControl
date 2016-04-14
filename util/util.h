#ifndef __UTIL_H__
#define __UTIL_H__

#include "defs.h"

#define GET_ARRAY_LEN( x ) ( sizeof( x )/sizeof( x[0] ) )

#define GETBIT( x, bit ) ( (x & (1<<bit)) >> bit )

/**
 *  \brief  get the high Nibble of a byte 
 *  \param[in]  bValue  byte to get the high nibble
 *  \return     high nibble
 */
inline BYTE HINIBBLE( BYTE bValue );

/**
 *  \brief  get the Low Nibble of a byte 
 *  \param[in]  bValue  byte to get the low nibble
 *  \return     low nibble
 */
inline BYTE LONIBBLE( BYTE bValue );

/**
 *  \brief  get the high byte of a byte 
 *  \param[in]  wValue  byte to get the high byte
 *  \return     high byte
 */
inline BYTE HIBYTE( WORD wValue );

/**
 *  \brief  get the low byte of a byte 
 *  \param[in]  wValue  byte to get the low byte
 *  \return     low byte
 */
inline BYTE LOBYTE( WORD wValue );

/**
 *  \brief  get the high word of a dword
 *  \param[in]  dwValue byte to get the high word
 *  \return     high word
 */
inline WORD HIWORD( DWORD dwValue );

/**
 *  \brief  get the low word of a dword
 *  \param[in]  dwValue byte to get the low word
 *  \return     low word
 */
inline WORD LOWORD( DWORD dwValue );

/**
 *  \brief  make a byte from two nibbles
 *  \param[in]  bLow low nibble
 *  \param[in]  bHigh high nibble
 */
inline BYTE MAKEBYTE( BYTE bLow,  BYTE bHigh );

/**
 *  \brief  make a word from two bytes
 *  \param[in]  bLow low byte
 *  \param[in]  bHigh high byte
 */
inline WORD MAKEWORD( BYTE bLow,  BYTE bHigh );

/**
 *  \brief  make a dword from two words
 *  \param[in]  bLow low word
 *  \param[in]  bHigh high word
 */
inline DWORD MAKEDWORD( WORD wLow,  WORD wHigh );

/**
 *  \brief convert from BDC to decimal
 *  \param[in]  bBCD binary code decimal data
 *  \return data decoded
 */
inline BYTE BCDtoDec( BYTE bBCD );
inline BYTE DectoBCD( BYTE bDec );

/**
 *  \brief  wait ms
 *  \param  ms time to wait
 */
void delay( int ms );



#endif //~ __UTIL_H__
