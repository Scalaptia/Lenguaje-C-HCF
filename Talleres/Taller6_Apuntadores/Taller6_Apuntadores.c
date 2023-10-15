#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multiplicarPorDos(int *x);

int numAleatorio(int ri, int rf)
{
    int rango = (rf - ri + 1);

    return rand() % rango + ri;
}

int busqSeqVect(int vect[], int n, int num)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (vect[i] == num)
        {
            return i; // Retorna índice
        }
    }

    return -1; // No se encontró
}

int main()
{
    srand(time(NULL));
    int op, i;
    do
    {
        system("CLS");
        printf("   M  E   N   U \n");
        printf("1.- APUNTADORES BASICOS \n");
        printf("2.- PASAR APUNTADORES A UNA FUNCION \n");
        printf("3.- ARREGLOS \n");
        printf("4.- MODIFICAR ELEMENTOS EN UN ARREGLO \n");
        printf("0.- SALIR  \n");
        printf("ESCOGE UNA OPCION: ");
        scanf("%d", &op);
        system("CLS");

        switch (op)
        {
        case 1:
            int x, *ptrx; // Declarar entero 'x' y puntero a entero 'ptr'
            ptrx = &x;    // Asignar puntero ptr a dirección de 'x'

            x = 10;

            printf("X: %d, *ptr: %d", x, *ptrx);
            break;

        case 2:
            int y, *ptry;
            ptry = &y;

            y = 10;

            printf("Y antes: %d\n", y);

            multiplicarPorDos(ptry);

            printf("Y despues: %d", y);
            break;

        case 3:
            int arr[7], num;

            for (i = 0; i < 7; i++)
            {
                do
                {
                    num = numAleatorio(0, 50);
                } while (busqSeqVect(arr, 7, num) != -1);

                arr[i] = num;
            }

            int *ptrArr = arr;

            for (i = 0; i < 7; i++)
            {
                printf("%d, ", *ptrArr);
                ptrArr++;
            }
            break;

        case 4:

            break;

        case 0:
            return 0;
        }

        printf("\n");
        system("PAUSE");
    } while (op != 0);

    return 0;
}

void multiplicarPorDos(int *a)
{
    *a = (*a) * 2;
}