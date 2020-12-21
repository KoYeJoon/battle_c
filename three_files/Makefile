SRCS := func.c main.c
OBJS := $(SRCS:.c=.o)
CC := gcc
CFLAGS = -c -Wall -g
#CFLAGS = -c -Wall -O2

mytest : $(OBJS)
	$(CC) -o $@ $^

#dummy target
clean :
	-rm $(OBJS)
	rm mytest

dep :
#	gcc -M $(SRCS)
	gccmakedep $(SRCS)

