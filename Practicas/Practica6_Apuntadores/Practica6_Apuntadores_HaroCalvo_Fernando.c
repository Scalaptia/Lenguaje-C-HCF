/*
    Nombre del archivo: Apuntadores_HaroCalvo_Fernando.c
    Autor: Fernando Haro Calvo
    Fecha de creación: 18 de octubre de 2023
    Descripción: Manipulación de cadenas usando apuntadores y funciones.
*/

// Librerias
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Prototipos de Funciones
void imprArr(int *arr, int n);
int sumaArr(int *arr, int n);
void copiarArr(int *copia, int *orig, int n);
void concatArr(int *concat, int *arr1, int n, int *arr2, int m);
int comparArr(int *arr1, int *arr2, int n);
int maxArr(int *arr, int n);

int main()
{
    int op, r;
    int vect1[] = {4, 7, 1, 5, 9};
    int vect2[] = {6, 5, 3, 2, 7};
    int vect3[] = {4, 7, 1, 5, 9};
    int vectCopy[5];
    int vectConcat[10];

    do
    {
        system("CLS");
        printf("   M  E   N   U \n");
        printf("1.- SUMA DE ELEMENTOS EN UN ARREGLO \n");
        printf("2.- COPIA DE ARREGLOS \n");
        printf("3.- CONCATENACION DE ARREGLOS \n");
        printf("4.- COMPARACION DE ARREGLOS \n");
        printf("5.- ENCONTRAR EL ELEMENTO MAXIMO \n");
        printf("0.- SALIR  \n");
        printf("ESCOGE UNA OPCION: ");
        scanf("%d", &op);
        system("CLS");

        switch (op)
        {
        case 1:
            r = sumaArr(vect1, 5);

            printf("Arreglo:\n");
            imprArr(vect1, 5);
            printf("\n\nLa suma de los elementos en el arreglo es: %d\n", r);
            break;

        case 2:
            copiarArr(vectCopy, vect1, 5);

            printf("Arreglo original:\n");
            imprArr(vect1, 5);
            printf("\n\nArreglo copia:\n");
            imprArr(vectCopy, 5);
            break;

        case 3:
            concatArr(vectConcat, vect1, 5, vect2, 5);

            printf("Arreglo 1:\n");
            imprArr(vect1, 5);
            printf("\n\nArreglo 2:\n");
            imprArr(vect2, 5);
            printf("\n\nArreglo Concatenado:\n");
            imprArr(vectConcat, 10);
            break;

        case 4:
            printf("Arreglo 1:\n");
            imprArr(vect1, 5);
            printf("\n\nArreglo 2:\n");
            imprArr(vect2, 5);

            if (comparArr(vect1, vect2, 5) == 1)
            {
                printf("\nSon iguales\n");
            }
            else
            {
                printf("\nSon distinitos\n");
            }

            printf("\n\nArreglo 1:\n");
            imprArr(vect1, 5);
            printf("\n\nArreglo 3:\n");
            imprArr(vect3, 5);

            if (comparArr(vect1, vect3, 5) == 1)
            {
                printf("\nSon iguales\n");
            }
            else
            {
                printf("\nSon distinitos\n");
            }
            break;

        case 5:
            printf("Arreglo 1:\n");
            imprArr(vect1, 5);

            r = maxArr(vect1, 5);
            printf("\n\nEl elemento maximo es: %d\n", r);
            break;

        case 0:
            return 0;
        }

        printf("\n");
        system("PAUSE");
    } while (1);
}

/*
    Función: imprArr
    Descripción: Calcula y devuelve la suma de los elementos en un arreglo.
*/
void imprArr(int *arr, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d, ", *(arr + i));
    }
}

/*
    Función: sumaArr
    Descripción: Calcula y devuelve la suma de los elementos en un arreglo.
*/
int sumaArr(int *arr, int n)
{
    int i, suma = 0;

    for (i = 0; i < n; i++)
    {
        suma += *(arr + i);
    }

    return suma;
}

/*
    Función: copiarArr
    Descripción: Crea una copia de un arreglo en otro arreglo.
*/
void copiarArr(int *copia, int *orig, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        *(copia + i) = *(orig + i);
    }
}

/*
    Función: concatArr
    Descripción: Toma dos arreglos de entrada y los concatena en un tercer arreglo.
*/
void concatArr(int *concat, int *arr1, int n, int *arr2, int m)
{
    int i;

    for (i = 0; i < n; i++)
    {
        *(concat + i) = *(arr1 + i);
    }

    for (i = 0; i < m; i++)
    {
        *(concat + n + i) = *(arr2 + i);
    }
}

/*
    Función: comparArr
    Descripción: Compara dos arreglos y determina si son iguales.
*/
int comparArr(int *arr1, int *arr2, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (*(arr1 + i) != *(arr2 + i))
        {
            return 0; // No son iguales
        }
    }

    return 1; // Si son iguales
}

/*
    Función: maxArr
    Descripción: Encuentra y devuelva el elemento máximo en el arreglo.
*/
int maxArr(int *arr, int n)
{
    int i;
    int max = arr[0];

    for (i = 1; i < n; i++)
    {
        if (*(arr + i) > max)
        {
            max = *(arr + i);
        }
    }

    return max;
}