
typedef struct
{
    int idUsuario;
    char usuario[50];
    char password[50];
    int acumuladorCalificacion;
    int estado;
    int cantidadVentas;


}eUsuario;

typedef struct
{
    int idProducto;
    int idUsuario;
    char nombre[50];
    float precio;
    int stock;
    int estado;

}eProducto;

/** \brief Inicializa el usuario
 *
 * \param estructura del usuario
 * \param int capacidad máxima de usuarios
 * \return void
 *
 */
void inicializarUsario (eUsuario[], int);

/** \brief Hardcode de datos de usuarios
 *
 * \param estructura usuario
 * \param int capacidad máxima de usuarios
 * \return void
 *
 */
void inicializarUsuariosHardCode (eUsuario[], int);


/** \brief Inicializa los productos
 *
 * \param estructura de productos
 * \param int capacidad máxima de productos
 * \return void
 *
 */
void inicializarProductos (eProducto [], int);

/** \brief Harcode de productos
 *
 * \param estructura de productos
 * \param int capacidad máxima de productos
 * \return void
 *
 */
void inicializarProductosHardCode (eProducto[], int);

/** \brief Muestra todos los usuarios con sus datos
 *
 * \param estructura de los usuarios
 * \param int capacidad máxima de usuarios
 * \return void
 *
 */
void mostrarUsuarios (eUsuario [], int);

/** \brief Muestra los productos de un usuario particular
 *
 * \param eProducto[] estructura de los productos
 * \param int capacidad máxima de productos
 * \return void
 *
 */
void mostrarProductosDelUsuario(eProducto[], int);

/** \brief Muestra todos los productos y sus datos
 *
 * \param eProducto[] estructura de productos
 * \param int capacidad máxima de productos
 * \return void
 *
 */
void mostrarProductos(eProducto[], int);


/** \brief Busca un espacio libre en la estructura
 *
 * \param eUsuario[] estructura de usuarios
 * \param int capacidad máxima de usuarios
 * \return int devuelve el índice libre
 *
 */
int buscarLibre (eUsuario[], int);

/** \brief Da de alta un usuario
 *
 * \param eUsuario[] estructura de usuarios
 * \param int capacidad máxima de usuarios
 * \return void
 *
 */
void altaUsuario (eUsuario[], int);

/** \brief Busca el id de usuario siguiente
 *
 * \param eUsuario[] estructura de usuarios
 * \param int capacidad máxima de usuarios
 * \return int el id siguiente libre
 *
 */
int siguienteId (eUsuario[], int);

/** \brief Modifica a un usuario
 *
 * \param eUsuario[] estructura de usuarios
 * \param int capacidad máxima de usuarios
 * \return void
 *
 */
void modificarUsuario (eUsuario[], int);

/** \brief Da de baja un usuario
 *
 * \param eUsuario[] estructura de usuarios
 * \param int capacidad máxima de usuarios
 * \return void
 *
 */
void bajaUsuario (eUsuario[], int);

/** \brief Da de alta un producto
 *
 * \param eUsuario[] estructura de productos
 * \param int capacidad máxima de productos
 * \return void
 *
 */
void altaProducto (eProducto[], int);

/** \brief Busca un espacio libre en la estructura del producto
 *
 * \param eProducto[] estructura de productos
 * \param int capacidad máxima de productos
 * \return int índice libre de la estructura productos
 *
 */
int buscarProductoLibre(eProducto[], int);

/** \brief Busca el siguiente id libre
 *
 * \param eProducto[] estructura de productos
 * \param int capacidad máxima de productos
 * \return int siguiente id libre
 *
 */
int siguienteIdProducto(eProducto[], int);

/** \brief Compra un producto
 *
 * \param eProducto[] estructura productos
 * \param int capacidad máxima de productos
 * \param eUsuario[] estructura de usuarios
 * \param int capacidad máxima usuarios
 * \return void
 *
 */
void comprarProducto (eProducto[], int, eUsuario[], int);


/** \brief Modifica la estructura productos
 *
 * \param eProducto[] estructura productos
 * \param int capacidad máxima productos
 * \return void
 *
 */
void modificarProductos(eProducto[], int);

/** \brief Cancela una publicación
 *
 * \param eProducto[] estructura productos
 * \param int capacidad máxima productos
 * \return void
 *
 */
void cancelarPublicacion (eProducto[], int);

/** \brief Muesta una lista de usuarios con su calificación promedio
 *
 * \param eUsuario[] estructura de usuarios
 * \param int capacidad máxima de usuarios
 * \return void
 *
 */
void listarUsuarios(eUsuario[], int);





