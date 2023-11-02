/*
    Nombre del archivo: Practica7_Punteros_HaroCalvo_Fernando.c
    Autor: Fernando Haro Calvo
    Fecha de creación: 1 de noviembre de 2023
*/

// Librerias
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[])
{
    printf("Numero total de argumentos: %d\n", argc);

    if (argc < 2)
    {
        printf("Debe proporcionar al menos un entero como argumento.\n");
        return 1;
    }

    int numero1 = atoi(argv[1]);
    int numero2 = atoi(argv[2]);

    printf("El entero ingresado es: %d\n", numero);

    return 0;

    return 0;
}