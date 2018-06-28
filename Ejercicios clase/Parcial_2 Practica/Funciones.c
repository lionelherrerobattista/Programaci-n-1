#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "Funciones.h"
#include "ArrayList.h"

int parseArchivo (char* nombreArchivo, ePropietarios* pPropietarios, ArrayList* listaPropietarios)
{
    FILE *pFile;

    int r;
    int i=0;
    char var1[50];
    char var2[50];
    char var3[50];
    char var4[50];
    //Devuelvo -1 si hay error
    int retorno=-1;

    //Abro el archivo en modo lectura
    pFile= fopen("Usuarios.txt","r");
    //Compruebo que no haya error
    if(pFile != NULL)
    {
        //Leo el archivo
        do
        {

            r= fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
            if(r==4)
            {
                //Cargo todos los datos en la lista
                ePropietarios_setId(pPropietarios+i,atoi(var1));
                ePropietarios_setNombre(pPropietarios+i,var2);
                ePropietarios_setTarjeta(pPropietarios+i,var3);
                ePropietarios_setDireccion(pPropietarios+i,var4);
                al_add(listaPropietarios,pPropietarios+i);
                i++;
                /*propietarioAux=nuevoPropietario();
                ePropietarios_setId(propietarioAux,atoi(var1));
                ePropietarios_setNombre(propietarioAux,var2);
                ePropietarios_setTarjeta(propietarioAux,var3);
                ePropietarios_setDireccion(propietarioAux,var4);
                al_add(listaPropietarios,propietarioAux);*/
            }
        }while(!feof(pFile));

        //Cierro el archivo
        fclose(pFile);
        //No hay error, retorno= 1
        retorno=1;
    }

    return retorno;

}

void mostrarPropietario(ePropietarios* this)
{

    printf("%-10d %-10s %-10s %-10s\n",this->id,this->nombre,this->tarjeta,this->direccion);
}

//setters
int ePropietarios_setId(ePropietarios* this, int id)
{
    int retorno=-1;

    if(this!= NULL && id>0 )
    {
        retorno=1;
        this->id=id;
    }
    return retorno;
}

int ePropietarios_setNombre(ePropietarios* this, char* nombre)
{
    int retorno=-1;

    if(this!= NULL && nombre!=NULL && strlen(nombre)>3 )
    {
        retorno=1;
        strcpy(this->nombre,nombre);
    }
    return retorno;

}

int ePropietarios_setTarjeta(ePropietarios* this, char* tarjeta)
{
    int retorno=-1;

    if(this!= NULL && tarjeta!=NULL && strlen(tarjeta)>3 )
    {
        retorno=1;
        strcpy(this->tarjeta,tarjeta);
    }
    return retorno;

}

int ePropietarios_setDireccion(ePropietarios* this, char* direccion)
{
    int retorno=-1;

    if(this!= NULL && direccion!=NULL && strlen(direccion)>3 )
    {
        retorno=1;
        strcpy(this->direccion,direccion);
    }
    return retorno;

}

/*int ePropietarios_setEstado(ePropietarios* this, int estado)
{
    int retorno=-1;

    if(this!= NULL && (estado==0 || estado==1))
    {
        retorno=1;
        this->estado=estado;
    }
    return retorno;
}*/

ePropietarios* nuevoPropietario()
{
    ePropietarios* propietario;
    propietario=(ePropietarios*) malloc(sizeof(ePropietarios));

    return propietario;
}

void pedirPropietario(ePropietarios* propietario)
{
    char nombre[50];
    char tarjeta[50];
    char direccion[50];

    printf("Ingrese el nombre:\n");
    gets(nombre);
    ePropietarios_setNombre(propietario,nombre);
    printf("Ingrese la tarjeta:\n");
    gets(tarjeta);
    ePropietarios_setTarjeta(propietario,tarjeta);
    printf("Ingrese la direccion:\n");
    gets(direccion);
    ePropietarios_setDireccion(propietario,direccion);
    ePropietarios_setId(propietario, 8);

}
