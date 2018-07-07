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

void mostrarEmpleado(ArrayList* this, int index)
{

    printf("%-15d %-15s %-15.2f %-15d %-15s\n",eEmpleados_getId(this, index),eEmpleados_getNombre(this,index),eEmpleados_getSueldo(this,index),eEmpleados_getEdad(this,index),eEmpleados_getProfesion(this,index));
}

void mostrarLista(ArrayList* this)
{
    int i;
    int totalEmpleados;

    totalEmpleados=al_len(this);

    printf("\n%-15s %-15s %-15s %-15s %-15s\n","Id:","Nombre:","Sueldo:","Edad:","Profesion:");

    for(i=0;i<totalEmpleados;i++)
    {
        mostrarEmpleado(this,i);
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

//Getters

int eEmpleados_getId(ArrayList* this, int index)
{
    int retorno;
    eEmpleados* auxiliar;
    auxiliar=nuevoEmpleado();

    retorno=-1;

    if(this!=NULL && auxiliar!=NULL)
    {
        auxiliar=al_get(this, index);
        retorno=auxiliar->id;
    }

    return retorno;
}


char* eEmpleados_getNombre(ArrayList* this, int index)
{
    char* retorno= NULL;
    eEmpleados* auxiliar;
    auxiliar=nuevoEmpleado();

    if(this != NULL)
    {
        auxiliar=al_get(this, index);
        retorno=auxiliar->nombre;
    }
    return retorno;
}

float eEmpleados_getSueldo(ArrayList* this, int index)
{
    float retorno;
    eEmpleados* auxiliar;
    auxiliar=nuevoEmpleado();

    retorno=-1;

    if(this!=NULL && auxiliar!=NULL)
    {
        auxiliar=al_get(this, index);
        retorno=auxiliar->sueldo;
    }

    return retorno;
}

int eEmpleados_getEdad(ArrayList* this, int index)
{
    int retorno;
    eEmpleados* auxiliar;
    auxiliar=nuevoEmpleado();

    retorno=-1;

    if(this!=NULL && auxiliar!=NULL)
    {
        auxiliar=al_get(this, index);
        retorno=auxiliar->edad;
    }

    return retorno;
}

char* eEmpleados_getProfesion(ArrayList* this, int index)
{
    char* retorno= NULL;
    eEmpleados* auxiliar;
    auxiliar=nuevoEmpleado();

    if(this != NULL)
    {
        auxiliar=al_get(this, index);
        retorno=auxiliar->profesion;
    }
    return retorno;
}

//Función que filtra
int functionFilter(void* item)
{
    int retorno=0;
    //Tengo que pasar el puntero a void a un auxiliar
    //sino no puedo usar operador flecha
    eEmpleados* auxiliar;

    if(item!=NULL)
    {
        auxiliar=item;

        if(strcmpi(auxiliar->profesion,"programador")==0 && auxiliar->edad>30)
        {
            retorno=1;
        }
    }

    return retorno;
}

ArrayList* filtarLista(ArrayList* this)
{
    ArrayList* listaFiltrada;

    //Utilizo la función al_filter
    listaFiltrada=al_filter(this,*functionFilter);

    return listaFiltrada;
}

//Crear archivo
void crearArchivo(ArrayList* this)
{
    FILE* miArchivo;

    char buffer[500]={};
    char bufferAux[500]={};

    int i;

    if(this!=NULL)
    {
        miArchivo = fopen("out.csv","w");

        if(miArchivo!=NULL)
        {
            for(i=0;i<al_len(this);i++)
            {
                //funcion que escribe el int en una string
                sprintf(bufferAux,"%d",eEmpleados_getId(this,i));
                //strcpy para vaciar el buffer en la nueva iteración
                strcpy(buffer,bufferAux);
                strcat(buffer,", ");
                strcat(buffer,eEmpleados_getNombre(this,i));
                strcat(buffer,", ");
                sprintf(bufferAux,"%f",eEmpleados_getSueldo(this,i));
                strcat(buffer,bufferAux);
                strcat(buffer,", ");
                sprintf(bufferAux,"%d",eEmpleados_getEdad(this,i));
                strcat(buffer,bufferAux);
                strcat(buffer,", ");
                strcat(buffer,eEmpleados_getProfesion(this,i));


                fprintf(miArchivo,"\n%s",buffer);

            }



            fclose(miArchivo);

        }

    }

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





