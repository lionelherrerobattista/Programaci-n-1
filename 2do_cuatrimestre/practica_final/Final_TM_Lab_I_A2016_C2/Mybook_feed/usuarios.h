/*
 ID_USUARIO: El identificador del usuario.
 • NICK : Apodo del usuario en la red social
 • POPULARIDAD :Refiere a la popularidad del usuario (cantidad de Followers).


*/
#define TAM_NICK 10

typedef struct
{
    int id_usuario;
    char nick[TAM_NICK];
    int popularidad;

}eUsuario;


eUsuario* newUsuario();
