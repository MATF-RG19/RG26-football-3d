#ifndef CALLBACK_H
#define CALLBACK_H

#include "main.h"

// ASCII kod nekih tastera    
#define ESC 27
#define SPACE 32

// Opis perspektive
#define PERS_ANGLE 60
#define PERS_NEAR 1
#define PERS_FAR 1024

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
#define JUMP 512

int keyboard;

// Callback funkcije
void on_mouse_motion(int, int);
void set_callback(void);
void on_idle(void);
void on_button_pressed(unsigned char, int, int);
void on_button_released(unsigned char, int, int);
void on_reshape(int, int);
void on_display(void);
void set_terrain(void);

#endif 
