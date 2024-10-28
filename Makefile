PROGRAM_DIRS := $(wildcard */)
PROGRAMS := $(patsubst %/,%, $(PROGRAM_DIRS))
BUILD_DIR := build

CC := gcc

all: $(BUILD_DIR) $(PROGRAMS)

$(PROGRAMS): % : $(BUILD_DIR)/%

$(BUILD_DIR)/%: %/*.c | $(BUILD_DIR)
	$(CC) $(CFLAGS_$*) $(INCLUDES_$*) -o $@ $< $(LIBS_$*)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	@rm -rf $(BUILD_DIR)

.PHONY: all clean