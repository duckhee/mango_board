#ifndef __GET_CLOCK_H__
#define __GET_CLOCK_H__

#include "Ap.h"

#ifdef GET_CLOCK_LOCAL
#define GET_CLOCK_DEF
#else
#define GET_CLOCK_DEF                 extern
#endif


GET_CLOCK_DEF void System_Information(void);


#endif