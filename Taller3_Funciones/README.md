# Taller 3. Funciones

Clase: Lenguaje C

1. **Calcular el factorial de un número entero utilizando una función sin retorno.**
- calcularFactorial: Esta función debe tomar un número entero como entrada y calcular su factorial. El resultado debe mostrarse en pantalla. No debe devolver ningún valor, solo mostrar el resultado.
- En la función main, solicita al usuario que ingrese un número entero no
negativo para calcular su factorial.
- Utiliza la función calcularFactorial para calcular el factorial del número ingresado y mostrar el resultado.
- Pregunta al usuario si desea calcular el factorial de otro número. Si es así, permite al usuario ingresar otro número y calcular su factorial. Si no, muestra un mensaje de despedida y termina el programa.

```c
/*
    Función: calcularFactorial
    Descripción: Calcula e imprime el factorial de un numero ingresado.
*/
void calcularFactorial()
{
    //  VARIABLES LOCALES
    int n, i, res, op;

inicio:
    system("CLS");
    //	TITULO
    printf("   FACTORIAL\n");

    //	PROGRAMA
    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("El numero ingresado debe ser positivo\n");
        system("PAUSE");
        return;
    }

    for (i = n - 1, res = n; i > 1; i--)
    {
        res *= i;
    }
    printf("\nEl factorial de %d es: %d\n", n, res);
    system("PAUSE");

reinicio:
    system("CLS");
    printf("\nDesea calcular el factorial de otro numero? (1: Si / 2: No): ");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        goto inicio;
        break;

    case 2:
        printf("Finalizando programa...\n");
        system("PAUSE");
        return;
        break;

    default:
        goto reinicio;
        break;
    }
}
```

---

1. **Calcular el factorial de un número entero utilizando una función recursiva. La función de calcularFactorial, esta función debe tomar un número entero como entrada y calcular su factorial de manera recursiva. Debe devolver el resultado del cálculo del factorial.**

```c
/*
    Función: calcularFactorialRecursion
    Descripción: Calcula e imprime el factorial de forma recursiva de un numero ingresado.
*/
int calcularFactorialRecursion(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * calcularFactorialRecursion(n - 1);
    }
}
```