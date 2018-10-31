

/** \brief Valida si el dato ingresado es de tipo int
 *
 * \param auxiliar[] char dato ingresado por el usuario
 * \return int 1 si es int, 0 si no es int
 *
 */
int esNumero(char auxiliar[]);

/** \brief Valida si el dato ingresado es de tipo char
 *
 * \param auxiliar[] char dato ingresado por el usuario
 * \return int 1 si es char, 0 si no es
 *
 */
int esLetra(char auxiliar[]);

/** \brief Valida que el dato ingresado sea alfanumérico
 *
 * \param auxiliar[] char dato ingresado por el usuario
 * \return int 1 si es alfanumérico, 0 si no lo es
 *
 */
int esAlfanumerico(char auxiliar[]);

/** \brief Valida si es un teléfono válido. Formato: 4xxx-xxxx
 *
 * \param auxiliar[] char dato ingresado por el usuario
 * \return int 1 es válido, 0 no es válido
 *
 */
int esTelefonoFijo(char auxiliar[]);
