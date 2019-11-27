#ifndef BASE_H
#define BASE_H

#include "main.h"

// Opis prozora
#define WIN_SIZE 500
#define WIN_POS 100

// Opis osvetljenja
#define SHININESS 100

// Bazne funkcije
void set_initialization(int*, char**);
void create_window(void);
void set_light(void);
void set_terrain(void);

#endif 
