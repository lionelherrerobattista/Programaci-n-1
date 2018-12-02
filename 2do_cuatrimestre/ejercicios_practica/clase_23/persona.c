#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "persona.h"
#define TAM_BUFFER 32

//Pido al usuario
int pedirCadenaLetras(char* mensaje, char* cadena)
{
    int flag=0;
    char auxiliar[50];

    if(cadena!=NULL)
    {


        cargarCadena(mensaje, auxiliar);

        while(esLetra(auxiliar)!=1)
        {
            printf("Error. No es valido.\n");
            cargarCadena(mensaje, auxiliar);
        }

        strcpy(cadena, auxiliar);

        if(stricmp(cadena, auxiliar)==0)
        {
            flag=1;
        }

    }

    return flag;

}

int pedirCadenaInt(char* mensaje, int minimo, int maximo)
{
    int flag=0;//No esta cargado
    char auxiliar[50]={};
    int numeroAuxiliar;

    do
    {
        cargarCadena(mensaje, auxiliar);

        while(esNumero(auxiliar)!=1)
        {
            printf("Error. No es un numero valido.\n");
            cargarCadena(mensaje, auxiliar);
        }

        numeroAuxiliar=atoi(auxiliar);//*Tomo el valor

        if(numeroAuxiliar>=minimo && numeroAuxiliar<=maximo)
        {
            flag=1;//Cumple con las condiciones. Sale de la iteracion.
        }
        else
        {
            printf("Fuera de rango.\n");
        }


    }while(flag==0);


    return numeroAuxiliar;

}

int cargarCadena(char* mensaje, char* cadena)
{
    int flag=0;//No está cargada

    if(cadena!=NULL)
    {

        printf("%s: ", mensaje);
        fflush(stdin);

        //Para no escribir de más en memoria uso fgets
        //(limita lo que se puede ingresar)
        fgets(cadena,sizeof(char)*TAM_BUFFER,stdin);

        //Agregar '\0' al final cuando cadena < al buffer
        //para que pueda validar (porque fgets escribe '\n' al final)
        if(strlen(cadena)<TAM_BUFFER-1)
        {
            *(cadena+(strlen(cadena)-1))='\0';
        }


        if(strlen(cadena)>0)
        {
            flag=1;
        }
    }

    return flag;
}

//Comprobaciones
int esLetra(char auxiliar[])
{
    int i;
    int flag=1;//1 es char

    for(i=0;i<strlen(auxiliar);i++)
    {
        if((auxiliar[i]!=' ') && (auxiliar[i]<'A' || auxiliar[i]>'Z') && (auxiliar[i]<'a' || auxiliar[i]>'z')) //Si hay espacio tambien es valido como letra
        {
            flag=0;//0 no es char
            break;
        }
    }

    return flag;
}

int esNumero (char auxiliar[])
{
    int i;
    int flag=1;//1 es entero

    for(i=0; i<strlen(auxiliar); i++)
    {
        if(auxiliar[i]<'0' || auxiliar[i]>'9')
        {
            flag=0;
            break;
        }
    }

    return flag;
}

//Setters
void persona_setName(ePersona* persona, char* nombre)
{
    if(persona!=NULL)
    {
        strcpy(persona->nombre, nombre);
    }

}

void persona_setAge(ePersona* persona, int edad)
{
    if(persona!=NULL)
    {
        persona->edad=edad;
    }
}

//Getters
ePersona** lista_getLista(eArrayList* arrayList, int index)
{
    ePersona** listaPersonas;

    if(arrayList!=NULL)
    {
        listaPersonas=arrayList->lista+index;
    }

    return listaPersonas;
}

ePersona* lista_getPersona(ePersona** listaPersonas, int index)
{
    ePersona* persona=NULL;

    if(listaPersonas!=NULL)
    {
        persona=*(listaPersonas+index);
    }

    return persona;

}

int lista_getSize(eArrayList* listaPersonas)
{
    int sizeLista=-1;

    if(listaPersonas!=NULL)
    {
        sizeLista=listaPersonas->index;
    }

    return sizeLista;
}

