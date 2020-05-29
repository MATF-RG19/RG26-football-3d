#ifndef BALL_H
#define BALL_H

#include "main.h"

// Startna pozicija lopte
#define BALL_X 35    
#define BALL_Y 0
#define BALL_Z 0

// Precnik lopte
#define B_RADIUS 1
#define B_SLICES 25
#define B_STACKS 25
#define SHININESS 100
// Brzina kretanja lopte
#define MOVE 6

// Opis skoka i rotacije
#define ANGLE_START 0
#define ANGLE_EXT 180
#define P_ANGLE 3.9
#define JUMP_LEVEL 3
#define MAT_DIM 16
#define ROT_Z 0

// Za kretanje
#define ROT_FORWARD 1
#define ROT_BACKWARD -1

// Funkcije za loptu
void make_ball(void);
void set_ball(void);
void ball_forward(void);
void ball_backward(void);
int ball_jump(void);
void ball_roll(int);

enum {
    JUMP_FALSE, 
    JUMP_END
};

// Struktura lopte
struct ball{
    GLdouble x, y, z;
    GLdouble slices;
    GLdouble stacks;
    GLdouble radius;
    GLdouble jump_p;
    GLUquadricObj* quad;
} ball;

// Struktura rotacije
struct rotation{
    GLdouble x, y;
    GLdouble matrix[MAT_DIM];
}rotation;

#endif 
