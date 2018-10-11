#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int main()
{
    //int vector[5]; desaparece el intermediario
    int* pVector;
    int* aux;
    int i;


    pVector=(int*)malloc(sizeof(int)*TAM);//guardo 5 elementos

    if(pVector!=NULL)//verifico que no sea nulo
    {
        for(i=0;i<TAM;i++)
        {
            *(pVector+i)=i+1;//*para el valor

        }
        for(i=0;i<TAM;i++)
        {
            printf("%d\n", *(pVector+i));

        }

        aux=(int*)realloc(pVector, sizeof(int)*(TAM*2));//recibe un puntero a void. Le digo donde empieza
        //creo un puntero auxiliar para no perder los datos

        if(aux!=NULL)//me fijo que no sea nulo
        {
            pVector=aux;//Lo vuelvo a asignar a la variable
            for(i=TAM;i<(TAM*2);i++)//Agrego mas elementos
            {
                *(pVector+i)=i+1;
            }
            printf("LUEGO DE REALLOC\n");
            for(i=0;i<(TAM*2);i++)
            {
                printf("%d\n", *(pVector+i));
            }

            //muestro menos elementos, se librea memoria
            aux=(int*)realloc(pVector,sizeof(int)*4);

            if(aux!=NULL)
            {

                printf("LUEGO DEL REALLOC POR MENOS\n");
                for(i=0;i<4;i++)
                {
                    printf("%d\n", *(pVector+i));
                }
            }
        }

        free(pVector);//Libero la memoria
    }




    return 0;
}
