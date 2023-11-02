/*
    Nombre del archivo: Taller8_ExperimentacionConPunteros.c
    Autor: Fernando Haro Calvo
    Fecha de creación: 31 de octubre de 2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solicitarNumero();
void llenarMatriz(int **q, int m, int n);

void imprimirMatriz_Metodo1(int *p, int m, int n);
void imprimirMatriz_Metodo2(int v[], int m, int n);
void imprimirMatriz_Metodo3(int A[][3], int m, int n);
void imprimirMatriz_Metodo4(int *p[], int m, int n);
void imprimirMatriz_Metodo5(int **q, int m, int n);

void busquedaLineal_Metodo1(int *p, int m, int n, int num);
void busquedaLineal_Metodo2(int v[], int m, int n, int num);
void busquedaLineal_Metodo3(int A[][3], int m, int n, int num);
void busquedaLineal_Metodo4(int *p[], int m, int n, int num);
void busquedaLineal_Metodo5(int **q, int m, int n, int num);

int main()
{
    int op, num;
    int m = 100, n = 15, i;

    int b[100][15];

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
        printf("1.- METODO 1 \n");
        printf("2.- METODO 2 \n");
        printf("3.- METODO 3 \n");
        printf("4.- METODO 4 \n");
        printf("5.- METODO 5 \n");
        printf("6.- LLENAR MATRIZ \n");
        printf("0.- SALIR \n");
        printf("\nESCOGE UNA OPCION: ");
        scanf("%d", &op);
        system("CLS");

        switch (op)
        {
        case 1:
            num = solicitarNumero();
            busquedaLineal_Metodo1(&b[0][0], m, n, num);
            imprimirMatriz_Metodo1(&b[0][0], m, n);
            break;

        case 2:
            num = solicitarNumero();
            busquedaLineal_Metodo2(&b[0][0], m, n, num);
            imprimirMatriz_Metodo2(&b[0][0], m, n);
            break;

        case 3:
            num = solicitarNumero();
            busquedaLineal_Metodo3(b, m, n, num);
            imprimirMatriz_Metodo3(b, m, n);
            break;

        case 4:
            num = solicitarNumero();
            busquedaLineal_Metodo4(q, m, n, num);
            imprimirMatriz_Metodo4(q, m, n);
            break;

        case 5:
            num = solicitarNumero();
            busquedaLineal_Metodo5(r, m, n, num);
            imprimirMatriz_Metodo5(r, m, n);
            break;

        case 6:
            llenarMatriz(r, m, n);
            printf("Matriz llenada");
            break;

        case 0:
            return 0;
        }

        printf("\n");
        system("PAUSE");
    } while (op != 0);
}

void llenarMatriz(int **q, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            q[i][j] = rand() % 1000;
        }
    }
}

int solicitarNumero()
{
    int num;
    printf("Ingrese el numero que desea buscar: ");
    scanf("%d", &num);

    return num;
}

void imprimirMatriz_Metodo1(int *p, int m, int n)
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

void imprimirMatriz_Metodo2(int v[], int m, int n)
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

void imprimirMatriz_Metodo3(int A[][3], int m, int n)
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

void imprimirMatriz_Metodo4(int *p[], int m, int n)
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

void imprimirMatriz_Metodo5(int **q, int m, int n)
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

void busquedaLineal_Metodo1(int *p, int m, int n, int num)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (*(p + i * n + j) == num)
            {
                printf("Numero %d encontrado en posicion [%d][%d]\n", num, i, j);
                return;
            }
        }
    }
    printf("Numero %d no encontrado\n", num);
}

void busquedaLineal_Metodo2(int v[], int m, int n, int num)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (v[i * n + j] == num)
            {
                printf("Numero %d encontrado en posicion [%d][%d]\n", num, i, j);
                return;
            }
        }
    }
    printf("Numero %d no encontrado\n", num);
}

void busquedaLineal_Metodo3(int A[][3], int m, int n, int num)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (A[i][j] == num)
            {
                printf("Numero %d encontrado en posicion [%d][%d]\n", num, i, j);
                return;
            }
        }
    }
    printf("Numero %d no encontrado\n", num);
}

void busquedaLineal_Metodo4(int *p[], int m, int n, int num)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (p[i][j] == num)
            {
                printf("Numero %d encontrado en posicion [%d][%d]\n", num, i, j);
                return;
            }
        }
    }
    printf("Numero %d no encontrado\n", num);
}

void busquedaLineal_Metodo5(int **q, int m, int n, int num)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (q[i][j] == num)
            {
                printf("Numero %d encontrado en posicion [%d][%d]\n", num, i, j);
                return;
            }
        }
    }
    printf("Numero %d no encontrado\n", num);
}