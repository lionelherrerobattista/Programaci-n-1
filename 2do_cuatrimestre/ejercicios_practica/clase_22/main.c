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


    ePersona** listaPersonas; //Puntero donde se guarda el array de punteros a Persona
    ePersona* auxiliarPersona;
    ePersona** auxiliarLista;

    //Creo el array de estructuras persona de forma dinámica:
    listaPersonas= (ePersona**)malloc(sizeArray * sizeof(ePersona*));

    do
    {

        //Creo la persona de forma dinámica:
        auxiliarPersona=(ePersona*)malloc(sizeof(ePersona));

        pedirCadenaLetras("Ingrese el nombre", auxiliarNombre);
        //Si escribe salir, termina de ingresar las personas
        if(stricmp(auxiliarNombre,"salir")==0)
        {
            break;
        }
        auxiliarEdad=pedirCadenaInt("Ingrese la edad",1, 100);

        //Paso la dirección de memoria de la estructura (Por referencia)
        persona_setName(auxiliarPersona, auxiliarNombre);
        persona_setAge(auxiliarPersona, auxiliarEdad);

        //Cargo la persona pasando los valores int por referencia
        *(listaPersonas+index)=auxiliarPersona; //puntero, tengo que usar operador * !!
        //Me muevo a la posición del siguiente indice
        (index)+=1;//puntero, tengo que usar operador * !!

        //Me fijo si no está completo el array
        if(index>=sizeArray)
        {
            printf("\nRedefino el array\n");
            (sizeArray)+=2; //puntero, tengo que usar operador * !!
            auxiliarLista=(ePersona**) realloc(listaPersonas, sizeArray * sizeof(ePersona*));

            if(auxiliarLista!=NULL)
            {
                listaPersonas=auxiliarLista;
            }
        }

    }while(index!=-1);//Mientras no llegue a cargar el max.


    //Libero el espacio en memoria
    free(auxiliarPersona);

    //Muestro solo hasta la cantidad de personas que cargué (index)
    for(i=0;i<index;i++)
    {
        mostrarPersona(listaPersonas[i]);//Paso la dir de memoria de las estructuras
    }

    //Libero el espacio en memoria
    for(i=0;i<index;i++)
    {
        free(*(listaPersonas+i));
    }


    return 0;
}
