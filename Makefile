CC = g++
LIB = -lncurses

all: AdbFetch

AdbFetch:
	$(CC) adbfetch.cpp -o adbfetch $(LIB)

clear:
	rm adbfetch
	sudo rm /bin/adbfetch

install:
	sudo cp adbfetch /bin

test:
	./adbfetch

cpp:
	micro adbfetch.cpp

.PHONY: clear all install test cpp