#include "ball.h"

void make_ball(void)
{
    // Centar, poluprecnik i preciznost lopte
    ball.x = B_CENTER;
    ball.y = B_CENTER;
    ball.z = B_CENTER;
    ball.precision = B_PRECISION;
    ball.radius = B_RADIUS;
}

void set_ball(void)
{
    // Ambijentalna, difuzna i spekularna boja svetla lopte
    GLfloat ambient_light[] = {0.5f, 0.5f, 0.5f, 1.0f};
    GLfloat diffuse_light[] = {0.5f, 0.5f, 0.5f, 1.0f};
    GLfloat specular_light[] = {1.0f, 1.0f, 1.0f, 1.0f};
    
    // Postavljanje svojstava materijala
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_light);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_light);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_light);
    glMateriali(GL_FRONT, GL_SHININESS, SHININESS);
    
    // Pomeranje u centar 
    glTranslated(ball.x, ball.y, ball.z);
    
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
}

void ball_backward(void)
{
    // Kretanje lopte unazad
    double length = sqrt(pow(camera.x - ball.x, 2)
                  + pow(camera.y - ball.y, 2)) * MOVE;
    ball.x += (camera.x - ball.x) / length;
    ball.y += (camera.y - ball.y) / length;
}
