#ifndef BALL_H
#define BALL_H

#include "main.h"

// Opis lopte
#define B_CENTER 0
#define B_RADIUS 1
#define B_PRECISION 20
#define SHININESS 100

// Struktura kamere
extern struct camera camera;

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

#endif 
