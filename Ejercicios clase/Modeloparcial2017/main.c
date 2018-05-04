#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define TAMUSUARIO 100
#define TAMPRODUCTO 1000


int main()
{
    int opcion;

    eUsuario listaDeUsuarios[TAMUSUARIO];
    eProducto listaDeProductos[TAMPRODUCTO];

    inicializarUsario(listaDeUsuarios, TAMUSUARIO);
    inicializarUsuariosHardCode(listaDeUsuarios, TAMUSUARIO);

    inicializarProductos(listaDeProductos, TAMPRODUCTO);
    inicializarProductosHardCode(listaDeProductos, TAMPRODUCTO);

    mostrarProductosDelUsuario(listaDeProductos,TAMPRODUCTO);


    do
    {
        printf("\n1.ALTAS\n2.MODIFICACIONES\n3.BAJAS\n4.PUBLICAR PRODUCTO\n9.SALIR\n \nElija una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
            case 1:

                    altaUsuario(listaDeUsuarios, TAMUSUARIO);
                    mostrarUsuarios(listaDeUsuarios, TAMUSUARIO);
                    break;

            case 2:
                    modificarUsuario(listaDeUsuarios, TAMUSUARIO);
                    mostrarUsuarios(listaDeUsuarios, TAMUSUARIO);
                    break;

            case 3:
                    bajaUsuario(listaDeUsuarios, TAMUSUARIO);
                    mostrarUsuarios(listaDeUsuarios, TAMUSUARIO);
            case 4:
                    altaProducto(listaDeProductos, TAMPRODUCTO);


        }




    } while (opcion!=9);









    return 0;
}
