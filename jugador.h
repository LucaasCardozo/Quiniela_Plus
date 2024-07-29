#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#include "carton.h"

struct JugadorE{

    char nombre[15];
    int dni;
    CartonPtr carton;

};

typedef struct JugadorE * JugadorPtr;

JugadorPtr crearJugadorPorTeclado();

JugadorPtr crearJugador(char n[15], int d);

void destruirJugador(JugadorPtr j);

void mostrarJugador(JugadorPtr j);

#endif // JUGADOR_H_INCLUDED
