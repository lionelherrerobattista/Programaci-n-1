
typedef struct
{
    int idUsuario;
    char usuario[50];
    char password[50];
    int estado;

}eUsuario;

void inicializarUsario (eUsuario[], int);
void inicializarUsuariosHardCode (eUsuario[], int);
void mostrarUsuarios (eUsuario [], int);
int buscarLibre (eUsuario[], int);
void altaUsuario (eUsuario[], int);
int siguienteId (eUsuario[], int);
