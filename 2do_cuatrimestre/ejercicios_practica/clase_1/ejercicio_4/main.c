#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int numeros[10];

    int contadorNegativos= 0;
    int contadorPositivos= 0;

    printf("Ingrese 10 numeros:\n");

    for(i=0;i<10;i++)
    {
        fflush(stdin);
        scanf("%d", &numeros[i]);

        if(numeros[i]<0)
        {
            contadorNegativos++;
        }
        else if (numeros[i]>0)
        {
            contadorPositivos++;
        }

        printf("\nEl numero ingresado es: %d\n", numeros[i]);
    }

    printf("\nLa cantidad de numeros negativos es: %d\n", contadorNegativos);
    printf("La cantidad de numeros positivos es: %d", contadorPositivos);

    return 0;
}
