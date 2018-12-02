#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "persona.h"


/**
1) Tomar el ejercicio de la clase 20
 y cambiar el array estático por uno dinámico usando malloc.
*/


int main()
{
    //Auxiliares para los datos
    char auxiliarNombre[32];
    int auxiliarEdad;
    int i;

    //Creo los punteros
    eListaPersonas* listaPersonas;
    ePersona* auxPersona;

    //Creo array dinámico y lo inicializo
    listaPersonas=persona_inicializarLista();


    do
    {
        //Creo una persona
        auxPersona=persona_crearPersona();

        //Pido los datos
        pedirCadenaLetras("Ingrese el nombre", auxiliarNombre);
        //Si escribe salir, termina de ingresar las personas
        if(stricmp(auxiliarNombre,"salir")==0)
        {
            break;
        }
        auxiliarEdad=pedirCadenaInt("Ingrese la edad",1, 100);

        //Cargo el auxiliar con los datos
        persona_setName(auxPersona, auxiliarNombre);
        persona_setAge(auxPersona, auxiliarEdad);

        //Agrego la persona a la lista dinámica
        persona_addPersona(listaPersonas, auxPersona);
        printf("Nombre:%s\nEdad:%d\n", persona_getName(*(listaPersonas->lista)), persona_getAge(*(listaPersonas->lista)));

    }while(listaPersonas->index!=-1);


    //Muestro solo hasta la cantidad de personas que cargué (uso el index)
    for(i=0;i<listaPersonas->index;i++)
    {
        mostrarPersona(*(listaPersonas->lista+i));
    }


    return 0;
}

