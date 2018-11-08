
/** \brief Realiza la carga secuencial de un array
 *
 * \param lista[] int array a cargar
 * \param largo int longitud del array
 * \return int 1 si carg�, 0 si hubo error
 *
 */
int cargarListaSecuencial(int lista[], int largo);

/** \brief Muestra un array
 *
 * \param lista[] int array a mostrar
 * \param largo int longitud del array
 * \return int 1 si mostr� correctamente, 0 si no pudo mostrar
 *
 */
int mostrarLista(int lista[], int largo);

/** \brief Devuelve el n�mero m�ximo de un array
 *
 * \param lista[] int array en el que se busca el n�mero
 * \param largo int longitud del array
 * \return int el n�mero m�ximo
 *
 */
int obtenerMaximo(int lista[], int largo);

/** \brief Devuelve el n�mero m�nimo de un array
 *
 * \param lista[] int array en el que se busca el n�mero
 * \param largo int longitud del array
 * \return int el n�mero m�nimo
 *
 */
int obtenerMinimo(int lista[], int largo);

/** \brief Calcula el promedio de los numeros de un array
 *
 * \param lista[] int array de donde se saca el promedio
 * \param largo int longitud del array
 * \return float promedio
 *
 */
float calcularPromedio(int lista[], int largo);

/** \brief Modifica un array de int
 *
 * \param lista[] int array a modificar
 * \param largo int longitud del array
 * \return int 1 si modific�, 0 si hubo error
 *
 */
int modificarLista(int lista[], int largo);

/** \brief Pide un entero y lo valida
 *
 * \return int n�mero validado
 *
 */
int getInt();

/** \brief Valida que sea un n�mero
 *
 * \param cadena[] char array que contiene los datos ingresados por el usuario
 * \return int 1 si es n�mero, 0 si no es un n�mero
 *
 */
int esNumero(char cadena[]);

/** \brief Valida que el n�mero ingresado est� dentro del rango
 *
 * \param numero int numero a validar
 * \param minimo int m�nimo del rango
 * \param maximo int m�ximo del rango
 * \return int n�mero validado
 *
 */
int validarRango(int numero, int minimo, int maximo);

/*
int getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int getInt(int* pResultado);
int esNumerica(char* cadena);
*/
