/*
    Nombre del archivo: Practica4_Funciones_HaroCalvo_Fernando.c
    Autor: Fernando Haro Calvo
    Fecha de creación: 13 de septiembre de 2023
    Descripción: Funciones con retorno y sin retorno
*/

// Librerias
#include <stdio.h>

// Prototipos de Funciones
void calcularFibonacci(int n);
int calcularFibonacciRecursion(int n);
void generarTrianguloPascal(int n);

int main()
{
    int op, res, n;
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

            calcularFibonacci(n);
            system("PAUSE");
            break;

        case 2:
            // TITULO
            printf("   FIBONACCI RECURSION \n");
            printf("Ingrese un numero entero positivo: ");
            scanf("%d", &n);

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

    return 0;
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
        printf("%d, ", res);
    }
    printf("\n");
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
    // Caso Base
    if (n <= 1)
    {
        return n;
    }

    // Caso Recursivo
    return calcularFibonacciRecursion(n - 1) + calcularFibonacciRecursion(n - 2);
}
/*
    Función: calcularCoeficienteBinomial
    Descripción: Funcion auxiliar para calcular el coeficiente binomial utilizando recursion.
    Formula: C(n, k) = n! / (k! * (n - k)!)
    Parámetros:
        - n: Número total de elementos.
        - k: Número de elementos a elegir.
*/
int calcularCoeficienteBinomial(int n, int k)
{
    // Caso Base
    if (k == 0 || k == n)
    {
        return 1;
    }

    // Caso Recursivo
    return calcularCoeficienteBinomial(n - 1, k - 1) + calcularCoeficienteBinomial(n - 1, k);
}

/*
    Función: generarTrianguloPascal
    Descripción: Genera e imprime n cantidad de filas del triangulo de pascal.
    Parámetros:
        - n: Número de filas deseado
*/
void generarTrianguloPascal(int n)
{
    int i, j;

    printf("\nTriangulo de Pascal con %d lineas:\n", n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= i; j++)
        {
            printf("%d ", calcularCoeficienteBinomial(i, j));
        }
        printf("\n");
    }
}