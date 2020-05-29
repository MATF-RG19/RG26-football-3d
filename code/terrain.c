#include "terrain.h"

// Funkcija za pravljenje scene
void make_scene(void)
{
  glPushMatrix(); 
  glTranslatef(-15, 0, 0);
  glEnable(GL_TEXTURE_2D);

  // Prednja strana scene
  glBindTexture(GL_TEXTURE_2D,texture_n[FRONT_SIDE_NUM]);
  glBegin(GL_POLYGON);
    glTexCoord2f(0,0);
    glVertex3f(-250,-250,250);
    
    glTexCoord2f(1,0);
    glVertex3f(-250,-250,-250);
    
    glTexCoord2f(1,1);
    glVertex3f(-250,250,-250);
    
    glTexCoord2f(0,1);
    glVertex3f(-250,250,250);
  glEnd();
  // Desna strana scene
  glBindTexture(GL_TEXTURE_2D,texture_n[RIGHT_SIDE_NUM]);
  glBegin(GL_POLYGON);
    glTexCoord2f(0,0);
    glVertex3f(-250,250,-250);
    
    glTexCoord2f(1,0);
    glVertex3f(250,250,-250);
    
    glTexCoord2f(1,1);
    glVertex3f(250,250,250);
    
    glTexCoord2f(0,1);
    glVertex3f(-250,250,250);
  glEnd();
  // Zadnja strana scene
  glBindTexture(GL_TEXTURE_2D,texture_n[BACK_SIDE_NUM]);
  glBegin(GL_POLYGON);
    glTexCoord2f(0,0);
    glVertex3f(250,-250,-250);
    
    glTexCoord2f(1,0);
    glVertex3f(250,-250,250);
    
    glTexCoord2f(1,1);
    glVertex3f(250,250,250);
    
    glTexCoord2f(0,1);
    glVertex3f(250,250,-250);
  glEnd();
  // Leva strana scene
  glBindTexture(GL_TEXTURE_2D,texture_n[LEFT_SIDE_NUM]);
  glBegin(GL_POLYGON);
    glTexCoord2f(1,1);
    glVertex3f(250,-250,-250);
    
    glTexCoord2f(0,1);
    glVertex3f(-250,-250,-250);
    
    glTexCoord2f(0,0);
    glVertex3f(-250,-250,250);
    
    glTexCoord2f(1,0);
    glVertex3f(250,-250,250);
  glEnd();
  // Donja strana scene
  glBindTexture(GL_TEXTURE_2D,texture_n[DOWN_SIDE_NUM]);
  glBegin(GL_POLYGON);
    glTexCoord2f(0,0); 
    glVertex3f(-250,-250,-250);

    glTexCoord2f(1,0); 
    glVertex3f(250,-250,-250);
    
    glTexCoord2f(1,1);
    glVertex3f(250,250,-250);
    
    glTexCoord2f(0,1);
    glVertex3f(-250,250,-250);
  glEnd();
  // Gornja strana scene
  glBindTexture(GL_TEXTURE_2D,texture_n[UP_SIDE_NUM]);
  glBegin(GL_POLYGON);
    glTexCoord2f(0,0);
    glVertex3f(250,-250,250);
    
    glTexCoord2f(1,0);
    glVertex3f(-250,-250,250);
    
    glTexCoord2f(1,1);
    glVertex3f(-250,250,250);
    
    glTexCoord2f(0,1);
    glVertex3f(250,250,250);
  glEnd();

  glDisable(GL_TEXTURE_2D);
  glPopMatrix();
}

