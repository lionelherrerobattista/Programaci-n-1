


/** \brief Carga datos ingresados por el usuario en una cadena
 *
 * \param mensaje[] char mensaje para el usuario
 * \param cadena[] char cadena donde se guardan los datos
 * \return int 1 si cargó, 0 si hubo error
 *
 */
int cargarCadena(char mensaje[], char cadena[]);

/** \brief Pide un numero al usuario, lo valida y lo guarda
 *
 * \param numeroEntero int* puntero a la variable donde se guarda el número ingresado
 * \param mensaje[] char mensaje para el usuario
 * \param minimo int número mínimo que puede ingresar el usuario inclusive
 * \param maximo int número máximo que puede ingrear el usuario inclusive
 * \return int 1 si cargó, 0 si hubo error
 *
 */
int getCadenaNumeros(int* numeroEntero, char mensaje[], int minimo, int maximo);

/** \brief Pide que el usuario ingrese una cadena de char, la valida y la guarda
 *
 * \param cadena[] char donde se guarda el dato ingresado
 * \param mensaje[] char mensaje que verá el usuario
 * \return int 1 si cargó, 0 si hubo error
 *
 */
int getCadenaLetras(char cadena[], char mensaje[]);

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


/** \brief Inicializa un array de enteros con un valor
 *
 * \param arrayEnteros[] int Array a inicializar
 * \param longitud int Longitud del array
 * \param valor int Valor con el que se va a inicializar el array
 * \return int 1 si inicializó correctamente, 0 si hubo error
 *
 */
int inicializarArrayEnteros(int arrayEnteros[],int longitud, int valor);

/** \brief Busca la primera ocurrencia de un valor determinado
 *
 * \param arrayEnteros[] int Array de enteros donde se va a buscar
 * \param longitud int Longitud del Array
 * \param valor int Valor que se va a buscar
 * \return int devuelve la posición en el array o -1 si no se encontró
 *
 */
int buscarPrimeraOcurrenciaInt(int arrayEnteros[], int longitud, int valor);
