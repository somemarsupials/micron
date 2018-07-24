# toolchain
cc=gcc
cflags=-Iinclude -Wall

# build
target=micron

# source files
src=$(shell find ./src -name "*.c")
obj=$(patsubst %.c, %.o, $(src))

# rules
all: $(target) clean

$(target): $(obj)
	$(cc) $(obj) -o build/$(target)

%.o: %.c
	$(cc) $(cflags) -o $@ -c $<

.PHONY: clean

clean:
	rm -f $(obj)
