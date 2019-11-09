PROGRAM = football
CC      = gcc
CFLAGS  = -g -Wall -Wextra -I/usr/X11R6/include -I/usr/pkg/include
LDFLAGS = -L/usr/X11R6/lib -L/usr/pkg/lib
LDLIBS  = -lglut -lGLU -lGL -lm

$(PROGRAM): main.o
	$(CC) $(LDFLAGS) -o $(PROGRAM) main.o $(LDLIBS)

.PHONY: run makerun clean dist

run:
	./$(PROGRAM) 

makerun:
	make && make run

clean:
	-rm *.o $(PROGRAM) *core

dist: clean
	-tar -chvj -C .. -f ../$(PROGRAM).tar.bz2 $(PROGRAM)
