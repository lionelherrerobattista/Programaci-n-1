#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vector[5]; //= {0,0,0,0,0}; //{9,-3,5,14,-4};
    int i=0;

    //Cargo datos al vector aleatoria.
    /*for(i=0; i<5; i++)
    {
        vector[i] = 1;
    }*/

    //Carga de datos secuencial.

    for(i=0; i<5; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &vector[i]);
    }

    //Muestro el vector.
    for(i=0; i<5; i++)
    {
        printf("%d -- %d\n",i,vector[i]);
    }




    return 0;
}
