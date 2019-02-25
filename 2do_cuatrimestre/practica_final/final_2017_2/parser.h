#include "LinkedList.h"
//Leer desde archivo:

/** \brief Carga una lista con los datos de un archivo de texto
 *
 * \param nombreArchivo char* Nombre del archivo a abrir
 * \param nombreLista LinkedList* Lista a cargar
 * \return int (-1) si no cargó
 *              (0) si no pudo abrir el archivo
 *              (1) si leyó el archivo y cargo la lista
 */
int archivo_cargarLogs(char* nombreArchivo, LinkedList* nombreLista);

int archivo_cargarServices(char* nombreArchivo, LinkedList* nombreLista);


//Escribir archivo:
int archivo_crearArchivoTexto(char* nombreArchivo, LinkedList* listaLogs, LinkedList* listaServices);




