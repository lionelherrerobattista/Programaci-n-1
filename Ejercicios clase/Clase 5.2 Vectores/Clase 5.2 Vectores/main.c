#include <stdio.h>
#include <stdlib.h>
#define TAM 5

//Hacer un vector y que mostrar el valor máximo

int main()
{
    int vector[TAM];
    int maximo;
    int i;
    int flag=0;

    for(i=0; i<TAM; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &vector[i]);

        if (flag==0 || vector[i]>maximo)
        {
            maximo=vector[i];
            flag=1;
        }
        /*else
        {
            if (vector[i]>maximo)
            {
                maximo=vector[i];
            }
        }*/

    }

    printf("El maximo es: %d", maximo);


    return 0;
}
