#include "base.h"

void set_initialization(int* argc, char** argv)
{
    // Inicijalizacija gluta
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
}

void create_window(void)
{
    // Kreiranje prozora
    glutInitWindowSize(WIN_SIZE, WIN_SIZE);
    glutInitWindowPosition(WIN_POS, WIN_POS);
    glutCreateWindow("Football 3D");
    
    // Ciscenje prozora
    glClearColor(0,0,0,0);
}

void set_light(void)
{
    // Ukljucivanje dubine i svetla
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
    //Ambijentalna, difuzna i spekularna boja svetla scene
    GLfloat light_ambient[] = {0.3f, 0.3f, 0.3f, 1.0f};
    GLfloat light_diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat light_specular[] = {0.8f, 0.8f, 0.8f, 1.0f};
    
    // Postavljanje svojstava svetla
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
}

void set_terrain(void)
{
   //Ambijentalna, difuzna i spekularna boja svetla terena
    GLfloat ambient_coeffs[] = {0.0f, 0.9f, 0.0f, 1.0f};
    GLfloat diffuse_coeffs[] = {0.0f, 0.9f, 0.0f, 1.0f};
    GLfloat specular_coeffs[] = {0.4f, 0.9f, 0.9f, 1.0f};
    
    // Postavljanje svojstava terena
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, SHININESS);
    
    // Keiranje terena
    for(int i=0; i<=10; i++){
    glBegin(GL_LINES);
        glVertex3i(-10,  i, -1);
        glVertex3i( 10,  i, -1);
        glVertex3i( 10, -i, -1);
        glVertex3i(-10, -i, -1);
    glEnd();   
    }
    for(int j=0; j<=10; j++){
    glBegin(GL_LINES);
        glVertex3i( j, -10, -1);
        glVertex3i( j,  10, -1);
        glVertex3i(-j,  10, -1);
        glVertex3i(-j, -10, -1);
    glEnd();
    }
}
