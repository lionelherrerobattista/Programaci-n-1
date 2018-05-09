
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

void inicializarUsario (eUsuario[], int);
void inicializarUsuariosHardCode (eUsuario[], int);
void inicializarProductos (eProducto [], int);

void inicializarProductosHardCode (eProducto[], int);
void mostrarUsuarios (eUsuario [], int);
void mostrarProductosDelUsuario(eProducto[], int);
void mostrarProductos(eProducto[], int);


int buscarLibre (eUsuario[], int);
void altaUsuario (eUsuario[], int);
int siguienteId (eUsuario[], int);
void modificarUsuario (eUsuario[], int);
void bajaUsuario (eUsuario[], int);
void altaProducto (eProducto[], int);
int buscarProductoLibre(eProducto[], int);
int siguienteIdProducto(eProducto[], int);

void comprarProducto (eProducto[], int, eUsuario[], int);


void modificarProductos(eProducto[], int);
void cancelarPublicacion (eProducto[], int);

void listarUsuarios(eUsuario[], int);





