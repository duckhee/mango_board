#ifndef __MENU_COMMAND_H__
#define __MENU_COMMAND_H__

#include "Menu.h"


#ifdef COMMAND_LOCAL
#define COMMAND_DEF
#else
#define COMMAND_DEF                extern
#endif

COMMAND_DEF void command_main(void);


#endif