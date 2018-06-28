#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "personas.h"

#define URGENTE 1
#define REGULAR 2


int main(void)
{
    char seguir='s';
    int opcion=0;
    int i;
    int len;
    int UltimoIdTramiteUrgente=0; //contador de la laista de tramite urgente
    int UltimoIdTramiteRegular=0; //contador

    ArrayList* listaTramiteUrgente;
    ArrayList* listaTramiteRegular;

    ArrayList* atendidosUrgentes;
    ArrayList* atendidosRegulares;

    listaTramiteUrgente= al_newArrayList(); //ARRAYLIST
    listaTramiteRegular= al_newArrayList();

    atendidosUrgentes=al_newArrayList();
    atendidosRegulares=al_newArrayList();

    eTramite* tramiteActual;
    //tramiteActual=new_Tramite(); esto no va aca

    char dni[10];


    do
    {
        printf("---------------------------------------\n\n");
        printf("1- TRAMITE URGENTE\n");
        printf("2- TRAMITE REGULAR\n");
        printf("3- PROXIMO CLIENTE\n");
        printf("4- LISTAR PERSONAS\n");
        printf("5- INFORMAR\n\n");
        printf("6- Salir\n\n");

        printf("Respuesta: ");
        scanf("%d",&opcion);

        printf("---------------------------------------\n");

        switch(opcion)
        {
        case 1:

            UltimoIdTramiteUrgente++;

            printf("Ingrese su dni:");
            fflush(stdin);
            gets(dni);

            cargarTramite(listaTramiteUrgente,UltimoIdTramiteUrgente,dni);

            break;
        case 2:

            UltimoIdTramiteRegular++; //incremento el contador

            printf("Ingrese su dni:");//cargo de datos
            fflush(stdin);
            gets(dni);

            cargarTramite(listaTramiteRegular,UltimoIdTramiteRegular,dni); //carga el tramite en la lista de tramites


            break;
        case 3: //si hay tramites urgentes ,tengo que sacar el primero POP([0]) conlo que devuelve el pop lo agrego a la lista de atendidos

            if(!(listaTramiteUrgente->isEmpty(listaTramiteUrgente)))//si la lista de urgente no esta vacia
            {
                printf("CLIENTE A SER ATENTIDO (URGENTE): \n\n");
                atenderTramite(listaTramiteUrgente,atendidosUrgentes);
            }
            else
            {
                if(!(listaTramiteRegular->isEmpty(listaTramiteRegular)))//si la lista de urgente no esta vacia
                {
                    printf("CLIENTE A SER ATENTIDO (REGULAR): \n\n");
                    atenderTramite(listaTramiteRegular,atendidosRegulares);
                }
                else
                {
                    printf("No hay clientes por atender!\n");
                }
            }
            break;
        case 4:

            if(!(listaTramiteUrgente->isEmpty(listaTramiteUrgente)))
            {
                len=listaTramiteUrgente->len(listaTramiteUrgente);

                printf("TRAMITES URGENTES\n\n");
                for(i=0; i<len; i++)
                {
                    tramiteActual=(eTramite*)listaTramiteUrgente->get(listaTramiteUrgente,i);
                    mostrarTramite(tramiteActual);
                }
            }

            if(!(listaTramiteRegular->isEmpty(listaTramiteRegular)))
            {
                len=listaTramiteRegular->len(listaTramiteRegular);

                printf("TRAMITES REGULARES \n\n");
                for(i=0; i<len; i++)
                {
                    tramiteActual=(eTramite*)listaTramiteRegular->get(listaTramiteRegular,i);
                    mostrarTramite(tramiteActual);
                }
            }
            break;
        case 5:

            if(!(atendidosUrgentes->isEmpty(atendidosUrgentes)))
            {
                len=atendidosUrgentes->len(atendidosUrgentes);

                atendidosUrgentes->sort(atendidosUrgentes,compararPorDni,0);

                printf("TRAMITES URGENTES\n\n");
                for(i=0; i<len; i++)
                {
                    tramiteActual=(eTramite*)atendidosUrgentes->get(atendidosUrgentes,i);
                    mostrarTramite(tramiteActual);
                }
            }

            if(!(atendidosRegulares->isEmpty(atendidosRegulares)))
            {
                len=atendidosRegulares->len(atendidosRegulares);

                atendidosRegulares->sort(atendidosRegulares,compararPorDni,0); //ordena la lista de atendidos


                printf("TRAMITES REGULARES \n\n");
                for(i=0; i<len; i++)
                {
                    tramiteActual=(eTramite*)atendidosRegulares->get(atendidosRegulares,i);
                    mostrarTramite(tramiteActual);
                }
            }

            break;
        case 6:
            seguir = 'n';
            break;
        }
        system("pause");
        system("cls");
    }
    while(seguir=='s');

    return 0;
}


