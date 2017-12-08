#ifndef __LED_COMMAND_H__
#define __LED_COMMAND_H__

#include "Menu.h"



#ifdef COMMAND_LED_LOCAL
#define COMMAND_LED_DEF
#else
#define COMMAND_LED_DEF             extern
#endif

COMMAND_LED_DEF int command_led_main(int argc, char **argv);
COMMAND_LED_DEF int command_led_main_menu(void);



#endif