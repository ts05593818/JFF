CROSS_COMPILER ?= arm-none-eabi-
CC:= $(CROSS_COMPILER)gcc
CFLAG = -std=gnu99 \
	 -Wall -Werror \
	 -mcpu=cortex-m4 \
	 -Wl,-T main.ld -nostartfiles 
TARGET := ./main.bin
OBJ := *.o
SOURCE := ./source/*.c
all: $(TARGET)
$(OBJ):$(SOURCE)
	$(CC) -c $^

$(TARGET):$(SOURCE)
	@echo "build" 
	$(CC) $(CFLAG)  -o main.elf  $^
	$(CROSS_COMPILER)objcopy -Obinary main.elf $(TARGET)
	$(CROSS_COMPILER)objdump -S main.elf > main.list
clean:
	rm -f *.o *.bin *.elf *.list