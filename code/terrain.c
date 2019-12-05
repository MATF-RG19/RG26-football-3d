#include "terrain.h"

void set_terrain(void)
{
    glEnable(GL_NORMALIZE);
    // Crtanje trave
    glPushMatrix();
        // Ambijentalna, difuzna i spekularna boja svetla terena
        GLfloat ambient_light[] = {0.0f, 0.7f, 0.2f, 1.0f};
        GLfloat diffuse_light[] = {0.0f, 0.7f, 0.2f, 1.0f};
        GLfloat specular_light[] = {0.1f, 0.1f, 0.1f, 0.1f};

        // Postavljanje svojstava materijala
        glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_light);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_light);
        glMaterialfv(GL_FRONT, GL_SPECULAR, specular_light);
        glMateriali(GL_FRONT, GL_SHININESS, SHININESS);

        glTranslatef(-15, 0, -1.3);
        glScalef(30, 20, 0.5);
        glutSolidCube(1);
    glPopMatrix();
    
    // Crtanje zemlje
    glPushMatrix();
        // Ambijentalna, difuzna i spekularna boja svetla terena
        GLfloat ambient_light1[] = {0.5f, 0.20f, 0.05f, 1.0f};
        GLfloat diffuse_light1[] = {0.5f, 0.20f, 0.05f, 1.0f};
        GLfloat specular_light1[] = {0.1f, 0.1f, 0.1f, 0.1f};

        // Postavljanje svojstava materijala
        glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_light1);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_light1);
        glMaterialfv(GL_FRONT, GL_SPECULAR, specular_light1);
        glMateriali(GL_FRONT, GL_SHININESS, SHININESS);
    
        glTranslatef(-15, 0, -2.1);
        glScalef(30, 20, 1.1);
        glutSolidCube(1);
    glPopMatrix();
    glDisable(GL_NORMALIZE);
}
