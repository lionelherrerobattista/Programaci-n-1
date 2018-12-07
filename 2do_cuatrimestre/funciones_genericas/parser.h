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
int archivo_cargarDesdeTexto(char* nombreArchivo, LinkedList* nombreLista);

/** \brief Carga una lista con los datos de un archivo binario
 *
 * \param nombreArchivo char* Nombre del archivo a abrir
 * \param nombreLista LinkedList* Lista a cargar
 * \return int (-1) si no cargó
 *              (0) si no pudo abrir el archivo
 *              (1) si leyó el archivo y cargo la lista
 */
int archivo_cargarDesdeBinario(char* nombreArchivo, LinkedList* nombreLista);

//Escribir archivo:
/** \brief Crea un archivo de texto con los datos de la lista
 *
 * \param nombreArchivo char* Nombre del archivo a crear
 * \param nombreLista LinkedList* Lista con los datos a cargar
 * \return int (-1) si no cargó
 *              (0) si no pudo abrir el archivo
 *              (1) si creo el archivo y cargo la lista
 */
int archivo_crearArchivoTexto(char* nombreArchivo, LinkedList* nombreLista);

/** \brief Crea un archivo binario con los datos de la lista
 *
 * \param nombreArchivo char* Nombre del archivo a crear
 * \param nombreLista LinkedList* Lista con los datos a cargar
 * \return int (-1) si no cargó
 *              (0) si no pudo abrir el archivo
 *              (1) si creo el archivo y cargo la lista
 */
int archivo_crearArchivoBinario(char* nombreArchivo, LinkedList* nombreLista);


