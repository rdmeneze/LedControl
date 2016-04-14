#ifndef __DEFS_H__
#define __DEFS_H__

#include "errno.h"
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <inc/hw_types.h>

#define BYTE        uint8_t     
#define WORD        uint16_t    
#define DWORD       uint32_t    
#define LPVOID      void*       
#define HANDLE      void*

typedef unsigned int	UINT;
typedef int				INT;

/* These types must be 8-bit integer */
typedef char			CHAR;
typedef unsigned char	UCHAR;

/* These types must be 16-bit integer */
typedef short			SHORT;
typedef unsigned short	USHORT;
typedef unsigned short	WCHAR;

/* These types must be 32-bit integer */
typedef long			LONG;
typedef unsigned long	ULONG;

/* Boolean type */
typedef enum { FALSE = 0, TRUE } BOOL;

#ifdef NULL 
#undef NULL 
#endif

#define NULL ((void*)0U)


#endif //~ __DEFS_H__
