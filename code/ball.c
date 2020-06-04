#include "ball.h"  

void make_ball(void)
{
    // Koordinate fudbalske lopte
    ball.x = BALL_X;
    ball.y = BALL_Y;
    ball.z = BALL_Z;
    ball.radius = B_RADIUS;
    ball.slices = B_SLICES;
    ball.stacks = B_STACKS;
    ball.move = MOVE;
    
    // quadric za fudbalsku loptu
    ball.quad = gluNewQuadric();
    gluQuadricDrawStyle(ball.quad, GLU_FILL);
    gluQuadricTexture(ball.quad, GL_TRUE);
    
    // Matrica rotacije se inicijalizuje na jedinicnu
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glGetDoublev(GL_MODELVIEW_MATRIX, rotation.matrix);
}

void set_ball(void) 
{
    // Transliranje lopte
    glTranslated(ball.x, ball.y, ball.z);
    
    // Za realniji izgled kretanja lopte po terenu
    glMultMatrixd(rotation.matrix);
    
    // Ukljucivanje teksture za loptu
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_n[BALL_TEXTURE_NUM]);
    glPushMatrix();
        // Pravimo fudbalsku loptu
        gluSphere(ball.quad, ball.radius, ball.slices, ball.stacks);
    glPopMatrix();
    
    // iskljucivanje teksture
    glDisable(GL_TEXTURE_2D);
}

// Kolizija sa preprekom
void cone_colission(void) {
    
    float d1 = powf((CONE_X - ball.x), 2);
    float d2 = powf((animation_parameter - ball.y), 2);

    float distance = sqrt(d1 + d2);

    if (distance < EPS_1) {
        start = END;
        glutDisplayFunc(game_over);
        glutPostRedisplay();
        glob_time.diff = END;
        // Vrati loptu na pocekat
        make_ball();
        set_ball();
        make_camera();
    }
    
}

void ball_forward(void)
{
    // Kretanje lopte napred
    double length = ball.move/glob_time.diff * sqrt(pow(ball.x - camera.x, 2) + pow(ball.y - camera.y, 2));
    ball.x += (ball.x - camera.x) / length;
    ball.y += (ball.y - camera.y) / length;
    
    ball_roll(ROT_FORWARD);
    
    // Kolizija, donja desna ivica terana
    if (ball.y >= COLLISION_EDGE_Y) {
            ball.y -= EPS;
            ball.move = MOVE_STOP;
            return;
    } else ball.move = MOVE;
    
    // Kolizija, donja leva ivica terena
    if (ball.x >= COLLISION_EDGE_X1 || ball.y <= -COLLISION_EDGE_Y) {
            ball.x -= EPS;
            ball.y += EPS;
            ball.move = MOVE_STOP;
            return;
    } else ball.move = MOVE;
    
    // Kolizija, gornja leva ivica terena
    if (ball.x <= -COLLISION_EDGE_X2) {
            ball.x += EPS;
            ball.move = MOVE_STOP;
            return;
    } else ball.move = MOVE;
    
    // Kolizija, gornja desna ivica terena
    if (ball.x <= -COLLISION_EDGE_X2) {
            ball.x += EPS;
            ball.move = MOVE_STOP;
            return;
    } else ball.move = MOVE;
    
    // Kolizija, donja desna stativa
    if (ball.x >= COLLISION_GOAL_X1 && ball.y >= COLLISION_GOAL_Y) {
        ball.x -= EPS;
        ball.y -= EPS;
        ball.move = MOVE_STOP;
        return;
    } else ball.move = MOVE;
    
    // Kolizija, donja leva stativa
    if (ball.x >= COLLISION_GOAL_X1 && ball.y <= -COLLISION_GOAL_Y) {
        ball.x -= EPS;
        ball.y += EPS;
        ball.move = MOVE_STOP;
        return;
    } else ball.move = MOVE;
    
    // Kolizija, gornja desna stativa
    if (ball.x <= -COLLISION_GOAL_X2 && ball.y >= COLLISION_GOAL_Y) {
        ball.x += EPS;
        ball.y -= EPS;
        ball.move = MOVE_STOP;
        return;
    } else ball.move = MOVE;
    
    // Kolizija, gornja leva stativa
    if (ball.x <= -COLLISION_GOAL_X2 && ball.y <= -COLLISION_GOAL_Y) {
        ball.x += EPS;
        ball.y += EPS;
        ball.move = MOVE_STOP;
        return;
    } else ball.move = MOVE;
    
    if(ball.x <= -GOOAL) {
        start = END;
        glutDisplayFunc(gooal);
        glob_time.diff = END;
        // Vrati loptu na pocekat
        make_ball();
        set_ball();
        make_camera();
    }
    cone_colission();
}