int persona_getAge(ePersona* persona)
{
    int retorno=-1;

    if(persona!=NULL)
    {
        retorno= persona->edad;
    }

    return retorno;

}

char* persona_getName(ePersona* persona)
{
    return persona->nombre;
}

//Mostrar
void persona_mostrarPersona(ePersona* persona)
{
    if(persona!=NULL)
    {
        printf("-----------------------------------\n");
        printf("Nombre:%s\nEdad:%d\n", persona_getName(persona), persona_getAge(persona));

    }
}

//Constructores
eArrayList* lista_inicializarArrayList(void)
{
    eArrayList* listaPersonas=NULL;

    //Asigno memoria para 1 lista
    listaPersonas= (eArrayList*) malloc(sizeof(listaPersonas));

    listaPersonas->index=0;//Indice de personas en la lista
    listaPersonas->totalPersonas=2; //Tamaño total de personas en la lista
    //Creo la lista asignando memoria dinámica;
    listaPersonas->lista= lista_crearLista(listaPersonas->totalPersonas);

    return listaPersonas;
}

ePersona** lista_crearLista(int totalPersonas)
{
    ePersona** listaPersonas=NULL;

    //Array dinámico
    listaPersonas=(ePersona**)malloc( totalPersonas * sizeof(ePersona*));

    return listaPersonas;

}

ePersona* persona_crearPersona()
{
    ePersona* persona=NULL;

    persona=(ePersona*)malloc(sizeof(ePersona));

    return persona;
}

//Cargo datos
int persona_cargarPersona(ePersona* persona)
{
    //Auxiliares para los datos
    char auxiliarNombre[32];
    int auxiliarEdad;
    int flag=0;

    if(persona!=NULL)
    {

        pedirCadenaLetras("Ingrese el nombre", auxiliarNombre);
        //Si escribe salir, termina de ingresar las personas
        if(stricmp(auxiliarNombre,"salir")==0)
        {
            flag=-1;
        }
        else
        {
            auxiliarEdad=pedirCadenaInt("Ingrese la edad",1, 100);
            //Cargo el auxiliar con los datos
            persona_setName(persona, auxiliarNombre);
            persona_setAge(persona, auxiliarEdad);
            flag=1;
        }
    }

    return flag;
}

int lista_addPersona(eArrayList* arrayList, ePersona* persona)
{
    ePersona** auxLista=NULL;//Si no apunta a ningun lado puede generar problemas al hacer realloc(?)
    //auxLista=lista_crearLista(arrayList->totalPersonas);

    int flag=0;//No hay espacio

    //Compruebo que los punteros no vengan nulos
    if(arrayList!=NULL && persona!=NULL)
    {

        if(arrayList->lista+arrayList->index!=NULL)
        {
            //Cargo la persona en la posición index de la lista
            *(arrayList->lista+arrayList->index)=persona; //Usar aritmética de punteros
            //Sumo 1 al indice (paso a la siguiente posición)
            arrayList->index++;

            //Compruebo que la lista no esté completa
            if(arrayList->index >= arrayList->totalPersonas)//Llegué al final, lista completa
            {
                //Asigno más memoria a la lista
                arrayList->totalPersonas+=5;
                printf("\nRedefino array... Total personas:%d\n",arrayList->totalPersonas);
                //uso aux por si devuelve NULL
                auxLista=(ePersona**) realloc(arrayList->lista, arrayList->totalPersonas * sizeof(ePersona*));

                if(auxLista!=NULL)
                {
                    arrayList->lista=auxLista;
                    flag=1;//hay espacio
                }
                else
                {
                    printf("No hay memoria.");
                    flag=-1;
                }

            }
        }
    }
    else
    {
        printf("Puntero nulo.");
    }

    return flag;

}


//Liberar memoria
void lista_free(eArrayList* arrayList)
{
    if(arrayList!=NULL)
    {
        free(arrayList);
    }

}



