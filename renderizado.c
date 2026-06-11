#include "common.h"

void renderizado()
{
    // Fondo
    SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
    SDL_RenderClear(renderer);
    


    // Recorrer filas
    for(int i = 0; i < 20; i++)
    {
        // Recorrer columnas
        for(int j = 0; j < 40; j++)
        {
            // Ignorar espacios vacíos
            if(tilemap[i][j] == 0)
            {
                continue;
            }

            // Crear rectángulo del tile
            SDL_Rect tile;


            tile.x = j * tileSize;
            tile.y = i * tileSize;

            // Tamaño del bloque
            tile.w = tileSize;
            tile.h = tileSize;


            if(tilemap[i][j]=='1')
            {
                SDL_Rect destino =
                {
                    j * tileSize,
                    i * tileSize,
                    tileSize,
                    tileSize
                };
                
                SDL_RenderCopy(renderer,tileLadrillosPiedra,NULL,&destino);
            }
            if(tilemap[i][j] == '2')
            {
                SDL_Rect destino =
                {
                    j * tileSize,
                    i * tileSize,
                    tileSize,
                    tileSize
                };
                
                SDL_RenderCopy(renderer,tileLadrillosPiedraQuebrados,NULL,&destino);
            }
            if(tilemap[i][j] == 'L')
            {
                SDL_Rect destino =
                {
                    j * tileSize,
                    i * tileSize,
                    tileSize,
                    tileSize
                };
                
                SDL_RenderCopy(renderer,tileLadrillosPuerta_Derecha_Arriba,NULL,&destino);
            }
            if(tilemap[i][j] == '4')
            {
                SDL_Rect destino =
                {
                    j * tileSize,
                    i * tileSize,
                    tileSize,
                    tileSize
                };
                
                SDL_RenderCopy(renderer,tileLadrillosPuerta_Derecha,NULL,&destino);
            }


            if(tilemap[i][j] == 'Z')
            {
                SDL_Rect destino =
                {
                    j * tileSize,
                    i * tileSize,
                    tileSize,
                    tileSize
                };
                
                SDL_RenderCopy(renderer,tileLadrillosPuerta_Izquierda_Arriba,NULL,&destino);
            }
            if(tilemap[i][j] == 'P')
            {
                SDL_Rect destino =
                {
                    j * tileSize,
                    i * tileSize,
                    tileSize,
                    tileSize
                };
                
                SDL_RenderCopy(renderer,tileLadrillosPuerta_Izquierda,NULL,&destino);
            }

        }
        // Jugador
        SDL_Rect player = { jugador.playerX, jugador.playerY, 32, 64 };
        
        


    SDL_Rect jugadorRect = { jugador.playerX, jugador.playerY, jugador.hitboxAncho, jugador.hitboxAltura };
    SDL_RenderCopy(renderer,PersonajeXD,NULL,&jugadorRect); 

    }

    SDL_RenderPresent(renderer);

    SDL_Delay(16); //60fps = 16,7

}