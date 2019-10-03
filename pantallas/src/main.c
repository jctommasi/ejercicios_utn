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
			{ 1005, 0, 0, 854, 1, "Presley.mp4"},
		};

	do
		{
			stuff_showMenu();
			utn_getUnsignedInt(MSG, MSG_ERROR,1,2,1,2,2, &opNumber);
			switch (opNumber)
			{
				case 1:
					pantalla_signup(arrayPantalla, DB_PANTALLA_LENGHT, &id_autoinc_pantalla);
					break;

				case 2:
					if(pantalla_checkIfDbHasEntries(arrayPantalla, DB_PANTALLA_LENGHT) >= 0)
					{
						pantalla_modify(arrayPantalla, DB_PANTALLA_LENGHT);
					} else {stuff_printAndSleep(2, NO_DBENTRIES_ERROR);}
					break;

				case 3:
					if(pantalla_checkIfDbHasEntries(arrayPantalla, DB_PANTALLA_LENGHT) >= 0)
					{
						pantalla_destroy(arrayPantalla, DB_PANTALLA_LENGHT);
					} else {stuff_printAndSleep(2, NO_DBENTRIES_ERROR);}
					break;

				case 4:
					publicidad_signup(arrayPublicidad, DB_PUBLICIDAD_LENGHT, &id_autoinc_publicidad);
					break;

				case 5:
					if(publicidad_checkIfDbHasEntries(arrayPublicidad, DB_PUBLICIDAD_LENGHT) >= 0)
					{
						publicidad_modify(arrayPublicidad, DB_PUBLICIDAD_LENGHT);
					}else {stuff_printAndSleep(2, NO_DBENTRIES_ERROR);}
					break;

				case 6:
					if(publicidad_checkIfDbHasEntries(arrayPublicidad, DB_PUBLICIDAD_LENGHT) >= 0)
					{
						publicidad_destroy(arrayPublicidad, DB_PUBLICIDAD_LENGHT);
					}else {stuff_printAndSleep(2, NO_DBENTRIES_ERROR);}
					break;

				case 7:

					break;

				case 8:

					break;

				case 9:

					break;

				case 10:

					break;

				default:
					printf(MSG_ERROR);
					break;

			}
	} while (opNumber != 11);

	return EXIT_SUCCESS;
}
