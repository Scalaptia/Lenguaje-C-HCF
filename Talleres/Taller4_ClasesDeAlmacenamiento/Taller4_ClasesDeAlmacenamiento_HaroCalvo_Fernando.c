/*
    Nombre del archivo: Taller4_ClasesDeAlmacenamiento_HaroCalvo_Fernando.c
    Autor: Fernando Haro Calvo
    Fecha de creación: 25 de septiembre de 2023
*/

#include <stdio.h>
#include <stdlib.h>

void contadorAuto(void);
void contadorEstatico(void);

int main()
{
    int op, i;
    do
    {
        system("CLS");
        printf("   M  E   N   U \n");
        printf("1.- CONTADOR AUTO \n");
        printf("3.- CONTADOR ESTATICO \n");
        printf("0.- SALIR  \n");
        printf("ESCOGE UNA OPCION: ");
        scanf("%d", &op);
        system("CLS");

        switch (op)
        {
        case 1:
            for (i = 0; i < 10; i++)
            {
                contadorAuto();
            }

            break;

        case 3:
            for (i = 0; i < 10; i++)
            {
                contadorEstatico();
            }

            break;

        case 0:
            return;
        }
        printf("\n");
        system("PAUSE");
    } while (op != 0);
}

/*
    Función: contadorAuto
    Descripción: Declara una variable automatica, aumenta 1 a su valor y lo imprime.
*/
void contadorAuto()
{
    auto int contador = 0;

    contador++;

    printf("%d\n", contador);
}

/*
    Función: contadorAuto
    Descripción: Declara una variable estática, aumenta 1 a su valor y lo imprime.
*/
void contadorEstatico()
{
    static int contador = 0;

    contador++;

    printf("%d\n", contador);
}