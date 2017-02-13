
OBJS = main.o problem.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

main : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o main

main.o : main.cpp problem.h
	$(CC) $(CFLAGS) main.cpp

problem.o : problem.cpp problem.h
	$(CC) $(CFLAGS) problem.cpp

clean: 
	\rm *.o main
