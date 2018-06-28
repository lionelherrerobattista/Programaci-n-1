#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Funciones.h"
#define TAM 4


int main()
{
    int propietariosCargados;
    //int i;


    //Creo un puntero lista de propietarios
    ArrayList* listaPropietarios;
    //Creo la nueva lista
    listaPropietarios= al_newArrayList();

    //Creo el vector de estructuras
    ePropietarios propietarios[TAM];

    //Defino un puntero a la estructura de propietarios
    //ePropietarios* propietarioAux;
    ePropietarios* pPropietarios;
    //le asigno memoria
    //propietarioAux=nuevoPropietario();
    pPropietarios=nuevoPropietario();
    //Hago que el vector apunte a la estructura
    pPropietarios=propietarios;

    //Cargo datos desde archivo*/
    parseArchivo("Usuarios.txt", pPropietarios, listaPropietarios);


    //tamaño de los datos cargados
    propietariosCargados=al_len(listaPropietarios);
    printf("Propietarios cargados: %d\n",propietariosCargados);

    /*
    //Tomo y muestro los propietarios
    printf("\n%-10s %-10s %-10s %-10s\n","Id","Nombre","Tarjeta","Direccion");
    for(i=0;i<propietariosCargados;i++)
    {
        //Tomo el propietario en la ubicación i
        propietarioAux=(ePropietarios*)al_get(listaPropietarios,i);
        //Muestro el porpietario que tomé
        mostrarPropietario(propietarioAux);
    }

    //Compruebo que ese propietario está en la lista
    if(al_contains(listaPropietarios, propietarioAux))
    {
        printf("\nEncontro el elemento!\n");
    }

    //-Ingreso un elemento a la lista:
    //Pido un nuevo propietario sino pisa el ultimo dato ingresado
    propietarioAux=nuevoPropietario();
    //Le pido al usuario que ingrese datos
    pedirPropietario(propietarioAux);
    //Ingreso el elemento
    al_set(listaPropietarios, 1, propietarioAux);

    //Tomo y muestro
    printf("\n%-10s %-10s %-10s %-10s\n","Id","Nombre","Tarjeta","Direccion");
    mostrarPropietario(propietarioAux);
    for(i=0;i<propietariosCargados;i++)
    {
        //Tomo el propietario en la ubicación i
        propietarioAux=(ePropietarios*)al_get(listaPropietarios,i);
        //Muestro el porpietario que tomé
        mostrarPropietario(propietarioAux);
    }

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
