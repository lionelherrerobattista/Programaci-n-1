#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1;
    float numero2;
    float resultado;
    char letra;

    printf("Ingrese un numero entero: ");
    scanf("%d",&numero1);

    printf("Ingrese un numero con coma: ");
    scanf("%f",&numero2);

    printf("Ingrese una letra: ");
    //fflush(stdin);

    letra = getche();
    //scanf("%c", &letra);

    resultado = numero1+numero2;


    printf("\nEl numero entero es: %d y el numero flotante es: %.2f", numero1, numero2);
    printf("\nEl resultado es: %.2f", resultado);
    printf("\nLa letra es: %c", letra);


    return 0;
}
