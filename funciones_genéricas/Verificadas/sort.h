
/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);

//Función con criterio de ordenamiento
/** \brief Ordena los datos de acuerdo a un criterio determinado
 *
 * \param tramiteUno void* primer dato
 * \param tramiteDos void* segundo dato
 * \return int valor según el criterio de ordenamiento
 *
 */
int ordenar(void* tramiteUno, void* tramiteDos);
