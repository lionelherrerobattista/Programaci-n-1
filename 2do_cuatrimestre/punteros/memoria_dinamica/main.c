#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* pEntero;

    //Asigno puntero a dir de memoria del heap
    pEntero = (int*) malloc(sizeof(int));//busca espacio en memoria en el heap
    if(pEntero!=NULL)
    {
        //Le asigno un valor con operador *
        *pEntero = 9;
        printf("%d", *pEntero);
    }
    else
    {
        printf("No hay suficiente espacio");
    }


    printf("%d", *pEntero);

    return 0;
}
