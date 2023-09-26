/*
    Nombre del archivo: ClasesDeAlmacenamiento_HaroCalvo_Fernando.c
    Autor: Fernando Haro Calvo
    Fecha de creación: 25 de septiembre de 2023
    Descripción: Juego de lotería y carrera de coches.
*/

// Librerias
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototipos de Funciones
void loteria(void);
void carrera(void);

int main()
{
    srand(time(NULL)); // Inicializa la semilla aleatoria.
    int op;
    do
    {
        system("CLS");
        printf("   M  E   N   U \n");
        printf("1.- JUEGO DE LA LOTERIA \n");
        printf("2.- LA CARRERA DE COCHES \n");
        printf("0.- SALIR  \n");
        printf("ESCOGE UNA OPCION: ");
        scanf("%d", &op);
        system("CLS");

        switch (op)
        {
        case 1:
            // TITULO
            printf("   JUEGO DE LA LOTERIA \n");
            loteria();

            system("PAUSE");
            break;

        case 2:
            // TITULO
            printf("   LA CARRERA DE COCHES \n");
            carrera();

            system("PAUSE");
            break;
        }
    } while (op != 0);

    return 0;
}

/*
    Función: generarNumeroLoteria
    Descripción: Genera un número aleatorio entre 1 y 100
*/
int generarNumeroLoteria()
{
    return rand() % 100 + 1;
}

/*
    Función: loteria
    Descripción: Simula un juego de lotería utilizando variables estáticas y automáticas.
*/
void loteria()
{
    static int numeroGanador = 0;

    // Si el número ganador no ha sido generado, genera uno
    if (numeroGanador == 0)
    {
        numeroGanador = generarNumeroLoteria();
    }

    // Genera el número del jugador
    int numeroJugador = generarNumeroLoteria();

    if (numeroJugador == numeroGanador)
    {
        printf("Felicidades, ganaste la loteria!, el numero ganador fue: %d\n", numeroGanador);
    }
    else
    {
        printf("Lo siento, no ganaste esta vez. El numero ganador era: %d, tu numero fue: %d\n", numeroGanador, numeroJugador);
    }
}

/*
    Función: carrera
    Descripción: Simula una carrera de coches utilizando variables de registro (register).
*/
void carrera()
{
}