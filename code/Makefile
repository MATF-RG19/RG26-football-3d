PROGRAM = football
CC      = gcc
FLAGS  = -g -Wall
LIBS  = -lglut -lGLU -lGL -lm
OBJS = main.o ball.o display.o callback.o camera.o terrain.o image.o textures.o axis.o

$(PROGRAM): $(OBJS) 
	    $(CC) $(FLAGS) -o $(PROGRAM) $(OBJS) $(LIBS)

main.o: main.c main.h
	$(CC) -c $(FLAGS) main.c -o main.o $(LIBS) $(FLAGS)
	
ball.o: ball.c ball.h
	$(CC) -c $(FLAGS) ball.c -o ball.o $(LIBS) $(FLAGS)
	
display.o: display.c display.h
	$(CC) -c $(FLAGS) display.c -o display.o $(LIBS) $(FLAGS)
	
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
	
axis.o: axis.c axis.h
	$(CC) -c $(FLAGS) axis.c -o axis.o $(LIBS) $(FLAGS)

.PHONY: play run clean 

play:
	./$(PROGRAM) 

run:
	make && make play

clean:
	-rm -f *~ $(OBJS) $(PROGRAM) *~


