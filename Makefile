CC = gcc
CFLAGS = -Iinclude

TARGET = my_program

SRCS = main.c src/*.c
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

//gcc -Iinclude main.c src/*.c -o my_program