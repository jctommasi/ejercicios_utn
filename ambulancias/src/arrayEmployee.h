#ifndef FANTASMA_H_INCLUDED
#define FANTASMA_H_INCLUDED

#define TEXT_SIZE 51

#define MSG_DEFAULT_ERROR "\nError, opcion no valida..\n"

#define MSG_ERROR_MODIFY_CHOOSE  "\nError al elegir"
#define MSG_MODIFY_CHOOSE "\n\t\t\t\t\t(choose: A B C D # S = Salir)\n\n\t\t\t\t\tQue dato desea modificar?:"

#define MSG_ERROR_MODIFY_SECTOR  "\nError al modificar la edad"
#define MSG_MODIFY_SECTOR  "\nIngrese la edad, por favor:"

#define MSG_ERROR_MODIFY_SALARY  "\nError al modificar el pago"
#define MSG_MODIFY_SALARY "\nIngrese el nuevo monto del pago, por favor:"

#define MSG_ERROR_MODIFY_SURNAME  "\nError al modificar el apellido"
#define MSG_MODIFY_SURNAME "\nIngrese el nuevo apellido, por favor:"

#define MSG_ERROR_MODIFY_NAME  "\nError al modificar el nombre"
#define MSG_MODIFY_NAME "\nIngrese el nombre, por favor:"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "stuff.h"

typedef struct
{
    int idUnico;
    int isEmpty;
    int sector;
    float salary;
    char lastName[TEXT_SIZE]; // STRING TYPE
    char name[TEXT_SIZE]; // LONG STRING TYPE

}ePantalla;

#endif

int publicidad_clear_all(ePantalla array[], int size);
int publicidad_checkIfDbHasEntries(ePantalla array[], int size);
int publicidad_findEmpty(ePantalla array[], int size, int* posicion);
int publicidad_findId(ePantalla array[], int size, int valorBuscado, int* posicion);
int publicidad_searchInt(ePantalla array[], int size, int valorBuscado, int* posicion);
int publicidad_searchString(ePantalla array[], int size, char* valorBuscado, int* indice);
int publicidad_signup(ePantalla array[], int size, int* contadorID);
int publicidad_destroy(ePantalla array[], int sizeArray);
int publicidad_destroyMatchedInt(ePantalla array[], int sizeArray, int valorBuscado);
int publicidad_modify(ePantalla array[], int sizeArray);
int publicidad_sortByString(ePantalla array[],int size);
int publicidad_paginate(ePantalla array[], int size);
int publicidad_info_getSalaryMedia(ePantalla array[], int size);
