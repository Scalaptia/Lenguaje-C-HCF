#include <stdio.h>
#include <string.h>

void invCad(char *strng)
{
    int j = strlen(strng) - 1;

    int i = 0;
    char temp;

    while (i < j)
    {
        temp = strng[i];
        strng[i] = strng[j];
        strng[j] = temp;
        i++;
        j--;
    }
}

int main()
{
    char cad[] = "hola";
    char cad2[] = "holas";

    fflush(stdin);
    gets(cad);

    printf("original: %s\n", cad);
    invCad(cad);
    printf("inv: %s\n", cad);

    printf("original: %s\n", cad2);
    invCad(cad2);
    printf("inv: %s\n", cad2);

    return 0;
}
