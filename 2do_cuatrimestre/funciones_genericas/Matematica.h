/** \brief Pide un float al usuario y lo devuelve
 *
 * \param mensaje[] char mensaje al usuario
 * \param min float número mínimo que puede ingresar el usuario
 * \param max float número máximo que puede ingresar el usuario
 * \return float el número ingresado
 *
 */
float pedirFloat(char mensaje[], float min, float max);

/** \brief Valida un float
 *
 * \param numero float el número a validar
 * \param min float número mínimo que se puede ingresar
 * \param max float número máximo que se puede ingresar
 * \param [] char mensaje mensaje de error
 * \return float número validado
 *
 */
float validarFloat(float numero, float min, float max, char mensaje []);

/** \brief Calcula el área del círculo y la devuelve
 *
 * \param radio float radio del círculo
 * \return float área del círculo
 *
 */
float calcularAreaCirculo(float radio);
