
/** \brief Comprueba que el numero ingresado sea int
 *
 * \param auxiliar char* cadena con el numero ingresado
 * \return int (1) si es int, (0) si no es int
 *
 */
int esInt(char* auxiliar);

/** \brief Comprueba que el numero ingresado sea float
 *
 * \param auxiliar char* cadena con el numero ingresado
 * \return int (1) si es float, (0) si no es float
 *
 */
int esFloat(char* auxiliar);

/** \brief Comprueba que el dato ingresado sea char
 *
 * \param auxiliar char* cadena con el dato ingresado
 * \return int (1) si es char, (0) si no es char
 *
 */
int esLetra(char* auxiliar);



//Solicitud de datos al usuario
/** \brief Pide al usuario que ingrese una cadena de letras y la valida
 *
 * \param mensaje char* Mensaje que se le va a mostrar al usuario
 * \param cadena char* Donde se va a guardar el dato
 * \return int (0) si no carg� la cadena, (1) si carg�
 *
 */
int pedirCadenaLetras(char* mensaje, char* cadena);

/** \brief Pide al usuario que ingrese un n�mero int
 *
 * \param mensaje char* Mensaje que se le va a mostrar al usuario
 * \param minimo int n�mero m�nimo que puede ingresar el usuario
 * \param maximo int n�mero m�ximo que puede ingresar el usuario
 * \return int el numero ingresado
 *
 */
int pedirCadenaInt(char* mensaje, int minimo, int maximo);

/** \brief Pide al usuario que ingrese un n�mero float
 *
 * \param mensaje char* Mensaje que se le va a mostrar al usuario
 * \param minimo int n�mero m�nimo que puede ingresar el usuario
 * \param maximo int n�mero m�ximo que puede ingresar el usuario
 * \return int el numero ingresado
 *
 */
float pedirCadenaFloat(char* mensaje, int minimo, int maximo);


//Cargar cadena char
/** \brief Pide el ingreso de una cadena al usuario
 *
 * \param mensaje char* Mensaje que se le muestra al usuario
 * \param cadena char* Donde se van a guardar los datos ingresados
 * \return int (1) Si carg� los datos, (0) si no los carg�
 *
 */
int cargarCadena(char* mensaje, char* cadena);


void mostrarMenu();