void ball_backward(void)
{
    // Kretanje lopte unazad
    double length = ball.move/glob_time.diff * sqrt(pow(camera.x - ball.x, 2) + pow(camera.y - ball.y, 2));
    ball.x += (camera.x - ball.x) / length;
    ball.y += (camera.y - ball.y) / length;
    
    ball_roll(ROT_BACKWARD);
    
    // Kolizija, donja desna ivica terana
    if (ball.y >= COLLISION_EDGE_Y) {
            ball.y -= EPS;
            ball.move = MOVE_STOP;
            return;
    } else ball.move = MOVE;
    
    // Kolizija, donja leva ivica terena
    if (ball.x >= COLLISION_EDGE_X1 || ball.y <= -COLLISION_EDGE_Y) {
            ball.x -= EPS;
            ball.y += EPS;
            ball.move = MOVE_STOP;
            return;
    } else ball.move = MOVE;
    
    // Kolizija, gornja leva ivica terena
    if (ball.x <= -COLLISION_EDGE_X2) {
            ball.x += EPS;
            ball.move = MOVE_STOP;
            return;
    } else ball.move = MOVE;
    
    // Kolizija, gornja desna ivica terena
    if (ball.x <= -COLLISION_EDGE_X2) {
            ball.x += EPS;
            ball.move = MOVE_STOP;
            return;
    } else ball.move = MOVE;
    
    // Kolizija, donja desna stativa
    if (ball.x >= COLLISION_GOAL_X1 && ball.y >= COLLISION_GOAL_Y) {
        ball.x -= EPS;
        ball.y -= EPS;
        ball.move = MOVE_STOP;
        return;
   } else ball.move = MOVE;
    
    // Kolizija, donja leva stativa
    if (ball.x >= COLLISION_GOAL_X1 && ball.y <= -COLLISION_GOAL_Y) {
        ball.x -= EPS;
        ball.y += EPS;
        ball.move = MOVE_STOP;
        return;
    } else ball.move = MOVE;
    
    // Kolizija, gornja desna stativa
    if (ball.x <= -COLLISION_GOAL_X2 && ball.y >= COLLISION_GOAL_Y) {
        ball.x += EPS;
        ball.y -= EPS;
        ball.move = MOVE_STOP;
        return;
    } else ball.move = MOVE;
    
    // Kolizija, gornja leva stativa
    if (ball.x <= -COLLISION_GOAL_X2 && ball.y <= -COLLISION_GOAL_Y) {
        ball.x += EPS;
        ball.y += EPS;
        ball.move = MOVE_STOP;
        return;
    } else ball.move = MOVE;
    
    if(ball.x <= -GOOAL) {
        start = END;
        glutDisplayFunc(gooal);
        glob_time.diff = END;
        set_ball();
        // Vrati loptu na pocekat
        make_ball();
        set_ball();
        make_camera();
    }
    
    cone_colission();
}
int ball_jump(void)
{
    // Povratna vrednost
    int return_v = JUMP_FALSE;
    
    // Uvecavamo parametar skoka
    ball.jump_p += glob_time.diff * P_ANGLE;
    
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
    
    GLdouble angle = glob_time.diff * P_ANGLE  * direction;
    glRotated(angle, rotation.x, rotation.y, ROT_Z);
    
    // Za realniji izgled kretanja lopte po terenu
    glMultMatrixd(rotation.matrix);
    
    // Cuvanje nove matrice rotacije
    glGetDoublev(GL_MODELVIEW_MATRIX, rotation.matrix);
    
    glPopMatrix();
}
