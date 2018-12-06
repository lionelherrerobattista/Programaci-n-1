#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "logs.h"
#include "services.h"
#include "validaciones.h"


int main()
{
    int respuesta=0;

    LinkedList* listaLogs;
    LinkedList* listaServices;


    listaLogs=ll_newLinkedList();
    listaServices=ll_newLinkedList();

    archivo_cargarLog(listaLogs);
    archivo_cargarService(listaServices);

    do
    {
        printf("---------------------------\n");
        printf("1-Leer Log\n");
        printf("2-Procesar informacion\n");
        printf("3-Mostrar estadisticas\n");
        printf("4-Salir\n");
        printf("---------------------------\n");
        respuesta=pedirCadenaInt("Opcion", 1, 4);



        switch(respuesta)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;

        }
    }while(respuesta!=4);



    return 0;
}
