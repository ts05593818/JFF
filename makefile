CROSS_COMPILER ?= arm-none-eabi-
CC:= $(CROSS_COMPILER)gcc
CFLAG = -fno-common -O0\
		-mcpu=cortex-m4 -mthumb\
		-T main.ld -nostartfiles\
TARGET := main.bin
OBJ := ./*.o
SOURCE := ./source/*.c
all: $(TARGET)
$(TARGET):$(OBJ)
	$(CC) $(CFLAG) $^ -o main.elf
	$(CROSS_COMPILER)objcopy -Obinary main.elf main.bin
	$(CROSS_COMPILER)objdump -S main.elf > $(OUTPUT)main.list
$(OBJ):$(SOURCE)
	$(CC) -c $^
clean:
	rm -f *.o *.bin *.elf *.list