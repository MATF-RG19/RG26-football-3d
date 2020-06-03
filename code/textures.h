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
#define FANCE_FILE "textures/fance.bmp"
#define ADD_FILE "textures/add.bmp"
#define ADD1_FILE "textures/add1.bmp"
#define START_GAME_FILE "textures/start_screen.bmp"
#define GOOAL_FILE "textures/gooal.bmp"
#define GAME_OVER_FILE "textures/game_over.bmp"

#define BALL_TEXTURE_NUM 0
#define PITCH_TEXTURE_NUM 1
#define FRONT_SIDE_NUM 2
#define RIGHT_SIDE_NUM 3
#define LEFT_SIDE_NUM 4
#define BACK_SIDE_NUM 5
#define UP_SIDE_NUM 6
#define DOWN_SIDE_NUM 7
#define SOIL_TEXTURE_NUM 8
#define FANCE_TEXTURE_NUM 9
#define ADD_TEXTURE_NUM 10
#define ADD1_TEXTURE_NUM 11
#define START_SCREEN_NUM 12
#define GOOAL_NUM 13
#define GAME_OVER_NUM 14


GLuint texture_n[15];
void init_textures();

#endif
