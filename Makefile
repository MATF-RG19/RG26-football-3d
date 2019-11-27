PROGRAM = football
CC      = gcc
FLAGS  = -g -Wall -Wextra -I/usr/X11R6/lib -I/usr/pkg/lib
SRC = code/main.c code/ball.c code/base.c code/callback.c code/camera.c
HDR = code/main.c code/ball.h code/base.h code/callback.h code/camera.h
LIBS  = -lglut -lGLU -lGL -lm

$(PROGRAM): $(SRC) $(HDR) 
	    $(CC) $(FLAGS) -o $(PROGRAM) $(SRC) $(LIBS)

.PHONY: play run clean

play:
	./$(PROGRAM) 

run:
	make && make play

clean:
	rm -f *~ code/*~ gifs/*~

