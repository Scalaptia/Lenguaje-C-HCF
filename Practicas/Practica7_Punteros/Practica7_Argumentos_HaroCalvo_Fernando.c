/*
    Nombre del archivo: Practica7_Argumentos_HaroCalvo_Fernando.c
    Autor: Fernando Haro Calvo
    Fecha de creación: 6 de noviembre de 2023
*/

// Librerias
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[])
{
    printf("Numero total de argumentos: %d\n\n", argc);

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    printf("La suma de %d + %d = %d\n", num1, num2, num1 + num2);
    printf("La resta de %d - %d = %d\n", num1, num2, num1 - num2);
    printf("La multiplicacion de %d * %d = %d\n", num1, num2, num1 * num2);
    printf("La division de %d / %d = %d\n", num1, num2, num1 / num2);

    return 0;
}