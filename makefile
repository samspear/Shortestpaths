#David S. Spear

CC = g++
CFLAGS = -c -g
LFLAGS = -g -I. -o Graph

Graph: test.o graph.o
	$(CC) $(LFLAGS) test.o graph.o
	rm *.o
	rm *.gch
test.o: test.cpp graph.h
	$(CC) $(CFLAGS) test.cpp graph.h
graph.o: graph.cpp graph.h
	$(CC) $(CFLAGS) graph.cpp graph.h
