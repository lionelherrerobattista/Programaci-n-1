
typedef struct
{
    int idUsuario;
    char usuario[50];
    char password[50];
    int estado;

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

int buscarLibre (eUsuario[], int);
void altaUsuario (eUsuario[], int);
int siguienteId (eUsuario[], int);
void modificarUsuario (eUsuario[], int);
void bajaUsuario (eUsuario[], int);
void altaProducto (eProducto[], int);
int buscarProductoLibre(eProducto[], int);
int siguienteIdProducto(eProducto[], int);



