#include <stdio.h>
#include <stdlib.h>

int main()
{
    //carga secuencial
    int vector[5];
    int i;

    //Cargo los datos de manera secuencial
    for (i=0; i<5; i++)
    {
        printf("Ingrese el valor a cargar en el vector: ");
        scanf("%d",&vector[i]); //variable i toma valores desde 0 a 4 ordenadamente
    }

    //Leo los datos uno por uno
    for (i=0; i<5; i++)
    {
        printf("%d\n",vector[i]);
    }


}
