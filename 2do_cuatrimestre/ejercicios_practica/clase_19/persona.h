
typedef struct
{
    char name[32];
    char surname[32];
    int age;

}ePersona;


int pedirCadenaLetras(char mensaje[], char cadena[]);
int pedirCadenaInt(char mensaje[], int minimo, int maximo);
int cargarCadena(char mensaje[], char cadena[]);

int esLetra(char auxiliar[]);
int esNumero (char auxiliar[]);

//Setters
void persona_setName(ePersona listaPersonas[], char name[], int index);
void persona_setSurname(ePersona listaPersonas[], char surname[], int index);
void persona_setAge(ePersona listaPersonas[], int age, int index);

int crearBinario(ePersona listaPersonas[], char nombreArchivo[], int totalPersonas);
ePersona* persona_buscarApellido(char nombreArchivo[], char apellido[], int cantidadPersonas);
