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


/** \brief Valida si el dato ingresado es de tipo float
 *
 * \param auxiliar[] char Dato ingresado por el usuario
 * \return int 1 si es float, 0 si no es float
 *
 */
int esNumeroFloat(char auxiliar[]);

/** \brief Valida si el dato ingresado es de tipo char
 *
 * \param auxiliar[] char dato ingresado por el usuario
 * \return int 1 si es char, 0 si no es
 *
 */
int esLetra(char auxiliar[]);


//Setters
/** \brief Carga el nombre a la estructura
 *
 * \param pPerson S_Person* Puntero a la estructura
 * \param nombre[] char Nombre a cargar
 * \return int 1 si cargó, 0 si hubo error
 *
 */
int person_setNombre(S_Person* pPerson, char nombre[]);

/** \brief Carga la edad a la estructura
 *
 * \param pPerson S_Person* Puntero a la estructura
 * \param edad int Edad a cargar
 * \return int 1 si cargó, 0 si hubo error
 *
 */
int person_setEdad(S_Person* pPerson, int edad);

/** \brief Carga el Dni a la estructura
 *
 * \param pPerson S_Person* Puntero a la estructura
 * \param dni long int Dni a cargar
 * \return int 1 si cargó, 0 si hubo error
 *
 */
int person_setDni(S_Person* pPerson, long int dni);

/** \brief Carga los datos a la estructura persona
 *
 * \param pPerson S_Person* puntero a la estructura persona
 * \return int 1 si cargó, 0 si hubo error
 *
 */
int loadPerson(S_Person* pPerson);


/** \brief Muestra por consola la estructura cargada
 *
 * \param pPerson S_Person* Puntero a la estructura a mostrar
 * \return void
 *
 */
void printPerson(S_Person* pPerson);




