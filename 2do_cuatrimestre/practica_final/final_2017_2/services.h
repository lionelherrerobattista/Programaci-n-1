
typedef struct
{
    int id;
    char name[33];
    char email[65];

}S_Service;

S_Service* newService();
void cargarServices(S_Service* pAuxEstructura,char* auxId,char* auxName,char* auxEmail);
void services_mostrarDatos(LinkedList* listaServices);
int services_getId(void* pService);
char* services_getName(void* pService);
char* services_getEmail(void* pService);
