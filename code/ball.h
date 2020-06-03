#ifndef BALL_H
#define BALL_H

#include "main.h"

// Kolizija terena
#define COLLISION_EDGE_Y 30.5
#define COLLISION_EDGE_X1 36.2
#define COLLISION_EDGE_X2 66.2

// Kolizija golova
#define COLLISION_GOAL_Y 5.75
#define COLLISION_GOAL_X1 32.2
#define COLLISION_GOAL_X2 62.2
#define GOOAL 63.5

// Startna pozicija lopte
#define BALL_X 34
#define BALL_Y 0
#define BALL_Z 0

// Precnik lopte
#define B_RADIUS 1
#define B_SLICES 25
#define B_STACKS 25
#define SHININESS 100

// Brzina kretanja lopte
#define MOVE 5
#define MOVE_STOP 100000

// Kolizija
#define EPS 0.01

// Uglovi skoka
#define ANGLE_START 0
#define ANGLE_EXT 180
// Brzinja rolanja lopte
#define P_ANGLE 3.9
// Visina skoka
#define JUMP_LEVEL 2
#define MAT_DIM 16
#define ROT_Z 0

// Za kretanje napred, nazad
#define ROT_FORWARD 1
#define ROT_BACKWARD -1

// Funkcije za loptu
void make_ball(void);
void set_ball(void);
void ball_forward(void);
void ball_backward(void);
int ball_jump(void);
void ball_roll(int);
void cone_collision(void);

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
    GLdouble move;
} ball;

// Struktura rotacije
struct rotation{
    GLdouble x, y;
    GLdouble matrix[MAT_DIM];
}rotation;

#endif 
