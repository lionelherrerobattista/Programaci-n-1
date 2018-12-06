#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "logs.h"


int main()
{
    LinkedList* listaLogs;

    listaLogs=ll_newLinkedList();

    S_LogEntry* auxLog;

    archivo_cargarLog(listaLogs);

    auxLog=ll_get(listaLogs, 0);


    printf("%s-----%s------%d\n", auxLog->date, auxLog->time,auxLog->serviceId);
    auxLog=ll_get(listaLogs, 1);
    printf("%s-----%s------%d", auxLog->date, auxLog->time,auxLog->serviceId);



    return 0;
}
