/*
    Nombre del archivo: Taller3_Funciones_HaroCalvo_Fernando.c
    Autor: Fernando Haro Calvo
    Fecha de creación: 13 de septiembre de 2023
    Descripción: Funciones para calcular factorial (recursiva y no recursiva).
*/

#include <stdio.h>

void calcularFactorial(void);
void calcularFactorialRec(void);

int main()
{
    int op;
    do
    {
        system("CLS");
        printf("   M  E   N   U \n");
        printf("1.- FACTORIAL NO RECURSIVO \n");
        printf("2.- FACTORIAL RECURSIVO \n");
        printf("0.- SALIR  \n");
        printf("ESCOGE UNA OPCION: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            calcularFactorial();
            break;

        case 2:
            calcularFactorialRec();
            break;
        }
    } while (op != 0);
}

/*
    Función: calcularFactorial
    Descripción: Calcula e imprime el factorial de un numero ingresado.
*/
void calcularFactorial()
{
    //  VARIABLES LOCALES
    int n, i, res, op;

inicio:
    system("CLS");
    //	TITULO
    printf("   FACTORIAL\n");

    //	PROGRAMA
    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("El numero ingresado debe ser positivo\n");
        system("PAUSE");
        return;
    }

    for (i = n - 1, res = n; i > 1; i--)
    {
        res *= i;
    }
    printf("\nEl factorial de %d es: %d\n", n, res);
    system("PAUSE");

reinicio:
    system("CLS");
    printf("\nDesea calcular el factorial de otro numero? (1: Si / 2: No): ");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        goto inicio;
        break;

    case 2:
        printf("Finalizando programa...\n");
        system("PAUSE");
        return;
        break;

    default:
        goto reinicio;
        break;
    }
}

/*
    Función: calcularFactorialRec
    Descripción: Calcula e imprime el factorial de forma recursiva de un numero ingresado.
*/
void calcularFactorialRec()
{
    int n;

    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}