#include "ArrayList.h"

typedef struct
{
    int id;
    char nombre[50];
    float sueldo;
    int edad;
    char profesion[50];

}eEmpleados;

eEmpleados* nuevoEmpleado();
//Setter
int eEmpleados_setId(eEmpleados* this, int id);
int siguienteId(eEmpleados* this, int limite);
int eEmpleados_setNombre(eEmpleados* this, char* nombre);
int eEmpleados_setSueldo(eEmpleados* this, float sueldo);
int eEmpleados_setEdad(eEmpleados* this, int edad);
int eEmpleados_setProfesion(eEmpleados* this, char* profesion);

void mostrarEmpleado(eEmpleados* this);
void mostrarLista(ArrayList* this);

