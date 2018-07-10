#include <stdio.h>
#include <stdlib.h>
#include "personas.h"
#include "ArrayList.h"

int main()
{
    char seguir='s';
    int opcion=0;
    char dni[10];
    //Creo contadores para los tramites y los inicio en 0
    int contadorTramiteUrgente=0;
    int contadorTramiteRegular=0;

    //Creo dos listas 1 para los tramites urgentes y 1 para regulares
    ArrayList* listaTramitesUrgentes;
    ArrayList* listaTramitesRegulares;
    //Dos listas para los tramites atendidos
    ArrayList* listaAtendidosUrgentes;
    ArrayList* listaAtendidosRegulares;

    //creo la lista
    listaTramitesUrgentes=al_newArrayList();
    listaTramitesRegulares=al_newArrayList();

    listaAtendidosUrgentes=al_newArrayList();
    listaAtendidosRegulares=al_newArrayList();





    //Menú de opciones del usuario
    do
    {
        printf("---------------------------------------\n\n");
        printf("1- TRAMITE URGENTE\n");
        printf("2- TRAMITE REGULAR\n");
        printf("3- PROXIMO CLIENTE\n");
        printf("4- LISTAR\n");
        printf("5- INFORMAR\n");
        printf("6- SALIR\n");

        printf("\nRespuesta: ");
        scanf("%d",&opcion);
        printf("---------------------------------------\n");

        switch(opcion)
        {
            case 1:
                //Cuento los tramites urgentes
                contadorTramiteUrgente++;

                printf("Ingrese su DNI: ");
                //limpio el buffer
                fflush(stdin);
                //se ingresa el dni y se guarda en la string
                gets(dni);

                cargarTramite(listaTramitesUrgentes,contadorTramiteUrgente,dni);

                break;

            case 2:
                contadorTramiteRegular++;

                printf("Ingrese su DNI: ");
                fflush(stdin);
                gets(dni);

                cargarTramite(listaTramitesRegulares,contadorTramiteRegular,dni);

                break;

            case 3:
                //Tramite siguiente(tienen prioridad los urgentes)
                if(!(listaTramitesUrgentes->isEmpty(listaTramitesUrgentes)))//si la lista NO está vacía
                {
                    //agarrar el siguiente tramite urgente y mostrarlo
                    printf("-----CLIENTE A SER ATENDIDO(URGENTE)-----\n");
                    atenderTramite(listaTramitesUrgentes,listaAtendidosUrgentes);

                }
                else
                {
                    if(!(listaTramitesRegulares->isEmpty(listaTramitesRegulares)))
                    {
                        printf("-----CLIENTE A SER ATENDIDO(REGULAR)-----\n");
                        atenderTramite(listaTramitesRegulares,listaAtendidosRegulares);
                    }
                    else
                    {
                        printf("No hay tramites por atender\n");
                    }
                }


                break;

            case 4:

                printf("------Tramites urgentes------\n\n");
                mostrarListaTramites(listaTramitesUrgentes);

                break;

            case 5:

                break;
            case 6:
                seguir='n';
                break;
        }
    }while(seguir=='s');


    return 0;
}
