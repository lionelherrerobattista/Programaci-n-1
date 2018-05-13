
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

void egresoAutomovil(eAutos[] ,int, ePropietarios[]);

float valorEstadia (int);

int devolverHorasEstadia();

void mostrarRecaudacionTotal(eAutos[], int);

void mostrarEstadiaPorMarca(eAutos[], int);

void mostrarPropietarioConAutos(ePropietarios[],int, eAutos[],int);

void motrarAutoPorMarca(eAutos[],int, ePropietarios[],int, int);

void autosOrdenadosPorPatente(eAutos[],int, ePropietarios[], int);



