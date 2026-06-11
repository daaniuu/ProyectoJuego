#include "common.h"

int espaciopresionadoAntes = 0;
int sPresionadoAntes = 0;
void input()
{
    SDL_Event event;

    jugador.movimientoA_D=0;

    while(SDL_PollEvent(&event))
    {
        if(event.type==SDL_QUIT)
        {
            running=0;
        }
    }

    const Uint8* keyboard=
    SDL_GetKeyboardState(NULL);

    int espacioPresionado= keyboard[SDL_SCANCODE_SPACE];
    if(espacioPresionado && !espaciopresionadoAntes)
    {
        salto();
    }
    espaciopresionadoAntes = espacioPresionado;



    int sAhora = keyboard[SDL_SCANCODE_S];
    if(sAhora && !sPresionadoAntes)
    {
        agacharse();
    }
    sPresionadoAntes = sAhora;
 

    if(jugador.estado != 1) // agachado no se mueve
    {
        if(keyboard[SDL_SCANCODE_A])
            jugador.movimientoA_D = -1;
 
        if(keyboard[SDL_SCANCODE_D])
            jugador.movimientoA_D = 1;
    }
}
 
