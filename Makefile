# the compiler:
CC = gcc

# compiler flags:
CFLAGS = -lncurses

# the build target executable:
TARGET = fake-pacman

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	rm -f $(TARGET)
