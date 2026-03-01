CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

TARGET = my_program

SRCS = main.c src/object.c src/integer.c
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)