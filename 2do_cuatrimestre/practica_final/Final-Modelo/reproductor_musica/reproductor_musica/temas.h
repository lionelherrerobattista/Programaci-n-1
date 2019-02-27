#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre_tema[300];
    char artista[300];
}S_Tema;

S_Tema* newTema();
int tema_cargarTema(S_Tema* pTema, char* auxId, char* nombre_tema, char* artista);
int tema_ordenarPorArtista(void* temaUno, void* temaDos);
int tema_pedirTema(LinkedList* listaTemas);

///Mostrar
void tema_mostrarAutorConMasTemas(LinkedList* listaTemas);
void tema_mostrarListaTemas(LinkedList* listaTemas);
void tema_mostrarTemaMasEscuchado(LinkedList* listaTemasMasEscuchados);
void tema_mostrarAutorConMasRepeticiones(LinkedList* listaTemasMasEscuchados);

///Setters
int tema_setId(S_Tema* pAuxEstructura, int id);
int tema_setNombre(S_Tema* pAuxEstructura, char* nombre);
int tema_setArtista(S_Tema* pAuxEstructura, char* nombre);

///Getters
int temas_getId(void* pEstructura);
char* tema_getNombre(void* pEstructura);
char* tema_getArtista(void* pEstructura);
