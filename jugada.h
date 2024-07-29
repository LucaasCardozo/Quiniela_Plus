#ifndef JUGADA_H_INCLUDED
#define JUGADA_H_INCLUDED

#include "carton.h"
#include "jugador.h"

struct JugadaE{

    int juego[20];
    JugadorPtr jugador;

};

typedef struct JugadaE * JugadaPtr;

JugadaPtr crearJugada();

void destruirJugada(JugadaPtr j);

void mostrarJugada(JugadaPtr j);

int verificarCarton(CartonPtr c, int j[]);

void mostrarAciertos(JugadorPtr j, JugadaPtr ju);

int jugarHastaGanar(JugadorPtr jue, JugadaPtr ju);

void mostrarCuandoGanaria(JugadaPtr j);

int generarAleatorio(int maximo, int minimo);

#endif // JUGADA_H_INCLUDED
