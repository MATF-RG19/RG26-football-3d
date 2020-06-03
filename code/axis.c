#include "axis.h"

void draw_axis(void) 
{
    //Koordinatni sistem
    glPushMatrix();
        glTranslatef(35,0,-1);
        int len = 100;
        glDisable(GL_LIGHTING);
        glBegin(GL_LINES);
        
            glColor3f(1,0,0);
            glVertex3f(0,0,0);
            glVertex3f(len,0,0);

            glColor3f(0,1,0);
            glVertex3f(0,0,0);  
            glVertex3f(0,-len,0);

            glColor3f(0,0,1);
            glVertex3f(0,0,0);
            glVertex3f(0,0,len);
        glEnd();
        glEnable(GL_LIGHTING);
    glPopMatrix();
    
    // Drugi Koordinatni
    glPushMatrix();
        glTranslatef(-65,0,-1);
        int len1 = 100;
        glDisable(GL_LIGHTING);
        glBegin(GL_LINES);
        
            glColor3f(1,0,0);
            glVertex3f(0,0,0);
            glVertex3f(-len1,0,0);

            glColor3f(0,1,0);
            glVertex3f(0,0,0);  
            glVertex3f(0,len1,0);

            glColor3f(0,0,1);
            glVertex3f(0,0,0);
            glVertex3f(0,0,len1);
        glEnd();
        glEnable(GL_LIGHTING);
    glPopMatrix();
}
