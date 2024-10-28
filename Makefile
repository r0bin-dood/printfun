PROGRAM_DIRS := $(filter-out build/, $(wildcard */))
PROGRAMS := $(patsubst %/,%, $(PROGRAM_DIRS))
BUILD_DIR := build

CC := gcc

all: $(addprefix $(BUILD_DIR)/, $(PROGRAMS))

$(BUILD_DIR)/%: %/*.c | $(BUILD_DIR)
	$(CC) $(CFLAGS_$*) $(INCLUDES_$*) -o $@ $< $(LIBS_$*)

$(PROGRAMS): %: $(BUILD_DIR)/%

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	@rm -rf $(BUILD_DIR)

.PHONY: all clean $(PROGRAMS)