#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "JPLIB.h"

int menu(){
    int opcion;
    int* control = (int*) malloc(sizeof(int));
    system("cls");
    printf("*******************************************************************************\n");
    printf("                      L I N K E D  L I S T    \n");
    printf("*******************************************************************************\n\n");
    printf("MENU: \n\n");
    printf("  1. Cargar los datos de los empleados desde el archivo (modo texto).\n");
    printf("  2. Cargar los datos de los empleados desde el archivo (modo binario).\n");
    printf("  3. Alta de empleado\n");
    printf("  4. Modificar datos de empleado\n");
    printf("  5. Baja de empleado\n");
    printf("  6. Listar empleados\n");
    printf("  7. Ordenar empleados\n");
    printf("  8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("  9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf(" 10. Salir\n\n");
    printf("********************************************************************************\n\n");
    *control = getInt(&opcion, "Ingrese opcion: ", "\nError, ingrese una opcion de la lista: ", 1, 10, 3);
    if(*control == 0){
        opcion = 0;
        printf("\nGame over.\n\n");
    }
    free(control);
    return opcion;
}

int menuModificarEmpleado(){
    int opcion;
    int* control = (int*) malloc(sizeof(int));
    system("cls");
    printf("**** Menu Modificar Empleado ****\n\n");
    printf("Seleccione un campo a editar: \n");
    printf("1. Nombre                    \n");
    printf("2. Horas Trabajadas          \n");
    printf("3. Sueldo                     \n\n");
    printf("******************************\n\n");
    *control = getInt(&opcion, "Ingrese opcion: ", "\nError, ingrese una opcion de la lista: ", 1, 3, 3);
    if(*control == 0){
        opcion = 0;
        printf("\nGame over.\n\n");
    }
    free(control);
    return opcion;
}

int menuSelectOrder(){
    int opcion;
    int* control = (int*) malloc(sizeof(int));
    system("cls");
    printf("****  Menu Ordenamiento  ****\n\n");
    printf("Seleccione un campo a ordenar: \n");
    printf("1. Id                        \n");
    printf("2. Nombre                    \n");
    printf("3. Horas Trabajadas          \n");
    printf("4. Sueldo                     \n\n");
    printf("*******************************\n\n");
    *control = getInt(&opcion, "Ingrese opcion: ", "\nError, ingrese una opcion de la lista: ", 1, 4, 3);
    if(*control == 0){
        opcion = 0;
        printf("\nGame over.\n\n");
    }
    free(control);
    return opcion;
}

int menuCriterio(){
    int opcion;
    int* control = (int*) malloc(sizeof(int));
    system("cls");
    printf("**** Menu Criterio de Ordenamiento ****\n\n");
    printf("Seleccione el Orden:           \n");
    printf("0. Descendente                \n");
    printf("1. Ascendente                 \n\n");
    printf("***************************************\n\n");
    *control = getInt(&opcion, "Ingrese opcion: ", "Error, ingrese una opcion de la lista: ", 0, 1, 3);
    if(*control == 0){
        opcion = 0;
        printf("\nGame over.\n\n");
    }
    free(control);
    return opcion;
}

int getString(char* cadena, char* ing, char* err, int inf, int sup, int chances){
    int* length = (int*) malloc(sizeof(int));
    int control;

    printf("%s", ing);
    fflush(stdin);
    gets(cadena);
    control = validStrArr(cadena); // valida que todos los caracteres del array sean letras.
    *length = strlen(cadena); // contabiliza los caracteres del array.
    chances--;
    while((*length < inf || *length > sup || control == 0) && chances >= 1){
        chances--;
        printf("%s", err);
        fflush(stdin);
        gets(cadena);
        control = validStrArr(cadena);
    }
    free(length);
    return control; // si (control = 0) no obtuvo la cadena.
}

int validStrArr(char* cadena){
    int aux;
    int* contador = (int*) malloc(sizeof(int));
    for(*contador = 0; *contador < strlen(cadena); (*contador)++){ // recorre el array.
        if(!(isalpha(*(cadena+(*contador))))){
            aux = 0; // retorna 0 si algún caracter no es letra.
            break;
        }
        aux = 1;
    }
    free(contador);
    return aux; // retorna 1 si todos los caracteres son letras.
}

int getInt(int *x, char* ing, char* err, int inf, int sup, int chances){
    int* control = (int*) malloc(sizeof(int));
    int bandera = 0;
    int* aux = (int*) malloc(sizeof(int));

    printf("%s", ing);
    *control = scanf("%d", aux);
    chances--;
    while((*control != 1 || *aux < inf || *aux > sup) && chances>=1){
        printf("%s", err);
        fflush(stdin);
        *control = scanf("%d", aux);
        chances--;
    }
    if(*control == 1){
        bandera = 1;
        *x = *aux;
    }
    free(control);
    free(aux);
    return bandera; // si (bandera == 0) no obtuvo el entero.
}
