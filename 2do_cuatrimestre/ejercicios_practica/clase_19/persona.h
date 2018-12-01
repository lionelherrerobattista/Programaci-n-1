
typedef struct
{
    char name[32];
    char surname[32];
    int age;

}ePersona;


int pedirCadenaLetras(char* mensaje, char* cadena);
int pedirCadenaInt(char* mensaje, int minimo, int maximo);
int cargarCadena(char* mensaje, char* cadena);

int esLetra(char auxiliar[]);
int esNumero (char auxiliar[]);

//Constructores
ePersona** persona_crearLista(int cantidadPersonas);
ePersona* persona_crearPersona();

//Setters
void persona_cargarPersona(ePersona* persona);
void persona_setName(ePersona* persona, char name[]);
void persona_setSurname(ePersona* persona, char surname[]);
void persona_setAge(ePersona* persona, int age);

//Archivos
int crearBinario(ePersona** listaPersonas, char nombreArchivo[], int totalPersonas);
ePersona* persona_buscarApellido(char nombreArchivo[], char apellido[], int cantidadPersonas);
