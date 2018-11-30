#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "persona.h"

void persona_cargarListaPersona(ePersona listaPersona[], int indice);

int main()
{
    char nombreArchivo[50]={"BIN.dat"};
    char auxApellido[50];
    char respuesta;
    int i=0;
    int totalPersonas=0;

    ePersona listaPersonas[5];
    ePersona* auxPersona;

    do
    {
        persona_cargarListaPersona(listaPersonas, i);

        i++;

        printf("Desea continuar ingresando personas? (s/n): ");
        scanf("%c", &respuesta);


    }while(respuesta=='s');

    totalPersonas=i;

    crearBinario(listaPersonas, nombreArchivo, totalPersonas);

    cargarCadena("Ingrese el apellido a buscar", auxApellido);

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

void persona_cargarListaPersona(ePersona listaPersonas[], int indice)
{
    char auxNombre[50];
    char auxApellido[50];
    int auxEdad;

    pedirCadenaLetras("Ingrese el nombre", auxNombre);
    pedirCadenaLetras("Ingrese el apellido", auxApellido);
    auxEdad=pedirCadenaInt("Ingrese la edad", 0, 100);

    persona_setName(listaPersonas, auxNombre, indice);
    persona_setSurname(listaPersonas, auxApellido, indice);
    persona_setAge(listaPersonas, auxEdad, indice);

}
