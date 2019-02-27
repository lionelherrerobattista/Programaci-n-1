/** \brief Muestra un menú de opciones
 *
 * \return void
 *
 */
void mostrarMenu();

/** \brief Muestra los datos de dos listas relacionadas
 *
 * \param listaTramitesUrgentes LinkedList* lista uno
 * \param listaTramitesRegulares LinkedList* lista dos
 * \return void
 *
 */
void mostrarTramites(LinkedList* listaTramitesUrgentes, LinkedList* listaTramitesRegulares);

/** \brief Muestra el primer dato que se encuentra guardado utilizando dos listas que se relacionan
 *
 * \param listaTramitesUrgentes LinkedList* lista uno
 * \param listaTramitesRegulares LinkedList* lista dos
 * \return void
 *
 */
void mostrarProximoTurno(LinkedList* listaTramitesUrgentes, LinkedList* listaTramitesRegulares);

/** \brief Busca el mayor dentro de una lista
 *
 * \param listaTemas LinkedList* lista donde se va a buscar
 * \return void
 *
 */
void tema_mostrarAutorConMasTemas(LinkedList* listaTemas)
