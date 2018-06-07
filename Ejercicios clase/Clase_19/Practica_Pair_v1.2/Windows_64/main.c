#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include <string.h>

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
    int empleadosCargados;
    int i;


    ArrayList* lista;//gestiona direcciones de memoria
    lista=al_newArrayList(); //Creo lista de cosas. Le pedimos memoria al sistema operativo, para el dato que hay que guardar

    Employee* e1;//crear puntero a estructura de empleados para guardar
    e1=malloc(sizeof(Employee));

    //creo auxiliar para mostrar datos
    Employee* empleadoAuxiliar;//para guardar el dato ingresado
    //no es necesario un malloc. El dato ya esta guardado en memoria

    //creo un nuevo empleado
    Employee* e2;
    e2=malloc(sizeof(Employee));//tengo que cargar los datos

     //cargar valores para el empleado1
    e1->id=666;
    strcpy(e1->name,"Juan");
    strcpy(e1->lastName,"Perez");
    e1->isEmpty=1;

    al_add(lista, e1);//agrega a la lista

    //cargar valores para el empleado2
    e2->id=665;
    strcpy(e2->name,"Pedro");
    strcpy(e2->lastName,"Gonzalez");
    e2->isEmpty=1;

    al_add(lista, e2);

    empleadosCargados=al_len(lista);//devuelve el tamaño de la lista
    printf("Size lista: %d\n",empleadosCargados);//imprimo el tamaño en pantalla

    printf("\n----Antes del ordenamiento-----");

    for(i=0;i<empleadosCargados;i++)
    {
        //tomar un elemento
        empleadoAuxiliar=(Employee*)al_get(lista,i);//apunta a la misma direccion de e1. Hacer casteo a empleado
        employee_print(empleadoAuxiliar);//muestro el empleado

    }

    al_sort(lista,(employee_compare),0);//le paso la funcion sin los parametros, estoy pasandole la dirección de memoria

    printf("\n----Despues del ordenamiento----");

    for(i=0;i<empleadosCargados;i++)
    {
        //tomar un elemento
        empleadoAuxiliar=(Employee*)al_get(lista,i);//apunta a la misma direccion de e1. Hacer casteo a empleado
        employee_print(empleadoAuxiliar);//muestro el empleado

    }



    /*//constructor destructor, parser employee. Lee empleados y los carga dentro del vector. parser en apunte

    return 0;
}
