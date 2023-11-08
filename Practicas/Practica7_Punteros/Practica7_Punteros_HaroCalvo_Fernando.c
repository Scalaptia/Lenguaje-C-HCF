/*
    Nombre del archivo: Practica7_Punteros_HaroCalvo_Fernando.c
    Autor: Fernando Haro Calvo
    Fecha de creación: 6 de noviembre de 2023
*/

// Librerias
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Constantes
#define NUM_PALABRAS 5

// Prototipos de funciones
void argumentos(char *argv[]);
void matriz();
void ordenacion();

int main(int argc, char *argv[])
{
    int op;

    do
    {
        printf("   M   E   N   U   \n");
        printf("1.- OPERACIONES CON ARGUMENTOS \n");
        printf("2.- ANALISIS DE MATRIZ \n");
        printf("3.- ORDENACION DE PALABRAS \n");
        printf("0. Salir\n");

        scanf("%d", &op);
        system("CLS");

        switch (op)
        {
        case 1:
            argumentos(argv);
            system("PAUSE");
            break;
        case 2:
            matriz();
            system("PAUSE");
            break;
        case 3:
            ordenacion();
            system("PAUSE");
            break;
        case 0:
            printf("Saliendo...\n");
            break;
        }

        system("CLS");
        printf("\n");
    } while (op != 0);

    return 0;
}

void argumentos(char *argv[])
{
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    printf("La suma de %d + %d = %d\n", num1, num2, num1 + num2);
    printf("La resta de %d - %d = %d\n", num1, num2, num1 - num2);
    printf("La multiplicacion de %d * %d = %d\n", num1, num2, num1 * num2);
    printf("La division de %d / %d = %d\n", num1, num2, num1 / num2);
}

void matriz()
{
    int matriz[3][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};

    int max = 0, fila = 0, col = 0, suma = 0;

    int *ptr = &matriz[0][0];

    for (int i = 0; i < 3 * 3; i++)
    {
        suma += *ptr;
        if (*ptr > max)
        {
            max = *ptr;
            fila = i / 3;
            col = i % 3;
        }
        ptr++;
    }

    printf("\nSuma de la matriz: %d\n", suma);
    printf("Elemento mas grande: %d\n", max);
    printf("Fila %d\nColumna %d\n", fila, col);
}

void ordenacion()
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
}
