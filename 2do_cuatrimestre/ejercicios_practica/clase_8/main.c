#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM_AGENDA 200

int agenda_mostrarLista(ePersona listaPersonas[], int longitud);

/*
1) Realizar una agenda para guardar los datos de hasta 200 personas de las cuales se toman los siguientes datos (utilizar una estructura para representar a la persona.):

Nombre
Apellido
Legajo (NO SE PUEDE REPETIR)
a- Realizar un programa con un menú de opciones para hacer altas , bajas y modificaciones (ABM) de una agenda.

b- Mostrar un listado ordenado por Apellido
*/


int main()
{

    int opcion;
    int indiceLibre;
    int auxiliarLegajo;
    int indiceEstructura;


    ePersona agendaPersonas[TAM_AGENDA];

    inicializarArrayEstructura(agendaPersonas, TAM_AGENDA, -1);


    while(opcion != 6)
    {
        printf("---------------------------------\n");
        printf("1-Alta\n");
        printf("2-Baja\n");
        printf("3-Modificacion\n");
        printf("4-Listar\n");
        printf("5-Ordenar apellido por orden alfabetico\n");
        printf("6-Salir\n");
        printf("---------------------------------\n");
        getCadenaNumeros(&opcion,"Ingrese una opcion", 1, 6);
        printf("---------------------------------\n");


        switch(opcion)
        {
            case 1: //Alta
                //Busco el indice de legajo libre valor==-1:
                indiceLibre=agenda_buscarPrimeraOcurrencia(agendaPersonas, TAM_AGENDA, -1);

                if(indiceLibre==-1)
                {
                    printf("No hay legajos libres!!\n");
                }
                else
                {
                    getCadenaNumeros(&auxiliarLegajo, "Ingrese el legajo", 1, 9999);

                    //Busco que no se repita el numero de legajo:
                    while(agenda_buscarPrimeraOcurrencia(agendaPersonas, TAM_AGENDA, auxiliarLegajo)!=-1)
                    {
                        printf("El legajo ya existe.\n");
                        getCadenaNumeros(&auxiliarLegajo, "Ingrese el legajo", 1, 9999);
                    }

                    //Copio el legajo en la estructura:
                    agendaPersonas[indiceLibre].legajo=auxiliarLegajo;

                    //Pido los datos que faltan:
                    getCadenaLetras(agendaPersonas[indiceLibre].nombre,"Ingrese el nombre");
                    getCadenaLetras(agendaPersonas[indiceLibre].apellido,"Ingrese el apellido");
                }
                break;
            case 2:
                //Baja lógica, pido legajo:
                getCadenaNumeros(&auxiliarLegajo, "Ingrese el legajo que desea dar de baja", 1, 9999);

                //Busco el indice
                indiceEstructura=agenda_buscarPrimeraOcurrencia(agendaPersonas, TAM_AGENDA, auxiliarLegajo);
                if(indiceEstructura!=-1)
                {
                    agendaPersonas[indiceEstructura].legajo=-1;//lo doy de baja (lógica)
                }
                else
                {
                    printf("No se encuentra el legajo\n");
                }
                break;

            case 3:
                //Modificación:
                getCadenaNumeros(&auxiliarLegajo, "Ingrese el legajo que desea modificar", 1, 9999);
                //Busco el indice de la estructura:
                indiceEstructura=agenda_buscarPrimeraOcurrencia(agendaPersonas, TAM_AGENDA, auxiliarLegajo);

                if(indiceEstructura!=-1)
                {
                    //Pido todo de nuevo:
                    getCadenaNumeros(&auxiliarLegajo, "Ingrese el nuevo legajo", 1, 9999);

                    //Busco que no se repita el numero de legajo:
                    while(agenda_buscarPrimeraOcurrencia(agendaPersonas, TAM_AGENDA, auxiliarLegajo)!=-1)
                    {
                        printf("El legajo ya existe.\n");
                        getCadenaNumeros(&auxiliarLegajo, "Ingrese el nuevo legajo", 1, 9999);
                    }

                    //Copio el legajo en la estructura:
                    agendaPersonas[indiceLibre].legajo=auxiliarLegajo;
                    //Pido los datos que faltan:
                    getCadenaLetras(agendaPersonas[indiceLibre].nombre,"Ingrese el nombre");
                    getCadenaLetras(agendaPersonas[indiceLibre].apellido,"Ingrese el apellido");
                }
                else
                {
                    printf("No se encuentra el legajo\n");
                }
                break;

            case 4:
                printf("%-15s %-15s %-15s\n", "LEGAJO", "NOMBRE", "APELLIDO");
                agenda_mostrarLista(agendaPersonas, TAM_AGENDA);

                break;

/*
            case 5:
                //Inserción
                for(i=1;i<TAM_AGENDA;i++)
                {
                    if(legajos[i]==-1)//Si está vacío
                    {
                        continue;//Paso a la proxima iteración
                    }
                    //Empiezo en indice 1 y voy avanzando hacia la derecha con cada iteración
                    strcpy(auxiliarApellido,apellido[i]);
                    strcpy(auxiliarNombre,nombre[i]);
                    auxiliarLegajo=legajos[i];
                    j=i-1;

                    //Comparo con el de la izquierda
                    while(j>=0 && stricmp(auxiliarApellido,apellido[j])<0)//Apellido A-Z
                    {
                        legajos[j+1] = legajos[j];//muevo todo para la derecha
                        strcpy(apellido[j+1],apellido[j]);
                        strcpy(nombre[j+1],nombre[j]);


                        j--;
                    }

                    legajos[j+1]=auxiliarLegajo;//inserto al final a la izquierda
                    strcpy(nombre[j+1], auxiliarNombre);
                    strcpy(apellido[j+1], auxiliarApellido);
                }
                printf("Se ordeno alfabeticamente por apellido.\n");

                break;*/

        }
    }
    return 0;
}



