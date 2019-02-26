#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "urgente.h"
#include "funciones.h"
#include "LinkedList.h"
#include "regular.h"


S_TramiteRegular* newTramiteRegular()
{
    S_TramiteRegular* pTramiteRegular=NULL;

    pTramiteRegular = (S_TramiteRegular*)malloc(sizeof(S_TramiteRegular));

    return pTramiteRegular;
}

int cargarTramiteRegular(LinkedList* listaTramitesRegulares)
{
    long dni;
    int retorno=0;//no cargo

    //Puntero al nuevo trámite
    S_TramiteRegular* pAuxTramite;

    if(listaTramitesRegulares != NULL)
    {
        //Asigno espacio en memoria
        pAuxTramite = newTramiteRegular();

        //Pido el dni al usuario
        dni = pedirCadenaInt("Ingrese su DNI", 0, 99999999);

        //Guardo el dni en la estructura
        regular_setDni(pAuxTramite, dni);
        regular_setId(pAuxTramite, listaTramitesRegulares);

        //Agrego el usuario a la lista
        ll_add(listaTramitesRegulares, pAuxTramite);

        retorno = 1;//cargó
    }

    return retorno;
}

//Setters
int regular_setDni(S_TramiteRegular* pTramiteRegular, long dni)
{

    pTramiteRegular->dni = dni;


    return 1;
}

int regular_setId(S_TramiteRegular* pTramiteRegular, LinkedList* listaTramitesRegulares)
{
    int retorno = 0; //no cargó

    if(pTramiteRegular != NULL)
    {
        pTramiteRegular->id=ll_len(listaTramitesRegulares);//Siempre me da el id siguiente libre
        retorno = 1;//cargó
    }

    return retorno;
}

