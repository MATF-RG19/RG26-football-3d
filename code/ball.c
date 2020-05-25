#include "ball.h"

void make_ball(void)
{
    // Centar, poluprecnik i preciznost lopte
    ball.x = BALL_X;
    ball.y = BALL_Y;
    ball.z = BALL_Z;
    ball.precision = B_PRECISION;
    ball.radius = B_RADIUS;
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glGetDoublev(GL_MODELVIEW_MATRIX, rotation.matrix);
}

void set_ball(void)
{
    // Ambijentalna, difuzna i spekularna boja svetla lopte
    GLfloat ambient_light[] = {0.7f, 0.7f, 0.7f, 1.0f};
    GLfloat diffuse_light[] = {0.7f, 0.7f, 0.7f, 1.0f};
    GLfloat specular_light[] = {1.0f, 1.0f, 1.0f, 1.0f};
    
    // Postavljanje svojstava materijala
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_light);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_light);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_light);
    glMateriali(GL_FRONT, GL_SHININESS, SHININESS);
    
    // Pomeranje lopte
    glTranslated(ball.x, ball.y, ball.z);
    
    glMultMatrixd(rotation.matrix);
    
    // Crtanje lopte
    glutSolidSphere(ball.radius, ball.precision, ball.precision);
}

void ball_forward(void)
{
    // Kretanje lopte napred
    double length = sqrt(pow(ball.x - camera.x, 2)
                  + pow(ball.y - camera.y, 2)) * MOVE;
    ball.x += (ball.x - camera.x) / length;
    ball.y += (ball.y - camera.y) / length;
    
    ball_roll(ROT_FORWARD);
}

void ball_backward(void)
{
    // Kretanje lopte unazad
    double length = sqrt(pow(camera.x - ball.x, 2)
                  + pow(camera.y - ball.y, 2)) * MOVE;
    ball.x += (camera.x - ball.x) / length;
    ball.y += (camera.y - ball.y) / length;
    
    ball_roll(ROT_BACKWARD);
}

int ball_jump(void)
{
    // Povratna vrednost
    int return_v = JUMP_FALSE;
    
    // Uvecavamo parametar skoka
    ball.jump_p += P_ANGLE;
    
    if (ball.jump_p >= ANGLE_EXT){
        ball.jump_p = ANGLE_START;
        return_v = JUMP_END;
    }
    
    ball.z = JUMP_LEVEL * sin(ball.jump_p * M_PI / ANGLE_EXT);
    
    return return_v;
}

void ball_roll(int direction)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    
    // Vektor rotacije
    rotation.x = camera.y - ball.y;
    rotation.y = ball.x - camera.x;
    
    GLdouble angle = direction * P_ANGLE;
    glRotated(angle, rotation.x, rotation.y, ROT_Z);
    
    glMultMatrixd(rotation.matrix);
    
    // Cuvanje nove matrice rotacije
    glGetDoublev(GL_MODELVIEW_MATRIX, rotation.matrix);
    
    glPopMatrix();
}

