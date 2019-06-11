#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

Employee* employee_new(){
    Employee* empleado = (Employee*) malloc(sizeof(Employee));

    empleado->id = 0;
    strcpy(empleado->nombre, "");
    empleado->horasTrabajadas = 0;
    empleado->sueldo = 0;

    return empleado;
}

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr){
    Employee* empleado = (Employee*) malloc(sizeof(Employee));

    empleado->id = *idStr;
    strcpy(empleado->nombre, nombreStr);
    empleado->horasTrabajadas = *horasTrabajadasStr;
    empleado->sueldo = 0;

    return empleado;
}

void employee_delete(){

}

int employee_setId(Employee* this, int id){
    int ok = 0;

    if(this != NULL && id > 0){
        this->id = id;
        ok = 1;
    }
    return ok;
}

int employee_getId(Employee* this, int* id){
    int ok = 0;

    if(this != NULL){
        *id = this->id ;
        ok = 1;
    }
    return ok;
}

int employee_setNombre(Employee* emp, char* name){
    int ok = 0;

    if(emp != NULL && name != NULL){
        strncpy(emp->nombre, name, sizeof(emp->nombre));
        ok = 1;
    }
    return ok;
}

char* employee_getNombre(Employee* emp){
    char* name = (char*) malloc(sizeof(char)*30);
    if(emp != NULL && name != NULL){
        strncpy(name, emp->nombre, strlen(name));
    }
    return name;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas){
    int ok = 0;

    if(this != NULL && horasTrabajadas > 0){
        this->horasTrabajadas = horasTrabajadas;
        ok = 1;
    }
    return ok;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas){
    int ok = 0;

    if(this != NULL && *horasTrabajadas > 0){
        *horasTrabajadas = this->horasTrabajadas;
        ok = 1;
    }
    return ok;
}

int employee_setSueldo(Employee* this, int sueldo){
    int ok = 0;

    if(this != NULL && sueldo > 0){
        this->sueldo = sueldo;
        ok = 1;
    }
    return ok;
}

int employee_getSueldo(Employee* this, int* sueldo){
    int ok = 0;

    if(this != NULL){
        *sueldo = this->sueldo ;
        ok = 1;
    }
    return ok;
}

void employee_show(Employee* this){
    if(this != NULL){
        printf("%4d %16s %6d %8d\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
    }
}

int employee_sortById(void* employeeA, void* employeeB){
    int ret;

    if(((Employee*)employeeA)->id > ((Employee*)employeeB)->id){
        ret = 1;
    }
    else if(((Employee*)employeeA)->id < ((Employee*)employeeB)->id){
        ret = -1;
    }
    else{
       ret = 0;
    }
    return ret;
}

void swap(void* elementA, void* elementB){
    void* auxElement = malloc(sizeof(auxElement));
    auxElement = elementA;
    elementA = elementB;
    elementB = auxElement;
    free(auxElement);
}

void employee_sortByName(LinkedList* pLinkedList, int order){
    int ret, cont, count;
    Employee* empA = (Employee*) malloc(sizeof(Employee));
    Employee* empB = (Employee*) malloc(sizeof(Employee));

    for(cont = 0; cont < ll_len(pLinkedList)-1; cont++){
        for(count = 1; count < ll_len(pLinkedList); count++){
            empA = ll_get(pLinkedList, cont);
            empB = ll_get(pLinkedList, count);
            ret = strcmp(employee_getNombre(empA), employee_getNombre(empB));
            if(ret == 1 && order == 1){
                swap(empA, empB);
            }
            if(ret == -1 && order == 0){
                swap(empB, empA);
            }
        }
    }
   // ret = strncmp(((Employee*)employeeA)->nombre, ((Employee*)employeeB)->nombre, sizeof(char)*6);
   // ret = strncmp(empA->nombre, empB->nombre, sizeof(char)*6);

   // free(empA);
   // free(empB);
   // return ret;
}

int employee_sortByWorkHours(void* employeeA, void* employeeB){
    int ret;

    if(((Employee*)employeeA)->horasTrabajadas > ((Employee*)employeeB)->horasTrabajadas){
        ret = 1;
    }
    else if(((Employee*)employeeA)->horasTrabajadas < ((Employee*)employeeB)->horasTrabajadas){
        ret = -1;
    }
    else{
        ret = 0;
    }
    return ret;
}

int employee_sortBySalary(void* employeeA, void* employeeB){
    int ret;

    if(((Employee*)employeeA)->sueldo > ((Employee*)employeeB)->sueldo){
        ret = 1;
    }
    else if(((Employee*)employeeA)->sueldo < ((Employee*)employeeB)->sueldo){
        ret = -1;
    }
    else{
        ret = 0;
    }
    return ret;
}
