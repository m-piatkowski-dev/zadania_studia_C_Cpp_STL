CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.c generuj.c
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=gen

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	
.c.o:
	$(CC) $(CFLAGS) $< -o $@
