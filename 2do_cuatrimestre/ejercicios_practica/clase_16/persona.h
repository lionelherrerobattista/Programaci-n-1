typedef struct{

    int edad;
    char nombre[50];
    int dni;

}S_Person;


int cargarCadena(char mensaje[], char cadena[]);
int cargarCadena(char mensaje[], char cadena[]);

int pedirCadenaInt(char mensaje[], int minimo, int maximo);
float pedirCadenaFloat(char mensaje[], float minimo, float maximo);
int pedirCadenaLetras(char mensaje[], char cadena[]);
/** \brief Valida si el dato ingresado es de tipo int
 *
 * \param auxiliar[] char dato ingresado por el usuario
 * \return int 1 si es int, 0 si no es int
 *
 */
int esNumero(char auxiliar[]);

int esNumeroFloat (char auxiliar[]);

/** \brief Valida si el dato ingresado es de tipo char
 *
 * \param auxiliar[] char dato ingresado por el usuario
 * \return int 1 si es char, 0 si no es
 *
 */
int esLetra(char auxiliar[]);


//Setters
int person_setNombre(S_Person* pPerson, char nombre[]);
int person_setEdad(S_Person* pPerson, int edad);
int person_setDni(S_Person* pPerson, long int dni);


