#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "urgente.h"
#include "funciones.h"
#include "LinkedList.h"


S_TramiteUrgente* newTramiteUrgente()
{
    S_TramiteUrgente* pTramiteUrgente=NULL;

    pTramiteUrgente = (S_TramiteUrgente*)malloc(sizeof(S_TramiteUrgente));

    return pTramiteUrgente;
}

int cargarTramiteUrgente(LinkedList* listaTramitesUrgentes)
{
    long dni;
    int retorno=0;//no cargo

    //Puntero al nuevo trámite
    S_TramiteUrgente* pAuxTramite;

    if(listaTramitesUrgentes != NULL)
    {
        //Asigno espacio en memoria
        pAuxTramite = newTramiteUrgente();

        //Pido el dni al usuario
        dni = pedirCadenaInt("Ingrese su DNI", 0, 99999999);

        //Guardo el dni en la estructura
        urgente_setDni(pAuxTramite, dni);
        urgente_setId(pAuxTramite, listaTramitesUrgentes);

        //Agrego el usuario a la lista
        ll_add(listaTramitesUrgentes, pAuxTramite);

        retorno = 1;//cargó
    }

    return retorno;
}

//Setters
int urgente_setDni(S_TramiteUrgente* pTramiteUrgente, long dni)
{

    pTramiteUrgente->dni = dni;


    return 1;
}

int urgente_setId(S_TramiteUrgente* pTramiteUrgente, LinkedList* listaTramitesUrgentes)
{
    int retorno = 0; //no cargó

    if(pTramiteUrgente != NULL)
    {
        pTramiteUrgente->id=ll_len(listaTramitesUrgentes);//Siempre me da el id siguiente libre
        retorno = 1;//cargó
    }

    return retorno;
}
