
PREFIX = arm-none-eabi-
REMOVE_CMD = rm
#start file
STARTUP_C = Hw_StartUp.c
#target file
TARGET = main
#build folder
OUTDIR = ./Build
#extra header folder
EXTRAINCDIRS = ../LIB                       \
               ../LIB_AP                    \
               ../LIB_AP/Ap_Core            \
               ../LIB_AP/Ap_Lib             \
               ../LIB_HW                    \
               ../LIB_HW/Hw_Core            \
	           ../LIB_HW/Hw_Lib             \
			   ../MENU                      \
	           ../Main

SRC_AP =   ../LIB_AP/Ap_Core/Get_clock.c    \
           ../Main/main.c                   


SRC_MENU = ../Menu/Key_Menu.c              \
           ../Menu/Led_Menu.c              

SRC_HW = ../LIB_HW/Hw_Core/$(STARTUP_C)    \
		 ../LIB_HW/Hw_Core/Hw.c            \
		 ../LIB_HW/Hw_Core/Hw_Gpio.c       \
		 ../LIB_HW/Hw_Core/Hw_Usart.c      \
		 ../LIB_HW/Hw_Lib/Hw_Led.c         \
		 ../LIB_HW/Hw_Lib/Hw_Key.c         \
         ../LIB_HW/Hw_Lib/Hw_Segment.c     \

SRC_LB = ../LIB/Ld_Printf.c                \
         ../LIB/Util.c

#source file 
SRC = $(SRC_AP) $(SRC_LB) $(SRC_HW) $(SRC_MENU)
#thumb mode
THUMB = -mthumb
#include header
INCLUDE = -I./include -I.

#C compiler option
CC = $(PREFIX)gcc
CPP = $(PREFIX)g++
OBJCOPY = $(PREFIX)objcopy
OBJDUMP = $(PREFIX)objdump
OBJNM = $(PREFIX)nm
SIZE = $(PREFIX)size
REMOVE = $(REMOVE_CMD) -rf

CFLAGS  = -gdwarf-2 -O2 -mcpu=cortex-m3 -mthumb-interwork -DSTM32F10X_MD 
#CFLAGS += $(INCLUDE) -mlong-calls -ffunction-sections -fdata-sections -fpromote-loop-indices -Wall -Wextra -Wimplicit -Wcast-align -Wpointer-arith -Wredundant-decls 
CFLAGS += $(INCLUDE) -mlong-calls -ffunction-sections -fdata-sections -Wall -Wextra -Wimplicit -Wcast-align -Wpointer-arith -Wredundant-decls 
CFLAGS += -Wshadow -Wcast-qual -Wcast-align -Wa,-adhlns=start_stm32f10x.lst -MD -MP -MF $(TARGET).elf.d
#$(patsubst pattern, replacement, teext)
#test안에서 공백문자로 분리된 단어들 중 patern과 매치된ㄴ 단어를 찾아서 그거들을 replacement로변경한다. 와일드 카드인 %를 가질수 있다.
#$(patsubst %.c, %.o,, x.c.c bar.c)
#'x.c.o bar.o'라는 값을 만든다. 대입참조 (see section 대입참조)는 patsubst 의 효과를 얻는 더 단순한 방법이다.
CFLAGS += $(patsubst %,-I%,$(EXTRAINCDIRS))
#무엇인지 확인
CONLYFLAGS += -Wnested-externs 
CONLYFLAGS += -std=gnu99
#이게 맞는지?
LDFLAGS = -static -nostdlib -nostartfiles -Wl,-Map=$(TARGET).map,--cref,--gc-sections -L./ -lc  -lm  -lc -lgcc -T.//stm32f10x.ld
#ELF32_LDFLAGS = -Wl,-T,stm32f10x.ld



# Define Messages
# English
MSG_LOAD_FILE = Creating load file:
MSG_EXTENDED_LISTING = Creating Extended Listing/Disassembly:
MSG_SYMBOL_TABLE = Creating Symbol Table:
MSG_LINKING = ---- Linking :
MSG_CLEANING = Cleaning project:
MSG_ASMFROMC = "Creating asm-File from C-Source:"

