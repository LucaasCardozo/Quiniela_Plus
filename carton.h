#ifndef CARTON_H_INCLUDED
#define CARTON_H_INCLUDED

struct CartonE{

    int numeros[8];
    char direccion[15];

};

typedef struct CartonE * CartonPtr;

CartonPtr crearCartonAutomatico(char d[15]);

CartonPtr crearCartonPorTeclado(char d[15]);

void destruirCarton(CartonPtr c);

void mostrarCarton(CartonPtr c);

void ordenamiento(int n[], int t);

int busqueda(int n[], int t, int loQBusco);

void guardarCarton(CartonPtr c);

#endif // CARTON_H_INCLUDED
