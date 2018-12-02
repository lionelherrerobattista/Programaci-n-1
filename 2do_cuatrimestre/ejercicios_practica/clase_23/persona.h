
//Estructura que guarda los datos de la persona
typedef struct
{
    char nombre[32];
    int edad;

}ePersona;

//Creo una estructura para la lista
//sino se pueden perder la ref. de los punteros
//al hacer malloc()
typedef struct
{
    int totalPersonas;
    ePersona** lista;
    int index;

}eArrayList;


//Pedir ingreso de datos
int pedirCadenaLetras(char* mensaje, char* cadena);
int pedirCadenaInt(char* mensaje, int minimo, int maximo);
int cargarCadena(char* mensaje, char* cadena);

int esLetra(char auxiliar[]);
int esNumero (char auxiliar[]);

//Setters
void persona_setName(ePersona* persona, char* nombre);
void persona_setAge(ePersona* persona, int edad);

//Getters
//Getters
int persona_getAge(ePersona* persona);

char* persona_getName(ePersona* persona);



//Mostrar
void persona_mostrarPersona(ePersona* persona);

//Constructores
eArrayList* lista_inicializarArrayList(void);
ePersona** lista_crearLista(int totalPersonas);
ePersona* persona_crearPersona();
int lista_addPersona(eArrayList* listaPersonas, ePersona* persona);
