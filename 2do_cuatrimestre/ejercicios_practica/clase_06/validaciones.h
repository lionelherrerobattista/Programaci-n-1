

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

/** \brief Valida que el dato ingresado sea alfanum�rico
 *
 * \param auxiliar[] char dato ingresado por el usuario
 * \return int 1 si es alfanum�rico, 0 si no lo es
 *
 */
int esAlfanumerico(char auxiliar[]);

/** \brief Valida si es un tel�fono v�lido. Formato: 4xxx-xxxx
 *
 * \param auxiliar[] char dato ingresado por el usuario
 * \return int 1 es v�lido, 0 no es v�lido
 *
 */
int esTelefonoFijo(char auxiliar[]);
