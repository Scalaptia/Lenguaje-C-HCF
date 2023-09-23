#include <stdio.h>
#include <windows.h>

int binario();
int calificacion();
int gestionInventario();

int main()
{
    char op;

    do
    {
        system("cls");
        printf("------------- Menu -------------\n");
        printf("1 - Numero a binario\n");
        printf("2 - Calificacion numero a letra\n");
        printf("3 - Gestion de inventario\n");
        printf("4 - Finalizar\n\n");
        printf("Ingrese su seleccion: ");
        scanf(" %c", &op);
        system("cls");

        switch (op)
        {
        case '1':
            binario();
            break;

        case '2':
            calificacion();
            break;

        case '3':
            gestionInventario();
            break;
        }
    } while (op != '4');

    return 0;
}

int binario()
{
    int num, numBits = 0, bitsSignificativos = 0, setBits = 0;
    int bits[128], posiciones[128];

    // Inicializar arreglo de bits y posiciones con ceros
    for (int i = 0; i < 128; i++)
    {
        bits[i] = 0;
        posiciones[i] = 0;
    }

    printf("Ingrese un numero entero: ");
    scanf("%d", &num);
    printf("Ingrese el numero de bits a considerar: ");
    scanf("%d", &numBits);
    system("cls");

    if (num < 0 || numBits < 0)
    {
        printf("Numero de bits y numero decimal deben ser mayores a 0");
        return 1;
    }

    printf("Numero decimal: %d\n", num);

    // Convertir a binario
    int temp = num;
    while (temp > 0)
    {
        bits[bitsSignificativos] = temp % 2;
        temp /= 2;
        bitsSignificativos++; // Longitud del arreglo
    }

    // Imprimir numero binario
    printf("Numero binario: ");
    for (int i = numBits - 1; i >= 0; i--)
    {
        if ((i + 1) % 4 == 0)
            printf(" "); // Imprime un espacio entre cada 4 bits
        printf("%d", bits[i]);
    }

    // Recorrer arreglo de bits en orden para contar bits encendidos y almacenar las posiciones.
    int contadorPos = 1;
    for (int i = -1; i <= numBits - 1; i++)
    {
        if (bits[i] == 1)
        {
            setBits++;                       // Aumentar bits encendidos por 1
            posiciones[contadorPos] = i + 1; // Almacenar posicion de bit encendido en arreglo de posiciones
            contadorPos++;
        }
    }

    printf("\nBits encendidos: %d", setBits);

    printf("\nPosiciones de bits encendidos: ");

    // Regresivamente imprimir arreglo de posiciones desde valor mas alto a 0
    for (int i = 1; i < contadorPos; i++)
    {
        printf("%d ", posiciones[i]);
    }

    printf("\nCantidad de bits analizados: %d", numBits);

    printf("\n");
    system("PAUSE");
    return 0;
}

int calificacion()
{
    int calif, letra;

    printf("Ingrese una calificacion entre 0-100: ");
    scanf("%d", &calif);

    if (calif < 0 || calif > 100)
    {
        printf("Error en la calificacion\n");
        system("PAUSE");
        return 1;
    }

    (calif < 80)
        ? (calif < 70)
              ? (calif < 60)
                    ? (letra = 'F')
                    : (letra = 'D')
              : (letra = 'C')
    : (calif < 90)
        ? (letra = 'B')
        : (letra = 'A');

    printf("Calificacion: %d, recibe una %c\n", calif, letra);
    system("PAUSE");
    return 0;
}

int gestionInventario()
{
    int inventario[5] = {0, 0, 0, 0, 0};
    const int maxCapacidad = 5;
    int elementos = 0, flag = 1;
    char opcion;

    while (flag)
    {
        printf("------------- Inventario -------------\n");
        printf("1 - Agregar\n");
        printf("2 - Retirar\n");
        printf("3 - Mostrar\n");
        printf("4 - Salir\n\n");
        printf("Ingrese su seleccion: ");
        scanf(" %c", &opcion);
        system("CLS");

        switch (opcion)
        {
        case '1':
            if (elementos < maxCapacidad)
            {
                inventario[elementos] = 1;
                elementos++;
                printf("Agregaste 1 elemento\n");
            }
            else
            {
                printf("El inventario está lleno\n");
            }
            break;

        case '2':
            if (elementos > 0)
            {
                elementos--;
                inventario[elementos] = 0;
                printf("Eliminaste 1 elemento\n");
            }
            else
            {
                printf("El inventario está vacio\n");
            }
            break;

        case '3':
            for (int i = 0; i < maxCapacidad; i++)
            {
                printf("%d, ", inventario[i]);
            }
            printf("El inventario tiene %d elementos\n", elementos);
            break;

        case '4':
            printf("Finalizando...");
            flag = 0;
            break;
        }
    }

    printf("\n");
    system("PAUSE");
    return 0;
}