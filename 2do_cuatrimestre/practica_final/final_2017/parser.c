#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "parser.h"
#include "LinkedList.h"
#include "logs.h"



void archivo_cargarLog(LinkedList* listaLogs)
{
    FILE* pArchivo;
    S_LogEntry* auxLog;

    pArchivo=fopen("log.txt","r");

    char auxFecha[32];
    char auxHora[32];
    char auxId[32];
    char auxGravedad[32];
    char auxMensaje[64];

    int cantidadDatos=0;


    if(pArchivo!=NULL)
    {
        do
        {
            cantidadDatos=fscanf(pArchivo,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n",auxFecha,auxHora,auxId,
                                 auxGravedad,auxMensaje);

            //"%[^;];%[^;];%[^;];%[^;];%[^\n]\n"
            if(cantidadDatos==5)
            {

                    auxLog=newLog();
                    strcpy(auxLog->date, auxFecha);
                    strcpy(auxLog->time, auxHora);
                    auxLog->serviceId=atoi(auxId);
                    auxLog->gravedad=atoi(auxGravedad);
                    strcpy(auxLog->msg,auxMensaje);

                    ll_add(listaLogs, auxLog);

            }


        }while(!feof(pArchivo));

        fclose(pArchivo);





    }

}
