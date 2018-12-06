#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "parser.h"
#include "LinkedList.h"
#include "logs.h"


S_LogEntry* newLog()
{

    S_LogEntry* pLogEntry=NULL;

    pLogEntry=(S_LogEntry*)malloc(sizeof(S_LogEntry));

    return pLogEntry;
}

