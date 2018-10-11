

/** \brief Pide un entero y lo devuelve
 *
 * \param mensaje[] char mensaje para el usuario
 * \param min int n�mero m�nimo que puede ingresar el usuario
 * \param max int n�mero m�ximo que puede ingresar el usuario
 * \return int el n�mero ingresado
 *
 */
int pedirInt(char mensaje[], int min, int max);

/** \brief Valida que el int se encuentre dentro de los l�mites
 *
 * \param numero int numero ingresado
 * \param min int n�mero m�nimo
 * \param max int n�mero m�ximo
 * \param [] char mensaje mensaje de error
 * \return int n�mero validado
 *
 */
int validarInt(int numero, int min, int max, char mensaje []);

/** \brief Comprueba que se haya ingresado un int
 *
 * \param auxiliar[] char datos a validar
 * \return int  el n�mero validado
 *
 */
int esInt(char auxiliar[]);

/** \brief Pide un float al usuario y lo devuelve
 *
 * \param mensaje[] char mensaje al usuario
 * \param min float n�mero m�nimo que puede ingresar el usuario
 * \param max float n�mero m�ximo que puede ingresar el usuario
 * \return float el n�mero ingresado
 *
 */
float pedirFloat(char mensaje[], float min, float max);

/** \brief Valida un float, si no es v�lido lo vuelve a pedir
 *
 * \param numero float el n�mero a validar
 * \param min float n�mero m�nimo que se puede ingresar
 * \param max float n�mero m�ximo que se puede ingresar
 * \param [] char mensaje mensaje de error
 * \return float n�mero validado
 *
 */
float validarFloat(float numero, float min, float max, char mensaje []);
