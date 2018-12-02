#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "persona.h"

/**
1) Tomar el ejercicio de la clase 24
 y agregar a la biblioteca la posibilidad de crear más de una lista.
*/

int lista_getSize(eArrayList* listaPersonas);
int persona_cargarPersona(ePersona*);
ePersona** lista_getLista(eArrayList* arrayList, int index);
ePersona* lista_getPersona(ePersona** listaPersonas, int index);
void lista_free(eArrayList* arrayList);

int main()
{

    int i;

    //Creo los punteros
    eArrayList* listaPersonas;
    ePersona* auxPersona;

    //Creo array dinámico y lo inicializo
    listaPersonas=lista_inicializarArrayList();
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
        persona_mostrarPersona(lista_getPersona(listaPersonas->lista, i));
    }

    //Libero las personas
    for(i=0;i<lista_getSize(listaPersonas);i++)
    {
        if(lista_getPersona(listaPersonas->lista, i)!=NULL)
        {
            free(lista_getPersona(listaPersonas->lista, i));
        }

    }

    //Libero la lista
    lista_free(listaPersonas);

    return 0;
}

int lista_getSize(eArrayList* listaPersonas)
{
    int sizeLista=-1;

    if(listaPersonas!=NULL)
    {
        sizeLista=listaPersonas->index;
    }

    return sizeLista;
}

ePersona** lista_getLista(eArrayList* arrayList, int index)
{
    ePersona** listaPersonas;

    if(arrayList!=NULL)
    {
        listaPersonas=arrayList->lista+index;
    }

    return listaPersonas;
}

ePersona* lista_getPersona(ePersona** listaPersonas, int index)
{
    ePersona* persona=NULL;

    if(listaPersonas!=NULL)
    {
        persona=*(listaPersonas+index);
    }

    return persona;

}

int persona_cargarPersona(ePersona* persona)
{
    //Auxiliares para los datos
    char auxiliarNombre[32];
    int auxiliarEdad;
    int flag=0;

    if(persona!=NULL)
    {

        pedirCadenaLetras("Ingrese el nombre", auxiliarNombre);
        //Si escribe salir, termina de ingresar las personas
        if(stricmp(auxiliarNombre,"salir")==0)
        {
            flag=-1;
        }
        else
        {
            auxiliarEdad=pedirCadenaInt("Ingrese la edad",1, 100);
            //Cargo el auxiliar con los datos
            persona_setName(persona, auxiliarNombre);
            persona_setAge(persona, auxiliarEdad);
            flag=1;
        }
    }

    return flag;
}

void lista_free(eArrayList* arrayList)
{
    if(arrayList!=NULL)
    {
        free(arrayList);
    }

}
