
///Estructuras con memoria dinámica:
/** \brief Crea una nueva estructura en memoria
 *
 * \return S_TramiteRegular* puntero a la estructura creada
 *
 */
S_TramiteRegular* newTramiteRegular();


/** \brief Carga una estructura con datos
 *
 * \param pTema S_Tema*
 * \param auxId char*
 * \param nombre_tema char*
 * \param artista char*
 * \return int 1 si cargó la estructura, 0 si hubo error
 *
 */
int tema_cargarTema(S_Tema* pTema, char* auxId, char* nombre_tema, char* artista)

/** \brief Inicializa un array de estructuras en un valor determinado
 *
 * \param listaPersonas[] ePersona estructura a inicializar
 * \param longitud int tamaño de la estructura
 * \param valor int valor con el que se va a inicializar
 * \return int (0) si no está inicializada, (1) si está inicializada
 *
 */
int inicializarArrayEstructura(ePersona listaPersonas[],int longitud, int valor);

/** \brief Busca la primera ocurrencia de un valor determinado
 *
 * \param listaPersonas[] ePersona lista donde se va a buscar
 * \param longitud int tamaño de la lista
 * \param valor int dato que se va a buscar
 * \return int devuelve el índice donde se encuentra el dato buscado, (-1) si no se encontró
 *
 */
int agenda_buscarPrimeraOcurrencia(ePersona listaPersonas[], int longitud, int valor);

/** \brief Imprime una lista por pantalla
 *
 * \param listaPersonas[] ePersona lista imprimir
 * \param longitud int largo de la lista
 * \return int (0) si no mostró, (1) si mostró
 *
 */
int agenda_mostrarLista(ePersona listaPersonas[], int longitud);

/** \brief Ordena una lista de modo A-Z
 *
 * \param listaPersonas[] ePersona lista a ordenar
 * \param longitud int tamaño de la lista
 * \return int (0) si no ordenó, (1) si ordenó
 *
 */
int agenda_ordenarListaApellidos(ePersona listaPersonas[], int longitud);

