#ifndef FANTASMA_H_INCLUDED
#define FANTASMA_H_INCLUDED

#define TEXT_SIZE 51

#define MSG_DEFAULT_ERROR "\nError, opcion no valida..\n"

#define MSG_ERROR_MODIFY_CHOOSE  "\nError al elegir"
#define MSG_MODIFY_CHOOSE "\n\t\t\t\t\t(choose: A B C D # S = Salir)\n\n\t\t\t\t\tQue dato desea modificar?:"

#define MSG_ERROR_MODIFY_DIAS  "\nError al modificar la edad"
#define MSG_MODIFY_DIAS  "\nIngrese la edad, por favor:"

#define MSG_ERROR_MODIFY_FILE  "\nError al modificar el pago"
#define MSG_MODIFY_FILE "\nIngrese el nuevo monto del pago, por favor:"

#define MSG_ERROR_MODIFY_CUIT  "\nError al modificar el apellido"
#define MSG_MODIFY_CUIT "\nIngrese el nuevo apellido, por favor:"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "stuff.h"

typedef struct
{
    int idPublicidad;
    int idPantalla;
    int isEmpty;
    int cuit;
    int dias;
    char archive[TEXT_SIZE]; // STRING TYPE

}ePublicidad;

#endif

int publicidad_clear_all(ePublicidad array[], int size);
int publicidad_checkIfDbHasEntries(ePublicidad array[], int size);
int publicidad_findEmpty(ePublicidad array[], int size, int* posicion);
int publicidad_findId(ePublicidad array[], int size, int valorBuscado, int* posicion);
int publicidad_searchInt(ePublicidad array[], int size, int valorBuscado, int* posicion);
int publicidad_searchString(ePublicidad array[], int size, char* valorBuscado, int* indice);
int publicidad_signup(ePublicidad array[], int size, int* contadorID);
int publicidad_destroy(ePublicidad array[], int sizeArray);
int publicidad_destroyMatchedInt(ePublicidad array[], int sizeArray, int valorBuscado);
int publicidad_modify(ePublicidad array[], int sizeArray);
int publicidad_sortByString(ePublicidad array[],int size);
int publicidad_paginate(ePublicidad array[], int size);
int publicidad_info_getSalaryMedia(ePublicidad array[], int size);
