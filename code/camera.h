#ifndef CAMERA_H
#define CAMERA_H

#include "main.h"

// Pocetni sferni parametri
#define CAMERA_RAD 5
#define CAMERA_PHI 0
#define CAMERA_THETA (M_PI/6)

// Promena parametara
#define CAMERA_RAD_D 0.05
#define CAMERA_PHI_D (M_PI/420)
#define CAMERA_THETA_D (M_PI/320)

// Min parametara
#define CAMERA_RAD_MIN 3
#define CAMERA_PHI_MIN -M_PI
#define CAMERA_THETA_MIN 0

// Max parametara
#define CAMERA_RAD_MAX 22
#define CAMERA_PHI_MAX M_PI
#define CAMERA_THETA_MAX (M_PI/2-M_PI/400)

// Pun krug za azimut
#define CAMERA_PHI_POM (2*M_PI)

// Razlike, resetovanje
#define DIFF_BEGIN 0
#define RES_END 1

// Struktura lopte sa centrom (x,y,z) i radijusom r
extern struct ball ball;

// Struktura kamere pomocu sfernih kordinata
struct camera{
    // Poluprecnik i promena
    GLdouble r, d_r;

    // Azimutni ugao i promena
    GLdouble phi, d_phi;
    
    // Polarni ugao i promena
    GLdouble theta, d_theta;
    
    // Dekartove koordinate
    GLdouble x, y, z;
} camera;

// Struktura razlike pocetnog i trenutnog stanja kamere
struct diff{
    int r;
    int phi;
    int theta;
} diff;

// Deklaracije funckija za kameru
void make_camera(void);
void repair_camera(void);
int reset_camera(void);
void camera_left(void);
void camera_right(void);
void camera_up(void);
void camera_down(void);
void camera_forward(void);
void camera_back(void);

#endif 
