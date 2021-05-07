# The compiler:
CC = gcc

# Compiler flags:
CFLAGS = -lncurses

# The build target executable:
TARGET = fake-pacman

linux: main.c
	mkdir -p bin/
	$(CC) -o bin/$(TARGET)-linux main.c $(CFLAGS) 
macX86:
	mkdir -p bin/
	$(CC) -o bin/$(TARGET)-macX86 -target x86_64-apple-macos10.12 main.c $(CFLAGS)

macARM:
	mkdir -p bin/
	$(CC) -o bin/$(TARGET)-macARM -target arm64-apple-macos11 main.c $(CFLAGS) 

macUNI: macARM macX86
	lipo -create -output bin/$(TARGET)-macUNI bin/$(TARGET)-X86 bin/$(TARGET)-ARM

clean:
	rm -rf bin/
