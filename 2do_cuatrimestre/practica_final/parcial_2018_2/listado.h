#include "LinkedList.h"

void mostrarTramites(LinkedList* listaTramitesUrgentes, LinkedList* listaTramitesRegulares);
void mostrarProximoTurno(LinkedList* listaTramitesUrgentes, LinkedList* listaTramitesRegulares);
void atenderCliente(LinkedList* listaUrgente, LinkedList* listaRegular, LinkedList* listaAtendidosUrgente, LinkedList* listaAtendidosRegular);
void mostrarTramitesAtendidos(LinkedList* listaAtendidosUrgentes, LinkedList* listaAtendidosRegulares);
int ordenarTramitesUrgentes(void* tramiteUno, void* tramiteDos);
int ordenarTramitesRegulares(void* tramiteUno, void* tramiteDos);
