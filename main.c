#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "jugador.h"
#include "carton.h"
#include "jugada.h"

int main()
{
    srand(time(0));

    JugadaPtr jugada = crearJugada();
    mostrarJugada(jugada);

    return 0;
}
