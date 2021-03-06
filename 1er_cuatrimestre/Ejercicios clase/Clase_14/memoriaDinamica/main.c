#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nombre[50];
} ePersona;

//setters
int ePersona_setId(ePersona*, int);
int ePersona_setNombre(ePersona*, char*);
//getters
int ePersona_getId(ePersona*);
char* ePersona_getNombre(ePersona*);

//malloc
ePersona* newPersona();

int main()
{
    //ePersona miPersona;
    ePersona* pPersona;
    //pPersona= &miPersona;
    //printf("%p\n",pPersona);
    pPersona=newPersona(); //(ePersona*) malloc(sizeof(ePersona));

    ePersona* otro=newPersona();//Construyo espacio en persona
    //printf("%p\n",pPersona);

    if(pPersona!=NULL)
    {
        // pPersona->id=45; yano podemos hacer esto sino ->
        if(ePersona_setId(pPersona,3)==-1)
        {
            printf("ID INCORRECTO\n");
        }
        else
        {
            //strcpy(pPersona->nombre,"Juan");
            if(ePersona_setNombre(pPersona,"juan")==-1)
            {
                printf("NOMBRE INCORRECTO\n");
            }
            else
            {
                  printf("%d---%s",ePersona_getId(pPersona),ePersona_getNombre(pPersona));//pPersona->id,pPersona->nombre);
            }
        }
    }
    return 0;
}

int ePersona_setId(ePersona* this, int id)
{
    int retorno=-1;

    if(this!= NULL && id>0 )
    {
        retorno=1;
        this->id=id;
    }
    return retorno;
}

int ePersona_setNombre(ePersona* this, char* nombre)
{
    int retorno=-1;

    if(this!= NULL && nombre!=NULL && strlen(nombre)>3 )
    {
        retorno=1;
        strcpy(this->nombre,nombre);
    }
    return retorno;

}

int ePersona_getId(ePersona* this)
{
    int ret=-1;
    if(this!=NULL)
    {
        ret= this->id;
    }
    return ret;

}

char* ePersona_getNombre(ePersona* this)
{
    char* ret= NULL;

    if(this != NULL)
    {
        ret=this->nombre;
    }
    return ret;
}

ePersona* newPersona()
{
    ePersona* persona;
    persona=(ePersona*) malloc(sizeof(ePersona));

    return persona;
}
