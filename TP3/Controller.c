#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "JPLIB.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee){
    int isOk = 0;
    FILE* pFile = fopen(path, "r");

    if(pFile == NULL || path == NULL || pArrayListEmployee == NULL){
        printf("\nEl archivo no existe.\n");
    }
    else{
        isOk = ll_clear(pArrayListEmployee);
        isOk = parser_EmployeeFromText(pFile, pArrayListEmployee);
    }
    fclose(pFile);
    return isOk;
}

int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee){
    int isOk = 0;
    FILE* pFile = fopen(path, "rb");

    if(pFile == NULL || path == NULL || pArrayListEmployee == NULL){
        printf("\nEl archivo no existe.\n");
    }
    else{
        isOk = ll_clear(pArrayListEmployee);
        isOk = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
    }
    fclose(pFile);
    return isOk;
}

/** \brief Alta de empleados
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_addEmployee(LinkedList* pArrayListEmployee){
    Employee* empleado = (Employee*) malloc(sizeof(Employee));
    int* control = (int*) malloc(sizeof(int));
    char* nombre = (char*) malloc(sizeof(char)*20);
    int* horasTrabajadas = (int*) malloc(sizeof(int));
    int* sueldo = (int*) malloc(sizeof(int));
    int isOk = 0;
    empleado = employee_new();

    if(pArrayListEmployee == NULL || empleado == NULL){
        printf("Problemas para cargar empleado.\n");
    }
    else{
        empleado->id = 1 + ll_len(pArrayListEmployee);
        if(!getString( nombre, "Ingrese Nombre: ", "Error, ingrese solo letras respetando el rango (3 - 19): ", 3, 19, 3)){
            printf("\nError al cargar nombre.\n");
        }
        else{
            employee_setNombre(empleado, nombre);
            if(!getInt( horasTrabajadas, "Ingrese Horas Trabajadas: ", "Error, ingrese solo numeros respetanto el rango (1 - 100): ", 1, 100, 3)){
                printf("\nError al cargar horas trabajadas.\n");
            }
            else{
                employee_setHorasTrabajadas(empleado, *horasTrabajadas);
                if(!getInt( sueldo, "Ingrese Sueldo: ", "Error, ingrese solo numeros respetanto el rango (10000 - 50000): ", 10000, 50000, 3)){
                    printf("\nError al cargar sueldo.\n");
                }
                else{
                    employee_setSueldo(empleado, *sueldo);
                    if(ll_add(pArrayListEmployee, empleado) == 0){
                        isOk = 1;
                    }
                }
            }
        }
    }
    free(empleado);
    free(nombre);
    free(horasTrabajadas);
    free(sueldo);
    free(control);
    return isOk;
}

int controller_editEmployee(LinkedList* pArrayListEmployee){
    int control = 0;
    int* idEmp = (int*) malloc(sizeof(int));
    int* idEdit = (int*) malloc(sizeof(int));
    //Employee* auxEmp = (Employee*) malloc(sizeof(Employee));
    int* indice = (int*) malloc(sizeof(int));
    char* nombre = (char*) malloc(sizeof(char)*30);
    int* horasTrabajadas = (int*) malloc(sizeof(int));
    int* sueldo = (int*) malloc(sizeof(int));
    //auxEmp = employee_new();

    if(pArrayListEmployee != NULL){
        control = getInt(idEdit, "Ingrese Id: ", "Error, ingrese solo numeros respetanto el rango (1 - 1000): ", 1, 1000, 3);
        for(*indice = 0; *indice < ll_len(pArrayListEmployee); (*indice)++){
            //auxEmp = (Employee*) ll_get(pArrayListEmployee, *indice);
            control = employee_getId( (Employee*)ll_get(pArrayListEmployee, *indice), idEmp);
            if(control == 1 && (*idEmp) == (*idEdit)){
                switch(menuModificarEmpleado()){
                    case 1:
                        control = getString( nombre, "Ingrese Nombre: ", "Error, ingrese solo letras respetando el rango (3 - 30): ", 3, 30, 3);
                        if(control == 1){
                            employee_setNombre( (Employee*)ll_get(pArrayListEmployee, *indice), nombre);
                        }
                        break;
                    case 2:
                        control = getInt( horasTrabajadas, "Ingrese Horas Trabajadas: ", "Error, ingrese solo numeros respetanto el rango (50 - 350): ", 50, 350, 3);
                        if(control == 1){
                            employee_setHorasTrabajadas( (Employee*)ll_get(pArrayListEmployee, *indice), *horasTrabajadas);
                        }
                        break;
                    case 3:
                        control = getInt( sueldo, "Ingrese Sueldo: ", "Error, ingrese solo numeros respetanto el rango (10000 - 80000): ", 10000, 80000, 3);
                        if(control == 1){
                            employee_setSueldo( (Employee*)ll_get(pArrayListEmployee, *indice), *sueldo);
                        }
                        break;
                    default:
                        break;
                }
                if(control == 0){
                    printf("\nProblemas pata modificar el campo.\n");
                }
                /*else{
                    ll_set(pArrayListEmployee, *indice, auxEmp);
                }*/
            break;
            }
        }
    }
    else{
        printf("No hay datos en la lista.\n");
    }
    free(idEmp);
    free(idEdit);
    free(indice);
    free(nombre);
    free(horasTrabajadas);
    free(sueldo);
    //free(auxEmp);
    return control;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee){ // reformar
    int control = 0;
    int* idEmp = (int*) malloc(sizeof(int));
    int* idRemove = (int*) malloc(sizeof(int));
    int* indice = (int*) malloc(sizeof(int));
    Employee* auxEmp = (Employee*) malloc(sizeof(Employee));
    auxEmp = employee_new();

    if(pArrayListEmployee != NULL){
        control = getInt(idRemove, "\nIngrese Id: ", "Error, ingrese solo numeros respetanto el rango (1 - 1000): ", 1, 1000, 3);
        for(*indice = 0; *indice < ll_len(pArrayListEmployee); (*indice)++){
            auxEmp = (Employee*) ll_get(pArrayListEmployee, *indice);

            control = employee_getId(auxEmp, idEmp);
            if(control == 1 && *idEmp == *idRemove){
                ll_remove(pArrayListEmployee, *indice);
                idRepair(pArrayListEmployee, *indice);
                break;
            }
        }
    }
    else{
        printf("No hay datos en la lista.\n");
    }
    free(auxEmp);
    free(idEmp);
    free(idRemove);
    free(indice);
    return control;
}

