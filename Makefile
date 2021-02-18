# Makefile
CC=gcc
LDFLAGS=-lncurses

all: fake-pacman

clean:
	rm -f fake-pacman
