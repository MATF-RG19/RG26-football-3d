#ifndef CAMERA_H
#define CAMERA_H

#include "main.h"

// Startna pozicija kamere
#define CAMERA_RADIUS 14
#define CAMERA_PHI 0
#define CAMERA_THETA (M_PI/7)

// Brzina kretanja kamere (zoom in/out speed)
#define ZOOM_SPEED 0.1 
// Brzina rotiranja kamere levo-desno
#define ROTATION_SPEED (M_PI/120)
// Brzina kretanja kamere gore-dole
#define UP_DOWN_SPEED (M_PI/320) 

// Min zoom in vrednost kamere
#define CAMERA_RADIUS_MIN 8
#define CAMERA_PHI_MIN -M_PI
#define CAMERA_THETA_MIN 0

// Max zoom out vrednost kamere
#define CAMERA_RADIUS_MAX 100
#define CAMERA_PHI_MAX M_PI
#define CAMERA_THETA_MAX (M_PI/2-M_PI/400)

// Azimutni ugao
#define CAMERA_PHI_AZIMUTH (2*M_PI)

// Razlike, resetovanje
#define DIFF_BEGIN 0
#define RESTART_OK 1
#define RESTART_FALSE 0

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
int reset_camera(void);
void make_camera(void);
void update_camera(void);
void camera_left(void);
void camera_right(void);
void camera_up(void);
void camera_down(void);
void camera_zoom_in(void);
void camera_zoom_out(void);

#endif 
