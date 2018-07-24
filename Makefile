# toolchain
cc=gcc
cflags=-Iinclude -Wall

# build
target=micron
binaries=bin

# source files
src=$(shell find ./src -name "*.c")
obj=$(patsubst %.c, %.o, $(src))

# rules
all: build clean
build: $(target)

$(target): $(obj)
	$(cc) $(obj) -o $(binaries)/$(target)

%.o: %.c
	$(cc) $(cflags) -o $@ -c $<

.PHONY: clean

clean:
	rm -f $(obj)
