#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include "string.h"


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    Employee* empleado1;
    Employee* empleado2;

    int comparacion=0;

    empleado1=pEmployeeA;
    empleado2=pEmployeeB;

    comparacion=stricmp(empleado1->name,empleado2->name);


    return comparacion;
}


void employee_print(Employee* this)
{
    printf("\nId: %d",this->id);
    printf("\nNombre: %s",this->name);
    printf("\nApellido: %s\n",this->lastName);


}


Employee* employee_new(void)
{

    Employee* returnAux = NULL;

    return returnAux;

}

void employee_delete(Employee* this)
{


}

int employee_setId(Employee* this, int id)
{

    return 0;

}

int employee_getId(Employee* this)
{

    return 0;

}


