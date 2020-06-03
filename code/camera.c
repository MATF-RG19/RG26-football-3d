#include "camera.h"
 
void make_camera(void)
{
    // Postavljanje radijusa i uglova
    camera.r = CAMERA_RADIUS;
    camera.d_r = ZOOM_SPEED;
    camera.phi = CAMERA_PHI;
    camera.d_phi = ROTATION_SPEED;
    camera.theta = CAMERA_THETA;
    camera.d_theta = UP_DOWN_SPEED;
    
    // Postavljanje razlike
    diff.r = DIFF_BEGIN;
    diff.phi = DIFF_BEGIN;
    diff.theta = DIFF_BEGIN;
}
 
void update_camera(void)
{
    // Prevodjenje sfernih koordinata u Dekartove
    camera.x = ball.x + camera.r * cos(camera.theta) * cos(camera.phi);
    camera.y = ball.y + camera.r * cos(camera.theta) * sin(camera.phi);
    camera.z = ball.z + camera.r * sin(camera.theta);
} 

void camera_left(void)
{
    // Kamera ide levo
    camera.phi -= glob_time.diff * camera.d_phi;
    diff.phi--;
    
    // Popravka jer phi = [-pi, pi)
    if (camera.phi < CAMERA_PHI_MIN){
        camera.phi += CAMERA_PHI_AZIMUTH;
        diff.phi = (camera.phi - CAMERA_PHI) / ROTATION_SPEED;
    }
}

void camera_right(void)
{
    // Kamera ide desno
    camera.phi += glob_time.diff * camera.d_phi;
    diff.phi++;
    
    // Popravka jer phi = [-pi, pi)
    if (camera.phi >= CAMERA_PHI_MAX){
        camera.phi -= CAMERA_PHI_AZIMUTH;
        diff.phi = (camera.phi - CAMERA_PHI) / ROTATION_SPEED;
    }
}

void camera_up(void)
{
    // Kamera ide gore
    camera.theta += glob_time.diff * camera.d_theta;
    diff.theta++;
    
    // Popravka jer theta = [0, pi/2]
    if (camera.theta > CAMERA_THETA_MAX){
        camera.theta = CAMERA_THETA_MAX;
        diff.theta--;
    }
}

void camera_down(void)
{
    // Kamera ide dole
    camera.theta -= glob_time.diff * camera.d_theta;
    diff.theta--;
    
    // Popravka jer theta = [0, pi/2]
    if (camera.theta < CAMERA_THETA_MIN){
        camera.theta = CAMERA_THETA_MIN;
        diff.theta++;
    }
}

void camera_zoom_in(void)
{
    // Kamera ide napred
    camera.r -= glob_time.diff * camera.d_r;
    diff.r--;
    
    // Popravka jer r = [CAMERA_RADIUS_MIN, CAMERA_RADIUS_MAX] 
    if (camera.r < CAMERA_RADIUS_MIN){
        camera.r = CAMERA_RADIUS_MIN;
        diff.r++;
    }
}

void camera_zoom_out(void)
{
    // Kamera ide nazad
    camera.r += glob_time.diff * camera.d_r;
    diff.r++;
    
    // Popravka jer r = [CAMERA_RADIUS_MIN, CAMERA_RADIUS_MAX] 
    if (camera.r > CAMERA_RADIUS_MAX){
        camera.r = CAMERA_RADIUS_MAX;
        diff.r--;
    }
}

int reset_camera(void)
{
    // Animacija resetovanja kamere
    if (diff.r || diff.phi || diff.theta){
        if (diff.r > DIFF_BEGIN){
            camera_zoom_in();
        } 
        else if (diff.r < DIFF_BEGIN){
            camera_zoom_out();
        }
        
        diff.phi = DIFF_BEGIN;
        
        if (diff.theta > DIFF_BEGIN){
            camera_down();
        } 
        else if (diff.theta < DIFF_BEGIN){
            camera_up();
        }
    } 
    else return RESTART_OK;
    
    return RESTART_FALSE;
}
