
/** \brief Realiza la carga secuencial de un array
 *
 * \param lista[] int array a cargar
 * \param largo int longitud del array
 * \return int 1 si cargó, 0 si hubo error
 *
 */
int cargarListaSecuencial(int lista[], int largo);

/** \brief Muestra un array
 *
 * \param lista[] int array a mostrar
 * \param largo int longitud del array
 * \return int 1 si mostró correctamente, 0 si no pudo mostrar
 *
 */
int mostrarLista(int lista[], int largo);

/** \brief Devuelve el número máximo de un array
 *
 * \param lista[] int array en el que se busca el número
 * \param largo int longitud del array
 * \return int el número máximo
 *
 */
int obtenerMaximo(int lista[], int largo);

/** \brief Devuelve el número mínimo de un array
 *
 * \param lista[] int array en el que se busca el número
 * \param largo int longitud del array
 * \return int el número mínimo
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
 * \return int 1 si modificó, 0 si hubo error
 *
 */
int modificarLista(int lista[], int largo);

/** \brief Pide un entero y lo valida
 *
 * \return int número validado
 *
 */
int getInt();

/** \brief Valida que sea un número
 *
 * \param cadena[] char array que contiene los datos ingresados por el usuario
 * \return int 1 si es número, 0 si no es un número
 *
 */
int esNumero(char cadena[]);

/** \brief Valida que el número ingresado esté dentro del rango
 *
 * \param numero int numero a validar
 * \param minimo int mínimo del rango
 * \param maximo int máximo del rango
 * \return int número validado
 *
 */
int validarRango(int numero, int minimo, int maximo);

/*
int getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int getInt(int* pResultado);
int esNumerica(char* cadena);
*/
