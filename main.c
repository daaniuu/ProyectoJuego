#include "common.h"

player jugador;

int tileSize=32;

int running;

SDL_Window* window;
SDL_Renderer* renderer;

char tilemap[20][40];


int main(int argc,char *argv[])
{
    loadSDL();

    loadGAME();

    while(running)
    {
        input();

        logica();

        renderizado();
    }

    SDL_DestroyRenderer(renderer);

    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}

void logica()
{
    if(jugador.coyotesFrames>0)
        jugador.coyotesFrames--;
        
    movimiento();
    gravedad();
    colisionesVerticales();
    comprobarPuertas();
}