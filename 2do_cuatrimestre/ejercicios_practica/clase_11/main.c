#include <stdio.h>
#include <stdlib.h>
#include "comercio.h"
#define TAM_PRODUCTOS 5

/*
1) Desarrollar una aplicaci�n para un comercio que le permita administrar sus productos.

Datos de cada producto:

C�digo (1 a 1000) (Validar)
Descripci�n (m�ximo 50 caracteres) (Validar)
Importe (Validar)
Cantidad (Validar)
1. ALTAS: No es necesario el ingreso de todos los productos.
2. MODIFICAR: Se ingresar� el C�digo de Producto, permitiendo modificar:

Descripci�n
Importe
Cantidad

3. BAJA: Se ingresa el C�digo de Producto y se limpiar�n los datos asociados
4. LISTAR: Realizar un solo listado de los datos ordenados por descripci�n (descendente)
*/


int main()
{
    int opcion;
    int indiceLibre;

    eProducto listaProductos[TAM_PRODUCTOS];

    productos_inicializarArrayEstructura(listaProductos, TAM_PRODUCTOS, -1);



    while(opcion != 6)
    {
        printf("---------------------------------\n");
        printf("1-Alta\n");
        printf("2-Modificar\n");
        printf("3-Baja\n");
        printf("4-Listar\n");
        printf("5-Salir\n");
        printf("---------------------------------\n");
        getCadenaNumeros(&opcion,"Ingrese una opcion", 1, 5);
        printf("---------------------------------\n");


        switch(opcion)
        {
            case 1:
                indiceLibre=productos_buscarPrimeraOcurrencia(listaProductos, TAM_PRODUCTOS, -1);
                if(indiceLibre==-1)
                {
                    printf("No hay espacio libre.\n");
                }
               /* else
                {
                    getCadenaLetras(listaProductos.);
                }*/
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;

        }


    }









    return 0;


}
