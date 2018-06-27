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

    //Defino un puntero a la estructura de propietarios de tam 1 propietario
    ePropietarios* propietarioAux;
    //Iteración que carga los datos
    for (i=0;i<TAM;i++)
    {
        //Pido memoria del tamaño de la estructura
        propietarioAux=malloc(sizeof(ePropietarios));
        //Cargo datos desde archivo
        parseArchivo("Usuarios.txt",propietarioAux);
        //Pongo el estado en 1
        ePropietarios_setEstado(propietarioAux,1);
        //Agrego el propietario a la lista
        al_add(listaPropietarios,propietarioAux);
    }

    //tamaño de los datos cargados
    propietariosCargados=al_len(listaPropietarios);

    printf("Propietarios cargados: %d",propietariosCargados);



    return 0;
}
