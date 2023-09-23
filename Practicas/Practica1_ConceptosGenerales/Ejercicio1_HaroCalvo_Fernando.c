#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.1416

int calculadora() {
    float num1, num2, resultado;
    char operador;

    printf("Ingrese el primer numero: ");
    scanf("%f", &num1);

    printf("Ingrese el operador (+, -, *, /): ");
    scanf(" %c", &operador);

    printf("Ingrese el segundo numero: ");
    scanf("%f", &num2);

    switch (operador) {
        case '+':
            resultado = num1 + num2;
            break;

        case '-':
            resultado = num1 - num2;
            break;

        case '*':
            resultado = num1 * num2;
            break;

        case '/':
            if (num2 != 0) {
                resultado = num1 / num2;
            } else {
                printf("No se puede dividir entre cero");
                return 1;
            }
            break;

        default:
            printf("Operador no valido");
            return 1;
    }

    printf("\nEl resultado de %.2f %c %.2f es %.2f", num1, operador, num2, resultado);
    return 0;
}

int juego() {
    srand(time(NULL)); // Inicializa generador de números aleatorios
    int numSecreto = rand() % 100 + 1; // Escoger número
    int intento, numIntentos = 0;

    while (1) {
        printf("Ingrese un numero entre 1 y 100: ");
        scanf("%d", &intento);
        numIntentos++;
        
        if (intento < 1 || intento > 100) {
            printf("El numero debe estar entre 1 y 100.\n");
            continue;
        }
        
        if (intento < numSecreto) {
            printf("Demasiado bajo\n");
        } else if (intento > numSecreto) {
            printf("Demasiado alto\n");
        } else {
            printf("\nAdivinaste el numero %d en %d intentos", numSecreto, numIntentos);
            break;
        }
    }

    return 0;
}

int areas() {
    char figura;
    float resultado;
    float base, altura, radio, lado;

    printf("------------- Menu -------------\n");
    printf("1 - Triangulo\n");
    printf("2 - Circulo\n");
    printf("3 - Rectangulo\n");
    printf("4 - Cubo\n");
    printf("5 - Cilindro\n\n");
    scanf(" %c", &figura);
    system("cls");

    switch (figura) {
        case '1':
            printf("Ingresa la base: ");
            scanf("%f", &base);
            printf("Ingresa la altura: ");
            scanf("%f", &altura);

            resultado = base * altura / 2;
            break;

        case '2':
            printf("Ingresa el radio: ");
            scanf("%f", &radio);

            resultado = PI * radio * radio;
            break;

        case '3':
            printf("Ingresa la base: ");
            scanf("%f", &base);
            printf("Ingresa la altura: ");
            scanf("%f", &altura);

            resultado = base * altura;
            break;

        case '4':
            printf("Ingresa la longitud de un lado: ");
            scanf("%f", &lado);

            resultado = lado * lado;
            break;
        
        case '5':
            printf("Ingresa el radio: ");
            scanf("%f", &radio);
            printf("Ingresa la altura: ");
            scanf("%f", &altura);

            resultado = 2 * PI * radio * (radio + altura);
            break;

        default:
            printf("Opcion ingresada no valida");
            return 1;
    }

    printf("\nEl area es de: %.2f", resultado);
    return 0;
}

int main() {
    char opcion;

    printf("------------- Menu -------------\n");
    printf("1 - Calculadora\n");
    printf("2 - Juego Adivinar\n");
    printf("3 - Calculadora de Areas\n\n");
    printf("Ingrese su seleccion: ");
    scanf(" %c", &opcion);
    system("cls");

    switch (opcion) {
        case '1':
            calculadora();
            break;
        
        case '2':
            juego();
            break;

        case '3':
            areas();
            break;
        
        default:
            printf("Opcion ingresada no valida");
            break;
    }
}