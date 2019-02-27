#include "LinkedList.h"

int archivo_cargarDesdeTexto(char* nombreArchivo, LinkedList* nombreLista);
int archivo_cargarTema(char* nombreArchivo, LinkedList* nombreLista);
int archivo_crearArchivoTexto(char* nombreArchivo, LinkedList* listaUsuarios, LinkedList* listaTemas, int idUsuario, int idTema);
int archivo_cargarTemasMasEscuchados(char* nombreArchivo, LinkedList* nombreLista);
int archivo_cargarEstadistica(char* nombreArchivo, LinkedList* nombreLista);
