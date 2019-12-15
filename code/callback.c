#include "callback.h"

void set_callback(void)
{
    // Postavljanje callback funkcija
    glutIdleFunc(on_idle);
    glutKeyboardFunc(on_button_push);
    glutKeyboardUpFunc(on_button_pull);
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);
    
    // Na pocetku nije nista pritisnuto
    keyboard = EMPTY;
}

void on_idle(void)
{
    // Reset kamere i kraj animacije
    if (keyboard & RESET){
        if (reset_camera() == RES_END){
            keyboard &= ~RESET;
        }
    }
    
    // Lopta se krece napred
    if (keyboard & FORWARD){
        ball_forward();
    }
    
    // Lopta se krece nazad
    if (keyboard & BACKWARD){
        ball_backward();
    }

    // Kretaneje kamere napred, nazad, gore, dole, desno, levo
    if (keyboard & ZOOM_IN){
        camera_zoom_in();
    }
    if (keyboard & ZOOM_OUT){
        camera_zoom_out();
    }
    if (keyboard & UP){
        camera_up();
    }
    if (keyboard & DOWN){
        camera_down();
    }
    
    // Rotacija lopte levo 
    if (keyboard & LEFT){
        if (keyboard & BACKWARD){
            camera_left();
        } else camera_right();
    }
    
    // Rotacija lopte desno
    if (keyboard & RIGHT){
        if (keyboard & BACKWARD){
            camera_right();
        } else camera_left();
    }
    
    // Skok lopte
    if (keyboard & JUMP){
        if (ball_jump() == JUMP_END){
            keyboard &= ~JUMP;
        }
    }
    
    // Refresh window
    glutPostRedisplay();
}

void on_button_push(unsigned char key, int x, int y)
{
    // Zanemaruje se mesto pritiska
    CANCEL(x);
    CANCEL(y);
    
    switch (key){
    case ESC:
        // Prekid programa
        exit(EXIT_SUCCESS);
        
    // Lopta se rotira levo, desno
    case 'a':
    case 'A':
        keyboard |= LEFT;
        break;
    
    case 'd':
    case 'D':
        keyboard |= RIGHT;
        break;
    
    // Lopta ide napred, nazad
    case 'w':
    case 'W':
        keyboard |= FORWARD;
        break;
        
    case 's':
    case 'S':
        keyboard |= BACKWARD;
        break;
    
    // Kamera se krece napred, nazad, dole, gore
    case 'l':
    case 'L':
        keyboard |= ZOOM_IN;
        break;
    
    case 'j':
    case 'J':
        keyboard |= ZOOM_OUT;
        break;
    
    case 'k':
    case 'K':
        keyboard |= DOWN;
        break;
    
    case 'i':
    case 'I':
        keyboard |= UP;
        break;
    
    // Resetovanje kamere
    case 'r':
    case 'R':
        keyboard |= RESET;
        break;
    
    // Skok lopte
    case SPACE:
        keyboard |= JUMP;
        break;
        
    case 'f':
    case 'F':
        // Preko celog ekrana
        glutFullScreenToggle();
        break;    
    }
}

void on_button_pull(unsigned char key, int x, int y)
{
    // Zanemaruje se mesto pritiska
    CANCEL(x);
    CANCEL(y);
    
    switch (key){
    case ESC:
        break;
    
    // Lopta se vise ne rotira levo, desno
    case 'd':
    case 'D':
        keyboard &= ~RIGHT;  
        break;
        
    case 'a':
    case 'A':
        keyboard &= ~LEFT;
        break;
        
    case 's':
    case 'S':
        // Lopta vise ne ide nazad
        keyboard &= ~BACKWARD;
        break;
    
    case 'w':
    case 'W':
        // Lopta vise ne ide napred
        keyboard &= ~FORWARD;
        break;
    
    // Kamera se vise ne krece napred, nazad, dole, gore
    case 'l':
    case 'L':
        keyboard &= ~ZOOM_IN;
        break;
    
    case 'j':
    case 'J':
        keyboard &= ~ZOOM_OUT;
        break;
    
    case 'k':
    case 'K':    
        keyboard &= ~DOWN;
        break;
    
    case 'i':
    case 'I':
        keyboard &= ~UP;
        break;
        
    case 'r':
    case 'R':
        break;
        
    case SPACE:
        break;
    }
}

void on_reshape(int width, int height)
{
    // Postavljanje pogleda i projekcije
    glViewport(0,0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(PERS_ANGLE, (float)width/height, 
                   PERS_NEAR, PERS_FAR);
}

void on_display(void)
{
    // Ciscenje prozora i matrica transformacije
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Polozaj svetla
    GLint light_position[] = {0, 0, 1, 0};
    glLightiv(GL_LIGHT0, GL_POSITION, light_position);
    
    // Racunanje pozicije kamere
    repair_camera();
    
    // Postavljanje vidnih parametara
    gluLookAt(camera.x, camera.y, camera.z, 
              ball.x,   ball.y,   ball.z,   
              NORM_X,   NORM_Y,   NORM_Z);  
    
    // Postavljanje terena
    set_terrain();
    
    // Crtanje lopte
    set_ball();
    
    // Prikaz slike 
    glutSwapBuffers();
}