# List of all source files.
ALLSRC     =  $(SRC)
# List of all source files without directory and file-extension.
ALLSRCBASE = $(notdir $(basename $(ALLSRC)))

# Define all object files.
#ALLOBJ = $(addprefix $(OUTDIR)/, $(addsuffix .o, $(ALLSRCBASE)))
ALLOBJ = $(addsuffix .o, $(ALLSRCBASE))


# Default target.
all: createdirs build

elf: $(TARGET).elf
lss: $(TARGET).lss 
sym: $(TARGET).sym
hex: $(TARGET).hex
bin: $(TARGET).bin


build: elf hex bin lss sym

# Create output directories.
createdirs:
	-@md $(OUTDIR) >NUL 2>&1 || echo "" >NUL
	-@md $(OUTDIR)\dep >NUL 2>&1 || echo "" >NUL

# Create final output file (.hex) from ELF output file.
%.hex: %.elf
	@echo $(MSG_LOAD_FILE) $@
	$(OBJCOPY) -O ihex $< $@
	
# Create final output file (.bin) from ELF output file.
%.bin: %.elf
	@echo $(MSG_LOAD_FILE) $@
	$(OBJCOPY) -O binary $< $@

# Create extended listing file/disassambly from ELF output file.
# using objdump testing: option -C
%.lss: %.elf
	@echo $(MSG_EXTENDED_LISTING) $@
	$(OBJDUMP) -h -S -C -r $< > $@
#	$(OBJDUMP) -x -S $< > $@

# Create a symbol table from ELF output file.
%.sym: %.elf
	@echo $(MSG_SYMBOL_TABLE) $@
	$(OBJNM) -n $< > $@

# Link: create ELF output file from object files.
.SECONDARY : $(TARGET).elf
.PRECIOUS : $(ALLOBJ)
%.elf:  $(ALLOBJ)
	@echo $(MSG_LINKING) $@
	$(CC) $(THUMB) $(CFLAGS) $(ALLOBJ) --output $@ $(LDFLAGS)

# Compile: create object files from C source files.
define COMPILE_C_TEMPLATE
$(notdir $(basename $(1))).o : $(1)
	@echo $(MSG_COMPILING) $$< to $$@
	$(CC) -c $(THUMB) $$(CFLAGS) $$(CONLYFLAGS) $$< -o $$@ 
endef
$(foreach src, $(SRC), $(eval $(call COMPILE_C_TEMPLATE, $(src)))) 


# Compile: create assembler files from C source files. ARM/Thumb
$(SRC:.c=.s) : %.s : %.c
	@echo $(MSG_ASMFROMC) $< to $@
	$(CC) $(THUMB) -S $(CFLAGS) $(CONLYFLAGS) $< -o $@

###################################################################################################
###################################################################################################
###################################################################################################
###################################################################################################
###################################################################################################
# Define all listing files (used for make clean).
LSTFILES   = $(addsuffix .lst, $(ALLSRCBASE))
# Define all depedency-files (used for make clean).
DEPFILES   = $(addsuffix .o.d, $(ALLSRCBASE))


# Target: clean project.
clean: clean_list

clean_list :
	@echo $(MSG_CLEANING)
	$(REMOVE) $(TARGET).map
	$(REMOVE) $(TARGET).elf
	$(REMOVE) $(TARGET).elf.d
	$(REMOVE) $(TARGET).hex
	$(REMOVE) $(TARGET).bin
	$(REMOVE) $(TARGET).sym
	$(REMOVE) $(TARGET).lss
	$(REMOVE) $(ALLOBJ)
	$(REMOVE) $(LSTFILES)
	$(REMOVE) $(DEPFILES)
	$(REMOVE) $(SRC:.c=.s)
	$(REMOVE) NUL
	$(REMOVE) start_stm32f10x.lst
	$(REMOVE) NUL

# Create object files directory
##$(shell mkdir $(OBJDIR) 2>/dev/null)

# Include the dependency files.
#-include $(shell mkdir dep 2>/dev/null) $(wildcard dep/*)
-include $(wildcard dep/*)

# Listing of phony targets.
.PHONY : all finish \
build elf hex bin lss sym clean clean_list createdirs

