#ifndef TEXTURES_H
#define TEXTURES_H

#include "image.h"
#include <GL/glut.h>

#define BALL_FILE "textures/ball.bmp"
#define PITCH_FILE "textures/pitch.bmp"
#define FRONT_SIDE_FILE "textures/front.bmp"
#define RIGHT_SIDE_FILE "textures/right.bmp"
#define LEFT_SIDE_FILE "textures/left.bmp"
#define BACK_SIDE_FILE "textures/back.bmp"
#define UP_SIDE_FILE "textures/up.bmp"
#define DOWN_SIDE_FILE "textures/down.bmp"
#define SOIL_FILE "textures/soil.bmp"

#define BALL_TEXTURE_NUM 0
#define PITCH_TEXTURE_NUM 1
#define FRONT_SIDE_NUM 2
#define RIGHT_SIDE_NUM 3
#define LEFT_SIDE_NUM 4
#define BACK_SIDE_NUM 5
#define UP_SIDE_NUM 6
#define DOWN_SIDE_NUM 7
#define SOIL_TEXTURE_NUM 8


GLuint texture_n[9];
void init_textures();

#endif
