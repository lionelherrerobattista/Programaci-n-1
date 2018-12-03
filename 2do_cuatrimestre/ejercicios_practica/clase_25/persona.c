#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "persona.h"
#define TAM_BUFFER 32

//Pido al usuario
int pedirCadenaLetras(char* mensaje, char* cadena)
{
    int flag=0;
    char* auxiliar;

    if(cadena!=NULL)
    {
        auxiliar=(char*)malloc(sizeof(char)*TAM_BUFFER);

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

        free(auxiliar);

    }

    return flag;

}

int pedirCadenaInt(char* mensaje, int minimo, int maximo)
{
    int flag=0;//No esta cargado
    char* auxiliar;
    int numeroAuxiliar;

    auxiliar=(char*)malloc(sizeof(char)*TAM_BUFFER);

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

    free(auxiliar);


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

int esNumero (char* auxiliar)
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

//Funcion repetida
int lista_getSize(eArrayList* arrayList)
{
    int sizeLista=-1;

    if(arrayList!=NULL)
    {
        sizeLista=arrayList->index;
    }

    return sizeLista;
}

int lista_getIndex(eArrayList* arrayList)
{
    int indexLista=-1;

    if(arrayList!=NULL)
    {
        indexLista=arrayList->index;
    }

    return indexLista;
}

int lista_getMaxPersonas(eArrayList* arrayList)
{
    int maxPersonas=-1;

    if(arrayList!=NULL)
    {
        maxPersonas=arrayList->totalPersonas;
    }

    return maxPersonas;
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
eArrayList* lista_inicializarArrayList()
{
    eArrayList* arrayList=NULL;

    //Asigno memoria para 1 lista
    arrayList= (eArrayList*) malloc(sizeof(eArrayList));

    arrayList->index=0;//Indice de personas en la lista
    arrayList->totalPersonas=2; //Tamaño total de personas en la lista
    //Creo la lista asignando memoria dinámica;
    arrayList->lista= lista_crearLista(arrayList->totalPersonas);

    return arrayList;
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
    char* auxiliarNombre;
    int auxiliarEdad;
    int flag=0;

    if(persona!=NULL)
    {
        auxiliarNombre=(char*)malloc(sizeof(char)*TAM_BUFFER);

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
    //auxLista=lista_crearLista(arrayList->totalPersonas); //Otra solución?

    int flag=0;//No hay espacio

    //Compruebo que los punteros no vengan nulos
    if(arrayList!=NULL && persona!=NULL)
    {

        if(lista_getLista(arrayList,lista_getIndex(arrayList))!=NULL)
        {
            //Cargo la persona en la posición index de la lista
            *(lista_getLista(arrayList,lista_getIndex(arrayList)))=persona; //Usar aritmética de punteros
            //Sumo 1 al indice (paso a la siguiente posición)
            arrayList->index++;

            //Compruebo que la lista no esté completa
            if(lista_getIndex(arrayList) >= lista_getMaxPersonas(arrayList))//Llegué al final, lista completa
            {
                //Asigno más memoria a la lista
                arrayList->totalPersonas+=2;
                printf("\nRedefino array... Total personas:%d\n",lista_getMaxPersonas(arrayList));
                //uso aux por si devuelve NULL
                auxLista=(ePersona**) realloc(lista_getLista(arrayList, 0), lista_getMaxPersonas(arrayList) * sizeof(ePersona*));

                if(auxLista==NULL)
                {
                    printf("No hay memoria.");
                    arrayList->index--;
                    flag=-1;
                }
                else
                {

                    arrayList->lista=auxLista;
                    flag=1;//hay espacio
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

void lista_borrarPersona(eArrayList* arrayList, int indice_a_borrar)
{
    int i;
    int tamLista;

    tamLista=lista_getIndex(arrayList);

    if(arrayList!=NULL && tamLista>0)
    {

        //A partir de ese indice muevo todo un lugar a la izquierda
        for(i=indice_a_borrar;i<(tamLista-1);i++)
        {
            *(arrayList->lista+i)=*(arrayList->lista+(i+1));
            printf("%d",i);
        }

        //Achico el indice en 1
        arrayList->index--;
    }

}



