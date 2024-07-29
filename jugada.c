#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "jugador.h"
#include "carton.h"
#include "jugada.h"

JugadaPtr crearJugada(){

    JugadaPtr j = malloc(sizeof(struct JugadaE));

    //j->jugador = crearJugadorPorTeclado();
    j->jugador = crearJugador("Lionel", 45365874);

    for(int i=0; i<20; i++){

        j->juego[i] = rand()%100;

    }

    return j;

}

void destruirJugada(JugadaPtr j){

    free(j);

}

void mostrarJugada(JugadaPtr j){

    mostrarJugador(j->jugador);

    printf("\n\n------------------------- JUGADA -------------------------\n\n");

    for(int i=0; i<20; i++){

        int n = 0;

        for(int k=0; k<8; k++){

            if(j->jugador->carton->numeros[k] == j->juego[i]){

                printf(" '%d'", j->juego[i]);

                k = 9;

                n = 1;

            }

        }

        if(n == 0){

            printf(" %d", j->juego[i]);

        }

    }

    printf("\n\n");

    mostrarAciertos(j->jugador, j);

}

int verificarCarton(CartonPtr c, int j[]){

    int aciertos = 0;

    for(int i=0; i<20; i++){

        for(int k=0; k<8; k++){

            if(c->numeros[k] == j[i]){

                aciertos = aciertos + 1;

            }

        }

    }

    return aciertos;

}

void mostrarAciertos(JugadorPtr j, JugadaPtr ju){

    int aciertos = verificarCarton(j->carton, ju->juego);

    switch(aciertos){

        case 0: printf("\n PERDISTE!! NO HAS TENIDO NINGUN ACIERTO\n");
                mostrarCuandoGanaria(ju);
                break;
        case 1: printf("\n PERDISTE!! HAS TENIDO SOLO %d ACIERTO\n", aciertos);
                mostrarCuandoGanaria(ju);
                break;
        case 2: printf("\n PERDISTE!! HAS TENIDO SOLO %d ACIERTOS\n", aciertos);
                mostrarCuandoGanaria(ju);
                break;
        case 3: printf("\n PERDISTE!! HAS TENIDO SOLO %d ACIERTOS\n", aciertos);
                mostrarCuandoGanaria(ju);
                break;
        case 4: printf("\n PERDISTE!! HAS TENIDO SOLO %d ACIERTOS\n", aciertos);
                mostrarCuandoGanaria(ju);
                break;
        case 5: printf("\n GANASTE 50 PESOS!! HAS TENIDO %d ACIERTOS\n", aciertos);
                mostrarCuandoGanaria(ju);
                break;
        case 6: printf("\n GANASTE 500 PESOS!! HAS TENIDO %d ACIERTOS\n", aciertos);
                mostrarCuandoGanaria(ju);
                break;
        case 7: printf("\n GANASTE 20 MIL PESOS!! HAS TENIDO %d ACIERTOS\n", aciertos);
                mostrarCuandoGanaria(ju);
                break;
        case 8: printf("\n GANASTE 11 MILLONES DE PESOS!! HAS TENIDO %d ACIERTOS", aciertos);
                break;

    }

    printf("\n");

}

int jugarHastaGanar(JugadorPtr jue, JugadaPtr ju){

    int num = 0;

    while((verificarCarton(jue->carton, ju->juego)) != 8){

        for(int i=0; i<20; i++){

        ju->juego[i] = rand()%100;

        }

        num = num + 1;

    }

    return num;

}

void mostrarCuandoGanaria(JugadaPtr j){

    int n = jugarHastaGanar(j->jugador, j);

    if(n == 1){

        printf("\n PARA LLEGAR A GANAR CON 8 ACIERTOS TENDRIAS QUE JUGAR CON EL MISMO CARTON %d VEZ MAS!!\n", n);

    }else{

        printf("\n PARA LLEGAR A GANAR CON 8 ACIERTOS TENDRIAS QUE JUGAR CON EL MISMO CARTON %d VECES MAS!!\n", n);

    }

}

int generarAleatorio(int maximo, int minimo){

    int num = minimo + rand()%(maximo-minimo+1);

    return num;

};
