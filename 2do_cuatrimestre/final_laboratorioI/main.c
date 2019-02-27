#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "validaciones.h"
#include "parser.h"
#include "ingrediente.h"
#include "receta.h"

int main()
{
    int opcion;

    LinkedList* listaIngredientes;
    LinkedList* listaRecetas;

    listaIngredientes = ll_newLinkedList();
    listaRecetas = ll_newLinkedList();

    archivo_cargarIngrediente("ingrediente.csv", listaIngredientes);
    archivo_cargarReceta("receta.csv", listaRecetas);

    do
    {
        mostrarMenu();
        opcion = pedirCadenaInt("Opcion", 0, 7);

        switch(opcion)
        {
            case 1:
                if(ingrediente_agregarIngrediente(listaIngredientes))
                {
                    printf("Ingrediente agredado.\n");
                }
                break;
            case 2:
                if(ingrediente_modificarIngrediente(listaIngredientes))
                {
                    printf("Ingrediente modificado.\n");
                }
                break;
            case 3:
                if(ingrediente_eliminarIngrediente(listaIngredientes, listaRecetas))
                {
                    printf("Ingrediente eliminado\n");
                }
                break;
            case 4:
                ll_sort(listaIngredientes, ingrediente_ordenarIngrediente,1);
                //mostrar
                ingrediente_mostrarListaIngredientes(listaIngredientes);
                break;
            case 5:
                //Nueva receta
                break;
            case 6:
                break;
            case 7:
                break;
        }


    }while(opcion != 7);

    return 0;
}
