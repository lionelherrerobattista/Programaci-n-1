#include "Vectores.h"
#include <stdio.h>

void mostrarVector (int vec[],int tamanio)
{
    int i;

    for(i=0; i<tamanio; i++)
    {
        printf("%d -- %d\n",i,vec[i]);
    }
}

void modificarValor (int vec[])
{
    vec [3]= 6456;
}

int buscarMaximo (int vec[], int tam)
{
    int maximo;
    int i;
    int flag=0;

    for(i=0; i<tam; i++)
    {
        if (flag==0 || vec[i]>maximo)
        {
            maximo=vec[i];
            flag=1;
        }
    }
    return maximo;
}

void cargarVector (int vec[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &vec[i]);
    }
}

//busca un numero y devuelve la primera posición que aparece.

int buscarNumero (int vec[], int tam, int valor)
{
    int index = - 1; //nunca cambia el valor del index si no lo encuentra
    int i;

    for(i=0; i<tam; i++)
    {
        if (valor==vec[i])
        {
            index = i;
            break; // para que salga de la estructura repetitiva.
        }
    }
    return index;
}

//Cantidad de numeros pares
int cantidadNumerosPares (int vec[], int tam)
{
    int i;
    int numerosPares=0;

    for(i=0; i<tam; i++)
    {
        if (vec[i]%2==0 && vec[i]!=0 )
        {
            numerosPares++;
        }
    }
    
    return numerosPares;

}

//Cantidad de números positivos.
int cantidadNumerosPositivos (int vec[], int tam)
{
    int contadorPositivos=0;
    int i;

    for(i=0; i<tam; i++)
    {
        if (vec[i]>0)
        {
            contadorPositivos++;
        }
    }
    return contadorPositivos;
}

//Buscador de posición de caracter
int buscarChar (char vec[], int tam, char caracter)
{
    int index = - 1;
    int i;

    for(i=0; i<tam; i++)
    {
        if (caracter==vec[i])
        {
            index = i;
            break;
        }
    }
    return index;
}






