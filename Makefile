# The compiler:
CC = gcc

# Compiler flags:
CFLAGS = -lncurses

# The build target executable:
TARGET = fake-pacman

linux: main.c
	$(CC) $(CFLAGS) -o $(TARGET)-linux main.c
macX86:
	$(CC) $(CFLAGS) -o $(TARGET)-X86 -target x86_64-apple-macos10.12 main.c

macARM:
	$(CC) $(CFLAGS) -o $(TARGET)-ARM -target arm64-apple-macos11 main.c

macUNI: macARM macX86
	lipo -create -output $(TARGET)-mac x86_app arm_app

clean:
	rm -f $(TARGET)-linux $(TARGET)-mac x86_app arm_app
