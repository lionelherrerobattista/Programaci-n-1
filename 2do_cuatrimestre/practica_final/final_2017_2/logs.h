#include "LinkedList.h"

typedef struct
{
    char date[11];
    char time[6];
    int serviceId;
    int gravedad;
    char msg[65];

}S_LogEntry;

S_LogEntry* newLog();
void cargarLogs(S_LogEntry* pEstructura, char* auxDate, char* auxTime, char* auxServiceId,char* auxGravedad,char* auxMsg);
int log_getServiceId(S_LogEntry* pLogEntry);
int log_getGravedad(S_LogEntry* pLogEntry);
char* log_getDate(S_LogEntry* pLogEntry);
char* log_getTime(S_LogEntry* pLogEntry);
char* log_getMsg(S_LogEntry* pLogEntry);
void log_mostrarDatos(LinkedList* lista);
