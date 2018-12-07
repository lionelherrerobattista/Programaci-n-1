#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "logs.h"
#include "services.h"
#include "validaciones.h"
#include "informacion.h"

void procesarInfo(LinkedList* listaLogs,LinkedList* listaServices)
{
    int i;//logs
    int j;//warnings
    S_LogEntry* auxLog;
    S_Service* auxServices;

    LinkedList* listaLogsWarnings;
    LinkedList* listaServicesWarnings;

    LinkedList* listaLogsError;
    LinkedList* listaServicesError;

    listaLogsWarnings=ll_newLinkedList();
    listaServicesWarnings=ll_newLinkedList();

    listaLogsError=ll_newLinkedList();
    listaServicesError=ll_newLinkedList();

    for(i=0;i<ll_len(listaLogs); i++)
    {
        auxLog=ll_get(listaLogs, i);

        //gravedad==3 imprimir en warnings.txt
        if(auxLog->gravedad==3)
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

            //creo el archivo de warnings, paso las nuevas listas a la función
            archivo_crearWarning(listaLogsWarnings, listaServicesWarnings);

        }
        else
        {


             //Imprimir por pantalla (menos 45)
            if((auxLog->gravedad>3 && auxLog->gravedad<=7) && auxLog->serviceId!=45)
            {

                for(j=0;j<ll_len(listaServices);j++)
                {
                    auxServices=ll_get(listaServices, j);

                    if(auxLog->serviceId==auxServices->id)
                    {
                        mostrarInfo(auxLog,auxServices);
                        break;
                    }

                }


            }
            else
            {
                if(auxLog->gravedad>7)//Copiar en errors.txt
                {
                    ll_add(listaLogsError, auxLog);//Agrego el log a una nueva lista

                    for(j=0;j<ll_len(listaServices);j++)
                    {
                        auxServices=ll_get(listaServices, j);

                        if(auxLog->serviceId==auxServices->id)
                        {
                            ll_add(listaServicesError, auxServices);//Agrego el service que coincide
                            break;
                        }

                    }

                    //creo el archivo de warnings, paso las nuevas listas a la función
                    archivo_crearError(listaLogsError, listaServicesError);

                }
            }
        }


    }
}



void mostrarInfo(S_LogEntry* auxLogs, S_Service* auxServices)
{
    printf("%s;%s;%s;%s;%d\n", auxLogs->date, auxLogs->time, auxServices->name,
            auxLogs->msg, auxLogs->gravedad);
}



void mostrarEstadisticas(LinkedList* listaLogs, LinkedList* listaServices)
{
    int contadorFallosA=0;//<3
    int contadorFallosB=0;//=3
    int contadorFallosC=0;//3< x <=7
    int contadorFallosD=0;//>7

    int maxFallos=0;
    int fallos=0;
    int flag=0;

    int i;//logs
    int j;

    S_LogEntry* auxLog;
    S_Service* auxService;
    S_Service* servicioMasFallos;


    //Servicio con mas fallos:
    for(j=0;j<ll_len(listaServices);j++)
    {
        auxService=ll_get(listaServices, j);
        fallos=0;

        for(i=0;i<ll_len(listaLogs); i++)
        {
            auxLog=ll_get(listaLogs, i);

            if(auxService->id == auxLog->serviceId)
            {
                    fallos++;
            }
        }

        if(flag==0)
        {
            maxFallos=fallos;
            servicioMasFallos=ll_get(listaServices, j);
            flag=1;


        }
        else
        {
            if(flag==1 && maxFallos<fallos)
            {

                maxFallos=fallos;
                servicioMasFallos=ll_get(listaServices, j);
            }
        }


    }

    //Cantidad de fallos:
    for(i=0;i<ll_len(listaLogs); i++)
    {
        auxLog=ll_get(listaLogs, i);

        if(auxLog->serviceId == servicioMasFallos->id)
        {

            //gravedad==3
            if(auxLog->gravedad==3)
            {
                contadorFallosB++;

            }
            else
            {


                 //Imprimir por pantalla (menos 45)
                if((auxLog->gravedad>3 && auxLog->gravedad<=7) && auxLog->serviceId!=45)
                {
                    contadorFallosC++;

                }
                else
                {
                    if(auxLog->gravedad>7)//Copiar en errors.txt
                    {
                        contadorFallosD++;

                    }
                    else
                    {
                        contadorFallosA++;
                    }



                }

            }
        }
    }

    printf("Servicio con mas fallos: %s\nFallos:%d\n", servicioMasFallos->name, maxFallos);
    printf("----------Cantidad de Fallos-----------\n");
    printf("Menores a tres:%d\nTres:%d\nEntre cuatro y siete inclusive:%d\nMayores a siete:%d\n", contadorFallosA,
            contadorFallosB, contadorFallosC, contadorFallosD);

}
