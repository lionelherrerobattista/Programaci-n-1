#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "logs.h"
#include "services.h"
#include "validaciones.h"

void procesarInfo(LinkedList* listaLogs,LinkedList* listaServices);
void archivo_crearWarning(LinkedList* listaLogs, LinkedList* listaServices);

int main()
{
    int respuesta=0;

    LinkedList* listaLogs;
    LinkedList* listaServices;


    listaLogs=ll_newLinkedList();
    listaServices=ll_newLinkedList();


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
                archivo_cargarLog(listaLogs);
                archivo_cargarService(listaServices);
                break;
            case 2:
                procesarInfo(listaLogs, listaServices);
                break;
            case 3:
                break;

        }
    }while(respuesta!=4);



    return 0;
}

void procesarInfo(LinkedList* listaLogs,LinkedList* listaServices)
{
    int i;//logs
    int j;//warnings
    S_LogEntry* auxLog;
    S_Service* auxServices;

    LinkedList* listaLogsWarnings;
    LinkedList* listaServicesWarnings;

    listaLogsWarnings=ll_newLinkedList();
    listaServicesWarnings=ll_newLinkedList();

    for(i=0;i<ll_len(listaLogs); i++)
    {
        auxLog=ll_get(listaLogs, i);

        if(auxLog->gravedad==3)//imprimir en warnings.txt
        {
            ll_add(listaLogsWarnings, auxLog);//Agrego el log a una nueva lista

            for(j=0;j<ll_len(listaServices);j++)
            {
                auxServices=ll_get(listaServices, j);

                if(auxLog->serviceId==auxServices->id)
                {
                    ll_add(listaServicesWarnings, auxServices);//Agrego el service que coincide
                    break;
                }

            }

            //creo el archivo de warnings
            archivo_crearWarning(listaLogsWarnings, listaServicesWarnings);

        }
        else
        {



            if(auxLog->gravedad>3 && auxLog->gravedad<=7) //Imprimir por pantalla (menos 45)
            {


            }
            else
            {
                if(auxLog->gravedad<7)//Copiar en errors.txt
                {

                }
            }
        }


    }
}

void archivo_crearWarning(LinkedList* listaLogs, LinkedList* listaServices)
{
    FILE* pArchivo;
    //Creo los auxiliares
    S_LogEntry* auxLog;
    S_Service* auxService;

    int i=0;//logs
    int j;//services

    pArchivo=fopen("warnings.txt", "w");

    if(pArchivo!=NULL)
    {
        while(i<ll_len(listaLogs))
        {
            auxLog=ll_get(listaLogs, i);

            for(j=0;j<ll_len(listaServices);j++)//Busco en la lista de services
            {
                auxService=ll_get(listaServices, j);

                if(auxLog->serviceId==auxService->id)//Me fijo que conicidan los id
                {
                    //Imprimo los dos juntos
                    fprintf(pArchivo,"%s;%s;%s;%s;%s\n",auxLog->date, auxLog->time,
                        auxService->name, auxLog->msg, auxService->email);
                    break;
                }

            }

            i++;

        }

        fclose(pArchivo);

    }
    else
    {
        printf("No se pudo crear el archivo.");
    }
}

