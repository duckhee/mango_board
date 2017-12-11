#ifndef __LSTRING_H__
#define __LSTRING_H__

#include "Ap.h"

 #ifdef LD_PRINTF_LOCAL
 #define LD_PRINTF_DEF
 #else
 #define LD_PRINTF_DEF        extern
 #endif

 



LD_PRINTF_DEF void printf(char *fmt, ...);
LD_PRINTF_DEF char get_byte(void);

#endif