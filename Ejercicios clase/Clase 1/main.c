#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1;
    float numero2;

    char letra;

    float resultado;

    printf("Escriba un numero entero: ");
    scanf("%d", &numero1);

    printf("Escriba un numero con coma: ");
    scanf("%f", &numero2);

    printf("Ingrese una letra: ");
    letra = getche();

    printf("\nEl numero entero que ingreso es %d y el numero con coma %.2f", numero1, numero2);

    resultado=(float) numero1+numero2;
    printf("\nEl resultado de la suma de los numeros es: %.2f",resultado);

    printf("\nLa letra que ingreso es: %c",letra);



    return 0;
}
