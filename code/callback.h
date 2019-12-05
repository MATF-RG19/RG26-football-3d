#ifndef CALLBACK_H
#define CALLBACK_H

#include "main.h"

// ASCII kod nekih tastera    
#define ESC 27

// Nekoriscene  varijable
#define CANCEL(x) (void)x

// Opis perspektive
#define PERS_ANGLE 60
#define PERS_NEAR 1
#define PERS_FAR 100

// Opis pogleda
#define NORM_X 0
#define NORM_Y 0
#define NORM_Z 1

// Bafer bitovskih tastera
#define EMPTY 0
#define ZOOM_IN 1
#define ZOOM_OUT 2
#define UP 4
#define DOWN 8
#define LEFT 16
#define RIGHT 32
#define RESET 64
#define FORWARD 128
#define BACKWARD 256

int keyboard;

// Callback funkcije
void set_callback(void);
void on_idle(void);
void on_button_push(unsigned char, int, int);
void on_button_pull(unsigned char, int, int);
void on_reshape(int, int);
void on_display(void);
void set_terrain(void);

#endif 
