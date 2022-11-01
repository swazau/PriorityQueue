CC=g++
CFLAGS=-c -Wall -std=c++98 
LDFLAGS=
SOURCES=main.cpp Node.h LinkedList.h LQueue.h
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=a3

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp %.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core
