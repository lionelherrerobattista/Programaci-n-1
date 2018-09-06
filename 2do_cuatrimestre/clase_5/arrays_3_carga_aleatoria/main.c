#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int main()
{
    int vector[TAM];
    int posicion;
    int i;

    char seguir;

    //inicializar el vector en un valor conocido
    for(i=0; i<TAM; i++)
    {
        vector[i]=0;
    }

    //carga de datos
    do
    {
        //pido la posición
        do
        {
            printf("\nIngrese la posicion (0-5): ");
            scanf("%d",&posicion);

        }while(posicion<0 || posicion>5);


        printf("Ingrese valor a cargar en el vector: ");
        scanf("%d",&vector[posicion]); //uso la variable que indica la posc.

        printf("\nDesea ingresar otro dato s/n: ");
        fflush(stdin);
        scanf("%c",&seguir);

    }while(seguir=='s');

    //Leo el vector
    for(i=0; i<TAM; i++)
    {
        if(vector[i]!=0)
        {
            printf("Los valores cargados son:\n");
            printf("%d\n",vector[i]);
        }
    }



    return 0;
}
