default: all

all: build

build: tema1.c
	gcc -Wall -Wextra -o tema1 tema1.c

clean: rm -f tema1
