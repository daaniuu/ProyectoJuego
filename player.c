#include "common.h"

void movimiento()
{
    int hitboxArribaJugador=jugador.playerY/tileSize;

    int hitboxAbajoJugador= (jugador.playerY+jugador.hitboxAltura-1)/tileSize;


    if(jugador.movimientoA_D==-1)
    {
        int hitboxLateralIzquierdo = (jugador.playerX - jugador.velocidad.jugador) / tileSize;

        int bloqueado = 0;
        int fila;
        for(fila = hitboxArribaJugador; fila <= hitboxAbajoJugador; fila++)
        {
            if(tilemap[fila][hitboxLateralIzquierdo] == '1')
            {
                bloqueado = 1;
                break;
            }
        }
 
        if(!bloqueado)
        {   if(jugador.estado==0)
                jugador.playerX -= jugador.velocidad.jugador;
            else if(jugador.estado==2)
                jugador.playerX -= jugador.velocidad.esfera;
        }
        else
        {
            jugador.playerX = (hitboxLateralIzquierdo + 1) * tileSize;
        }
    }


    if(jugador.movimientoA_D==1)
    {
        int hitboxLateralDerecho = (jugador.playerX + jugador.hitboxAncho + jugador.velocidad.jugador - 1) / tileSize;
 
        int bloqueado = 0;
        int fila;
        for(fila = hitboxArribaJugador; fila <= hitboxAbajoJugador; fila++)
        {
            if(tilemap[fila][hitboxLateralDerecho] == '1')
            {
                bloqueado = 1;
                break;
            }
        }
 
        if(!bloqueado)
        {
            if(jugador.estado==0)
                jugador.playerX += jugador.velocidad.jugador;
            else if (jugador.estado==2)
            {
                jugador.playerX += jugador.velocidad.esfera;
            }
            
        }
        else
        {
            jugador.playerX = (hitboxLateralDerecho * tileSize) - jugador.hitboxAncho;
        }
    }
}

void gravedad()
{
    if(jugador.enSuelo == 0)
    {
        jugador.velocidad.vertical += jugador.velocidad.gravedad;
 

        if(jugador.velocidad.vertical > 20.0f)
            jugador.velocidad.vertical = 20.0f;
 
        jugador.playerY += (int)jugador.velocidad.vertical;
    }
}

void colisionesVerticales()
{
    int hitboxAbajoJugador= (jugador.playerY+jugador.hitboxAltura-1)/tileSize;
    int hitboxArribaJugador=jugador.playerY/tileSize;
    int hitboxLateralDerecho = (jugador.playerX+jugador.hitboxAncho-1)/tileSize;
    int hitboxLateralIzquierdo = jugador.playerX/tileSize;    
    
    
    if(tilemap[hitboxAbajoJugador][hitboxLateralDerecho]=='1' || tilemap[hitboxAbajoJugador][hitboxLateralIzquierdo]=='1')
    {
        jugador.playerY = (hitboxAbajoJugador * tileSize) - jugador.hitboxAltura;
        jugador.velocidad.vertical = 0;
        jugador.enSuelo = 1;
        jugador.coyotesFrames=6;
        jugador.saltodisponibles =2;
    }
    else
    {
        jugador.enSuelo = 0;
    }

    //colisiones con el techo 
    if(tilemap[hitboxArribaJugador][hitboxLateralDerecho]=='1' || tilemap[hitboxArribaJugador][hitboxLateralIzquierdo]=='1')
    {
        jugador.playerY = (hitboxArribaJugador + 1) * tileSize;
        jugador.velocidad.vertical = 0;
    }
}

void salto()
{
    
    if(jugador.enSuelo==1 || jugador.coyotesFrames>0 || (jugador.estado==2 && jugador.saltodisponibles>0))
    {
        jugador.velocidad.vertical = -(float)jugador.salto;
        jugador.enSuelo=0;
        jugador.saltodisponibles--;
    }


}

void agacharse()
{
    if(jugador.estado == 0) 
    {
        jugador.estado       = 1;
        jugador.hitboxAltura = 32;
 
        jugador.playerY     += 32;
    }
    else if(jugador.estado == 1) 
    {
        jugador.estado = 2;

    }
    else if(jugador.estado == 2) 
    {
        int filaArriba    = (jugador.playerY - 32) / tileSize; // donde quedaria la cabeza
        int colIzq        = jugador.playerX / tileSize;
        int colDer        = (jugador.playerX + jugador.hitboxAncho - 1) / tileSize;
 
        if(tilemap[filaArriba][colIzq] != '1' && tilemap[filaArriba][colDer] != '1')
        {
            jugador.estado       = 0;
            jugador.hitboxAltura = 64;
            jugador.playerY     -= 32; 
        }

    }
}

void comprobarPuertas()
{
    int hitboxArribaJugador=jugador.playerY/tileSize;
    int hitboxAbajoJugador= (jugador.playerY+jugador.hitboxAltura-1)/tileSize;
    int hitboxLateralIzquierdo = (jugador.playerX - jugador.velocidad.jugador) / tileSize;
    int hitboxLateralDerecho = (jugador.playerX + jugador.hitboxAncho + jugador.velocidad.jugador - 1) / tileSize;
    int fila;

    for(fila = hitboxArribaJugador; fila <= hitboxAbajoJugador; fila++)
    {
        if(tilemap[fila][hitboxLateralIzquierdo] == 'P')
        {
            salaY--;
            
            cargarMapa(mundo[salaX][salaY]);
            printf("Colision con puerta Izquierda");
            jugador.playerX = 1200;
            break;
        }
    }

    for(fila = hitboxArribaJugador; fila <= hitboxAbajoJugador; fila++)
    {
        if(tilemap[fila][hitboxLateralDerecho] == '4')
        {
            salaY++;

            cargarMapa(mundo[salaX][salaY]);
            printf("Colision con puerta derecha");
            jugador.playerX = 40;
        }
    }
}
