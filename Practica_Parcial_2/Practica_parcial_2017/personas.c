#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "personas.h"
#include "ArrayList.h"


eTramite* nuevoTramite()
{
    eTramite* auxiliar;
    //Creo un nuevo trámite, lo casteo a puntero a estructura

    auxiliar=(eTramite*)malloc(sizeof(eTramite));

    return auxiliar;
}

int setDni(eTramite* this, char* dni)
{
    int seteo=-1;

    //Compruebo que el puntero no venga NULL
    if (this!=NULL)
    {
        //Copio las strings
        strcpy(this->dni,dni);
        //Pongo el retorno en 0
        seteo=0;
    }

    return seteo;
}

char* getDni(eTramite* this)
{
    char* dni;

    //Compruebo que no sea nulo
    if(this!=NULL)
    {
        //Asigno el puntero
        dni=this->dni;
    }

    return dni;
}

int setIdTramite(eTramite* this, int id)
{
    int seteo=-1;

    //Compruebo que el puntero no venga NULL
    if(this!=NULL)
    {
        this->idTramite=id;
        //Pongo el retorno en 0
        seteo=0;
    }

    return seteo;
}

int getIdTramite(eTramite* this)
{
    int id=-1;

    if(this!=NULL)
    {
        id=this->idTramite;
    }

    return id;
}


int cargarTramite(ArrayList* listaTramite, int idTramite, char* dni)
{
    int cargo=-1;
    //Puntero a estructura para cargar el tramite actual
    eTramite* tramiteActual;

    //Me fijo que no venga NULL el puntero
    if(listaTramite!=NULL)
    {
        //Le asigno espacio en el heap
        tramiteActual=nuevoTramite();

        if(idTramite>0 && dni!=NULL)
        {
            //Agrego los datos con setters a la estructura que quiero cargar en la lista
            setDni(tramiteActual, dni);
            setIdTramite(tramiteActual, idTramite);

            //Cargo la estructura en la lista
            listaTramite->add(listaTramite, tramiteActual);

            //Cambio el retorno
            cargo=0;
        }
    }

    return cargo;

}

int mostrarTramite(eTramite* this)
{
    int mostro=-1;
    //Compruebo el puntero no sea NULL

    if(this!=NULL)
    {
        printf("%d-----%s\n",getIdTramite(this), getDni(this));
        mostro=0;
    }

    return mostro;

}

int mostrarListaTramites(ArrayList* this)
{
    int mostro=-1;
    int i;
    int largo;
    eTramite* tramiteActual;


    if(this!=NULL)
    {
        //averiguo el largo de la lista y cargo el valor en la variable
        largo=this->len(this);


        //Muestro todo lo que tiene la lista
        for(i=0;i<largo;i++)
        {
            //Cargo los datos de la lista en la estructura de a uno
            tramiteActual=(eTramite*)this->get(this,i);
            //Muestro el tramite
            mostrarTramite(tramiteActual);

        }

        mostro=0;

    }

    return mostro=-1;

}

int atenderTramite(ArrayList* this,ArrayList* listaAtendidos)
{
    int atendio=-1;

    eTramite* tramiteActual;

    if(this!=NULL && listaAtendidos!=NULL)
    {
        //Saco el tramite de la lista de pendientes
        tramiteActual=(eTramite*)this->pop(this,0);
        //Agrego el trámite a la lista de atendidos
        listaAtendidos->add(listaAtendidos,tramiteActual);
        //Muestro el trámite
        mostrarTramite(tramiteActual);

        atendio=0;

    }

    return atendio;

}

