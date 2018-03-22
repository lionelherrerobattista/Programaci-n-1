#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int i;
    int maximo;
    int minimo;
    int acumulador;
    float promedio;


    printf("Ingrese un numero: ");
    scanf("%d",&numero);

    maximo = numero;
    minimo = numero;
    acumulador=numero;


    for (i=0; i<4;i++)
    {
        printf("\nIngrese un numero:");
        scanf("%d",&numero);

        acumulador=acumulador+numero;

        if (numero<minimo)
        {
            minimo=numero;
        }
        else
        {
         if (numero>maximo)
         {
             maximo=numero;
         }
        }
    }

    promedio=acumulador/5;

    printf("\nEl promedio de los numeros es: %.2f", promedio);
    printf("\nEl numero maximo es: %d", maximo);
    printf("\nEl numero minimo es: %d", minimo);
}
