#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct _speed
{
    int jugador;
    int esfera;
    float gravedad;
    float vertical;
}_velocidad;

typedef struct _jugador
{
    int playerX;
    int playerY;
    int Vida;

    int movimientoA_D;
    int hitboxAltura;
    int hitboxAncho;
    //gravedad

    _velocidad velocidad;
    //saltos
    int enSuelo;
    int salto;
    int saltodisponibles;

    int coyotesFrames;
    //esfera
    int estado;

} player;



extern player jugador;

extern int tileSize;
extern int running;

extern SDL_Window* window;
extern SDL_Renderer* renderer;

extern SDL_Texture *tileLadrillosPiedra;
extern SDL_Texture *tileLadrillosPiedraQuebrados;
extern SDL_Texture *tileLadrillosPuerta_Izquierda_Arriba;
extern SDL_Texture *tileLadrillosPuerta_Izquierda;
extern SDL_Texture *tileLadrillosPuerta_Derecha_Arriba;
extern SDL_Texture *tileLadrillosPuerta_Derecha;
extern SDL_Texture *PersonajeXD;

extern int salaX;
extern int salaY;

extern char *mundo[3][3];

extern char tilemap[20][40];
// enums

void loadSDL();
void loadGAME();

void input();

void logica();

void renderizado();

void movimiento();
void colisionesVerticales();
void gravedad();
void salto();
void agacharse();

void cargarMapa(char ruta[]);
void comprobarPuertas();

void cargarTexturas();

#endif