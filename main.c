#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

const static float pi = 3.141592653589793;

static float phi, theta;
static float delta_phi, delta_theta;

static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_display(void);

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);

    glutKeyboardFunc(on_keyboard);
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);
    
    glClearColor(0,0,0,0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);

    phi = theta = 0;
    delta_phi = delta_theta = pi / 90;
 
    //svetlo
	GLfloat light_ambient[] = {0.3, 0.3, 0.3, 1};
	GLfloat light_diffuse[] = {0.8, 0.8, 0.8, 1};
	GLfloat light_specular[] = {1, 1, 1, 1};

	GLfloat model_ambient[] = {1, 1, 1, 0};
	GLfloat light_position[] = {0, 0, 1, 0};
    
    glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);

    glEnable(GL_NORMALIZE);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    
   
    glutMainLoop();

    return 0;
}

static void on_keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
        /* Zavrsava se program. */
        exit(0);
        break;

    case 'd':
        phi -= delta_phi;
        if (phi > 2 * pi) {
            phi -= 2 * pi;
        } else if (phi < 0) {
            phi += 2 * pi;
        }
        glutPostRedisplay();
        break;

    case 'a':
        phi += delta_phi;
        if (phi > 2 * pi) {
            phi -= 2 * pi;
        } else if (phi < 0) {
            phi += 2 * pi;
        }
        glutPostRedisplay();
        break;

    case 'r':
    case 'R':
        phi = theta = 0;
        glutPostRedisplay();
        break;

    case 'w':
        theta -= delta_theta;
        if (theta > 2 * pi) {
            theta -= 2 * pi;
        } else if (theta < 0) {
            theta += 2 * pi;
        }
        glutPostRedisplay();
        break;

    case 's':
        theta += delta_theta;
        if (theta > 2 * pi) {
            theta -= 2 * pi;
        } else if (theta < 0) {
            theta += 2 * pi;
        }
        glutPostRedisplay();
        break;
    }
}

static void on_reshape(int width, int height)
{
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (float) width / height, 1, 10);
}

static void on_display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    gluLookAt(5 * cos(theta) * cos(phi),
              5 * cos(theta) * sin(phi),
              5 * sin(theta),
              0, 0, 0, 0, 0, 1);
    
    glRotatef(0, 0, 0, 1);
    glRotatef(0, 1, 0, 0);
    glutWireSphere(1.5,25,25);
    
     
    glutSwapBuffers();
}
