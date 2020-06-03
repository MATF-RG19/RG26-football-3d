#ifndef BASE_H
#define BASE_H

#include "main.h"

// Dimenzije prozora
#define WIN_WIDTH 640
#define WIN_HEIGHT 480
#define WIN_POS 100
#define SHININESS 100 

// Bazne funkcije
void set_init(int*, char**);
void create_window(void);
void set_light(void);
void start_game(void);
void gooal(void);	
void game_over(void);

#endif 
