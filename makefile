CC=g++
CFLAGS=-c
LDFLAGS=
SOURCES=$(shell find . -type f -name '*.cpp' )
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=run.exe

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS)
