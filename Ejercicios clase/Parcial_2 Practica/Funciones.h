#include "ArrayList.h"

typedef struct
{
    int id;
    char nombre[50];
    char tarjeta[50];
    char direccion[50];
}ePropietarios;

int parseArchivo (char* nombreArchivo, ePropietarios* propietarioAux, ArrayList* listaPropietarios);

void mostrarPropietario(ePropietarios* this);

void pedirPropietario(ePropietarios* propietario);

//Setters
int ePropietarios_setId(ePropietarios* this, int id);
int ePropietarios_setNombre(ePropietarios* this, char* nombre);
int ePropietarios_setTarjeta(ePropietarios* this, char* tarjeta);
int ePropietarios_setDireccion(ePropietarios* this, char* direccion);
int ePropietarios_setEstado(ePropietarios* this, int estado);
ePropietarios* nuevoPropietario();
