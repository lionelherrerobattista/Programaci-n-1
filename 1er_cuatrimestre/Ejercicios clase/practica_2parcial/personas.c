#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "personas.h"
#include "ArrayList.h"

eTramite* new_Tramite()
{
    eTramite* aux;

    aux=(eTramite*)malloc(sizeof(eTramite));

    return aux;
}

int setId(eTramite* this, int id)
{
    int seteo=-1;

    if(this!=NULL)
    {
        this->idTramite=id;
        seteo=0;
    }
    return seteo;
}
int getId (eTramite* this)
{
    int id=-1;
    if(this!=NULL)
    {
        id=this->idTramite;
    }

    return id;
}

int setDni(eTramite* this, int dni)
{
    int seteo=-1;

    if(this!=NULL)
    {
        //if(dni!=NULL)
        {
            strcpy(this->dni,dni);
            seteo=0;
        }
    }
    return seteo;
}

char* getDni (eTramite* this)
{
    char* dni=NULL ;

    if(this!=NULL)
    {
        dni=this->dni;
    }
    return dni;


}


int mostrarTramite(eTramite* this)
{
    int mostro=-1;
    if(this!=NULL)
    {
        printf("%d--%s\n",getId(this),getDni(this));//(this->idTramite,this->dni);
        mostro=0;
    }
    return mostro;
}

int compararPorDni(void* tramiteA,void* tramiteB)
{
    eTramite* tramiteUno;
    eTramite* tramiteDos;

    tramiteUno=(eTramite*)tramiteA; //
    tramiteDos=(eTramite*)tramiteB;

    return strcmp(tramiteUno->dni,tramiteDos->dni);
}

int mostrarListaTramites(ArrayList* listado)
{
    int listo= -1;
    int i;
    int len;
    eTramite* tramiteActual;

    if(listado!=NULL)
    {
        len=listado->len(listado);
        for(i=0; i<len; i++)
        {
            tramiteActual=(eTramite*)listado->get(listado,i);
            mostrarTramite(tramiteActual);
            listo=0;
        }
    }
    return listo;
}

int cargarTramite(ArrayList* listado, int id,char* dni)
{
    int cargo=-1;
    eTramite*  tramiteActual;

    if(listado!=NULL)
    {
        tramiteActual=new_Tramite();
        if(id>0 && dni!=NULL)
        {
            setId(tramiteActual,id);

            setDni(tramiteActual,dni);

            listado->add(listado,tramiteActual);
            cargo=0;
        }
    }
    return cargo;
}


int atenderTramite (ArrayList* listaDePendientes,ArrayList* listaDeAtendidos)
{
    int atendio=-1;
    eTramite* tramiteActual;

    if(listaDeAtendidos!=NULL && listaDePendientes!=NULL)
    {
        tramiteActual=(eTramite*)listaDePendientes->pop(listaDePendientes,0);//saca

        listaDeAtendidos->add(listaDeAtendidos,tramiteActual);//pone

        mostrarTramite(tramiteActual);
    }

}

/*void auxMostrarUnaLista(ArrayList* Clientes)
{
    int ocupado=0;
    int longitud;

    longitud=Clientes->len(Clientes);

        for(int i=0;i <longitud; i++)
        {

            if( Clientes->estado>0)
            {
                printf("DNI---TRAMITE--TURNO\n\n");
                printf("\n%d       %d    %d\n\n",Clientes->dni,Clientes->estado,Clientes->turno);
            }
        }
}*/



/*void mostrarLista (Clientes* personas)
{
    int i;
    //int flag=1;
    int longitud;

    longitud=personas->len(personas);


    for(i=0; i<longitud; i++)
    {
        if(Clientes->estado>0)
        {
            printf("\nDNI---TRAMITE--TURNO\n\n");
            auxMostrarUnaLista(personas);
        }

        else
        {
            printf("NO se ingresaron datos!!!\n\n");
            break;
        }
    }


}*/
