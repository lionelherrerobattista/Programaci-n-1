#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Funciones.h"
#define TAM 4


int main()
{
    int i;
    int propietariosCargados;


    //Creo un puntero lista de propietarios
    ArrayList* listaPropietarios;
    //Creo la nueva lista
    listaPropietarios= al_newArrayList();

    //Defino un puntero a la estructura de propietarios de tam
    ePropietarios* propietarios[TAM];
    ePropietarios* propietarioAux;
    //Iteraci�n que carga los datos
    for (i=0;i<TAM;i++)
    {
        /*
        //Pido memoria del tama�o de la estructura
        propietarios[TAM]=malloc(sizeof(ePropietarios));
        //Cargo datos desde archivo*/
        parseArchivo("Usuarios.txt",propietarios[TAM], listaPropietarios);
        /*//Pongo el estado en 1
        ePropietarios_setEstado(propietarios[TAM],1);*/
        //Agrego el propietario a la lista
        al_add(listaPropietarios,propietarios[TAM]);
    }

    //tama�o de los datos cargados
    propietariosCargados=al_len(listaPropietarios);

    printf("Propietarios cargados: %d\n",propietariosCargados);

    propietarioAux=al_get(listaPropietarios,0);

    mostrarPropietario(propietarioAux);



    return 0;
}
