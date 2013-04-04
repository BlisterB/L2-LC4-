SOURCES=fichier1.c fichier2.c ...
OBJECTS=$(SOURCES:.c=.o)
CFLAGS= -std=c89 -Wall -Wextra
EXECUTABLE=exo

$(EXECUTABLE): $(OBJECTS)
	gcc -o $(EXECUTABLE) $(OBJECTS)

%.o : %.c
	gcc -c $(CFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
