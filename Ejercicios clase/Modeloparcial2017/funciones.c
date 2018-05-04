#include <stdlib.h>
#include <stdio.h>
#include "funciones.h"
#include <strings.h>

#define LIBRE 1
#define OCUPADO 0

//Inicializo todos los valores en cero
void inicializarUsario (eUsuario usuarios[], int limite)
{
    int i;

    for(i=0; i<limite; i++)
    {
        usuarios[i].estado=LIBRE;
        usuarios[i].idUsuario=0;
    }
}

//Hardcodeo usuarios
void inicializarUsuariosHardCode (eUsuario usuarios[], int limite)
{
    int id[15] = {1000,1001,1002,1003,1004, 1005,1006,1007,1008,1009, 1010,1011,1012,1013,1014};
    char nombre[][50]= {"Juan","Maria","Pedro","Vanesa","Jose","Luisa","Laura","Marcelo","German","Victoria","Dafne","Antonela","Gisele","Dario","Pedro"};
    char password [][50] = {"casa", "perro", "gato", "auto", "moto"};

    int i;

    for (i=0; i<5; i++)
    {
        usuarios[i].idUsuario=id[i];
        strcpy(usuarios[i].usuario, nombre[i]);
        strcpy(usuarios[i].password, password[i]);
        usuarios[i].estado=OCUPADO;
    }

}

//asigno id+1
int siguienteId(eUsuario usuarios[], int limite)
{
    int retorno=0;
    int i;

    for(i=0; i<limite; i++)
    {
        if(usuarios[i].estado==OCUPADO)
        {
            if(usuarios[i].idUsuario>retorno)
            {
                retorno=usuarios[i].idUsuario;
            }
        }
    }
    //itera hasta el ultimo usuario y le suma 1 al retorno

    return retorno+1;

}

void mostrarUsuarios (eUsuario usuarios[], int limite)
{
    int i;

    printf("  \n");
    for (i=0; i<limite; i++)
    {

        if (usuarios[i].estado==OCUPADO)
        {
            printf("%-10d %-10s \n",usuarios[i].idUsuario, usuarios[i].usuario);
        }

    }
}

//Busco libre y devuelvo indice
int buscarLibre (eUsuario usuarios[], int limite)
{
    int i;
    int retorno=-2;

    for (i=0; i<limite; i++)
    {
        if(usuarios[i].estado==LIBRE)
        {
            retorno=i;
            break;
        }
    }

    return retorno;
}

void altaUsuario (eUsuario usuarios[], int limite)
{
    int index;


    index=buscarLibre(usuarios, limite);

    if (index>=0)
    {
        printf("\nIngrese un nombre de usuario: ");
        fflush(stdin);
        gets(usuarios[index].usuario);

        printf("\nIngrese una password: ");
        fflush(stdin);
        gets(usuarios[index].password);

        usuarios[index].idUsuario=siguienteId(usuarios, limite);

        usuarios[index].estado=OCUPADO;
    }

}

//modifica el usuario
void modificarUsuario (eUsuario usuarios[], int limite)
{
    int id=0;
    int i;

    printf("\nIngrese el id del usuario que desea modificar: ");
    scanf("%d", &id);

    for (i=0; i<limite; i++)
    {
        if (usuarios[i].idUsuario==id)
        {
            printf("\nIngrese un nombre de usuario: ");
            fflush(stdin);
            gets(usuarios[i].usuario);

            printf("\nIngrese una password: ");
            fflush(stdin);
            gets(usuarios[i].password);
        }
    }
}

//baja de usuarios
void bajaUsuario (eUsuario usuarios[], int limite)
{
    int id;
    int i;

    printf("Ingrese el id del usuario que quiere dar de baja: ");
    scanf("%d",&id);

    for (i=0; i<limite; i++)
    {
        if (usuarios[i].idUsuario==id)
        {
           usuarios[i].estado=LIBRE;
        }
    }
}

void altaProducto (eUsuario usuarios[], int limiteUsuarios, eProducto productos[], int limiteProductos)
{
    int id;
    int index;


    printf("Ingrese su id de usuario: ");
    scanf("%d", &id);


    index=buscarProductoLibre(productos, limiteProductos);

    if (index>=0)
    {
        printf("\nIngrese el nombre del producto: ");
        fflush(stdin);
        gets(productos[index].nombre);

        printf("\nIngrese un precio: ");
        scanf("%f", &productos[index].precio);

        printf("\nIngrese stock: ");
        scanf("%d", &productos[index].stock);

        productos[index].idProducto=siguienteIdProducto(productos, limiteProductos);

        productos[index].idUsuario=id;

        productos[index].estado=OCUPADO;

    }
    else
    {
        printf("No hay lugar.");
    }

}

//busco un index libre para el producto
int buscarProductoLibre(eProducto productos[], int limite)
{
    int i;
    int retorno=-2;

    for (i=0; i<limite; i++)
    {
        if(productos[i].estado==LIBRE)
        {
            retorno=i;
            break;
        }
    }

    return retorno;

}

//id+1 para el producto
int siguienteIdProducto(eProducto productos[], int limite)
{
    int retorno=0;
    int i;

    for(i=0; i<limite; i++)
    {
        if(productos[i].estado==OCUPADO)
        {
            if(productos[i].idProducto>retorno)
            {
                retorno=productos[i].idProducto;
            }
        }
    }

    return retorno;
}
