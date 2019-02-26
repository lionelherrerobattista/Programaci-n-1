typedef struct
{
    //DNI de la persona y el id del tramite
    char dni[10];
    int idTramite;

}eTramite;

/** \brief Crea una nueva estructura Tramite
 *
 * \return eTramite* devuelve la nueva estryctyra
 *
 */
eTramite* nuevoTramite();


/** \brief Agrego dato dni a la estructura
 *
 * \param this eTramite* puntero a estructura
 * \param dni char* dato que va a copiar en la estructura
 * \return int 0 si se pudo copiar, -1 si hubo error
 *
 */
int setDni(eTramite* this, char* dni);

/** \brief Obtengo el dato dni de la estructura
 *
 * \param this eTramite* estructura de donde obtengo el dato
 * \return char* devuelve el dni
 *
 */
char* getDni(eTramite* this);

/** \brief Carga el dato idTramite en la estructura
 *
 * \param this eTramite* estructura donde se va a cargar el dato
 * \param idTramite int id del tramite a cargar
 * \return int 0 si cargó el dato, -1 si hubo error
 *
 */
int setIdTramite(eTramite* this, int idTramite);

/** \brief Obtengo el id de la estructura
 *
 * \param this eTramite* estructura de donde se obtiene el id
 * \return int devuelve el id
 *
 */
int getIdTramite(eTramite* this);

/** \brief Carga un tramite en la lista de tramites
 *
 * \param listaTramite ArrayList* lista donde se va a cargar el trámite
 * \param idTramite int id del trámite a cargar
 * \param dni char* dni de la persona que realiza el trámite
 * \return int 0 si se agregó a la lista, -1 si hubo error
 *
 */
int cargarTramite(ArrayList* listaTramite, int idTramite, char* dni);

/** \brief Muestra un trámite
 *
 * \param this eTramite* estructura del trámite a mostrar
 * \return int 0 si mostró el trámite, -1 si hubo error
 *
 */
int mostrarTramite(eTramite* this);

/** \brief Muestra la lista completa
 *
 * \param this ArrayList* lista a mostrar
 * \return int 0 si mostró los tramites, -1 si hubo error
 *
 */
int mostrarListaTramites(ArrayList* this);

int atenderTramite(ArrayList* this,ArrayList* listaAtendidos);
