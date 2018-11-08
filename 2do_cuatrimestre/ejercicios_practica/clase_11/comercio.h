typedef struct
{
    int codigo;
    float importe;
    char descripcion[50];
    int cantidad;
    int estado;//-1 libre, 0 ocupado

}eProducto;

/** \brief Carga datos ingresados por el usuario en una cadena
 *
 * \param mensaje[] char mensaje para el usuario
 * \param cadena[] char cadena donde se guardan los datos
 * \return int 1 si cargó, 0 si hubo error
 *
 */
int cargarCadena(char mensaje[], char cadena[]);

int pedirCadenaInt(char mensaje[], int minimo, int maximo);
float pedirCadenaFloat(char mensaje[], float minimo, float maximo);
int pedirCadenaLetras(char mensaje[], char cadena[]);

//Setters
int productos_setCodigo(eProducto listaProductos[], int indice, int codigo);
int productos_setDescripcion(eProducto listaProductos[], int indice, char descripcion[]);
int productos_setCantidad(eProducto listaProductos[], int indice, int cantidad);
int productos_setImporte(eProducto listaProductos[], int indice, float importe);
int productos_setEstado(eProducto listaProductos[],int indice, int estado);

//Getters
int persona_getCodigo(eProducto listaProductos[], int indice);
char* persona_getDescripcion(eProducto listaProductos[], int indice);
int persona_getCantidad(eProducto listaProductos[], int indice);
float persona_getImporte(eProducto listaProductos[], int indice);

/** \brief Valida si el dato ingresado es de tipo int
 *
 * \param auxiliar[] char dato ingresado por el usuario
 * \return int 1 si es int, 0 si no es int
 *
 */
int esNumero(char auxiliar[]);

int esNumeroFloat (char auxiliar[]);

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
 * \param listaProductos[] eProducto Array de personas
 * \param longitud int Longitud del Array
 * \param valor int Valor con el que se inicializa
 * \return int 1 si se inicializó, 0 si hubo error
 *
 */
int productos_inicializarArrayEstructura(eProducto listaProductos[],int longitud, int valor);

int productos_buscarEstado(eProducto listaProductos[], int longitud, int valor);
int productos_buscarCodigo(eProducto listaProductos[], int longitud, int codigo);


void productos_mostrarLista(eProducto listaProductos[], int longitud);

int productos_ordenarListaDescripcion(eProducto listaProductos[], int longitud);
