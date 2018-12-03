#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "persona.h"

int main()
{

    int i;
    int indice_a_borrar;

    //Creo los punteros
    eArrayList* listaPersonas=NULL;
    eArrayList* listaEmpleados=NULL;
    ePersona* auxPersona=NULL;

    //Creo array dinámico y lo inicializo
    listaPersonas=lista_inicializarArrayList();
    //Puedo crear otra lista
    listaEmpleados=lista_inicializarArrayList();
    //Creo una persona
    auxPersona=persona_crearPersona();


    //Cargo los datos:
    while(persona_cargarPersona(auxPersona)!=-1)
    {
        //Agrego la persona a la lista dinámica
        if(lista_addPersona(listaPersonas, auxPersona)==-1)//Si no hay espacio en memoria
        {
            break;//Sino error
        }

        //Creo una persona nueva
        auxPersona=persona_crearPersona();

    }

    //Libero el auxiliar
    if(auxPersona!=NULL)
    {
        free(auxPersona);
    }



    //Muestro solo hasta la cantidad de personas que cargué (uso el index)
    for(i=0;i<lista_getSize(listaPersonas);i++)
    {
        persona_mostrarPersona(lista_getPersona(lista_getLista(listaPersonas, 0), i));
    }

    //Pregunto por el indice que quiero borrar
    indice_a_borrar=pedirCadenaInt("Ingrese el indice a borrar", 0, lista_getIndex(listaPersonas));
    lista_borrarPersona(listaPersonas,indice_a_borrar);

    for(i=0;i<lista_getSize(listaPersonas);i++)
    {
        persona_mostrarPersona(lista_getPersona(lista_getLista(listaPersonas, 0), i));
    }

    //Libero las personas
    for(i=0;i<lista_getSize(listaPersonas);i++)
    {
        if(lista_getPersona(lista_getLista(listaPersonas, 0), i)!=NULL)
        {
            free(lista_getPersona(lista_getLista(listaPersonas, 0), i));
        }

    }

    //Libero la lista
    lista_free(listaPersonas);

    return 0;
}
