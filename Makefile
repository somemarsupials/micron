all: build

build: src/main.c
	@echo "building Micron..."
	gcc -Wall -Iinclude -o bin/micron src/main.c
	@echo "build complete (see bin/micron)"

clean:
	rm -f obj/*.o bin/micron
