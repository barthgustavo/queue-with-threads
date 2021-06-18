OBJS	= main.o queue.o
SOURCE	= main.c queue.c
HEADER	= queue.h
OUT	= main.out
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = -lpthread

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.c
	$(CC) $(FLAGS) main.c 

queue.o: queue.c
	$(CC) $(FLAGS) queue.c 


clean:
	rm -f $(OBJS) $(OUT)