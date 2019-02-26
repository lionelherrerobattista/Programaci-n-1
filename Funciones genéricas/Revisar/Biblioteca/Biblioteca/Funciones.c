#include "Funciones.h"
#include <stdio.h>

int pedirEntero(char mensaje[], int min, int max)
{
    int numero;
    printf("%s", mensaje);
    scanf("%d",&numero);

    while (numero<min || numero>max)
    {
        printf("Error!! %s", mensaje);
        scanf("%d",&numero);
    }

    return numero;
}
