# The compiler:
CC = gcc

# Compiler flags:
CFLAGS = -lncurses

# The build target executable:
TARGET = fake-pacman

all: $(TARGET)

mac: 
      $(CC) $(CFLAGSP) -o arm_app -target arm64-apple-macos11 $(TARGET).c
      $(CC) $(CFLAGSP) -o x86_app -target x86_64-apple-macos10.12 $(TARGET).c
      lipo -create -output $(TARGET) x86_app arm_app

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	rm -f $(TARGET) 
	rm -f x86_app arm_app
