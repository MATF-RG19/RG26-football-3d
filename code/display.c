#include "display.h"

void set_init(int* argc, char** argv)
{
    // Inicijalizacija gluta
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
}

void create_window(void)
{
    // Kreiranje prozora
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glutInitWindowPosition(WIN_POS, WIN_POS);
    glutCreateWindow("Football 3D");
    glutFullScreen();
    
    // Ciscenje prozora, boja pozadine
    glClearColor(0,0,0,0);
}

void set_light(void)
{
    // Ukljucivanje dubine i svetla
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
    // Ambijentalna, difuzna i spekularna boja svetla scene
    GLfloat light_ambient[] = {0.3f, 0.3f, 0.3f, 1.0f};
    GLfloat light_diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat light_specular[] = {0.8f, 0.8f, 0.8f, 1.0f};
    
    // Postavljanje svojstava svetla
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
}

// Slika na pocektu igrice
void start_game(void)
{
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 2, 0,
              0, 0, 0,
              1, 0, 0);

    GLfloat light_position[] = {0, 0, 0, 1};
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_LIGHT0);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_n[START_SCREEN_NUM]);
    glBegin(GL_POLYGON);
        glNormal3f(0, 1, 0);

        glTexCoord2f(0, 0);
        glVertex3f(-0.75, 0, -1.5);

        glTexCoord2f(0, 1);
        glVertex3f(0.75, 0, -1.5);

        glTexCoord2f(1, 1);
        glVertex3f(0.75, 0, 1.5);

        glTexCoord2f(1, 0);
        glVertex3f(-0.75 ,0, 1.5);
        glEnd();
    glDisable(GL_TEXTURE_2D);
    
    glutSwapBuffers();
}

// Slika kada je postignut gol
void gooal(void)
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 2, 0,
              0, 0, 0,
              1, 0, 0);

    GLfloat light_position[] = {0, 0, 0, 1};
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_LIGHT0);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_n[GOOAL_NUM]);
    glBegin(GL_POLYGON);
        glNormal3f(0, 1, 0);

        glTexCoord2f(0, 0);
        glVertex3f(-0.5, 0, -0.5);

        glTexCoord2f(0, 1);
        glVertex3f(0.5, 0, -0.5);

        glTexCoord2f(1, 1);
        glVertex3f(0.5, 0, 0.5);

        glTexCoord2f(1, 0);
        glVertex3f(-0.5, 0, 0.5);
    glEnd();

    glDisable(GL_TEXTURE_2D);

    glutSwapBuffers();
}

// Slika na kraju igrice
void game_over(void)
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 2, 0,
              0, 0, 0,
              1, 0, 0);

    GLfloat light_position[] = {0, 0, 0, 1};
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_LIGHT0);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_n[GAME_OVER_NUM]);
    glBegin(GL_POLYGON);
        glNormal3f(0, 1, 0);

        glTexCoord2f(0, 0);
        glVertex3f(-0.75, 0, -1);

        glTexCoord2f(0, 1);
        glVertex3f(0.75, 0, -1);

        glTexCoord2f(1, 1);
        glVertex3f(0.75, 0, 1);

        glTexCoord2f(1, 0);
        glVertex3f(-0.75 ,0, 1);
    glEnd();

    glDisable(GL_TEXTURE_2D);

    glutSwapBuffers();
}
