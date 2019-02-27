#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[60];
    char email[60];
    char sexo[60];
    char pais[60];
    char password[150];
    char ip_address[60];

}S_Usuario;

S_Usuario* newUsuario();
int cargarUsuario(S_Usuario* pUsuario, char* id, char* nombre, char* email, char* sexo,
                  char* pais, char* password, char* ipAddress);
void usuario_mostrarListaUsuarios(LinkedList* listaUsuarios);

int usuario_setId(S_Usuario* pAuxEstructura, int id);
int usuario_setNombre(S_Usuario* pAuxEstructura, char* nombre);
int usuario_setEmail(S_Usuario* pAuxEstructura, char* email);
int usuario_setSexo(S_Usuario* pAuxEstructura, char* sexo);
int usuario_setPais(S_Usuario* pAuxEstructura, char* pais);
int usuario_setPassword(S_Usuario* pAuxEstructura, char* password);
int usuario_setIpAddress(S_Usuario* pAuxEstructura, char* ipAddress);

//Getters
int usuarios_getId(void* pEstructura);
char* usuario_getNombre(void* pEstructura);
char* usuario_getEmail(void* pEstructura);
char* usuario_getSexo(void* pEstructura);
char* usuario_getPais(void* pEstructura);
char* usuario_getPassword(void* pEstructura);
char* usuario_getIpAddress(void* pEstructura);

//sorte
int usuario_ordenarPorNombre(void* usuarioUno, void* usuarioDos);
int usuario_ordenarPorNacionalidad(void* usuarioUno, void* usuarioDos);

///comprobaciones
int usuario_comprobarUsuario(LinkedList* listaUsuarios);

