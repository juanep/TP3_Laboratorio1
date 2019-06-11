#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct{
    int id;
    char nombre[30];
    int horasTrabajadas;
    int sueldo;
}Employee;

#endif // employee_H_INCLUDED

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* emp, char* name);
char* employee_getNombre(Employee* emp);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief
 * \param
 */
void employee_show(Employee* this);

/** \brief Compara el campo Id de ambos parametros y retorna un valor para el ordenamiento.
 * \param puntero Employee A
 * \param puntero Employee B
 * \return  0	if both strings are identical (equal)
 *          -1	if the ASCII value of first unmatched character is less than second.
 *          1   if the ASCII value of first unmatched character is greater than second.
 */
int employee_sortById(void* employeeA, void* employeeB);

/** \brief Compara el campo Nombre de ambos parametros y retorna un valor para el ordenamiento.
 * \param puntero Employee A
 * \param puntero Employee B
 * \return  0	if both strings are identical (equal)
 *          -1	if the ASCII value of first unmatched character is less than second.
 *          1   if the ASCII value of first unmatched character is greater than second.
 */
void employee_sortByName(LinkedList* pLinkedList, int order);

/** \brief Compara el campo Horas_Trabajadas de ambos parametros y retorna un valor para el ordenamiento.
 * \param puntero Employee A
 * \param puntero Employee B
 * \return  0	if both strings are identical (equal)
 *          -1	if the ASCII value of first unmatched character is less than second.
 *          1   if the ASCII value of first unmatched character is greater than second.
 */
int employee_sortByWorkHours(void* employeeA, void* employeeB);

/** \brief Compara el campo Sueldo de ambos parametros y retorna un valor para el ordenamiento.
 * \param puntero Employee A
 * \param puntero Employee B
 * \return  0	if both strings are identical (equal)
 *          -1	if the ASCII value of first unmatched character is less than second.
 *          1   if the ASCII value of first unmatched character is greater than second.
 */
int employee_sortBySalary(void* employeeA, void* employeeB);

