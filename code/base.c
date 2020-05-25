#include "base.h"

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