void idRepair(LinkedList* pLinkedList, int index){
    int* count = (int*) malloc(sizeof(int));
    Employee* emp = (Employee*) malloc(sizeof(Employee));

    if(pLinkedList != NULL && index < ll_len(pLinkedList) && emp != NULL){
        for(*count = (index); *count < ll_len(pLinkedList); (*count)++){
            emp = (Employee*) ll_get(pLinkedList, *count);
            if(emp == NULL){
                break;
            }
            else
                emp->id--;
        }
    }

    free(emp);
    free(count);
}

int controller_ListEmployee(LinkedList* pArrayListEmployee){
    int cant = 0;
    Employee* emp = (Employee*) malloc(sizeof(Employee));
    int* indice = (int*) malloc(sizeof(int));
    emp = employee_new();

    if(pArrayListEmployee != NULL && emp != NULL){
        system("cls");
        printf(" Id           Nombre   Hs Trs   Sueldo\n");
        for(*indice = 0; *indice < ll_len(pArrayListEmployee); (*indice)++){
            emp = (Employee*) ll_get(pArrayListEmployee, *indice);
            if(emp != NULL && emp->id != -1){
                employee_show(emp);
                cant++;
            }
        }
    }
    else{
        printf("No hay datos en la lista.\n");
    }
    free(emp);
    free(indice);
    return cant;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee){
    int* opcion = (int*) malloc(sizeof(int));
    int* order = (int*) malloc(sizeof(int));
    int control;

    if(pArrayListEmployee == NULL){
        printf("Problemas para realizar el ordenamiento.\n");
    }
    else{
        *opcion = menuSelectOrder();
        *order = menuCriterio();
        switch(*opcion){
        case 1:
            control = ll_sort(pArrayListEmployee, employee_sortById, *order);
            break;
        case 2:
           // control =
             employee_sortByName(pArrayListEmployee, *order);
            break;
        case 3:
            control = ll_sort(pArrayListEmployee, employee_sortByWorkHours, *order);
            break;
        case 4:
            control = ll_sort(pArrayListEmployee, employee_sortBySalary, *order);
            break;
        }
    }
    free(opcion);
    free(order);
    return control;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee){
    int isOk = 0;
    int* indice = (int*) malloc(sizeof(int));
    int* tam = (int*) malloc(sizeof(int));
    FILE *pFile = (FILE*) malloc(sizeof(FILE));
    Employee* pEmployee = (Employee*) malloc(sizeof(Employee));

    if(pArrayListEmployee == NULL && path == NULL){
        printf("Problemas para guardar los datos.\n");
    }
    else{
        if(ll_len(pArrayListEmployee) == 0){
            printf("No hay datos en la lista.\n");
        }
        else{
            pFile = fopen(path,"w");
            pEmployee = employee_new();
            if(pFile==NULL){
                printf("Archivo inexistente\n");
            }
            else{
                *tam = ll_len(pArrayListEmployee);
                for(*indice = 0; *indice < *tam; (*indice)++){
                    pEmployee = (Employee*) ll_get(pArrayListEmployee, *indice);
                    fprintf(pFile, "%d, %s, %d, %d\n", pEmployee->id, pEmployee->nombre, pEmployee->horasTrabajadas, pEmployee->sueldo); //Se escribe al archivo
                }
                isOk = 1;
            }
        }
        fclose(pFile);
    }
    free(indice);
    free(tam);
    free(pEmployee);
    return isOk;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee){
    int isOk = 0;
    int* cant = (int*) malloc(sizeof(int));
    int* indice = (int*) malloc(sizeof(int));
    int* tam = (int*) malloc(sizeof(int));
    FILE *pFile = (FILE*) malloc(sizeof(FILE));
    Employee* pEmployee = (Employee*) malloc(sizeof(Employee));

    if(pArrayListEmployee == NULL && path == NULL){
        printf("Problemas para guardar los datos.\n");
    }
    else{
        if(ll_len(pArrayListEmployee) == 0){
            printf("No hay datos en la lista.\n");
        }
        else{
            pFile = fopen(path,"wb");
            pEmployee = employee_new();
            if(pFile==NULL){
                printf("Archivo inexistente\n");
            }
            else{
                *tam = ll_len(pArrayListEmployee);
                for(*indice = 0; *indice < *tam; (*indice)++){
                    pEmployee = (Employee*) ll_get(pArrayListEmployee, *indice);
                    *cant = fwrite(pEmployee, sizeof(Employee), 1, pFile );    //Se escribe al archivo
                    if(*cant != 1){
                        printf("\nError al escribir el archivo");
                        break;
                    }
                    else{
                        isOk = 1;
                    }
                }
            }
            fclose(pFile);
        }
    }
    free(indice);
    free(cant);
    free(tam);
    free(pEmployee);
    return isOk;
}