void set_terrain(void)
{
    glEnable(GL_NORMALIZE);
    
    // Koordinatni sistem
//     glPushMatrix();
//         glTranslatef(35,0,-1);
//         int len = 100;
//         glDisable(GL_LIGHTING);
//         glBegin(GL_LINES);
//         
//             glColor3f(1,0,0);
//             glVertex3f(0,0,0);
//             glVertex3f(len,0,0);
// 
//             glColor3f(0,1,0);
//             glVertex3f(0,0,0);  
//             glVertex3f(0,-len,0);
// 
//             glColor3f(0,0,1);
//             glVertex3f(0,0,0);
//             glVertex3f(0,0,len);
//         glEnd();
//         glEnable(GL_LIGHTING);
//     glPopMatrix();
//     
//     // Drugi Koordinatni
//     glPushMatrix();
//         glTranslatef(-65,0,-1);
//         int len1 = 100;
//         glDisable(GL_LIGHTING);
//         glBegin(GL_LINES);
//         
//             glColor3f(1,0,0);
//             glVertex3f(0,0,0);
//             glVertex3f(-len1,0,0);
// 
//             glColor3f(0,1,0);
//             glVertex3f(0,0,0);  
//             glVertex3f(0,len1,0);
// 
//             glColor3f(0,0,1);
//             glVertex3f(0,0,0);
//             glVertex3f(0,0,len1);
//         glEnd();
//         glEnable(GL_LIGHTING);
//     glPopMatrix();
    
    // Crtanje prepreke
    glPushMatrix();
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(1,0.5,0);;
        glPushMatrix();
            glTranslatef(-65, 0, -1);
            GLUquadricObj *quadratic = gluNewQuadric();
            gluCylinder(quadratic, 1.25, 0.25, 3.5, 32, 32);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-65, 0, -1);
            glScalef(3.25, 3.25, 0.2);
            glutSolidCube(1);
        glPopMatrix();
    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();
    
    // Scena
    make_scene();
    
    // Crtanje trave
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_n[PITCH_TEXTURE_NUM]);
    glBegin(GL_POLYGON);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 1);
        glVertex3f(-69.25, -32, -1);

        glTexCoord2f(0, 0);
        glVertex3f(39.25, -32, -1);

        glTexCoord2f(1, 0);
        glVertex3f(39.25, 32, -1);

        glTexCoord2f(1, 1);
        glVertex3f(-69.25, 32, -1);
    glEnd();
    glDisable(GL_TEXTURE_2D);
        
    // Crtanje zemlje, donja strana
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_n[SOIL_TEXTURE_NUM]);
    glBegin(GL_POLYGON);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 1);
        glVertex3f(39.5, -32, -1);

        glTexCoord2f(0, 0);
        glVertex3f(39.5, -32, -3);

        glTexCoord2f(32, 0);
        glVertex3f(39.5, 32, -3);

        glTexCoord2f(32, 1);
        glVertex3f(39.5, 32, -1);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    
    // Crtanje zemlje, gornja strana
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_n[SOIL_TEXTURE_NUM]);
    glBegin(GL_POLYGON);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 1);
        glVertex3f(-69.5, -32, -1);

        glTexCoord2f(0, 0);
        glVertex3f(-69.5, -32, -3);

        glTexCoord2f(32, 0);
        glVertex3f(-69.5, 32, -3);

        glTexCoord2f(32, 1);
        glVertex3f(-69.5, 32, -1);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    
    // Crtanje zemlje, leva strana
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_n[SOIL_TEXTURE_NUM]);
    glBegin(GL_POLYGON);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 1);
        glVertex3f(-69.5, -32, -1);

        glTexCoord2f(0, 0);
        glVertex3f(-69.5, -32, -3);

        glTexCoord2f(55, 0);
        glVertex3f(39.5, -32, -3);

        glTexCoord2f(55, 1);
        glVertex3f(39.5, -32, -1);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    
    // Crtanje zemlje, desna strana
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_n[SOIL_TEXTURE_NUM]);
    glBegin(GL_POLYGON);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-69.5, 32, -3);
        
        glTexCoord2f(55, 0);
        glVertex3f(39.5, 32, -3);
        
        glTexCoord2f(55, 1);
        glVertex3f(39.5, 32, -1);
        
        glTexCoord2f(0, 1);
        glVertex3f(-69.5, 32, -1);

    glEnd();
    glDisable(GL_TEXTURE_2D);
    
    //Crtanje prvog gola
    glPushMatrix();
    glTranslatef(-1.5,0,0);
        GLfloat ambient_light2[] =  {0.7f, 0.7f, 0.7f, 1.0f};
        GLfloat diffuse_light2[] =  {0.7f, 0.7f, 0.7f, 1.0f};
        GLfloat specular_light2[] = {1.0f, 1.0f, 1.0f, 1.0f};

        // Postavljanje svojstava materijala
        glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_light2);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_light2);
        glMaterialfv(GL_FRONT, GL_SPECULAR, specular_light2);
        glMateriali(GL_FRONT, GL_SHININESS, SHININESS);
        
        //Desna stativa
        glPushMatrix(); 
        glTranslatef(35, 7, 1.22);
        glScalef(0.5, 0.5, 5.38);
            glutSolidCube(1);
        glPopMatrix();
        // Leva stativa
        glPushMatrix(); 
        glTranslatef(35, -7, 1.22);
        glScalef(0.5, 0.5, 5.38);
            glutSolidCube(1);
        glPopMatrix();
        //Precka
        glPushMatrix(); 
        glTranslatef(35, 0, 4.13);
        glScalef(0.5, 14.5, 0.5);
            glutSolidCube(1);
        glPopMatrix();
        
        //Pomocna desna
        glPushMatrix(); 
        glTranslatef(39, 7, 1.22);
        glScalef(0.5, 0.5, 5.38);
            glutSolidCube(1);
        glPopMatrix();
        // Pomocna leva stativa
        glPushMatrix(); 
        glTranslatef(39, -7, 1.22);
        glScalef(0.5, 0.5, 5.38);
            glutSolidCube(1);
        glPopMatrix();
        //Pomocna Precka
        glPushMatrix(); 
        glTranslatef(39, 0, 4.13);
        glScalef(0.5, 14.5, 0.5);
            glutSolidCube(1);
        glPopMatrix();
        
        //Desna spojnica
        glPushMatrix(); 
        glTranslatef(37, 7, 4.13);
        glScalef(4, 0.5, 0.5);
            glutSolidCube(1);
        glPopMatrix();
        //Leva spojnica
        glPushMatrix(); 
        glTranslatef(37, -7, 4.13);
        glScalef(4, 0.5, 0.5);
            glutSolidCube(1);
        glPopMatrix();
        
        //Gornja mreza
        glPushMatrix();
        glTranslatef(37, 0, 0);
        glLineWidth(3   );
        for(int i=0; i<=7; i++){
        glBegin(GL_LINES);
            glVertex3f(-2,  i, 4.13);
            glVertex3f( 2,  i, 4.13);
            glVertex3f( 2, -i, 4.13);
            glVertex3f(-2, -i, 4.13);
        glEnd();   
        }
        for(int j=0; j<=2; j++){
        glBegin(GL_LINES);
            glVertex3f( j, -7, 4.13);
            glVertex3f( j,  7, 4.13);
            glVertex3f(-j,  7, 4.13);
            glVertex3f(-j, -7, 4.13);
        glEnd();
        }
        glPopMatrix();
        
        //Desna mreza
        glPushMatrix();
        glTranslatef(37, 8, 1);
        glLineWidth(3   );
        for(int i=0; i<=2; i++){
        glBegin(GL_LINES);
            glVertex3f(-2, -1,  i);
            glVertex3f( 2, -1,  i);
            glVertex3f( 2, -1, -i);
            glVertex3f(-2, -1, -i);
        glEnd();   
        }
        for(int j=0; j<=2; j++){
        glBegin(GL_LINES);
            glVertex3f( j, -1,  3);
            glVertex3f( j, -1, -3);
            glVertex3f(-j, -1,  3);
            glVertex3f(-j, -1, -3);
        glEnd();
        }
        glPopMatrix();

        //Leva mreza
        glPushMatrix();
        glTranslatef(37, -6, 1);
        glLineWidth(3   );
        for(int i=0; i<=2; i++){
        glBegin(GL_LINES);
            glVertex3f(-2, -1,  i);
            glVertex3f( 2, -1,  i);
            glVertex3f( 2, -1, -i);
            glVertex3f(-2, -1, -i);
        glEnd();   
        }
        for(int j=0; j<=2; j++){
        glBegin(GL_LINES);
            glVertex3f( j, -1,  3);
            glVertex3f( j, -1, -3);
            glVertex3f(-j, -1,  3);
            glVertex3f(-j, -1, -3);
        glEnd();
        }
        glPopMatrix();
        
        //Zadnja mreza
        glPushMatrix();
        glTranslatef(40, 0, 1);
        glLineWidth(3   );
        for(int i=0; i<=3; i++){
        glBegin(GL_LINES);
            glVertex3f(-1, -7,  i);
            glVertex3f(-1,  7,  i);
            glVertex3f(-1,  7, -i);
            glVertex3f(-1, -7, -i);
        glEnd();   
        }
        for(int j=0; j<=7; j++){
        glBegin(GL_LINES);
            glVertex3f(-1,  j, -3);
            glVertex3f(-1,  j,  3);
            glVertex3f(-1, -j,  3);
            glVertex3f(-1, -j, -3);
        glEnd();
        }
        glPopMatrix();

    //Crtanje drugog gola, desna stativa
    glPushMatrix();
    glTranslatef(3,0,0);
        glPushMatrix();
        glTranslatef(-104, 0, 0);
        glRotated(180, 0, 0, 1);
        glTranslatef(-74, 0, 0);
            glPushMatrix(); 
            glTranslatef(35, 7, 1.22);
            glScalef(0.5, 0.5, 5.38);
                glutSolidCube(1);
            glPopMatrix();
            // Leva stativa
            glPushMatrix(); 
            glTranslatef(35, -7, 1.22);
            glScalef(0.5, 0.5, 5.38);
                glutSolidCube(1);
            glPopMatrix();
            //Precka
            glPushMatrix(); 
            glTranslatef(35, 0, 4.13);
            glScalef(0.5, 14.5, 0.5);
                glutSolidCube(1);
            glPopMatrix();
            
            //Pomocna desna
            glPushMatrix(); 
            glTranslatef(39, 7, 1.22);
            glScalef(0.5, 0.5, 5.38);
                glutSolidCube(1);
            glPopMatrix();
            // Pomocna leva stativa
            glPushMatrix(); 
            glTranslatef(39, -7, 1.22);
            glScalef(0.5, 0.5, 5.38);
                glutSolidCube(1);
            glPopMatrix();
            //Pomocna Precka
            glPushMatrix(); 
            glTranslatef(39, 0, 4.13);
            glScalef(0.5, 14.5, 0.5);
                glutSolidCube(1);
            glPopMatrix();
            
            //Desna spojnica
            glPushMatrix(); 
            glTranslatef(37, 7, 4.13);
            glScalef(4, 0.5, 0.5);
                glutSolidCube(1);
            glPopMatrix();
            //Leva spojnica
            glPushMatrix(); 
            glTranslatef(37, -7, 4.13);
            glScalef(4, 0.5, 0.5);
                glutSolidCube(1);
            glPopMatrix();
            
            //Gornja mreza
            glPushMatrix();
            glTranslatef(37, 0, 0);
            glLineWidth(3   );
            for(int i=0; i<=7; i++){
            glBegin(GL_LINES);
                glVertex3f(-2,  i, 4.13);
                glVertex3f( 2,  i, 4.13);
                glVertex3f( 2, -i, 4.13);
                glVertex3f(-2, -i, 4.13);
            glEnd();   
            }
            for(int j=0; j<=2; j++){
            glBegin(GL_LINES);
                glVertex3f( j, -7, 4.13);
                glVertex3f( j,  7, 4.13);
                glVertex3f(-j,  7, 4.13);
                glVertex3f(-j, -7, 4.13);
            glEnd();
            }
            glPopMatrix();
            
            //Desna mreza
            glPushMatrix();
            glTranslatef(37, 8, 1);
            glLineWidth(3   );
            for(int i=0; i<=2; i++){
            glBegin(GL_LINES);
                glVertex3f(-2, -1,  i);
                glVertex3f( 2, -1,  i);
                glVertex3f( 2, -1, -i);
                glVertex3f(-2, -1, -i);
            glEnd();   
            }
            for(int j=0; j<=2; j++){
            glBegin(GL_LINES);
                glVertex3f( j, -1,  3);
                glVertex3f( j, -1, -3);
                glVertex3f(-j, -1,  3);
                glVertex3f(-j, -1, -3);
            glEnd();
            }
            glPopMatrix();

            //Leva mreza
            glPushMatrix();
            glTranslatef(37, -6, 1);
            glLineWidth(3   );
            for(int i=0; i<=2; i++){
            glBegin(GL_LINES);
                glVertex3f(-2, -1,  i);
                glVertex3f( 2, -1,  i);
                glVertex3f( 2, -1, -i);
                glVertex3f(-2, -1, -i);
            glEnd();   
            }
            for(int j=0; j<=2; j++){
            glBegin(GL_LINES);
                glVertex3f( j, -1,  3);
                glVertex3f( j, -1, -3);
                glVertex3f(-j, -1,  3);
                glVertex3f(-j, -1, -3);
            glEnd();
            }
            glPopMatrix();
            
            //Zadnja mreza
            glPushMatrix();
            glTranslatef(40, 0, 1);
            glLineWidth(3   );
            for(int i=0; i<=3; i++){
            glBegin(GL_LINES);
                glVertex3f(-1, -7,  i);
                glVertex3f(-1,  7,  i);
                glVertex3f(-1,  7, -i);
                glVertex3f(-1, -7, -i);
            glEnd();   
            }
            for(int j=0; j<=7; j++){
            glBegin(GL_LINES);
                glVertex3f(-1,  j, -3);
                glVertex3f(-1,  j,  3);
                glVertex3f(-1, -j,  3);
                glVertex3f(-1, -j, -3);
            glEnd();
            }
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    
    // Crtanje donje ograde
    glPushMatrix();
        GLfloat ambient_light3[] = {0.4f, 0.4f, 0.4f, 1.0f};
        GLfloat diffuse_light3[] = {0.4f, 0.4f, 0.4f, 1.0f};
        GLfloat specular_light3[] = {1.0f, 1.0f, 1.0f, 1.0f};

        // Postavljanje svojstava materijala
        glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_light3);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_light3);
        glMaterialfv(GL_FRONT, GL_SPECULAR, specular_light3);
        glMateriali(GL_FRONT, GL_SHININESS, SHININESS);
    
        glPushMatrix();
            glTranslatef(39.375, 0, 0);
            glScalef(0.25, 64, 2.1);
            glutSolidCube(1);
        glPopMatrix();
        
        // Crtanje ornje ograde
        glPushMatrix();
            glTranslatef(-69.375, 0, 0);
            glScalef(0.25, 64, 2.1);
            glutSolidCube(1);
        glPopMatrix();
        
        // Crtanje leve ograde
        glPushMatrix();
            glTranslatef(-15, -31.875, 0);
            glScalef(109, 0.25, 2.1);
            glutSolidCube(1);
        glPopMatrix();
        
        // Crtanje desne ograde
        glPushMatrix();
            glTranslatef(-15, 31.875, 0);
            glScalef(109, 0.25, 2.1);
            glutSolidCube(1);
        glPopMatrix();
        
    glPopMatrix();
    
    glDisable(GL_NORMALIZE);
}

   

  
    














