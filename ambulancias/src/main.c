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
	int id_autoinc_publicidad = 10000;

	ePantalla arrayPantalla[DB_LENGHT];
	pantalla_clear_all(arrayPantalla,DB_LENGHT);

	ePublicidad arrayPublicidad[DB_LENGHT];
	publicidad_clear_all(arrayPantalla,DB_LENGHT);

	return EXIT_SUCCESS;
}
