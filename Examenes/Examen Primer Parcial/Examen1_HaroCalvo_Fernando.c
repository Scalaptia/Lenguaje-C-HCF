/*
    Examen Primer Parcial - Lenguaje C
    Fernando Haro Calvo
*/

#include <stdio.h>

int esPerfecto(int num);
void printDivisores(int num);

int main()
{
    int n, i, op;

inicio:
    do
    {
        system("CLS");
        printf("Ingresa el rango de numeros perfectos (entero positivo): ");
        scanf("%d", &n);
    } while (n < 1);

    system("CLS");
    printf("\nNumeros perfectos en el rango 1-%d:\n", n);
    for (i = 1; i <= n; i++)
    {
        if (esPerfecto(i) == 1)
        {
            printf("%d - Divisores: ", i);
            printDivisores(i);
            printf("\n");
        }
    }
    system("PAUSE");

reinicio:
    system("CLS");
    printf("\nDesea repetir el programa? (0- Salir, 1- Repetir) ");
    scanf("%d", &op);

    switch (op)
    {
    case 0:
        return 0;

    case 1:
        goto inicio;

    default:
        goto reinicio;
    }
}

// Un número perfecto es un número entero positivo que es igual a la suma de sus divisores propios positivos (excluyendo a sí mismo).
int esPerfecto(int num)
{
    int i, suma = 0;

    for (i = 1; i < num; i++)
    {
        // Verifica si i es un divisor de num
        if (num % i == 0)
        {
            suma += i;
        }
    }

    if (num == suma)
    {
        return 1; // Si es perfecto
    }

    return -1; // No es perfecto
}

void printDivisores(int num)
{
    int i;

    for (i = 1; i < num; i++)
    {
        // Verifica si i es un divisor de num
        if (num % i == 0)
        {
            printf("%d, ", i);
        }
    }
}