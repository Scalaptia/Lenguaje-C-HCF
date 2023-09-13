/*
    Nombre del archivo: Practica3_JuegoAdivinanza_HaroCalvo_Fernando.c
    Autor: Fernando Haro Calvo
    Fecha de creación: 12 de septiembre de 2023
    Descripción: Juego de adivinanza de números utilizando etiquetas y la instrucción "goto" para controlar el flujo del juego.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    system("CLS");
    srand(time(NULL));                 // Inicializa generador de números aleatorios
    int numSecreto = rand() % 100 + 1; // Escoger número
    int intento, op, numIntentos = 0;

inicio:
    printf("Bienvenido al juego de adivinar el numero!\n\n");
    printf("- Para ganar, debes escribir un numero entre el 1 y el 100\n");
    printf("- Si el numero esta por debajo o por encima del correcto, tendras otro intento\n");
    printf("- Si el numero es correcto, ganas!\n\n");
    system("PAUSE");
    system("CLS");

adivinanza:
    printf("Ingrese un numero entre 1 y 100: ");
    scanf("%d", &intento);
    numIntentos++;

    if (intento < 1 || intento > 100)
    {
        printf("El numero debe estar entre 1 y 100.\n");
        goto adivinanza;
    }

    if (intento < numSecreto)
    {
        printf("Demasiado bajo\n");
        goto adivinanza;
    }
    else if (intento > numSecreto)
    {
        printf("Demasiado alto\n");
        goto adivinanza;
    }
    else
    {
        printf("\nAdivinaste el numero %d en %d intentos\n", numSecreto, numIntentos);
        system("PAUSE");
        system("CLS");
        goto reinicio;
    }

reinicio:
    printf("Desea jugar otra vez? (1: Si / 2: No): ");
    scanf("%d", &op);
    system("CLS");

    switch (op)
    {
    case 1:
        numIntentos = 0;
        numSecreto = rand() % 100 + 1;
        goto adivinanza;
        break;

    case 2:
        printf("Gracias por jugar!\n");
        printf("Finalizando programa...");
        return 0;

    default:
        goto reinicio;
        break;
    }
}