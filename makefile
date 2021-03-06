
OBJS = main.o problem.o node.o tree.o
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

node.o : node.cpp node.h
	$(CC) $(CFLAGS) node.cpp

tree.o : tree.cpp tree.h
	$(CC) $(CFLAGS) tree.cpp
clean: 
	\rm *.o main
