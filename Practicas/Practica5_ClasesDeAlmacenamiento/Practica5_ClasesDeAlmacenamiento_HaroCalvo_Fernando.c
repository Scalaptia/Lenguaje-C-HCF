/*
    Nombre del archivo: ClasesDeAlmacenamiento_HaroCalvo_Fernando.c
    Autor: Fernando Haro Calvo
    Fecha de creación: 25 de septiembre de 2023
    Descripción: Juego de lotería y carrera de coches.
*/

// Librerias
#include <stdio.h>
#include <stdlib.h>

// Prototipos de Funciones
void loteria(void);
void carrera(void);

int main()
{
    int op;
    do
    {
        system("CLS");
        printf("   M  E   N   U \n");
        printf("1.- JUEGO DE LA LOTERIA \n");
        printf("2.- LA CARRERA DE COCHES \n");
        printf("0.- SALIR  \n");
        printf("ESCOGE UNA OPCION: ");
        scanf("%d", &op);
        system("CLS");

        switch (op)
        {
        case 1:
            // TITULO
            printf("   JUEGO DE LA LOTERIA \n");
            loteria();

            system("PAUSE");
            break;

        case 2:
            // TITULO
            printf("   LA CARRERA DE COCHES \n");
            carrera();

            system("PAUSE");
            break;
        }
    } while (op != 0);

    return 0;
}

/*
    Función: loteria
    Descripción: Simula un juego de lotería utilizando variables estáticas y automáticas.
*/
void loteria()
{
}

/*
    Función: carrera
    Descripción: Simula una carrera de coches utilizando variables de registro (register).
*/
void carrera()
{
}