CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -liw

SRC_DIR = src
SRC = $(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/*/*.c)
OBJ = $(SRC:.c=.o)
TARGET = iwsuite

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
