/*
    Nombre del archivo: Taller5_ClasesDeAlmacenamiento_HaroCalvo_Fernando.c
    Autor: Fernando Haro Calvo
    Fecha de creación: 25 de septiembre de 2023
*/

#include <stdio.h>
#include <stdlib.h>

// Variable global
float pi = 3.14159;

void contadorAuto(void);
void contadorEstatico(void);
void variableLocal(void);

int main()
{
    int op, i;
    do
    {
        system("CLS");
        printf("   M  E   N   U \n");
        printf("1.- CONTADOR AUTO \n");
        printf("2.- VARIABLE EXTERNA \n");
        printf("3.- CONTADOR ESTATICO \n");
        printf("4.- VARIABLE TIPO REGISTRO \n");
        printf("5.- VARIABLE LOCAL Y GLOBAL \n");
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

        case 2:
            extern int saldo;
            printf("Desde el archivo 'variableExterna', (saldo) = %d\n", saldo);

            saldo -= 500;
            printf("Desde este archivo, (saldo - 500) = %d\n", saldo);
            break;

        case 3:
            for (i = 0; i < 10; i++)
            {
                contadorEstatico();
            }

            break;

        case 4:
            register int temp;
            auto int valor;

            temp = 10;
            valor = 10;

            printf("Valor de temp: %d\n", temp);
            printf("Valor de valor: %d\n", valor);

            break;

        case 5:
            printf("Valor de pi en la funcion main: %f\n", pi);
            variableLocal();
            printf("Valor de pi en la funcion main despues de 'variableLocal': %f\n", pi);

            break;

        case 0:
            return 0;
        }
        printf("\n");
        system("PAUSE");
    } while (op != 0);

    return 0;
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

/*
    Función: contadorAuto
    Descripción: Declara una variable local con el mismo nombre que una variable global y la imprime.
*/
void variableLocal()
{
    float pi = 3.14;

    printf("Valor de pi en la funcion 'variableLocal': %f\n", pi);
}