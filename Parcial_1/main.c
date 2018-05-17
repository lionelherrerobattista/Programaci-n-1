#include <stdio.h>
#include <stdlib.h>
#include "Propietarios.h"

#define TAMPROPIETARIOS 20
#define TAMAUTOS 20
#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4

int main()
{
    int opcion=0;



    ePropietarios listaDePropietarios[TAMPROPIETARIOS];
    eAutos listaDeAutos[TAMAUTOS];



    inicializarPropietario(listaDePropietarios, TAMPROPIETARIOS);
    inicializarPropietariosHardCode(listaDePropietarios, TAMPROPIETARIOS);

    inicializarAutos(listaDeAutos, TAMAUTOS);
    inicializarAutosHardCode(listaDeAutos, TAMAUTOS);


    do
    {
        printf(" \n");
        printf("\n1.ALTAS PROPIETARIO\n2.MODIFICACION PROPIETARIO\n3.BAJA PROPIETARIO\n4.INGRESO AUTOMOVIL\n5.EGRESO\n6.RECAUDACION TOTAL\n7.ESTADIA POR MARCA\n8.MOSTRAR PROPIETARIO Y SUS AUTOS\n9.DATOS PROPIETARIOS DE AUDI\n10.AUTOS ORDENADOS POR PATENTE\n11.MOSTRAR PROPIETARIOS\n12.MOSTRAR AUTOS\n13.SALIR\n \nElija una opcion: ");
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
                    egresoAutomovil(listaDeAutos, TAMAUTOS, listaDePropietarios);
                    break;
            case 6:
                    mostrarRecaudacionTotal(listaDeAutos, TAMAUTOS);
                    break;
            case 7:
                    mostrarEstadiaPorMarca(listaDeAutos,TAMAUTOS);
                    break;
            case 8:
                    mostrarPropietarioConAutos(listaDePropietarios, TAMPROPIETARIOS, listaDeAutos, TAMAUTOS);
                    break;
            case 9:
                    printf("\nPropietarios con Audi:\n");
                    mostrarAutoPorMarca(listaDeAutos, TAMAUTOS, listaDePropietarios, TAMPROPIETARIOS, AUDI);
                    break;
            case 10:
                    autosOrdenadosPorPatente(listaDeAutos, TAMAUTOS, listaDePropietarios, TAMPROPIETARIOS);
                    break;

            case 11:
                    mostrarPropietarios(listaDePropietarios, TAMPROPIETARIOS);
                    break;

            case 12:
                    mostrarAutos(listaDePropietarios, TAMPROPIETARIOS, listaDeAutos, TAMAUTOS);
                    break;



        }




    } while (opcion!=13);

    return 0;
}
