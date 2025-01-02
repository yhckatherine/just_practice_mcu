CC      = arm-none-eabi-gcc
LD      = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy
CFLAGS  = -mcpu=cortex-m4 -mthumb -Wall -g -O2
LDFLAGS = -T linker.ld

SRC_DIR = src
INC_DIR = include
LIB_DIR = libs/STM32_HAL
BUILD_DIR = build

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))

TARGET = $(BUILD_DIR)/led_control.elf

all: $(TARGET)

$(TARGET): $(OBJ)
	@echo "Linking: $@"
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	@echo "Compiling: $<"
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	@echo "Cleaning..."
	rm -rf $(BUILD_DIR)

flash: $(TARGET)
	st-flash write $(TARGET) 0x8000000

.PHONY: all clean flash

