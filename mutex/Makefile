SRCS := led_main.c led_green.c led_yellow.c
OBJS := $(SRCS:.c=.o)
CC := gcc
CFLAGS := -c -Wall

led_main : $(OBJS)
	$(CC) -o $@ $^ -lpthread -lwiringPi

# dummy target - no dependency
clean :
	-rm $(OBJS)
	-rm led_main

# dummy target - no dependency
dep :
	gccmakedep $(SRCS)

