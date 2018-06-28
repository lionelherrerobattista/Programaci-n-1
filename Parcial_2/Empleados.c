#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "Empleados.h"
#include "ArrayList.h"

eEmpleados* nuevoEmpleado()
{
    eEmpleados* aux;
    aux=(eEmpleados*)malloc(sizeof(eEmpleados));

    return aux;
}

void mostrarEmpleado(eEmpleados* this)
{

    printf("%-15d %-15s %-15.2f %-15d %-15s\n",this->id,this->nombre,this->sueldo,this->edad,this->profesion);
}

void mostrarLista(ArrayList* this)
{
    int i;
    int totalEmpleados;

    eEmpleados* empleadoAuxiliar;
    empleadoAuxiliar=nuevoEmpleado();

    totalEmpleados=al_len(this);

    printf("\n%-15s %-15s %-15s %-15s %-15s\n","Id:","Nombre:","Sueldo:","Edad:","Profesion:");

    for(i=0;i<totalEmpleados;i++)
    {
        empleadoAuxiliar=al_get(this,i);
        mostrarEmpleado(empleadoAuxiliar);
    }
}



//Setters
int eEmpleados_setId(eEmpleados* this, int id)
{
    int retorno=-1;

    if(this!= NULL && id>0 )
    {
        retorno=1;
        this->id=id;
    }
    return retorno;
}

int siguienteId(eEmpleados* this, int limite)
{
    int retorno=0;
    int i;

    for(i=0; i<limite; i++)
    {
            if((this+i)->id>retorno)
            {
                retorno=(this+i)->id;
            }
    }

    return retorno+1;
}

int eEmpleados_setNombre(eEmpleados* this, char* nombre)
{
    int retorno=-1;

    if(this!= NULL && nombre!=NULL && strlen(nombre)>3 )
    {
        retorno=1;
        strcpy(this->nombre,nombre);
    }
    return retorno;
}

int eEmpleados_setSueldo(eEmpleados* this, float sueldo)
{
    int retorno=-1;

    if(this!= NULL && sueldo>0 )
    {
        retorno=1;
        this->sueldo=sueldo;
    }
    return retorno;
}

int eEmpleados_setEdad(eEmpleados* this, int edad)
{
    int retorno=-1;

    if(this!= NULL)
    {
        if (edad>0 && edad<100)
        {
            retorno=1;
            this->edad=edad;
        }
    }
    return retorno;
}

int eEmpleados_setProfesion(eEmpleados* this, char* profesion)
{
    int retorno=-1;

    if(this!= NULL && profesion!=NULL && strlen(profesion)>3 )
    {
        retorno=1;
        strcpy(this->profesion,profesion);
    }
    return retorno;
}

/*int cargarEmpleado(ArrayList* listado, int id,char* dni)
{
    int cargo=-1;
    eTramite*  empleadoCarga;

    if(listado!=NULL)
    {
        empleadoCarga=nuevoEmpleado();
        if(id>0 && dni!=NULL)
        {
            setId(empleadoCarga,id);

            setDni(empleadoCarga,dni);

            listado->add(listado,empleadoCarga);
            cargo=0;
        }
    }
    return cargo;
}*/





