#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#define NOMBRE_LEN 50
#define HORAS_LEN 10
#define SUELDO_LEN 20
#define ID_LEN 20
#define HORAS_LEN 10


typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(int id,char* nombreStr,int horasTrabajadas,int sueldo);
Employee* employee_newParametrosTxt(char* id,char* nombre, char*  horasTrabajadas,char*  sueldo);

void employee_delete(Employee* this);

int employee_setIdTxt(Employee* this,char* id);
int employee_setId(Employee* this, int id);
int employee_getId(Employee* this,int* id);
int employee_getIdTxt(Employee* this,char* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_setHorasTrabajadasTxt(Employee* this, char* horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas);
int employee_getHorasTrabajadasTxt(Employee* this, char* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_setSueldoTxt(Employee* this,char* sueldo);
int employee_getSueldo(Employee* this, int* sueldo);
int employee_getSueldoTxt(Employee* this, char* sueldo);

int employee_printElement(Employee* this);

#endif // employee_H_INCLUDED
