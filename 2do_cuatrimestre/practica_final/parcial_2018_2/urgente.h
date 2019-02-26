#include "LinkedList.h"

typedef struct
{
    int id;
    long dni;

}S_TramiteUrgente;

S_TramiteUrgente* newTramiteUrgente();
int cargarTramiteUrgente(LinkedList* listaTramitesUrgentes);
int urgente_setDni(S_TramiteUrgente* pTramiteUrgente, long dni);
int urgente_setId(S_TramiteUrgente* pTramiteUrgente, LinkedList* listaTramitesUrgentes);
