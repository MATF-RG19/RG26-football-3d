#include "main.h"

int main(int argc, char** argv)
{
    // Pokretanje Gluta
    set_init(&argc, argv);
    
    // Pravljenje prozora
    create_window();
    
    // Postavljanje callback funkcija
    set_callback();
    
    // Postavljanje svetla
    set_light();
    
    // Pravljenje kamere
    make_camera();
    
    // Pravljenje lopte
    make_ball();
    
    // Inicijalizacija tekstura
    init_textures();
  
    // Glavna petlja Gluta
    glutMainLoop();
    
    // Prekid programa
    exit(EXIT_SUCCESS);
}
