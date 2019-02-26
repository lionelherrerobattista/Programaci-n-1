#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "urgente.h"
#include "funciones.h"
#include "regular.h"
#include "LinkedList.h"
#include "listado.h"

int main()
{
    int opcion;

    //Declaro las listas
    LinkedList* listaTramitesUrgentes;
    LinkedList* listaTramitesRegulares;
    LinkedList* listaTramitesAtendidosUrgentes;
    LinkedList* listaTramitesAtendidosRegulares;

    //Asigno espacio en memoria para las listas
    listaTramitesUrgentes = ll_newLinkedList();
    listaTramitesRegulares = ll_newLinkedList();
    listaTramitesAtendidosUrgentes = ll_newLinkedList();
    listaTramitesAtendidosRegulares = ll_newLinkedList();

    do
    {
        mostrarMenu();
        opcion = pedirCadenaInt("Opcion", 1, 7);
        printf("---------------------------\n");

        switch(opcion)
        {
            case 1://Tramite urgente
                if(cargarTramiteUrgente(listaTramitesUrgentes))
                {
                    printf("Tramite urgente cargado. Aguarde a ser atendido.\n");
                }
                break;
            case 2:
                if(cargarTramiteRegular(listaTramitesRegulares))
                {
                    printf("Tramite regular cargado. Aguarde a ser atendido.\n");
                }
                break;
            case 3:
                mostrarProximoTurno(listaTramitesUrgentes, listaTramitesRegulares);
                break;
            case 4:
                mostrarTramites(listaTramitesUrgentes, listaTramitesRegulares);
                break;
            case 5:
                mostrarTramitesAtendidos(listaTramitesAtendidosUrgentes,
                                          listaTramitesAtendidosRegulares);
                break;
            case 7:
                atenderCliente(listaTramitesUrgentes, listaTramitesRegulares,
                                listaTramitesAtendidosUrgentes,
                                 listaTramitesAtendidosRegulares);
                printf("Cliente atendido.\n");


        }


    }while(opcion != 6);

    return 0;
}
