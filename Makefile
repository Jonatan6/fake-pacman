# The compiler:
CC = gcc

# Compiler flags:
CFLAGS = -lncurses

# The build target executable:
TARGET = fake-pacman

linux: main.c
	$(CC) $(CFLAGS) -o $(TARGET)-linux main.c

mac: 
	$(CC) $(CFLAGS) -o arm_app -target arm64-apple-macos11 main.c
	$(CC) $(CFLAGS) -o x86_app -target x86_64-apple-macos10.12 main.c
	lipo -create -output $(TARGET)-mac x86_app arm_app

clean:
	rm -f $(TARGET)-linux $(TARGET)-mac x86_app arm_app
