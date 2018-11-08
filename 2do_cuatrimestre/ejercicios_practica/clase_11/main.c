#include <stdio.h>
#include <stdlib.h>
#include "comercio.h"
#define TAM_PRODUCTOS 5

/*
1) Desarrollar una aplicación para un comercio que le permita administrar sus productos.

Datos de cada producto:

Código (1 a 1000) (Validar)
Descripción (máximo 50 caracteres) (Validar)
Importe (Validar)
Cantidad (Validar)
1. ALTAS: No es necesario el ingreso de todos los productos.
2. MODIFICAR: Se ingresará el Código de Producto, permitiendo modificar:

Descripción
Importe
Cantidad

3. BAJA: Se ingresa el Código de Producto y se limpiarán los datos asociados
4. LISTAR: Realizar un solo listado de los datos ordenados por descripción (descendente)
*/


int main()
{
    int opcion;
    int indiceLibre;
    char baja;

    int codigo;
    float importe;
    char descripcion[50];
    int cantidad;

    eProducto listaProductos[TAM_PRODUCTOS];

    productos_inicializarArrayEstructura(listaProductos, TAM_PRODUCTOS, -1);



    while(opcion != 5)
    {

        printf("---------------------------------\n");
        printf("1-Alta\n");
        printf("2-Modificar\n");
        printf("3-Baja\n");
        printf("4-Listar\n");
        printf("5-Salir\n");
        printf("---------------------------------\n");
        opcion=getCadenaInt("Ingrese una opcion", 1, 5);
        printf("---------------------------------\n");


        switch(opcion)
        {
            case 1:
                indiceLibre=productos_buscarEstado(listaProductos, TAM_PRODUCTOS, -1);
                if(indiceLibre==-1)
                {
                    printf("No hay espacio libre.\n");
                }
                else
                {
                    codigo=getCadenaInt("Ingrese el codigo del producto", 1, 9999);
                    productos_setCodigo(listaProductos, indiceLibre, codigo);

                    getCadenaLetras("Ingrese la descripcion", descripcion);
                    productos_setDescripcion(listaProductos, indiceLibre, descripcion);

                    importe=getCadenaFloat("Ingrese el importe", 0, 99999);
                    productos_setImporte(listaProductos, indiceLibre, importe);

                    cantidad=getCadenaInt("Ingrese la cantidad", 0, 99999);
                    productos_setCantidad(listaProductos, indiceLibre, cantidad);

                    //Cambiar estado
                    listaProductos[indiceLibre].estado=1;
                }
                break;
            case 2:
                codigo=getCadenaInt("Ingrese el codigo del producto a modificar", 1, 9999);
                indiceLibre=productos_buscarCodigo(listaProductos, TAM_PRODUCTOS, codigo);

                if(indiceLibre==-1)
                {
                    printf("---------------------------------\n");
                    printf("No es un indice valido.\n");
                }
                else
                {
                    printf("---------------------------------\n");
                    codigo=getCadenaInt("Ingrese el nuevo codigo", 1, 9999);
                    productos_setCodigo(listaProductos, indiceLibre, codigo);

                    getCadenaLetras("Ingrese la descripcion", descripcion);
                    productos_setDescripcion(listaProductos, indiceLibre, descripcion);

                    importe=getCadenaFloat("Ingrese el importe", 0, 99999);
                    productos_setImporte(listaProductos, indiceLibre, importe);

                    cantidad=getCadenaInt("Ingrese la cantidad", 0, 99999);
                    productos_setCantidad(listaProductos, indiceLibre, cantidad);
                }
                break;
            case 3:
                codigo=getCadenaInt("Ingrese el codigo del producto a dar de baja", 1, 9999);
                indiceLibre=productos_buscarCodigo(listaProductos, TAM_PRODUCTOS, codigo);
                if(indiceLibre==-1)
                {
                    printf("---------------------------------\n");
                    printf("No es un indice valido.\n");
                }
                else
                {
                    printf("Esta seguro que desea darlo de baja?(s/n)\n");
                    fflush(stdin);
                    scanf("%c", &baja);
                    if(baja=='s')
                    {
                        listaProductos[indiceLibre].estado=-1;
                        printf("---------------------------------\n");
                        printf("Se dio de baja!\n");
                    }
                }
                break;
            case 4:
                productos_mostrarLista(listaProductos, TAM_PRODUCTOS);
                break;

        }


    }









    return 0;


}
