typedef struct
{
    int id;
    long dni;

}S_TramiteRegular;

S_TramiteRegular* newTramiteRegular();
int cargarTramiteRegular(LinkedList* listaTramitesRegulares);
int regular_setDni(S_TramiteRegular* pTramiteRegular, long dni);
int regular_setId(S_TramiteRegular* pTramiteRegular, LinkedList* listaTramitesRegulares);
