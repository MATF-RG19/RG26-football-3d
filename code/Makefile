PROGRAM = football
CC      = gcc
FLAGS  = -g -Wall 
SRC = main.c ball.c base.c callback.c camera.c terrain.c textures.c
HDR = main.h ball.h base.h callback.h camera.h terrain.h textures.h
LIBS  = -lglut -lGLU -lGL -lm
OBJS = main.o ball.o base.o callback.o camera.o terrain.o image.o textures.o 

$(PROGRAM): $(OBJS) 
	    $(CC) $(FLAGS) -o $(PROGRAM) $(OBJS) $(LIBS)

main.o: main.c main.h
	$(CC) -c $(FLAGS) main.c -o main.o $(LIBS) $(FLAGS)
	
ball.o: ball.c ball.h
	$(CC) -c $(FLAGS) ball.c -o ball.o $(LIBS) $(FLAGS)
	
base.o: base.c base.h
	$(CC) -c $(FLAGS) base.c -o base.o $(LIBS) $(FLAGS)
	
callback.o: callback.c callback.h
	$(CC) -c $(FLAGS) callback.c -o callback.o $(LIBS) $(FLAGS)
	
camera.o: camera.c camera.h
	$(CC) -c $(FLAGS) camera.c -o camera.o $(LIBS) $(FLAGS)
	
terrain.o: terrain.c terrain.h
	$(CC) -c $(FLAGS) terrain.c -o terrain.o $(LIBS) $(FLAGS)
	
image.o: image.c image.h
	$(CC) -c $(FLAGS) image.c -o image.o $(LIBS) $(FLAGS)
	
texture.o: texture.c texture.h
	$(CC) -c $(FLAGS)  texture.c -o texture.o $(LIBS) $(FLAGS)

.PHONY: play run clean dist

play:
	./$(PROGRAM) 

run:
	make && make play

clean:
	-rm -f $(OBJS) $(PROGRAM) *~

dist: clean
	-tar -chvj -C .. -f ../$(PROGRAM).tar.bz2 $(PROGRAM)

