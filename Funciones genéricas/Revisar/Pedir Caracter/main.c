#include <stdio.h>
#include <stdlib.h>

char pedirCaracter();

int main()
{
    char caracter;

    caracter=pedirCaracter();

    printf("El caracter ingresado es: %c",caracter);
    return 0;
}

char pedirCaracter()
{
    char caracter;

    printf("Ingrese un caracter: ");
    scanf("%c", &caracter);

    return caracter;
}
