#ifndef CALLBACK_H
#define CALLBACK_H

#include "main.h"

// ASCII kod ESC tastera
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
#define FORWARD 1
#define BACK 2
#define UP 4
#define DOWN 8
#define LEFT 16
#define RIGHT 32
#define RESET 64

int keyboard;

// Struktura lopte sa koordinatama x,y,z i radijusm r
extern struct ball ball;

// Struktura kamere sa koordinatama x,y,z
extern struct camera camera;

// Callback funkcije
void set_callback(void);
void on_idle(void);
void on_button_push(unsigned char, int, int);
void on_button_pull(unsigned char, int, int);
void on_reshape(int, int);
void on_display(void);

#endif 
