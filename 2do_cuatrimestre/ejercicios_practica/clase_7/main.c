#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "funciones.h"
#define TAM_AGENDA 200

/*
1) Realizar una agenda para guardar los datos de hasta 200 personas
 de las cuales se toman los siguientes datos:

Nombre
Apellido
Legajo (NO SE PUEDE REPETIR)

a- Realizar un programa con un menú de opciones para hacer altas ,
 bajas y modificaciones (ABM) de una agenda.

b- Mostrar un listado ordenado por Apellido

*/



int main()
{
    //------Arrays paralelos--------//
    char nombre[TAM_AGENDA][50]={};
    char apellido[TAM_AGENDA][50]={};
    int legajos[TAM_AGENDA];
    //------------------------------//

    int indiceLibre;

    inicializarArrayEnteros(legajos, TAM_AGENDA, -1);

    int auxiliarLegajo;
    int opcion=0;

    while(opcion != 5)
    {
        printf("---------------------------------\n");
        printf("1-Alta\n");
        printf("2-Baja\n");
        printf("3-Modificacion\n");
        printf("4-Listar\n");
        printf("5-Salir\n");
        printf("---------------------------------\n");
        getCadenaNumeros(&opcion,"Ingrese una opcion", 1, 5);
        printf("---------------------------------\n");

        switch(opcion)
        {
            case 1: //Alta
                //Busco el indice de legajo libre:
                indiceLibre=buscarPrimeraOcurrenciaInt(legajos, TAM_AGENDA, -1);

                if(indiceLibre==-1)
                {
                    printf("No hay legajos libres!!\n");
                }
                else
                {
                    getCadenaNumeros(&auxiliarLegajo, "Ingrese el legajo", 1, 9999);

                    //Busco que no se repita el numero de legajo:
                    while(buscarPrimeraOcurrenciaInt(legajos, TAM_AGENDA, auxiliarLegajo)==-1)
                    {
                        printf("El legajo ya existe.");
                        getCadenaNumeros(&auxiliarLegajo, "Ingrese el legajo", 1, 9999);
                    }

                    legajos[indiceLibre]=auxiliarLegajo;

                    //Pido los datos que faltan:
                    getCadenaLetras(nombre[indiceLibre],"Ingrese el nombre");
                    getCadenaLetras(apellido[indiceLibre],"Ingrese el apellido");
                }
                break;
            case 2:
                break;

            case 3:
                break;

            case 4:
                break;

        }
    }


    return 0;
}

