#ifndef CALLBACK_H
#define CALLBACK_H

#include "main.h"

// ASCII kod za escape i space   
#define ESC 27
#define SPACE 32

// Tajmer
#define TIMER_INTERVAL 60
#define TIMER_ID 0
#define FPS 1000/60

// Indikatori translacije kupe
#define MOVE_RIGHT 1
#define MOVE_LEFT -1

// Indikatori pocekta i kraja
#define START 1
#define END 0

// Distanca sa preprekom
#define EPS_1 4

// Opis perspektive
#define PERS_ANGLE 60
#define PERS_NEAR 1
#define PERS_FAR 16288

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
// Indikator za kretanje kupe levo-desno
int ind; 
int start;
int end;
float animation_parameter;

float camera_x; 
float camera_y;

// Globalni tajmer
struct glob_time {
	int elapse;
	int past;
	int diff;
} glob_time;

// Callback funkcije
void on_mouse_motion(int, int);
void set_callback(void);
void on_idle(void);
void on_button_pressed(unsigned char, int, int);
void on_button_released(unsigned char, int, int);
void on_reshape(int, int);
void on_display(void);
void set_terrain(void);
void on_timer(int);
void global_time(void);

#endif 
