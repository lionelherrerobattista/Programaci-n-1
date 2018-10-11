

/** \brief Pide un entero y lo devuelve
 *
 * \param mensaje[] char mensaje para el usuario
 * \param min int número mínimo que puede ingresar el usuario
 * \param max int número máximo que puede ingresar el usuario
 * \return int el número ingresado
 *
 */
int pedirInt(char mensaje[], int min, int max);

/** \brief Valida que el int se encuentre dentro de los límites
 *
 * \param numero int numero ingresado
 * \param min int número mínimo
 * \param max int número máximo
 * \param [] char mensaje mensaje de error
 * \return int número validado
 *
 */
int validarInt(int numero, int min, int max, char mensaje []);

/** \brief Comprueba que se haya ingresado un int
 *
 * \param auxiliar[] char datos a validar
 * \return int  el número validado
 *
 */
int esInt(char auxiliar[]);

/** \brief Pide un float al usuario y lo devuelve
 *
 * \param mensaje[] char mensaje al usuario
 * \param min float número mínimo que puede ingresar el usuario
 * \param max float número máximo que puede ingresar el usuario
 * \return float el número ingresado
 *
 */
float pedirFloat(char mensaje[], float min, float max);

/** \brief Valida un float, si no es válido lo vuelve a pedir
 *
 * \param numero float el número a validar
 * \param min float número mínimo que se puede ingresar
 * \param max float número máximo que se puede ingresar
 * \param [] char mensaje mensaje de error
 * \return float número validado
 *
 */
float validarFloat(float numero, float min, float max, char mensaje []);
