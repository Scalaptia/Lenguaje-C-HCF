#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int numAleatorio(int ri, int rf);
int busqSeqVect(int vect[], int n, int num);
void multiplicarPorDos(int *x);
void sumarAElementos(int *arr, int n, int val);

int main()
{
    srand(time(NULL));
    int op, i;
    int num;
    int x, *ptrx;
    int y, *ptry;
    int arr1[7], arr2[10];
    int *ptrArr1, *ptrArr2;

    do
    {
        system("CLS");
        printf("   M  E   N   U \n");
        printf("1.- APUNTADORES BASICOS \n");
        printf("2.- PASAR APUNTADORES A UNA FUNCION \n");
        printf("3.- ARREGLOS \n");
        printf("4.- MODIFICAR ELEMENTOS EN UN ARREGLO \n");
        printf("0.- SALIR  \n");
        printf("\nESCOGE UNA OPCION: ");
        scanf("%d", &op);
        system("CLS");

        switch (op)
        {
        case 1:
            ptrx = &x;

            x = 10;

            printf("X: %d, *ptr: %d", x, *ptrx);
            break;

        case 2:
            ptry = &y;

            y = 10;

            printf("Y antes: %d\n", y);

            multiplicarPorDos(ptry);

            printf("Y despues: %d", y);
            break;

        case 3:
            for (i = 0; i < 7; i++)
            {
                do
                {
                    num = numAleatorio(0, 50);
                } while (busqSeqVect(arr1, 7, num) != -1);

                arr1[i] = num;
            }

            ptrArr1 = arr1;

            for (i = 0; i < 7; i++)
            {
                printf("%d, ", *ptrArr1);
                ptrArr1++;
            }

            break;

        case 4:
            ptrArr2 = arr2;

            for (i = 0; i < 10; i++)
            {
                do
                {
                    num = numAleatorio(0, 50);
                } while (busqSeqVect(arr2, 10, num) != -1);

                arr2[i] = num;
            }

            printf("Arreglo original:   ");
            for (i = 0; i < 10; i++)
            {
                printf("%d, ", *ptrArr2);
                ptrArr2++;
            }
            ptrArr2 = arr2;

            sumarAElementos(ptrArr2, 10, 5); // Modificar arreglo
            ptrArr2 = arr2;

            printf("\nArreglo modificado: ");
            for (i = 0; i < 10; i++)
            {
                printf("%d, ", *ptrArr2);
                ptrArr2++;
            }

            break;

        case 0:
            return 0;
        }

        printf("\n\n");
        system("PAUSE");
    } while (op != 0);
}

/* Funciones Auxiliares */

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

void multiplicarPorDos(int *a)
{
    *a = (*a) * 2;
}

void sumarAElementos(int *arr, int n, int val)
{
    int i;

    for (i = 0; i < n; i++)
    {
        *arr += val;
        arr++;
    }
}