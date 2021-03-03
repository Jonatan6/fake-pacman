# The compiler:
CC = gcc

# Compiler flags:
CFLAGS = -lncurses

# The build target executable:
TARGET = fake-pacman

linux: main.c
	mkdir -p bin/
	$(CC) $(CFLAGS) -o bin/$(TARGET)-linux main.c
macX86:
	mkdir -p bin/
	$(CC) $(CFLAGS) -o bin/$(TARGET)-X86 -target x86_64-apple-macos10.12 main.c

macARM:
	mkdir -p bin/
	$(CC) $(CFLAGS) -o bin/$(TARGET)-ARM -target arm64-apple-macos11 main.c

macUNI: macARM macX86
	lipo -create -output bin/$(TARGET)-UNI bin/$(TARGET)-X86 bin/$(TARGET)-ARM

clean:
	rm -rf bin/
