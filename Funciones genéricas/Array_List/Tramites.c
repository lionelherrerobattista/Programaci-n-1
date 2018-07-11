#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "ArrayList.h"


eTramite* nuevoTramite()
{
    eTramite* auxiliar;
    //Creo un nuevo trámite, lo casteo a puntero a estructura

    auxiliar=(eTramite*)malloc(sizeof(eTramite));

    return auxiliar;
}


//Setter y getters
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


//Agregar a lista
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


//Mostrar elemento de la lista
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

//Mostrar todos los elementos de la lista:
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

//Saco un elemento de la lista y los muestro:
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


//Función que filtra elementos de una lista:
int functionFilter(void* item)
{
    int retorno=0;


    if(item!=NULL)
    {

        if(strcmpi(getProfesion(item),"programador")==0 && getEdad(item)>30)
        {
            retorno=1;
        }
    }

    return retorno;
}

ArrayList* filtarLista(ArrayList* this)
{
    ArrayList* listaFiltrada;

    //Utilizo la función al_filter
    listaFiltrada=al_filter(this,*functionFilter);

    return listaFiltrada;
}

//Función para crear un archivo y escribir:
void crearArchivo(ArrayList* this)
{
    FILE* miArchivo;

    char buffer[500]={};
    char bufferAux[500]={};

    int i;

    if(this!=NULL)
    {
        miArchivo = fopen("out.csv","w");

        if(miArchivo!=NULL)
        {
            for(i=0;i<al_len(this);i++)
            {
                //funcion que escribe el int en una string
                sprintf(bufferAux,"%d",eEmpleados_getId(this,i));
                //strcpy para vaciar el buffer en la nueva iteración
                strcpy(buffer,bufferAux);
                strcat(buffer,", ");
                strcat(buffer,eEmpleados_getNombre(this,i));
                strcat(buffer,", ");
                sprintf(bufferAux,"%f",eEmpleados_getSueldo(this,i));
                strcat(buffer,bufferAux);
                strcat(buffer,", ");
                sprintf(bufferAux,"%d",eEmpleados_getEdad(this,i));
                strcat(buffer,bufferAux);
                strcat(buffer,", ");
                strcat(buffer,eEmpleados_getProfesion(this,i));


                fprintf(miArchivo,"\n%s",buffer);

            }



            fclose(miArchivo);

        }

    }

}


//Funcion que compara
int compararPorDni(void* tramiteA, void* tramiteB)
{
    eTramite* tramiteUno;
    eTramite* tramiteDos;

    int comparacion;

    if(tramiteA!=NULL && tramiteB!=NULL)
    {
        tramiteUno=tramiteA;
        tramiteDos=tramiteB;

        comparacion=strcmp(getDni(tramiteUno),getDni(tramiteDos));
    }

    return comparacion;

}
