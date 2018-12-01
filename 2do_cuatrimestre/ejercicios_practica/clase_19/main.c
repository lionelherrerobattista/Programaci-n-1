#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "persona.h"
#define CANTIDAD_PERSONAS 5



int main()
{
    char nombreArchivo[50]={"BIN.dat"};
    char auxApellido[50];
    char respuesta;
    int i=0;
    int totalPersonas=0;

    ePersona** listaPersonas; //Lista de punteros
    ePersona* auxPersona; //Puntero a la estructura persona

    //Creo la lista
    listaPersonas=persona_crearLista(CANTIDAD_PERSONAS);

    do
    {
        //Creo una persona para cargarla a la lista
        auxPersona=persona_crearPersona();
        //Cargo los datos
        persona_cargarPersona(auxPersona);

        //Coloco la estructura dentro de la lista
        *(listaPersonas+i)=auxPersona;// operador * y artimética de punteros !!
        i++; //Me muevo una posición en la lista

        pedirCadenaLetras("Desea continuar ingresando personas? (s/n)", &respuesta);

    }while(respuesta=='s');

    totalPersonas=i;

    crearBinario(listaPersonas, nombreArchivo, totalPersonas);

    cargarCadena("Ingrese el apellido a buscar", auxApellido);

    free(auxPersona);
    auxPersona=NULL;

    auxPersona=persona_buscarApellido(nombreArchivo, auxApellido, totalPersonas);
    if(auxPersona!=NULL)
    {
        printf("Se encontro:\n Nombre:%s\n Apellido:%s\n Edad:%d", auxPersona->name, auxPersona->surname, auxPersona->age);
    }
    else
    {
        printf("No se encontro.");
    }

    return 0;
}
