#ifndef JPLIB_H_INCLUDED
#define JPLIB_H_INCLUDED

int menu();
int menuModificarEmpleado();
int menuSelectOrder();
int menuCriterio();

int getString(char* cadena, char* ing, char* err, int inf, int sup, int chances);
int validStrArr(char* cadena);

int getInt(int *x, char* ing, char* err, int inf, int sup, int chances);

#endif // JPLIB_H_INCLUDED
