typedef struct
{
    char nombre[32];
    int edad;
}ePersona;

//Pedir ingreso de datos
int pedirCadenaLetras(char* mensaje, char* cadena);
int pedirCadenaInt(char* mensaje, int minimo, int maximo);
int cargarCadena(char* mensaje, char* cadena);

int esLetra(char auxiliar[]);
int esNumero (char auxiliar[]);

//Setters
void persona_setName(ePersona* persona, char nombre[]);
void persona_setAge(ePersona* persona, int edad);

//Getters
int persona_getAge(ePersona* persona);
char* persona_getName(ePersona* persona);

//Mostrar
void mostrarPersona(ePersona* persona);

//Constructores

ePersona* crearLista(int sizeArray);
int cargarPersona(ePersona* listaPersonas, ePersona persona, int* index, int* sizeArray);
