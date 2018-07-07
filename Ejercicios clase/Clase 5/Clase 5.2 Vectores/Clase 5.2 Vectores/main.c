#include <stdio.h>
#include <stdlib.h>
#include "Vectores.h"
#define TAM 5

//Hacer un vector y que mostrar el valor máximo
//Recibir vector, tamaño, numero

int buscarMaximo (int[], int);


int main()
{
    int vector[TAM];
    int maximo;
    int indice;


    cargarVector(vector, TAM);
    maximo=buscarMaximo(vector,TAM);


    printf("El maximo es: %d", maximo);

    indice= buscarNumero(vector, TAM, 14);
    if (indice == -1)
    {
        printf("\nNo lo encontro!!!");
    }
    else
    {
        printf("\nEncontro el valor.");
    }


    return 0;
}


