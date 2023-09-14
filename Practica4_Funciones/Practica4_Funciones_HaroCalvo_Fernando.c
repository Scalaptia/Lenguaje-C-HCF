/*
    Nombre del archivo: Practica4_Funciones_HaroCalvo_Fernando.c
    Autor: Fernando Haro Calvo
    Fecha de creación: 13 de septiembre de 2023
    Descripción: Funciones con retorno y sin retorno
*/

#include <stdio.h>

void calcularFibonacci(int n);
int calcularFibonacciRecursion(int n);
void generarTrianguloPascal(int n);

int main()
{
    int op, i, res, n;
    do
    {
        system("CLS");
        printf("   M  E   N   U \n");
        printf("1.- FIBONACCI \n");
        printf("2.- FIBONACCI RECURSION \n");
        printf("3.- TRIANGULO DE PASCAL \n");
        printf("0.- SALIR  \n");
        printf("ESCOGE UNA OPCION: ");
        scanf("%d", &op);
        system("CLS");

        switch (op)
        {
        case 1:
            // TITULO
            printf("   FIBONACCI \n");
            printf("Ingrese un numero entero positivo: ");
            scanf("%d", &n);

            if (n < 0)
            {
                printf("El numero ingresado debe ser positivo\n");
                system("PAUSE");
                break;
            }

            calcularFibonacci(n);
            system("PAUSE");
            break;

        case 2:
            // TITULO
            printf("   FIBONACCI RECURSION \n");
            printf("Ingrese un numero entero positivo: ");
            scanf("%d", &n);

            if (n < 0)
            {
                printf("El numero ingresado debe ser positivo\n");
                system("PAUSE");
                break;
            }

            res = calcularFibonacciRecursion(n);
            printf("\nEl %d termino de fibonacci es: %d\n", n, res);
            system("PAUSE");
            break;

        case 3:
        pascal:
            // TITULO
            printf("   TRIANGULO DE PASCAL \n");
            printf("Ingrese el numero de filas deseado: ");
            scanf("%d", &n);

            if (n < 0)
            {
                printf("El numero ingresado debe ser positivo\n");
                system("PAUSE");
                break;
            }

            generarTrianguloPascal(n);
            printf("\n");
            system("PAUSE");

        reinicio:
            system("CLS");
            printf("\nDesea generar otro triangulo de pascal? (1: Si / 2: No): ");
            scanf("%d", &op);

            switch (op)
            {
            case 1:
                system("CLS");
                goto pascal;
                break;

            case 2:
                system("CLS");
                printf("Finalizando...\n");
                system("PAUSE");
                break;

            default:
                goto reinicio;
                break;
            }
        }
    } while (op != 0);
}

/*
    Función: calcularFibonacci
    Descripción: Calcula e imprime el n termino de fibonacci.
    Parámetros:
        - n: Número entero positivo
*/
void calcularFibonacci(int n)
{
    int cont, ant, sig, res;

    for (cont = 0, ant = -1, sig = 1, res = 0; cont < n; cont++)
    {
        ant = sig;
        sig = res;
        res = ant + sig;
    }

    printf("\nEl %d termino de fibonacci es: %d\n", n, res);
}

/*
    Función: calcularFibonacciRecursion
    Descripción: Calcula y retorna el n termino de fibonacci de forma recursiva.
    Parámetros:
        - n: Número entero positivo
    Valor de retorno: n termino de la secuencia de fibonacci.
*/
int calcularFibonacciRecursion(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return calcularFibonacciRecursion(n - 1) + calcularFibonacciRecursion(n - 2);
    }
}

/*
    Función: calcularTrianguloPascal
    Descripción: Genera e imprime n cantidad de filas del triangulo de pascal.
    Parámetros:
        - n: Número de filas deseado
*/

// Funcion auxiliar para calcular factorial.
int factorial(int n)
{
    int i, res = 1;
    for (i = 1; i <= n; i++)
    {
        res *= i;
    }

    return res;
}

void generarTrianguloPascal(int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        printf("\nFila %d: ", i + 1);

        for (j = 0; j <= i; j++)
        {
            printf("%d ", (factorial(i) / (factorial(j) * factorial(i - j))));
        }
    }
}