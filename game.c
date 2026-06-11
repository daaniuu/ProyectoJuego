#include "common.h"

void loadSDL()
{
    SDL_Init(SDL_INIT_VIDEO);

    window=SDL_CreateWindow("Metroidvania",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1280,720,0);

    renderer=SDL_CreateRenderer(window,-1,0);

    if(SDL_Init(SDL_INIT_VIDEO)!=0) //para prevenir ventanas suicidas segun chatgpt por errores que tuve con las carpetas por el common.h  :p
    {
        printf("%s\n",SDL_GetError());

        getchar();

        return;
    }
}

SDL_Texture *tileLadrillosPiedra;
SDL_Texture *tileLadrillosPiedraQuebrados;
SDL_Texture *tileLadrillosPuerta_Izquierda_Arriba;
SDL_Texture *tileLadrillosPuerta_Izquierda;
SDL_Texture *tileLadrillosPuerta_Derecha_Arriba;
SDL_Texture *tileLadrillosPuerta_Derecha;
SDL_Texture *PersonajeXD;


int salaX;
int salaY;

char *mundo[3][3] =
{
    {
        "../assets/levels/mapa00.txt",
        "../assets/levels/mapa01.txt",
        "../assets/levels/mapa02.txt"
    },

    {
        "../assets/levels/mapa10.txt",
        "../assets/levels/mapa11.txt",
        "../assets/levels/mapa12.txt"
    },

    {
        "../assets/levels/mapa20.txt",
        "../assets/levels/mapa21.txt",
        "../assets/levels/mapa22.txt"
    }
};

void loadGAME()
{
    int i,j;

    running=1;

    jugador.playerX=100;
    jugador.playerY=100;

    jugador.velocidad.jugador=7;
    jugador.velocidad.esfera=4;
    jugador.movimientoA_D=0;

    jugador.hitboxAltura=64;
    jugador.hitboxAncho=32;
    jugador.velocidad.gravedad=0.5;
    jugador.velocidad.vertical=0;
    jugador.enSuelo=1;
    jugador.salto=12;
    jugador.saltodisponibles=2;
    jugador.estado=0;

    salaX = 0;
    salaY = 1;  

    cargarMapa(mundo[salaX][salaY]);

    cargarTexturas();

}

void cargarMapa(char ruta[])
{
    int i,j;
    
    FILE *fdata;
    
    fdata=fopen(ruta,"r");
    
    if(fdata==NULL)
    {
        printf("error\n");
        running=0;
        return;
    }
    else
    {
        printf("Mapa cargado :) \nEstas en el %s", ruta);
    }
    for(i=0;i<20;i++)
    {
        for(j=0;j<40;j++)
        {
            fscanf(fdata," %c",&tilemap[i][j]);
        }
    }
    
    fclose(fdata);
}

void cargarTexturas()
{
    SDL_Surface *surface;

    surface = IMG_Load("../assets/images/stone_bricks.png");
    if(surface == NULL)
    {
        printf("%s\n", IMG_GetError());
    }
    tileLadrillosPiedra =SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("../assets/images/cracked_stone_bricks.png");
    if(surface == NULL)
    {
        printf("%s\n", IMG_GetError());
    }
    tileLadrillosPiedraQuebrados =SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("../assets/images/puerta_derecha_arriba_ladrillos.png");
    if(surface == NULL)
    {
        printf("%s\n", IMG_GetError());
    }
    tileLadrillosPuerta_Derecha_Arriba =SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("../assets/images/puerta_derecha_ladrillos.png");
    if(surface == NULL)
    {
        printf("%s\n", IMG_GetError());
    }
    tileLadrillosPuerta_Derecha =SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);


    surface = IMG_Load("../assets/images/puerta_izquierda_arriba_ladrillos.png");
    if(surface == NULL)
    {
        printf("%s\n", IMG_GetError());
    }
    tileLadrillosPuerta_Izquierda_Arriba =SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("../assets/images/puerta_izquierda_ladrillos.png");
    if(surface == NULL)
    {
        printf("%s\n", IMG_GetError());
    }
    tileLadrillosPuerta_Izquierda =SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);


    surface = IMG_Load("../assets/images/garenXD.jpg");
    if(surface == NULL)
    {
        printf("%s\n", IMG_GetError());
    }
    PersonajeXD =SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);

}