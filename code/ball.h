#ifndef BALL_H
#define BALL_H

#include "main.h"

// Opis lopte
#define B_CENTER 0
#define B_RADIUS 1
#define B_PRECISION 25
#define SHININESS 100
#define MOVE 10

// Struktura lopte
struct ball{
    // Koordinate centra, preciznost, poluprecnik
    GLdouble x, y, z;
    GLdouble precision;
    GLdouble radius;
} ball;

// Funkcije za loptu
void make_ball(void);
void set_ball(void);
void ball_forward(void);
void ball_backward(void);

#endif 
