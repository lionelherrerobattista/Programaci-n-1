#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void mostrarVector (int[],int);

int main()
{
    int vector[TAM]; //= {0,0,0,0,0}; //{9,-3,5,14,-4};
    int i=0;

    //Cargo datos al vector aleatoria.
    /*for(i=0; i<5; i++)
    {
        vector[i] = 1;
    }*/

    //Carga de datos secuencial.
    for(i=0; i<TAM; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &vector[i]);
    }

    //Muestro el vector.

    mostrarVector(vector,TAM);

    return 0;
}

void mostrarVector (int vec[],int tamanio)
{
    int i;

    for(i=0; i<tamanio; i++)
    {
        printf("%d -- %d\n",i,vec[i]);
    }
}
