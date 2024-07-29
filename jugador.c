#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "jugador.h"
#include "carton.h"

JugadorPtr crearJugadorPorTeclado(){

    JugadorPtr j = malloc(sizeof(struct JugadorE));

    printf("Por favor ingrese su nombre:\n");
    fflush(stdin);
    gets(j->nombre);

    printf("\nPor favor ingrese su dni:\n");
    scanf("%d", &j->dni);

    //j->carton = crearCartonAutomatico("Galicia 123");
    j->carton = crearCartonPorTeclado("Galicia 123");

    return j;

}

JugadorPtr crearJugador(char n[15], int d){

    JugadorPtr j = malloc(sizeof(struct JugadorE));

    strcpy(j->nombre, n);
    j->dni = d;
    j->carton = crearCartonAutomatico("Galicia 123");
    //j->carton = crearCartonPorTeclado("Galicia 123");

    return j;

}

void destruirJugador(JugadorPtr j){

    free(j);

}

void mostrarJugador(JugadorPtr j){

    printf("\n-------------- JUGADOR --------------\n");
    printf(" NOMBRE: %s\n", j->nombre);
    printf(" DNI: %d\n", j->dni);

    mostrarCarton(j->carton);

}
