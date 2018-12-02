#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "persona.h"
#define TAM_PERSONAS 5

/**
    1) Ingresar datos de 1 persona e imprimirlos.
    Crear la estructura "Persona":

    nombre [32]
    edad

    Si se ingresa 'salir' como nombre, se debe salir del programa,
    de lo contrario se pedirán los datos de nuevo.


    2) Modificar el ejercicio anterior para guardar
    las personas en un array estatico e imprimirlas al salir
 */




int main()
{
    char auxiliarNombre[32];
    int auxiliarEdad;
    int i=0;
    int j;

    ePersona persona[TAM_PERSONAS];


    do
    {

        pedirCadenaLetras("Ingrese el nombre", auxiliarNombre);
        //Si escribe salir, termina de ingresar las personas
        if(stricmp(auxiliarNombre,"salir")==0)
        {
            break;
        }
        auxiliarEdad=pedirCadenaInt("Ingrese la edad",1, 100);

        //Paso la dirección de memoria de la estructura
        persona_setName(&persona[i], auxiliarNombre);
        persona_setAge(&persona[i], auxiliarEdad);
        i++;

    }while(i!=TAM_PERSONAS);//Mientras no llegue a cargar el max.


    //Muestro solo hasta la cantidad de personas que cargué (i)
    for(j=0;j<i;j++)
    {
        mostrarPersona(persona[j]);
    }


    return 0;
}
