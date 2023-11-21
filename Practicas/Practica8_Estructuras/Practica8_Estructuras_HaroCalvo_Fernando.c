/*
    Nombre del archivo: Practica8_Estructuras_HaroCalvo_Fernando.c
    Autor: Fernando Haro Calvo
    Fecha de creación: 20 de noviembre de 2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Producto
{
    char nombre[20];
    int cantidad;
    float precio;
} Producto;

void agregarProducto(Producto inventario[], int *n);
void retirarProducto(Producto inventario[], int *n);
void mostrarInventario(Producto inventario[], int n);
void valorTotal(Producto inventario[], int n);

int main()
{
    Producto inventario[MAX];
    int op, n = 0;

    do
    {
        system("CLS");
        printf("   M   E   N   U   \n");
        printf("1.- Agregar producto\n");
        printf("2.- Retirar producto\n");
        printf("3.- Mostrar inventario\n");
        printf("4.- Valor total\n");
        printf("5.- Salir\n");

        printf("\nOpcion: ");
        scanf("%d", &op);

        system("CLS");
        switch (op)
        {
        case 1:
            printf("Agregar producto\n\n");
            agregarProducto(inventario, &n);
            break;

        case 2:
            printf("Retirar producto\n\n");
            retirarProducto(inventario, &n);
            break;

        case 3:
            printf("Mostrar inventario\n");
            mostrarInventario(inventario, n);
            break;

        case 4:
            printf("Valor total del inventario\n\n");
            valorTotal(inventario, n);
            break;

        case 5:
            return 0;

        default:
            printf("Opcion no valida\n");
            break;
        }
        system("PAUSE");
    } while (1);
}

void agregarProducto(Producto inventario[], int *n)
{
    printf("Nombre: ");
    scanf("%s", inventario[*n].nombre);

    printf("Cantidad: ");
    scanf("%d", &inventario[*n].cantidad);

    printf("Precio: ");
    scanf("%f", &inventario[*n].precio);

    (*n)++;
}

void retirarProducto(Producto inventario[], int *n)
{
    char nombre[20];
    printf("Nombre: ");
    scanf("%s", nombre);

    for (int i = 0; i < *n; i++)
    {
        if (strcmp(inventario[i].nombre, nombre) == 0)
        {
            for (int j = i; j < *n - 1; j++)
            {
                inventario[j] = inventario[j + 1];
            }
            (*n)--;
            break;
        }
    }
}

void mostrarInventario(Producto inventario[], int n)
{
    if (n < 1)
    {
        printf("\nInventario vacio\n\n");
        return;
    }

    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("Nombre: %s\n", inventario[i].nombre);
        printf("Cantidad: %d\n", inventario[i].cantidad);
        printf("Precio: %.2f\n", inventario[i].precio);
    }
    printf("\n");
}

void valorTotal(Producto inventario[], int n)
{
    float total = 0;
    for (int i = 0; i < n; i++)
    {
        total += inventario[i].cantidad * inventario[i].precio;
    }

    printf("Valor total: %.2f\n\n", total);
}