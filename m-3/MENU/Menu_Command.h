#ifndef __MENU_COMMAND_H__
#define __MENU_COMMAND_H__

#include "Menu.h"

#include "Led_Command.h"
#include "Key_Command.h"
#include "Seg_Command.h"



#ifdef MENU_COMMAND_LOCAL
#define MENU_COMMAND_DEF
#else
#define MENU_COMMAND_DEF                    extern
#endif

MENU_COMMAND_DEF void command_main(void);

#endif