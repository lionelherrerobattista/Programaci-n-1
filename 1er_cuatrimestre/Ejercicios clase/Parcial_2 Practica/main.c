#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Funciones.h"
#define TAM 10


int main()
{
    int propietariosCargados;
    int i;


    //Creo un puntero lista de propietarios
    ArrayList* listaPropietarios;
    //Creo la nueva lista
    listaPropietarios= al_newArrayList();

    //Creo el vector de estructuras
    //ePropietarios propietarios[TAM];

    //Defino un puntero a la estructura de propietarios
    ePropietarios* propietarioAux;
    ePropietarios* pPropietarios;
    //le asigno memoria
    propietarioAux=nuevoPropietario(TAM);
    pPropietarios=nuevoPropietario(TAM);
    //Hago que el vector apunte a la estructura
    //pPropietarios=propietarios;

    //Cargo datos desde archivo*/
    parseArchivo("Usuarios.txt", pPropietarios, listaPropietarios);


    //tamaño de los datos cargados
    propietariosCargados=al_len(listaPropietarios);
    printf("Propietarios cargados: %d\n",propietariosCargados);


    //Tomo y muestro los propietarios
    printf("\n%-10s %-10s %-10s %-10s\n","Id","Nombre","Tarjeta","Direccion");
    for(i=0;i<propietariosCargados;i++)
    {
        //Tomo el propietario en la ubicación i
        propietarioAux=(ePropietarios*)al_get(listaPropietarios,i);
        //Muestro el porpietario que tomé
        mostrarPropietario(propietarioAux);
    }

    printf("\nPropietario que se va a buscar:\n");
    mostrarPropietario(propietarioAux);
    //Compruebo que ese propietario está en la lista
    if(al_contains(listaPropietarios, propietarioAux))
    {
        printf("\nEncontro el elemento!\n");
    }


    //-Ingreso un elemento a la lista:

    //Le pido al usuario que ingrese datos
    //propietarios cargados siempre +1 que el total (?)
    propietarioAux=pedirPropietario(pPropietarios,TAM);
    //Ingreso el elemento
    al_set(listaPropietarios, 2, propietarioAux);


    //Tomo y muestro
    printf("\n%-10s %-10s %-10s %-10s\n","Id","Nombre","Tarjeta","Direccion");
    for(i=0;i<propietariosCargados;i++)
    {
        //Tomo el propietario en la ubicación i
        propietarioAux=(ePropietarios*)al_get(listaPropietarios,i);
        //Muestro el porpietario que tomé
        mostrarPropietario(pPropietarios+i);
    }

    /*
    //Saco un elemento de la lista y lo muestro
    propietarioAux2=nuevoPropietario();
    propietarioAux2=(ePropietarios*)al_pop(listaPropietarios,1);
    mostrarPropietario(propietarioAux2);*/
    /*printf("\n%-10s %-10s %-10s %-10s\n","Id","Nombre","Tarjeta","Direccion");
    for(i=0;i<propietariosCargados;i++)
    {
        //Tomo el propietario en la ubicación i
        propietarioAux=(ePropietarios*)al_get(listaPropietarios,i);
        //Muestro el porpietario que tomé
        mostrarPropietario(propietarioAux);
    }
    mostrarPropietario(propietarioAux2);*/





    return 0;
}
