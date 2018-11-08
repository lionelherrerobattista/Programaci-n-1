#include <stdio.h>
#include <stdlib.h>
#define T 5


int main()
{
    int* vector;
    int* pAux; //Por si realloc devuelve null, para no modificar el
               //vector original

    int i;

    //Asigno puntero a dir de memoria del heap
    vector = (int*) malloc(sizeof(int)*5);//busca espacio en memoria en el heap
    //funcion calloc() inicializa el vector en 0


    if(vector!=NULL)
    {
        for(i=0;i<T;i++)
        {
            *(vector+i) = i+1; //le cargo el valor * sino dir. de memoria
        }
        for(i=0;i<T;i++)
        {
            printf("%d\n", *(vector+i));
        }
        //Quiero màs espacio en memoria
        pAux = realloc(vector,sizeof(int)*T+5); //Lo asigno al vector nuevamente

        if(pAux!=NULL)//encontro una dir de memoria
        {
            vector=pAux;//piso las dir. de memoria
            //cargo los elementos que faltan
            for(i=T; i<T+5; i++)
            {
                *(vector+i) = i+1;

            }
            printf("\nACA MUESTRO 10\n");
            for(i=0;i<T+5;i++)
            {
                printf("%d\n", *(vector+i));
            }

            printf("\nACA MUESTRO 3\n");
            vector = (int*) realloc(vector,sizeof(int)*3); //achico el vector a 3
            for(i=0;i<3;i++)
            {
                printf("%d\n", *(vector+i));
            }


        }

        /*//Le asigno un valor con operador *
        *vector = 9;
        printf("%d", *vector);
        free(vector);//Libero el espacio en el HEAP
        printf("\n%d", *vector);//Basura*/
    }
    else
    {
        printf("No hay suficiente espacio");
    }

    return 0;
}
