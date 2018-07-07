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

void mostrarEmpleado(ArrayList* this, int index);
void mostrarLista(ArrayList* this);
//getters
int eEmpleados_getId(ArrayList* this, int index);
char* eEmpleados_getNombre(ArrayList* this, int index);
float eEmpleados_getSueldo(ArrayList* this, int index);
int eEmpleados_getEdad(ArrayList* this, int index);
char* eEmpleados_getProfesion(ArrayList* this, int index);
int functionFilter(void* item);
ArrayList* filtarLista(ArrayList* this);
void crearArchivo(ArrayList* this);



