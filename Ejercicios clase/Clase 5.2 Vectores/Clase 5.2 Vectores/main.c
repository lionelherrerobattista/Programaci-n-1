#include <stdio.h>
#include <stdlib.h>
#define TAM 5

//Hacer un vector y que mostrar el valor máximo

int buscarMaximo (int[], int);

int main()
{
    int vector[TAM];
    int maximo;



    maximo=buscarMaximo(vector,TAM);

    /*for(i=0; i<TAM; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &vector[i]);

        if (flag==0 || vector[i]>maximo)
        {
            maximo=vector[i];
            flag=1;
        }
        else
        {
            if (vector[i]>maximo)
            {
                maximo=vector[i];
            }
        }

    }*/

    printf("El maximo es: %d", maximo);


    return 0;
}

int buscarMaximo (int vec[], int tam)
{
    int maximo;
    int i;
    int flag=0;

    for(i=0; i<tam; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &vec[i]);

        if (flag==0 || vec[i]>maximo)
        {
            maximo=vec[i];
            flag=1;
        }
    }
    return maximo;
}
