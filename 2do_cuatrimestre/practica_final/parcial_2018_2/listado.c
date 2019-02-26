#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "urgente.h"
#include "regular.h"
#include "funciones.h"
#include "LinkedList.h"
#include "listado.h"

void mostrarTramites(LinkedList* listaTramitesUrgentes, LinkedList* listaTramitesRegulares)
{
    int i=0;
    int j=0;

    S_TramiteUrgente* pAuxTramiteUrgente;
    S_TramiteRegular* pAuxTramiteRegular;

    pAuxTramiteUrgente = newTramiteUrgente();
    pAuxTramiteRegular = newTramiteRegular();

    printf("%5s %15s\n", "Puesto","DNI");

    if(listaTramitesUrgentes != NULL && listaTramitesRegulares != NULL)
    {
        if(ll_len(listaTramitesUrgentes) != 0)
        {
            for(i = 0; i < ll_len(listaTramitesUrgentes); i++)
            {
                pAuxTramiteUrgente = ll_get(listaTramitesUrgentes, i);

                printf("%5d %15ld\n", i+1, pAuxTramiteUrgente->dni);
            }
        }

        if(ll_len(listaTramitesRegulares) != 0)
        {
            for(j = 0; j < ll_len(listaTramitesRegulares); j++)
            {
                pAuxTramiteRegular = ll_get(listaTramitesRegulares, j);
                printf("%5d %15ld\n", i+1, pAuxTramiteRegular->dni);
                i++;
            }
        }
    }
}

void mostrarProximoTurno(LinkedList* listaTramitesUrgentes, LinkedList* listaTramitesRegulares)
{

    S_TramiteUrgente* pAuxTramiteUrgente;
    S_TramiteRegular* pAuxTramiteRegular;

    pAuxTramiteUrgente = newTramiteUrgente();
    pAuxTramiteRegular = newTramiteRegular();

    printf("Siguiente turno: ");

    if(listaTramitesUrgentes != NULL && listaTramitesRegulares != NULL)
    {
        if(ll_len(listaTramitesUrgentes) != 0)
        {
            pAuxTramiteUrgente = ll_get(listaTramitesUrgentes, 0);

            printf("%ld ", pAuxTramiteUrgente->dni);
            printf("(Tramite urgente)\n");
        }
        else
        {

            if(ll_len(listaTramitesRegulares) != 0)
            {
                    pAuxTramiteRegular = ll_get(listaTramitesRegulares, 0);
                    printf("%ld", pAuxTramiteRegular->dni);
                    printf("(Tramite regular)\n");
            }
            else
            {
                printf("No hay turnos por atender.\n");
            }

        }


    }
}

void atenderCliente(LinkedList* listaUrgente, LinkedList* listaRegular, LinkedList* listaAtendidosUrgente, LinkedList* listaAtendidosRegular)
{
    S_TramiteUrgente* pAuxTramiteUrgente;
    S_TramiteRegular* pAuxTramiteRegular;

    pAuxTramiteUrgente = newTramiteUrgente();

    if(listaUrgente != NULL && listaRegular != NULL)
    {
        if(ll_len(listaUrgente) != 0)
        {
            pAuxTramiteUrgente = ll_pop(listaUrgente, 0);

            ll_add(listaAtendidosUrgente, pAuxTramiteUrgente);
        }
        else
        {

            if(ll_len(listaRegular) != 0)
            {
                pAuxTramiteRegular = ll_pop(listaRegular, 0);

                ll_add(listaAtendidosRegular, pAuxTramiteRegular);
            }

        }

    }

}


void mostrarTramitesAtendidos(LinkedList* listaAtendidosUrgentes, LinkedList* listaAtendidosRegulares)
{
    int i=0;
    int j=0;

    S_TramiteUrgente* pAuxTramiteUrgente;
    S_TramiteRegular* pAuxTramiteRegular;

    pAuxTramiteUrgente = newTramiteUrgente();
    pAuxTramiteRegular = newTramiteRegular();

    ll_sort(listaAtendidosUrgentes,*ordenarTramitesUrgentes, 0); //1 orden ascendente
    ll_sort(listaAtendidosRegulares,*ordenarTramitesRegulares, 0); //1 orden ascendente



    if(listaAtendidosUrgentes != NULL && listaAtendidosRegulares != NULL)
    {
        if(ll_len(listaAtendidosUrgentes) != 0)
        {
            printf("Tramites urgentes atendidos: \n");
            printf("%5s %15s\n", "Puesto","DNI");

            for(i = 0; i < ll_len(listaAtendidosUrgentes); i++)
            {
                pAuxTramiteUrgente = ll_get(listaAtendidosUrgentes, i);

                printf("%5d %15ld\n", i+1, pAuxTramiteUrgente->dni);
            }
        }

        if(ll_len(listaAtendidosRegulares) != 0)
        {
            printf("Tramites regulares atendidos: \n");
            printf("%5s %15s\n", "Puesto","DNI");
            for(j = 0; j < ll_len(listaAtendidosRegulares); j++)
            {
                pAuxTramiteRegular = ll_get(listaAtendidosRegulares, j);
                printf("%5d %15ld\n", i+1, pAuxTramiteRegular->dni);
                i++;
            }
        }
    }
}

//funcion generica
int ordenarTramitesUrgentes(void* tramiteUno, void* tramiteDos)
{
    //tengo que pasarlos a un auxiliar para utilizar el operador flecha
    S_TramiteUrgente* pAuxUrgenteUno;
    S_TramiteUrgente* pAuxUrgenteDos;

    pAuxUrgenteUno = (S_TramiteUrgente*) tramiteUno;
    pAuxUrgenteDos= (S_TramiteUrgente*) tramiteDos;

    int retorno = 0;

    if(pAuxUrgenteUno->dni <= pAuxUrgenteDos->dni)
    {
        retorno = -1;
    }
    else
    {
        if(pAuxUrgenteUno->dni > pAuxUrgenteDos->dni)
        {
            retorno = 1;
        }
    }

    return retorno;
}

int ordenarTramitesRegulares(void* tramiteUno, void* tramiteDos)
{
    //tengo que pasarlos a un auxiliar para utilizar el operador flecha
    S_TramiteRegular* pAuxRegularUno;
    S_TramiteRegular* pAuxRegularDos;

    pAuxRegularUno = (S_TramiteRegular*) tramiteUno;
    pAuxRegularDos = (S_TramiteRegular*) tramiteDos;

    int retorno = 0;

    if(pAuxRegularUno->dni <= pAuxRegularDos->dni)
    {
        retorno = -1;
    }
    else
    {
        if(pAuxRegularUno->dni > pAuxRegularDos->dni)
        {
            retorno = 1;
        }
    }

    return retorno;
}

