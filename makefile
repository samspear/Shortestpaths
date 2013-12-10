#David S. Spear

CC = g++
CFLAGS = -c -g
LFLAGS = -g -I. -o Graph

Graph: test.o graph.o compare.o
	$(CC) $(LFLAGS) test.o graph.o compare.o
	rm *.o
	rm *.gch
test.o: test.cpp graph.h
	$(CC) $(CFLAGS) test.cpp graph.h
graph.o: graph.cpp graph.h compare.h
	$(CC) $(CFLAGS) graph.cpp graph.h compare.h
compare.o: compare.h compare.cpp
	$(CC) $(CFLAGS) compare.h compare.cpp
