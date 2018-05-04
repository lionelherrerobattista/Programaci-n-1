#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define TAMUSUARIO 100
#define TAMPRODUCTO 1000


int main()
{
    eUsuario listaDeUsuarios[TAMUSUARIO];

    inicializarUsario(listaDeUsuarios, TAMUSUARIO);
    inicializarUsuariosHardCode(listaDeUsuarios, TAMUSUARIO);

    mostrarUsuarios(listaDeUsuarios, TAMUSUARIO);

    altaUsuario(listaDeUsuarios, TAMUSUARIO);

    mostrarUsuarios(listaDeUsuarios, TAMUSUARIO);


    return 0;
}
