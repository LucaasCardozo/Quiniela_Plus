#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "carton.h"

CartonPtr crearCartonAutomatico(char d[15]){

    CartonPtr c = malloc(sizeof(struct CartonE));

    for(int i=0; i<8; i++){

        c->numeros[i] = rand()%100;

        while(busqueda(c->numeros, i, c->numeros[i]) == 1){

            c->numeros[i] = rand()%100;

        }

    }

    ordenamiento(c->numeros, 8);

    strcpy(c->direccion, d);

    guardarCarton(c);

    return c;

}

CartonPtr crearCartonPorTeclado(char d[15]){

    CartonPtr c = malloc(sizeof(struct CartonE));

    printf("\nPor favor ingrese los ocho numeros que van a conformar su carton (ACLARACION: EL CARTON NO PUEDE CONTENER NUMEROS REPETIDOS NI NUMEROS MAYORES O IGUALES A 100!!):\n");

    for(int i=0; i<8; i++){

        printf("- ");
        scanf("%d", &c->numeros[i]);

        while((busqueda(c->numeros, i, c->numeros[i]) == 1) || (c->numeros[i] >= 100)){

            printf("\nEL ULTIMO NUMERO INGRESADO ESTA REPETIDO O ES MAYOR A 100, POR FAVOR INGRESE OTRO NUMERO:\n");
            printf("- ");
            scanf("%d", &c->numeros[i]);

        }

    }

    ordenamiento(c->numeros, 8);

    strcpy(c->direccion, d);

    guardarCarton(c);

    return c;

}

void destruirCarton(CartonPtr c){

    free(c);

}

void mostrarCarton(CartonPtr c){

    printf("\n CARTON -> ");

    for(int i =0; i<8; i++){
        printf("%d ", c->numeros[i]);
    }

    printf("\n DIRECCION DE LA AGENCIA: %s", c->direccion);

    printf("\n");

}

void ordenamiento(int n[], int t){

    int aux;

    for(int i=0; i<t-1; i++){

        for(int k=i+1; k<t; k++){

            if(n[k] < n[i]){

                aux  = n[i];
                n[i] = n[k];
                n[k] = aux;

            }

        }

    }

}

int busqueda(int n[], int t, int loQBusco){

    for(int i=0; i<t; i++){

        if(n[i] == loQBusco){

            return 1;

        }

    }

    return 0;

}

void guardarCarton(CartonPtr c){

    FILE * archivo = fopen("carton.txt", "w");

    for(int i=0; i<8; i++){

        fprintf(archivo, "%d\t", c->numeros[i]);

    }

    fclose(archivo);

}
