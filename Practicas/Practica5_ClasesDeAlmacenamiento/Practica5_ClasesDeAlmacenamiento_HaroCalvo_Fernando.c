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
#include <string.h>

// Prototipos de Funciones
int generarNumeroLoteria(void);
int generarVelocidadAleatoria(void);
void loteria(void);
void iniciarCarrera(void);

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

            printf("\n");
            system("PAUSE");
            break;

        case 2:
            // TITULO
            printf("   LA CARRERA DE COCHES \n");
            iniciarCarrera();

            printf("\n");
            system("PAUSE");
            break;
        }
    } while (op != 0);

    return 0;
}

/*
    Función: generarNumeroLoteria
    Descripción: Genera un número aleatorio entre 1 y 100.
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

    // Si el número ganador no ha sido generado, genera uno (el valor se mantendrá entre ejecuciones)
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
    Función: generarVelocidadAleatoria
    Descripción: Genera una velocidad aleatoria entre 100 y 200 km/h.
*/
int generarVelocidadAleatoria()
{
    return rand() % 101 + 100;
}

/*
    Función: iniciarCarrera
    Descripción: Simula una carrera de coches utilizando variables de registro (register).
*/
void iniciarCarrera()
{
    char n1[20] = "Rayo McQueen";
    char n2[20] = "Francesco Bernoulli";
    char n3[20] = "Mate";

    register int v1 = generarVelocidadAleatoria();
    register int v2 = generarVelocidadAleatoria();
    register int v3 = generarVelocidadAleatoria();

    int distancia = 1000;

    float t1 = (float)distancia / v1;
    float t2 = (float)distancia / v2;
    float t3 = (float)distancia / v3;

    // Mostrar los resultados de la carrera
    printf("\n%s - Velocidad: %d km/h - Tiempo: %.2fs\n", n1, v1, t1);
    printf("%s - Velocidad: %d km/h - Tiempo: %.2fs\n", n2, v2, t2);
    printf("%s - Velocidad: %d km/h - Tiempo: %.2fs\n\n", n3, v3, t3);

    // Identificar al coche ganador
    if (t1 < t2)
    {
        if (t1 < t3)
        {
            printf("%s es el ganador de la carrera!\n", n1);
        }
        else
        {
            printf("%s es el ganador de la carrera!\n", n3);
        }
    }
    else
    {
        if (t2 < t3)
        {
            printf("%s es el ganador de la carrera!\n", n2);
        }
        else
        {
            printf("%s es el ganador de la carrera!\n", n3);
        }
    }
}