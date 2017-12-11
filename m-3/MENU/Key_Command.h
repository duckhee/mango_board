#ifndef __KEY_COMMAND_H__
#define __KEY_COMMAND_H__

#include "Menu_Command.h"

#ifdef KEY_COMMAND_LOCAL
#define KEY_COMMAND_DEF
#else
#define KEY_COMMAND_DEF                     extern
#endif

KEY_COMMAND_DEF int command_key_main(int argc, char **argv);
KEY_COMMAND_DEF int command_key_main_menu(void);

#endif