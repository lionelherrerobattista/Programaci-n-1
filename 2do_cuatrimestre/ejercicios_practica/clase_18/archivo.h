
typedef struct
{
  char* key;
  char* value;
}S_Data;


int loadDataFile(char* fileName,S_Data* pdata, int arrayLen);
void* data_newArrayData();
