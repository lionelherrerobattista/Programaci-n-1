

/** \brief Guarda un dato de tipo int en la estructura que se pasa a la función
 *
 * \param pAuxEstructura void* Estructura donde se quiere guardar el dato
 * \param number int número que se quiere guardar
 * \return int devuelve 1 si guardó el dato, 0 si no lo pudo hacer
 *
 */
int setNumber(void* pAuxEstructura, int number);

/** \brief Guarda un dato de tipo int en la estructura que se pasa a la función
 *
 * \param pAuxEstructura void* Estructura donde se quiere guardar el dato
 * \param cadena char* string que se quiere guardar
 * \return int devuelve 1 si guardó el dato, 0 si no lo pudo hacer
 *
 */
int setChar(void* pAuxEstructura, char* cadena);
