#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee){
    int isOk = 0;
    int* cant = (int*) malloc(sizeof(int));
    char buffer[4][20];
    *cant = 0;

    if(pFile != NULL && pArrayListEmployee != NULL){
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        do{
            *cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
            if(*cant != 4){
                printf("\nProblemas para cargar el archivo data.csv\n");
            }
            else{
                Employee* pEmployee = employee_new();
                pEmployee->id = atoi(buffer[0]);
                strcpy(pEmployee->nombre, buffer[1]);
                pEmployee->horasTrabajadas = atoi(buffer[2]);
                pEmployee->sueldo = atoi(buffer[3]);
                ll_add(pArrayListEmployee, pEmployee);
            }

        }while(!feof(pFile));
        fclose(pFile);
        isOk = 1;
    }
    else{
        printf("Archivo vacio\n");
    }
    free(cant);
    return isOk;
}

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo binario).
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee){
    int isOk = 0;
    int* cant = (int*) malloc(sizeof(int));
    *cant = 0;

    if(pFile != NULL && pArrayListEmployee != NULL){
        while(!feof(pFile)){
            Employee* pEmployee = employee_new();
            *cant = fread(pEmployee, sizeof(Employee), 1, pFile);
            if(*cant == 1){
                ll_add(pArrayListEmployee, pEmployee);
            }
        }
        fclose(pFile);
        isOk = 1;
    }
    else{
        printf("\nArchivo vacio\n");
    }
    free(cant);
    return isOk;
}
