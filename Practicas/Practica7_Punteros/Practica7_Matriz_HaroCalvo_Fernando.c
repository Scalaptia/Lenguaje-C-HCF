/*
    Nombre del archivo: Practica7_Matriz_HaroCalvo_Fernando.c
    Autor: Fernando Haro Calvo
    Fecha de creación: 7 de noviembre de 2023
*/

#include <stdio.h>

int main()
{
    int matriz[3][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};

    int max = 0, fila = 0, col = 0, suma = 0;

    int *puntero = &matriz[0][0];

    for (int i = 0; i < 3 * 3; i++)
    {
        suma += *puntero;
        if (*puntero > max)
        {
            max = *puntero;
            fila = i / 3;
            col = i % 3;
        }
        puntero++;
    }

    printf("\nSuma de la matriz: %d\n", suma);
    printf("Elemento mas grande: %d\n", max);
    printf("Fila %d\nColumna %d\n", fila, col);

    return 0;
}
