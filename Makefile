CC = gcc
CFLAGS = -Wall -Wextra
MAINDIR = main
OBJDIR = obj
BINDIR = bin
TARGET = $(BINDIR)/banking_system

# List of source files
SOURCES = main.c \
          $(MAINDIR)/account.c \
          $(MAINDIR)/database.c \
          $(MAINDIR)/menu.c \
          $(MAINDIR)/ui.c

# Generate object file names
OBJECTS = $(patsubst %.c,$(OBJDIR)/%.o,$(notdir $(SOURCES)))

.PHONY: all clean

# Default target
all: directories $(TARGET)

# Create necessary directories
directories:
	mkdir -p $(OBJDIR) $(BINDIR)

# Rule to compile the executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# Pattern rule for object files
$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/%.o: $(MAINDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean target
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Run target
run: all
	$(TARGET) 