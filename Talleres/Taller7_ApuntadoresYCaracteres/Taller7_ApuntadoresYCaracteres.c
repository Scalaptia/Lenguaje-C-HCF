/*
    Nombre del archivo: Taller7_ApuntadoresYCaracteres.c
    Autor: Fernando Haro Calvo
    Fecha de creación: 25 de octubre de 2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimirNombres(char *nombres[], int n);
void invertirCadena(char *cadena);
void ordenarPalabras(char *palabras[], int n);

int main()
{
    int op, i;
    char *nombres[3];
    nombres[0] = strdup("Fernando");
    nombres[1] = strdup("Ricardo");
    nombres[2] = strdup("Luis");

    char nombreTemp[50];

    char *palabras[5];
    for (i = 0; i < 5; i++)
    {
        palabras[i] = strdup("");
    }

    do
    {
        system("CLS");
        printf("   M  E   N   U \n");
        printf("1.- IMPRIMIR NOMBRES \n");
        printf("2.- INGRESAR E IMPRIMIR NOMBRES \n");
        printf("3.- INVERTIR NOMBRES \n");
        printf("4.- ORDENAR PALABRAS \n");
        printf("0.- SALIR  \n");
        printf("\nESCOGE UNA OPCION: ");
        scanf("%d", &op);
        system("CLS");

        switch (op)
        {
        case 1:
            for (i = 0; i < 3; i++)
            {
                printf("Nombre %d: %s\n", i + 1, nombres[i]);
            }
            break;

        case 2:
            for (i = 0; i < 3; i++)
            {
                printf("Ingrese el nombre %d: ", i + 1);
                fflush(stdin);
                gets(nombreTemp);
                strcpy(nombres[i], nombreTemp);
            }

            imprimirNombres(nombres, 3);
            break;

        case 3:
            invertirCadena(nombres[0]);
            invertirCadena(nombres[1]);
            invertirCadena(nombres[2]);

            printf("Nombres Invertidos...");
            break;

        case 4:
            for (i = 0; i < 5; i++)
            {
                printf("Ingrese la palabra %d: ", i + 1);
                fflush(stdin);
                gets(nombreTemp);
                strcpy(palabras[i], nombreTemp);
            }

            ordenarPalabras(palabras, 5);

            printf("\nPalabras ordenadas:\n");
            imprimirNombres(palabras, 5);
            break;

        case 0:
            return 0;
        }

        printf("\n");
        system("PAUSE");
    } while (op != 0);
}

void imprimirNombres(char *nombres[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", nombres[i]);
    }
}

void invertirCadena(char *cadena)
{
    int j = strlen(cadena) - 1;

    int i = 0;
    char temp;

    while (i < j)
    {
        temp = cadena[i];
        cadena[i] = cadena[j];
        cadena[j] = temp;
        i++;
        j--;
    }
}

void ordenarPalabras(char *palabras[], int n)
{
    int i, j;
    char *temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(palabras[i], palabras[j]) > 0)
            {
                temp = palabras[i];
                palabras[i] = palabras[j];
                palabras[j] = temp;
            }
        }
    }
}