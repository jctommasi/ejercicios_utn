#ifndef FANTASMA_H_INCLUDED
#define FANTASMA_H_INCLUDED

#define TEXT_SIZE 51

#define MSG_DEFAULT_ERROR "\nError, opcion no valida..\n"

#define MSG_ERROR_MODIFY_CHOOSE  "\nError al elegir"
#define MSG_MODIFY_CHOOSE "\n\t\t\t\t\t(choose: A B C D # S = Salir)\n\n\t\t\t\t\tQue dato desea modificar?:"

#define MSG_ERROR_MODIFY_TYPE   "\nError al modificar la edad"
#define MSG_MODIFY_TYPE   "\nIngrese la edad, por favor:"

#define MSG_ERROR_MODIFY_PRICEPERDAY  "\nError al modificar el pago"
#define MSG_MODIFY_PRICEPERDAY "\nIngrese el nuevo monto del pago, por favor:"

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
    int idPantalla;
    int isEmpty;
    int type;
    float pricePerDay;
    char name[TEXT_SIZE]; // LONG STRING TYPE

}ePantalla;

#endif

int pantalla_clear_all(ePantalla array[], int size);
int pantalla_checkIfDbHasEntries(ePantalla array[], int size);
int pantalla_findEmpty(ePantalla array[], int size, int* posicion);
int pantalla_findId(ePantalla array[], int size, int valorBuscado, int* posicion);
int pantalla_searchInt(ePantalla array[], int size, int valorBuscado, int* posicion);
int pantalla_searchString(ePantalla array[], int size, char* valorBuscado, int* indice);
int pantalla_signup(ePantalla array[], int size, int* contadorID);
int pantalla_destroy(ePantalla array[], int sizeArray);
int pantalla_destroyMatchedInt(ePantalla array[], int sizeArray, int valorBuscado);
int pantalla_modify(ePantalla array[], int sizeArray);
int pantalla_sortByString(ePantalla array[],int size);
int pantalla_paginate(ePantalla array[], int size);
int pantalla_info_getSalaryMedia(ePantalla array[], int size);
