/*
 ============================================================================
 Name        : TRABAJO PRACTICO N-2
 Author      : Juan Cruz Tommasi
 Version     : 1.0 beta
 ============================================================================
 */

#include "global.h"

int main(void)
{

	int opNumber;
	int id_autoinc_pantalla = 0;
	int id_autoinc_publicidad = 1000;

	/* ePantalla arrayPantalla[DB_PANTALLA_LENGHT];
	pantalla_clear_all(arrayPantalla,DB_PANTALLA_LENGHT);

	ePublicidad arrayPublicidad[DB_PUBLICIDAD_LENGHT];
	publicidad_clear_all(arrayPublicidad,DB_PUBLICIDAD_LENGHT); */

	ePantalla arrayPantalla[6]=
		{
			{ 0, 0, 1, 420.00, "LCD 40p 9 DE JULIO"},
			{ 1, 0, 0, 120.00, "LeD 10p LAVALLE"},
			{ 2, 0, 0, 220.00, "LeD 20p CORRIENTES"},
			{ 3, 0, 1, 420.00, "LCD 40p CORRIENTES"},
			{ 4, 0, 0, 120.00, "LeD 10p ALEM"},
			{ 5, 0, 0, 120.00, "LeD 20p SAN JUAN"},
		};
	ePublicidad arrayPublicidad[6]=
		{
			{ 1000, 0, 0, 201, 2, "Gabriel.mp4"},
			{ 1001, 1, 0, 211, 5, "Bond.mp4"},
			{ 1002, 2, 0, 854, 4, "Doe.mp4"},
			{ 1003, 3, 0, 111, 13, "Patton.mp4"},
			{ 1004, 1, 0, 111, 4, "Marley.mp4"},
			{ 1005, 0, 0, 999, 1, "Presley.mp4"},
		};

	do
		{
			stuff_showMenu();
			utn_getUnsignedInt(MSG, MSG_ERROR,1,11,1,11,2, &opNumber);
			switch (opNumber)
			{

				case 1:
					/*Alta de pantalla: Se solicitan al usuario los datos de la pantalla, para que el sistema
					pueda​ ​ funcionar​ ​ se​ ​ deberá​ ​ generar​ ​ un​ ​ ID​ ​ único​ ​ para​ ​ cada​ ​ pantalla.*/

					pantalla_signup(arrayPantalla, DB_PANTALLA_LENGHT, &id_autoinc_pantalla);
					break;

				case 2:
					/*Modificar datos de pantalla: Se ingresa el ID de la pantalla, permitiendo modificar sus
					datos.*/

					if(pantalla_checkIfDbHasEntries(arrayPantalla, DB_PANTALLA_LENGHT) >= 0)
					{
						pantalla_modify(arrayPantalla, DB_PANTALLA_LENGHT);
					}
					else {stuff_printAndSleep(2, NO_DBENTRIES_ERROR);}
					break;

				case 3:
					/*Baja de pantalla: Se ingresa el ID de la pantalla, se eliminará la pantalla junto con todas
					las​ ​ contrataciones​ ​ de​ ​ publicidad​ ​ para​ ​ esta​ ​ pantalla.*/

					if(pantalla_checkIfDbHasEntries(arrayPantalla, DB_PANTALLA_LENGHT) >= 0)
					{
						pantalla_destroy(arrayPantalla, DB_PANTALLA_LENGHT);

					}
					else {stuff_printAndSleep(2, NO_DBENTRIES_ERROR);}
					break;

				case 4:
					/*Contratar una publicidad: ​ Se listaran todas las pantallas y se le pedirá al usuario que
					elija la pantalla donde se quiere publicar, ingresando su ID. Luego se pedirán los datos
					asociados a la publicidad: cuit del cliente, cantidad de días que dura la publicación y
					nombre​ ​ del​ ​ archivo​ ​ de​ ​ video​ ​ (p.ej.​ ​ Video1.avi).*/

					publicidad_signup(arrayPublicidad, DB_PUBLICIDAD_LENGHT, &id_autoinc_publicidad);
					break;

				case 5:
					/*Modificar condiciones de publicación: ​ Se pedirá que se ingrese el cuit del cliente y se
					listaran todas las pantallas de video que el cliente tiene contratadas mostrando todos sus
					campos. Luego de ingresar el ID de la pantalla, se permitirá modificar la cantidad de días
					contratados​ ​ para​ ​ la​ ​ misma.*/

					if(publicidad_checkIfDbHasEntries(arrayPublicidad, DB_PUBLICIDAD_LENGHT) >= 0)
					{
						publicidad_modify(arrayPublicidad, DB_PUBLICIDAD_LENGHT);
					}
					else {stuff_printAndSleep(2, NO_DBENTRIES_ERROR);}
					break;

				case 6:
					/*Cancelar contratación: ​ Se pedirá que se ingrese el cuit del cliente y se listaran todas las
					pantallas de video que el cliente tiene contratadas mostrando todos sus campos. Luego
					ingresar​ ​ el​ ​ ID​ ​ de​ ​ la​ ​ pantalla​ ​ de​ ​ la​ ​ cual​ ​ se​ ​ quiere​ ​ cancelar​ ​ la​ ​ contratación.*/

					if(publicidad_checkIfDbHasEntries(arrayPublicidad, DB_PUBLICIDAD_LENGHT) >= 0 && pantalla_checkIfDbHasEntries(arrayPantalla, DB_PANTALLA_LENGHT) >= 0)
					{
						publicidad_destroy(arrayPublicidad, DB_PUBLICIDAD_LENGHT);
					}
					else {stuff_printAndSleep(2, NO_DBENTRIES_ERROR);}
					break;

				case 7:
					/*Consulta facturación: Se deberá ingresar el cuit del cliente y se deberá listar el importe
					a​ ​ pagar​ ​ por​ ​ cada​ ​ contratación.*/

					if(publicidad_checkIfDbHasEntries(arrayPublicidad, DB_PUBLICIDAD_LENGHT) >= 0 && pantalla_checkIfDbHasEntries(arrayPantalla, DB_PANTALLA_LENGHT) >= 0)
					{
						publicidad_destroy(arrayPublicidad, DB_PUBLICIDAD_LENGHT);
					}
					else {stuff_printAndSleep(2, NO_DBENTRIES_ERROR);}
					break;

				case 8:
					/*Listar contrataciones: ​ Se deberán listar las contrataciones indicando nombre de la
					pantalla,​ ​ nombre​ ​ de​ ​ video,​ ​ cantidad​ ​ de​ ​ días​ ​ y ​ ​ cuit​ ​ de​ ​ cliente.*/

					if(publicidad_checkIfDbHasEntries(arrayPublicidad, DB_PUBLICIDAD_LENGHT) >= 0)
					{
						publicidad_sortByCuit(arrayPublicidad, 6);
						publicidad_paginate(arrayPublicidad, 6);

					}
					else {stuff_printAndSleep(2, NO_DBENTRIES_ERROR);}
					break;

				case 9:
					/*Listar​ ​ pantallas:​ ​ Se​ ​ deberán​ ​ listar​ ​ las​ ​ pantallas​ ​ existentes​ ​ indicando​ ​ todos​ ​ sus​ ​ campos.*/

					if(pantalla_checkIfDbHasEntries(arrayPantalla, DB_PANTALLA_LENGHT) >= 0)
					{

					}
					else {stuff_printAndSleep(2, NO_DBENTRIES_ERROR);}
					break;

				case 10:
					/*Informar:
					1. Lista​ ​ de​ ​ cada​ ​ cliente​ ​ con​ ​ cantidad​ ​ de​ ​ contrataciones​ ​ e ​ ​ importe​ ​ a ​ ​ pagar​ ​ por​ ​ cada​ ​ una.
					2. Cliente​ ​ con​ ​ importe​ ​ más​ ​ alto​ ​ a ​ ​ facturar​ ​ (si​ ​ hay​ ​ más​ ​ de​ ​ uno​ ​ indicar​ ​ el​ ​ primero)*/

					if(publicidad_checkIfDbHasEntries(arrayPublicidad, DB_PUBLICIDAD_LENGHT) >= 0 && pantalla_checkIfDbHasEntries(arrayPantalla, DB_PANTALLA_LENGHT) >= 0)
					{
							int reportNum;
							stuff_clearScreen();
							stuff_showReportsMenu();
							utn_getUnsignedInt(MSG, MSG_ERROR,1,2,1,2,2, &reportNum);

							switch (reportNum)
							{
							case 1:
								stuff_clearScreen();
								stuff_showPaginateBanner();

								break;
							case 2:
								stuff_clearScreen();
								stuff_showReportBanner();

								stuff_printAndSleep(2, MSG_REDIRECT);
								break;
							default:
								printf(MSG_ERROR);
								break;
							}
					}
					else {stuff_printAndSleep(2, NO_DBENTRIES_ERROR);}
					break;

				default:
					printf(MSG_ERROR);
					break;

			}
	} while (opNumber != 11);

	return EXIT_SUCCESS;
}
