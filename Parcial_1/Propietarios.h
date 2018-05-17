
typedef struct
{
    int idPropietario;
    char nombreApellido[50];
    char direccion[50];
    char numeroTarjeta[50];
    int estado;


}ePropietarios;

typedef struct
{
    int idAuto;
    char patente[50];
    int marca;
    int idPropietario;
    float estadia;
    int estado;

}eAutos;

/** \brief Inicializa el propietario
 *
 * \param estructura del propietario
 * \param int capacidad máxima de propietarios
 * \return void
 *
 */
void inicializarPropietario (ePropietarios[], int);

/** \brief Hardcode de datos de propietarios
 *
 * \param estructura propietario
 * \param int capacidad máxima de propietarios
 * \return void
 *
 */
void inicializarPropietariosHardCode (ePropietarios[], int);

/** \brief Muestra todos los propietarios con sus datos
 *
 * \param estructura de los propietarios
 * \param int capacidad máxima de propietarios
 * \return void
 *
 */
void mostrarPropietarios (ePropietarios[], int);

/** \brief Busca un espacio libre en la estructura
 *
 * \param ePropietarios[] estructura de propietarios
 * \param int capacidad máxima de propietarios
 * \return int devuelve el índice libre
 *
 */
int buscarLibre (ePropietarios[], int);

/** \brief Da de alta un propietario
 *
 * \param ePropietarios[] estructura de propietarios
 * \param int capacidad máxima de propietarios
 * \return void
 *
 */
void altaPropietario (ePropietarios[], int);

/** \brief Busca el id de propietario siguiente
 *
 * \param ePropietarios[] estructura de propietarios
 * \param int capacidad máxima de propietarios
 * \return int el id siguiente libre
 *
 */
int siguienteId (ePropietarios[], int);

/** \brief Modifica la tarjeta de un propietario
 *
 * \param ePropietarios[] estructura de propietarios
 * \param int capacidad máxima de propietarios
 * \return void
 *
 */
void modificarPropietario (ePropietarios[], int);

/** \brief Da de baja un propietario
 *
 * \param ePropietario[] estructura de propietarios
 * \param int capacidad máxima de propietarios
 * \return void
 *
 */
void bajaPropietario (ePropietarios[], int);

/** \brief Inicializa el auto
 *
 * \param estructura del auto
 * \param int capacidad máxima de auto
 * \return void
 *
 */
void inicializarAutos (eAutos[], int);

/** \brief Hardcode de datos de autos
 *
 * \param estructura autos
 * \param int capacidad máxima de autos
 * \return void
 *
 */
void inicializarAutosHardCode (eAutos[], int);

/** \brief Da de alta un auto
 *
 * \param eAutos[] estructura de autos
 * \param int capacidad máxima de autos
 * \return void
 *
 */
void altaAuto (eAutos[], int);

/** \brief Busca un espacio libre en la estructura
 *
 * \param eAutos[] estructura de autos
 * \param int capacidad máxima de autos
 * \return int devuelve el índice libre
 *
 */
int buscarLibreAuto (eAutos[], int);

/** \brief Busca el id de auto siguiente
 *
 * \param eAutos[] estructura de auto
 * \param int capacidad máxima de auto
 * \return int el id siguiente libre
 *
 */
int siguienteIdAuto (eAutos[], int);

/** \brief Muestra todos los autos con sus datos
 *
 * \param estructura de los autos
 * \param int capacidad máxima de autos
 * \return void
 *
 */
void mostrarAutos(ePropietarios[], int, eAutos[], int);

/** \brief Registra el egreso del automovil y muestra el valor de la estadía
 *
 * \param eAutos[] lista de autos
 * \param int limite de autos
 * \param ePropietarios[] lista de propietarios
 * \return void
 *
 */
void egresoAutomovil(eAutos[] ,int, ePropietarios[]);

/** \brief Calcula el valor de la estadía
 *
 * \param int numero que indica la marca del automóvil
 * \return float valor de la estadía
 *
 */
float valorEstadia(int);

int devolverHorasEstadia();

/** \brief Muestra la recaudación total del estacionamiento
 *
 * \param eAutos[] lista de autos
 * \param int limite de autos
 * \return void
 *
 */
void mostrarRecaudacionTotal(eAutos[], int);

/** \brief Muestra el valor de la estadía de acuerdo a la marca del auto
 *
 * \param eAutos[] lista de autos
 * \param int límite de autos
 * \return void
 *
 */
void mostrarEstadiaPorMarca(eAutos[], int);

/** \brief Muestra la lista de propietarios con su auto
 *
 * \param ePropietarios[] lista de propietarios
 * \param int límite de propietarios
 * \param eAutos[] lista de autos
 * \param int límite de autos
 * \return void
 *
 */
void mostrarPropietarioConAutos(ePropietarios[],int, eAutos[],int);

/** \brief Muestra los autos de acuerdo con la marca que se elija
 *
 * \param eAutos[] lista de autos
 * \param int limite de autos
 * \param ePropietarios[] lista de propietarios
 * \param int límite de propietarios
 * \param int número que hace referencia a la marca del auto
 * \return void
 *
 */
void mostrarAutoPorMarca(eAutos[],int, ePropietarios[],int, int);

/** \brief Ordena a los autos por patente y los muestra
 *
 * \param eAutos[] lista de autos
 * \param int límite de autos
 * \param ePropietarios[] lista de propietarios
 * \param int límite de propietarios
 * \return void
 *
 */
void autosOrdenadosPorPatente(eAutos[],int, ePropietarios[], int);

/** \brief Valida que el tipo de dato ingresado sea un char
 *
 * \param auxiliar[] char auxiliar para comprobar el char
 * \return int >0 si es char sino 0
 *
 */
int esChar(char auxiliar[]);

/** \brief Valida que el tipo de dato ingresado sea un int
 *
 * \param auxiliar[] char auxiliar para comprobar el dato de tipo int
 * \return int >0 si es int, =0 si no es int
 *
 */
int esInt(char auxiliar[]);



