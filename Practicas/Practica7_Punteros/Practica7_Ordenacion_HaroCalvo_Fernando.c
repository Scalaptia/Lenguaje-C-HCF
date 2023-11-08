/*
    Nombre del archivo: Practica7_Ordenacion_HaroCalvo_Fernando.c
    Autor: Fernando Haro Calvo
    Fecha de creación: 7 de noviembre de 2023
*/

#include <stdio.h>
#include <string.h>

#define NUM_PALABRAS 5

int main()
{
    char *palabras[NUM_PALABRAS] = {"manzana", "banana", "cereza", "uva", "naranja"};
    char *temp;
    int i, j;

    // Ordenar
    for (i = 0; i < NUM_PALABRAS - 1; i++)
    {
        for (j = i + 1; j < NUM_PALABRAS; j++)
        {
            if (strcmp(palabras[i], palabras[j]) > 0)
            {
                temp = palabras[i];
                palabras[i] = palabras[j];
                palabras[j] = temp;
            }
        }
    }

    // Imprimir
    for (i = 0; i < NUM_PALABRAS; i++)
    {
        printf("%s\n", palabras[i]);
    }

    return 0;
}
