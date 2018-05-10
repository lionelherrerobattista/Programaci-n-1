#include <stdio.h>
#include <stdlib.h>
#include "Propietarios.h"
#define TAMPROPIETARIOS 10
#define TAMAUTOS 20

int main()
{
    ePropietarios listaDePropietarios[TAMPROPIETARIOS];
    eAutos listaDeAutos[TAMAUTOS];

    int opcion=0;

    inicializarPropietario(listaDePropietarios, TAMPROPIETARIOS);
    inicializarPropietariosHardCode(listaDePropietarios, TAMPROPIETARIOS);

    inicializarAutos(listaDeAutos, TAMAUTOS);
    inicializarAutosHardCode(listaDeAutos, TAMAUTOS);


    do
    {
        printf(" \n");
        printf("\n1.ALTAS PROPIETARIO\n2.MODIFICACION PROPIETARIO\n3.BAJA PROPIETARIO\n4.INGRESO AUTOMOVIL\n5.EGRESO\n10.MOSTRAR PROPIETARIOS\n11.MOSTRAR AUTOS\n12.SALIR\n \nElija una opcion: ");
        scanf("%d", &opcion);
        printf(" \n");

        switch (opcion)
        {
            case 1:
                    altaPropietario(listaDePropietarios, TAMPROPIETARIOS);
                    break;

            case 2:
                    mostrarPropietarios(listaDePropietarios, TAMPROPIETARIOS);
                    modificarPropietario(listaDePropietarios, TAMPROPIETARIOS);
                    break;

            case 3:
                    mostrarPropietarios(listaDePropietarios, TAMPROPIETARIOS);
                    bajaPropietario(listaDePropietarios, TAMPROPIETARIOS);
                    break;

            case 4:
                    altaAuto(listaDeAutos, TAMAUTOS);
                    break;
            case 5:



            case 10:
                    mostrarPropietarios(listaDePropietarios, TAMPROPIETARIOS);
                    break;

            case 11:
                    mostrarAutos(listaDePropietarios, TAMPROPIETARIOS, listaDeAutos, TAMAUTOS);
                    break;



        }




    } while (opcion!=12);

    return 0;
}
