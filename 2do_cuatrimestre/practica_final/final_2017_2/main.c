#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "logs.h"
#include "services.h"
#include "parser.h"
#include "filtros.h"
#include "LinkedList.h"

int main()
{
    int opcion;
    int contadorWarnings = 0;
    int contadorGravedadMedia = 0;
    int contadorErrors = 0;
    int contadorErroresMenores = 0;

    LinkedList* listaLogs;
    LinkedList* listaServices;

    //Creo la nueva lista
    listaLogs = ll_newLinkedList();
    listaServices = ll_newLinkedList();



    do
    {
        //funcion que muestra el menú
        mostrarMenu();

        //pido la opción al usuario
        opcion = pedirCadenaInt("Opcion", 1, 4);

        switch(opcion)
        {
            case 1:
                if(archivo_cargarLogs("logs.txt", listaLogs))
                {
                    printf("Carga exitosa de logs.\n");
                }
                if(archivo_cargarServices("services.txt", listaServices))
                {
                    printf("Carga exitosa de services.\n");
                }
                break;
            case 2:
                contadorWarnings = filtrarWarnings(listaLogs, listaServices);
                contadorGravedadMedia = filtrarGravedadMedia(listaLogs, listaServices);
                contadorErrors = filtrarErrors(listaLogs, listaServices);
                break;
            case 3:
                contadorErroresMenores = contarErroresMenores(listaLogs);
                printf("Cantidad Errores Menores: %d\n", contadorErroresMenores);
                printf("Cantidad Warnings: %d\n", contadorWarnings);
                printf("Cantidad Gravedad Media: %d\n", contadorGravedadMedia);
                printf("Cantidad Errors: %d\n", contadorErrors);
                mostrarServicioConMasErrores(listaLogs, listaServices);
                break;

        }


    }while(opcion != 4);


    return 0;
}


