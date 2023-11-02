/*
    Nombre del archivo: Taller8_ExperimentacionConPunteros.c
    Autor: Fernando Haro Calvo
    Fecha de creación: 31 de octubre de 2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int op;
    int b[4][3] = {{1, 2, 3},
                   {4, 5, 6},
                   {7, 8, 9},
                   {10, 11, 12}};

    int m = 4, n = 3, i;
    int *q[m];

    for (i = 0; i < m; i++)
    {
        q[i] = &b[i][0];
    }

    int **r = q;

    do
    {
        system("CLS");
        printf("   M  E   N   U \n");
        printf("1.- IMPRIMIR MATRIZ \n");
        printf("2.- IMPRIMIR MATRIZ \n");
        printf("3.- IMPRIMIR MATRIZ \n");
        printf("4.- IMPRIMIR MATRIZ \n");
        printf("5.- IMPRIMIR MATRIZ \n");
        printf("0.- SALIR  \n");
        printf("\nESCOGE UNA OPCION: ");
        scanf("%d", &op);
        system("CLS");

        switch (op)
        {
        case 1:
            imprimirMatriz(&b[0][0], 4, 3);
            break;

        case 2:
            imprimirMatriz2(&b[0][0], 4, 3);
            break;

        case 3:
            imprimirMatriz3(b, 4, 3);
            break;

        case 4:
            imprimirMatriz4(q, 4, 3);
            break;

        case 5:
            imprimirMatriz5(r, 4, 3);
            break;

        case 0:
            return 0;
        }

        printf("\n");
        system("PAUSE");
    } while (op != 0);
}

void imprimirMatriz(int *p, int m, int n)
{
    int i, j;
    printf("La matriz es: \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", *(p + i * n + j));
        }
        printf("\n");
    }
    printf("\n");
}

void imprimirMatriz2(int v[], int m, int n)
{
    int i, j;
    printf("La matriz es: \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", v[i * n + j]);
        }
        printf("\n");
    }
    printf("\n");
}

void imprimirMatriz3(int A[][3], int m, int n)
{
    int i, j;
    printf("La matriz es: \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void imprimirMatriz4(int *p[], int m, int n)
{
    int i, j;
    printf("La matriz es: \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", p[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void imprimirMatriz5(int **q, int m, int n)
{
    int i, j;
    printf("La matriz es: \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", q[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}