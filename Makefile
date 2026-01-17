# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -lm # Warnings and C11 standard for modern features

# Output binary name
TARGET = leet-c

# Default target: build the executable
all: build

# Build the executable
build:
	$(CC) $(CFLAGS) main.c -o $(TARGET)

# Run tests (builds and runs the executable)
test: build
	./$(TARGET)

# Clean up build artifacts
clean:
	rm -f $(TARGET)

# Phony targets (not actual files)
.PHONY: all build test clean
