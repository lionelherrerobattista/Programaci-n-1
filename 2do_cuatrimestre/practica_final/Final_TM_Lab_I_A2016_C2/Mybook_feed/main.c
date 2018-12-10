#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "parser.h"
#include "usuarios.h"
#include "posts.h"
#include "LinkedList.h"

void mostrarInfoUsuario(eUsuario* auxUsuario);
void mostrarInfoPost(ePost* pPost);

int main()
{
    int i;

    LinkedList* pListaUsuarios;
    LinkedList* pListaPosts;

    pListaUsuarios=ll_newLinkedList();
    pListaPosts=ll_newLinkedList();

    archivo_cargarUsuarios("usuarios.csv", pListaUsuarios);
    archivo_cargarPosts("mensajes.csv", pListaPosts);

    for(i=0;i<ll_len(pListaUsuarios);i++)
    {
        mostrarInfoUsuario(ll_get(pListaUsuarios, i));
    }

    for(i=0;i<ll_len(pListaPosts);i++)
    {
        mostrarInfoPost(ll_get(pListaPosts, i));
    }

    archivo_crearArchivoTexto("feed.csv", pListaUsuarios, pListaPosts);


    return 0;
}


void mostrarInfoUsuario(eUsuario* auxUsuario)
{
    printf("%d;%s;%d\n", auxUsuario->id_usuario, auxUsuario->nick,
            auxUsuario->popularidad);
}

void mostrarInfoPost(ePost* pPost)
{
    printf("%d;%d;%d;%s\n", pPost->id_mensaje, pPost->id_usuario,
            pPost->popularidad, pPost->mensaje);
}
