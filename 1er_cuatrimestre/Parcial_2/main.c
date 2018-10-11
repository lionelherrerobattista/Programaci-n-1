#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Empleados.h"
#include "Parser.h"

int main()
{


    ArrayList* listaEmpleados;
    listaEmpleados=al_newArrayList();

    parseArchivo("Data.csv",listaEmpleados);

    mostrarLista(listaEmpleados);

    mostrarLista(filtarLista(listaEmpleados));

    crearArchivo(filtarLista(listaEmpleados));

    return 0;
}
