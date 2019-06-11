#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "JPLIB.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main(){
    int* opcion = (int*) malloc(sizeof(int));
    int* cant = (int*) malloc(sizeof(int));
    int* flagTxt = (int*) malloc(sizeof(int));
    int* flagBin = (int*) malloc(sizeof(int));
    LinkedList* listaEmpleados = (LinkedList*) malloc(sizeof(LinkedList));
    listaEmpleados = ll_newLinkedList();
    *flagTxt = 0;
    *flagBin = 0;
    do{
        *opcion = menu();
        switch(*opcion){
            case 1:
                if(listaEmpleados == NULL){
                    printf("No existe el archivo destino.\n");
                }
                else{
                    if(controller_loadFromText("data.csv",listaEmpleados)){
                        printf("\nDatos cargados con exito.\n\n");
                        *flagTxt = 1;
                    }
                    else{
                        printf("Problemas para cargar los datos.\n");
                    }
                }
                break;
            case 2:
                if(listaEmpleados == NULL){
                    printf("No existe el archivo destino.\n");
                }
                else{
                    if(controller_loadFromBinary("data.bin", listaEmpleados)){
                        printf("\nDatos cargados con exito.\n\n");
                        *flagBin = 1;
                    }
                    else{
                        printf("\nProblemas para cargar los datos.\n\n");
                    }
                }
                break;
            case 3:
                if(*flagTxt == 0 && *flagBin == 0){
                    printf("\nNo se cargaron datos en el sistema.\n\n");
                }
                else{
                    if(controller_addEmployee(listaEmpleados)){
                        printf("\nAlta exitosa!\n\n");
                    }
                    else{
                        printf("\nProblemas para cargar los datos.\n\n");
                    }
                }
                break;
            case 4:
                if(*flagTxt == 0 && *flagBin == 0){
                    printf("\nNo se cargaron datos en el sistema.\n\n");
                }
                else{
                    if(controller_editEmployee(listaEmpleados)){
                        printf("\nModificacion exitosa!\n\n");
                    }
                    else{
                        printf("\nProblemas para modificar los datos.\n\n");
                    }
                }
                break;
            case 5:
                if(*flagTxt == 0 && *flagBin == 0){
                    printf("\nNo se cargaron datos en el sistema.\n\n");
                }
                else{
                    if(controller_removeEmployee(listaEmpleados)){
                        printf("\nBaja exitosa!\n\n");
                    }
                    else{
                        printf("\nBaja cancelada.\n\n");
                    }
                }
                break;
            case 6:
                if(*flagTxt == 0 && *flagBin == 0){
                    printf("\nNo se cargaron datos en el sistema.\n\n");
                }
                else{
                    *cant = controller_ListEmployee(listaEmpleados);
                    if(*cant == 0){
                        printf("\nProblemas para listar los empleados.\n\n");
                    }
                    else{
                        printf("\nSe listaron con exito %i empleados.\n\n", *cant);
                    }
                }
                break;
            case 7:
                if(*flagTxt == 0 && *flagBin == 0){
                    printf("\nNo se cargaron datos en el sistema.\n\n");
                }
                else{
                    if(controller_sortEmployee(listaEmpleados) == -1){
                        printf("\nProblemas con el ordenamiento\n\n");
                    }
                    else{
                        printf("\nOrdenamiento exitoso!\n\n");
                    }
                }
                break;
            case 8:
                if(*flagTxt == 0 && *flagBin == 0){
                    printf("\nNo se cargaron datos en el sistema.\n\n");
                }
                else{
                    if(controller_saveAsText("data.csv", listaEmpleados)){
                        printf("\nDatos guardados con exito!\n\n");
                    }
                    else{
                        printf("\nProblemas para guardar los datos.\n\n");
                    }
                }
                break;
            case 9:
                if(*flagTxt == 0 && *flagBin == 0){
                    printf("\nNo se cargaron datos en el sistema.\n\n");
                }
                else{
                    if(controller_saveAsBinary("data.bin", listaEmpleados)){
                        printf("\nDatos guardados con exito!\n\n");
                    }
                    else{
                        printf("\nProblemas para guardar los datos.\n\n");
                    }
                }
                break;
            case 10:
                ll_deleteLinkedList(listaEmpleados);
                exit(0);
                break;
            default:
                break;
        }
        if(*opcion != 10){
            system("pause");
        }
    }while((*opcion) != 10);
    free(opcion);
    free(cant);
    free(listaEmpleados);
    free(flagTxt);
    free(flagBin);
    return 0;
}
