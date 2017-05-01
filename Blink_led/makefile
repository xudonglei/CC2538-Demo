include ./makedefs

CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
PROJECT = blink_led
OBJECTFILES = startup_gcc.o main.o setup.o
LINKERFILE = cc2538_512_gcc.cmd
SRCFOLDER = src

clean:
	-$(RM) $(PROJECT).elf
	-$(RM) $(PROJECT).map
	-$(RM) $(PROJECT).bin
	-$(RM) startup_gcc.o
	-$(RM) setup.o
	-$(RM) main.o

all: main.o startup_gcc.o setup.o $(PROJECT).elf $(PROJECT).bin

main.o : main.c 
	$(CC) -O0 -mthumb -mcpu=cortex-m3 -gdwarf-2 -fomit-frame-pointer -Wall -Wstrict-prototypes -c -g main.c 
	
startup_gcc.o : startup_gcc.c 
	$(CC) -O0 -mthumb -mcpu=cortex-m3 -gdwarf-2 -fomit-frame-pointer -Wall -Wstrict-prototypes -c -g startup_gcc.c 

$(PROJECT).elf : 
	$(CC) $(OBJECTFILES) -mthumb -mcpu=cortex-m3 -nostartfiles -T $(LINKERFILE) -Wl,-Map=$(PROJECT).map,--cref,--no-warn-mismatch -o $(PROJECT).elf
	
$(PROJECT).bin : $(PROJECT).elf
	$(OBJCOPY) -O binary --gap-fill 0xff $(PROJECT).elf $(PROJECT).bin




  