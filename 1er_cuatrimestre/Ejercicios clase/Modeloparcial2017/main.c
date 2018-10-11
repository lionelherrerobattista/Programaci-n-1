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




    do
    {
        printf("\n1.ALTAS\n2.MODIFICACIONES\n3.BAJAS\n4.PUBLICAR PRODUCTO\n5.MODIFICAR PUBLICACION\n6.CANCELAR PUBLICACION\n7.COMPRAR PRODUCTO\n8.LISTAR PUBLICACIONES DEL USUARIO\n9.LISTAR PUBLICACIONES\n10.LISTAR USUARIOS\n11.SALIR\n \nElija una opcion: ");
        scanf("%d", &opcion);
        printf(" \n");

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
                    break;
            case 4:
                    altaProducto(listaDeProductos, TAMPRODUCTO);
                    break;
            case 5:
                    modificarProductos(listaDeProductos, TAMPRODUCTO);
                    break;
            case 6:
                    cancelarPublicacion(listaDeProductos, TAMPRODUCTO);
                    break;

            case 7:
                    comprarProducto(listaDeProductos, TAMPRODUCTO, listaDeUsuarios, TAMUSUARIO);
                    break;

            case 8:
                    mostrarProductosDelUsuario(listaDeProductos, TAMPRODUCTO);
                    break;

            case 9:
                    mostrarProductos(listaDeProductos, TAMPRODUCTO);
                    break;

            case 10:
                    listarUsuarios(listaDeUsuarios, TAMUSUARIO);
                    break;





        }




    } while (opcion!=11);









    return 0;
}
