#include "ArrayList.h"

struct
{
    char dni[10];
    int idTramite;

}typedef eTramite;

//void auxMostrarUnaLista(ArrayList* Clientes);
//void mostrarLista (Clientes* this);

eTramite* new_Tramite();

int setId(eTramite* , int);
int getId (eTramite*);

int setDni(eTramite* , int);
char* getDni (eTramite*);

int mostrarTramite(eTramite*);

int compararPorDni(void* tramiteA,void* tramiteB);

int mostrarListaTramites(ArrayList*);

int cargarTramite(ArrayList*, int ,char*);

int atenderTramite (ArrayList*,ArrayList*);
