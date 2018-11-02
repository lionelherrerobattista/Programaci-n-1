//Estructura
typedef struct
{
    int legajo;
    char nombre[50];
    char apellido[50];

}ePersona;

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


//Funcion inicializar estructura
/** \brief Inicializa un campo de un Array de estructuras en un valor determinado
 *
 * \param listaPersonas[] ePersona Array de personas
 * \param longitud int Longitud del Array
 * \param valor int Valor con el que se inicializa
 * \return int 1 si se inicializó, 0 si hubo error
 *
 */
int inicializarArrayEstructura(ePersona listaPersonas[],int longitud, int valor);


/** \brief Busca la primera ocurrencia de un valor determinado en un array de estructuras
 *
 * \param listaPersonas[] ePersona array de estructuras
 * \param longitud int Longitud del array
 * \param valor int Valor a buscar
 * \return int Devuleve el indice donde encontro el valor, -1 si no lo encontró
 *
 */
int agenda_buscarPrimeraOcurrencia(ePersona listaPersonas[], int longitud, int valor);

/** \brief Imprime un array de estructuras por pantalla
 *
 * \param listaPersonas[] ePersona Array de estructuras a imprimir
 * \param longitud int Longitud del array
 * \return int 1 si imprimió todo, 0 si hubo error
 *
 */
int agenda_mostrarLista(ePersona listaPersonas[], int longitud);
