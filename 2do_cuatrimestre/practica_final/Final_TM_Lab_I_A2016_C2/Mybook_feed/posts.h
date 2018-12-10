

/*
 ID_MENSAJE: El identificador del mensaje.
 • MENSAJE: El contenido de la publicación.
 • POPULARIDAD :Refiere a la popularidad de la publicación (cantidad de Likes).
 • ID_USUARIO: El identificador del usuario que creó la publicación

*/
#define TAM_MENSAJE 5000

typedef struct
{
    int id_mensaje;
    char mensaje[TAM_MENSAJE];
    int popularidad;
    int id_usuario;
}ePost;

ePost* newPost();
