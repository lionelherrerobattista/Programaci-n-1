#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "comercio.h"
#define TAM_PRODUCTOS 5


/**
1) Al ejercicio de la clase 11 incorporar la siguiente funcionalidad

5. LISTAR: Realizar un solo listado de los datos ordenados por los siguientes criterios:

Descripción (descendente)
Cantidad (ascendente)

6. INFORMAR:

A. Los datos del/os producto/s de menor Importe.
B. Los datos del/os producto/s que superan el valor de precio promedio

7. MINIMIZAR:
Realizar las funciones necesarias a fin de minimizar la función main()
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

    //Inicializo el array de Productos en -1(libre)
    productos_inicializarArrayEstructura(listaProductos, TAM_PRODUCTOS, -1);



    while(opcion != 7)
    {

        printf("---------------------------------\n");
        printf("1-Alta\n");
        printf("2-Modificar\n");
        printf("3-Baja\n");
        printf("4-Listar por descripcion (descendente)\n");
        printf("5-Listar por cantidad (ascendente)\n");
        printf("6-Informar\n");
        printf("7-Salir\n");
        printf("---------------------------------\n");
        opcion=pedirCadenaInt("Ingrese una opcion", 1, 7);
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
                    codigo=pedirCadenaInt("Ingrese el codigo del producto", 1, 1000);
                    productos_setCodigo(listaProductos, indiceLibre, codigo);

                    pedirCadenaLetras("Ingrese la descripcion", descripcion);
                    productos_setDescripcion(listaProductos, indiceLibre, descripcion);

                    importe=pedirCadenaFloat("Ingrese el importe", 0, 99999);
                    productos_setImporte(listaProductos, indiceLibre, importe);

                    cantidad=pedirCadenaInt("Ingrese la cantidad", 0, 99999);
                    productos_setCantidad(listaProductos, indiceLibre, cantidad);

                    //Cambiar estado ocupado (estado=1)
                    productos_setEstado(listaProductos, indiceLibre, 1);
                }
                break;
            case 2:
                codigo=pedirCadenaInt("Ingrese el codigo del producto a modificar", 1, 1000);
                indiceLibre=productos_buscarCodigo(listaProductos, TAM_PRODUCTOS, codigo);

                if(indiceLibre==-1)
                {
                    printf("---------------------------------\n");
                    printf("No es un indice valido.\n");
                }
                else
                {
                    printf("---------------------------------\n");

                    pedirCadenaLetras("Ingrese la descripcion", descripcion);
                    productos_setDescripcion(listaProductos, indiceLibre, descripcion);

                    importe=pedirCadenaFloat("Ingrese el importe", 0, 99999);
                    productos_setImporte(listaProductos, indiceLibre, importe);

                    cantidad=pedirCadenaInt("Ingrese la cantidad", 0, 99999);
                    productos_setCantidad(listaProductos, indiceLibre, cantidad);
                }
                break;
            case 3:
                codigo=pedirCadenaInt("Ingrese el codigo del producto a dar de baja", 1, 9999);
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
                        productos_setEstado(listaProductos, indiceLibre, -1);
                        printf("---------------------------------\n");
                        printf("Se dio de baja!\n");
                    }
                }
                break;
            case 4:
                productos_ordenarListaDescripcion(listaProductos, TAM_PRODUCTOS);
                productos_mostrarLista(listaProductos, TAM_PRODUCTOS);
                break;
            case 5:
                productos_ordenarListaCantidad(listaProductos, TAM_PRODUCTOS);
                productos_mostrarLista(listaProductos, TAM_PRODUCTOS);
                break;
            case 6:
                productos_mostrarMenorImporte(listaProductos, TAM_PRODUCTOS);
                productos_mostrarSuperanPromedio(listaProductos, TAM_PRODUCTOS);
                break;


        }


    }

    return 0;
}
