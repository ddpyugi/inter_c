CC=gcc
CPP_FILES := $(wildcard src/*.c)
OBJ_FILES := $(addprefix build/,$(notdir $(CPP_FILES:.c=.o)))

all: main
	

main: $(OBJ_FILES)
	$(CC) -o $@ $<

test_var_manager: $(OBJ_FILES) tests/test_var_manager.c
	$(CC) -o test_var_manager $<

build/%.o: src/%.c
	$(CC) -c -o $@ $<

clean:
	rm -rf build/*
	rm -rf main
