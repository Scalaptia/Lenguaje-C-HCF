#include <stdio.h>
#include <stdlib.h>

typedef struct Mascota
{
    int ID;
    char nombre[30];
    char animal[30];
    char duenio[30];
    long telefono; // No puede ser int porque el numero de telefono es muy grande
    int status;
} Mascota;

#define MAX 10

void agregarRegistro(Mascota vect[], int n);
int buscarRegistro(Mascota vect[], int n, int idBuscado);
void imprRegistro(Mascota vect[], int n, int id);
void escrArchivo(Mascota vect[], int n);
void cargarArchivo(Mascota vect[], int *n);

int main()
{
    Mascota vect[MAX];
    int n = 0;
    int op = 0;
    int id = 0;

    cargarArchivo(vect, &n);

    do
    {
        system("CLS");
        printf("1. Agregar registro\n");
        printf("2. Imprimir registro\n");
        printf("3. Escribir archivo\n");
        printf("4. Salir\n");
        scanf("%d", &op);

        system("CLS");
        switch (op)
        {
        case 1:
            agregarRegistro(vect, n);
            n++;

            break;
        case 2:
            printf("ID a imprimir: ");
            scanf("%d", &id);
            imprRegistro(vect, n, id);

            break;
        case 3:
            escrArchivo(vect, n);
            printf("Archivo escrito con exito\n");
            break;
        }

        system("PAUSE");
    } while (op != 4);

    return 0;
}

void agregarRegistro(Mascota vect[], int n)
{
    n++;
    Mascota reg; // Se crea una variable de tipo Mascota
                 // donde se guardara el registro a agregar al vector

    reg.status = 1;
    printf("Duenio: ");
    fflush(stdin);
    gets(reg.duenio);

    printf("Animal: ");
    fflush(stdin);
    gets(reg.animal);

    printf("Nombre de la mascota: ");
    fflush(stdin);
    gets(reg.nombre);

    printf("Telefono: ");
    scanf("%d", &reg.telefono);

    reg.ID = n;
    vect[n] = reg;
}

int buscarRegistro(Mascota vect[], int n, int idBuscado)
{
    for (int i = 0; i <= n; i++) // Debe ser <= porque el vector empieza en 0
    {
        if (vect[i].ID == idBuscado)
        {
            return i;
        }
    }

    return -1;
}

void imprRegistro(Mascota vect[], int n, int id)
{
    int reg = buscarRegistro(vect, n, id);

    if (reg == -1)
    {
        printf("Registro no encontrado\n");
        return;
    }

    printf("Duenio: %s\n", vect[reg].duenio);
    printf("Nombre: %s\n", vect[reg].nombre);
    printf("Animal: %s\n", vect[reg].animal);
    printf("Telefono: %d\n", vect[reg].telefono);
}

void escrArchivo(Mascota vect[], int n)
{
    FILE *fa;
    fa = fopen("datos.txt", "w");

    for (int i = 0; i < n; i++)
    {
        fprintf(fa, "%d ", vect[i].ID);
        fprintf(fa, "%s ", vect[i].nombre);
        fprintf(fa, "%s ", vect[i].animal);
        fprintf(fa, "%s ", vect[i].duenio);
        fprintf(fa, "%d\n", vect[i].telefono);
    }

    fclose(fa); // Faltó cerrar el archivo
}

void cargarArchivo(Mascota vect[], int *n) // El vector se pasa sin puntero porque es un arreglo
{
    FILE *fa;
    Mascota reg; // Se crea una variable de tipo Mascota
                 // donde se guardara el registro a agregar al vector
    fa = fopen("datos.txt", "r");

    if (fa)
    {
        while (!feof(fa))
        {
            fscanf(fa, "%d", &reg.ID);
            fscanf(fa, "%s", &reg.nombre);
            fscanf(fa, "%s", &reg.animal);
            fscanf(fa, "%s", &reg.duenio);
            fscanf(fa, "%d", &reg.telefono);

            reg.status = 1;
            vect[*n] = reg; // Se agrega el registro al vector
            (*n)++;         // Se incrementa el contador de registros
        }

        fclose(fa); // Faltó cerrar el archivo
    }
}