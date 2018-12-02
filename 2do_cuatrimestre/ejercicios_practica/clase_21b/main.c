#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "persona.h"


int main()
{
    char auxiliarNombre[32];
    int auxiliarEdad;
    int sizeArray=2;//Tamaño del array de personas
    int index=0;
    int i;


    ePersona* listaPersonas; //Puntero donde se guarda el array de estructuras
    ePersona auxiliarPersona;

    //Creo el array de estructuras persona de forma dinámica:
    listaPersonas= crearLista(sizeArray);




    do
    {

        pedirCadenaLetras("Ingrese el nombre", auxiliarNombre);
        //Si escribe salir, termina de ingresar las personas
        if(stricmp(auxiliarNombre,"salir")==0)
        {
            break;
        }
        auxiliarEdad=pedirCadenaInt("Ingrese la edad",1, 100);

        //Paso la dirección de memoria de la estructura (Por referencia)
        persona_setName(&auxiliarPersona, auxiliarNombre);
        persona_setAge(&auxiliarPersona, auxiliarEdad);

        //Cargo la persona pasando los valores int por referencia
        cargarPersona(listaPersonas, auxiliarPersona, &index, &sizeArray);

    }while(index!=-1);//Mientras no llegue a cargar el max.


    //Muestro solo hasta la cantidad de personas que cargué (index)
    for(i=0;i<index;i++)
    {
        mostrarPersona((listaPersonas+i));//Paso la dir de memoria de las estructuras
    }

    return 0;
}

