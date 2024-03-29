#include "stuff.h"

void stuff_clearScreen()
{
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

void stuff_printAndSleep(int sleepTime, char msg[])
{
	printf(msg);
	fflush(stdout);
	sleep(sleepTime);
}

void stuff_sleep(int sleepTime)
{
	fflush(stdout);
	sleep(sleepTime);
}

void stuff_displayMainBanner()
{
	printf(	"\033[0;32m"
			"\n\t\t#############################################################################\n"
			"\t\tTRABAJO PRACTICO N-2 ## Alumno: Juan Cruz Tommasi ## Fecha de Entrega: 04 OCT\n"
			"\t\t#############################################################################\n"
			"\n\n\n"
			"\t\t_______  __   __  _______  ___      _______  __   __  _______  _______                   \n"
			"\t\t|       ||  |_|  ||       ||   |    |       ||  | |  ||       ||       |                  \n"
			"\t\t|    ___||       ||    _  ||   |    |   _   ||  |_|  ||    ___||    ___|                  \n"
			"\t\t|   |___ |       ||   |_| ||   |    |  | |  ||       ||   |___ |   |___                   \n"
			"\t\t|    ___||       ||    ___||   |___ |  |_|  ||_     _||    ___||    ___|                  \n"
			"\t\t|   |___ | ||_|| ||   |    |       ||       |  |   |  |   |___ |   |___                   \n"
			"\t\t|_______||_|   |_||___|    |_______||_______|  |___|  |_______||_______|                  \n"
			"\t\t__   __  _______  __    _  _______  _______  _______  __   __  _______  __    _  _______ \n"
			"\t\t|  |_|  ||   _   ||  |  | ||   _   ||       ||       ||  |_|  ||       ||  |  | ||       |\n"
			"\t\t|       ||  |_|  ||   |_| ||  |_|  ||    ___||    ___||       ||    ___||   |_| ||_     _|\n"
			"\t\t|       ||       ||       ||       ||   | __ |   |___ |       ||   |___ |       |  |   |  \n"
			"\t\t|       ||       ||  _    ||       ||   ||  ||    ___||       ||    ___||  _    |  |   |  \n"
			"\t\t| ||_|| ||   _   || | |   ||   _   ||   |_| ||   |___ | ||_|| ||   |___ | | |   |  |   |  \n"
			"\t\t|_|   |_||__| |__||_|  |__||__| |__||_______||_______||_|   |_||_______||_|  |__|  |___|  \n\n\n"
			"\033[0m");

}

void stuff_showMenu()
{
	printf("\033[0;31m");
	printf("\t\tBienvenidx al sistema administrativo de empleados, que operacion desea realizar?\n"
			"\n\t\t\t\t\t\t1. Alta"
			"\n\t\t\t\t\t\t2. Baja"
			"\n\t\t\t\t\t\t3. Modificar"
			"\n\t\t\t\t\t\t4. Informar"
			"\n\t\t\t\t\t\t5. Salir\n\n");
	printf("\033[0m");
}

void stuff_showSignUpBanner()
{
	printf(	"\033[0;32m"
			"\n\t\t#############################################################################\n"
			"\t\tTRABAJO PRACTICO N-2 ## Alumno: Juan Cruz Tommasi ## Fecha de Entrega: 04 OCT\n"
			"\t\t#############################################################################\n"
			"\n\n\n"
			"\t\t ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄        ▄       ▄         ▄  ▄▄▄▄▄▄▄▄▄▄▄ \n"
			"\t\t▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░▌      ▐░▌     ▐░▌       ▐░▌▐░░░░░░░░░░░▌\n"
			"\t\t▐░█▀▀▀▀▀▀▀▀▀  ▀▀▀▀█░█▀▀▀▀ ▐░█▀▀▀▀▀▀▀▀▀ ▐░▌░▌     ▐░▌     ▐░▌       ▐░▌▐░█▀▀▀▀▀▀▀█░▌\n"
			"\t\t▐░▌               ▐░▌     ▐░▌          ▐░▌▐░▌    ▐░▌     ▐░▌       ▐░▌▐░▌       ▐░▌\n"
			"\t\t▐░█▄▄▄▄▄▄▄▄▄      ▐░▌     ▐░▌ ▄▄▄▄▄▄▄▄ ▐░▌ ▐░▌   ▐░▌     ▐░▌       ▐░▌▐░█▄▄▄▄▄▄▄█░▌\n"
			"\t\t▐░░░░░░░░░░░▌     ▐░▌     ▐░▌▐░░░░░░░░▌▐░▌  ▐░▌  ▐░▌     ▐░▌       ▐░▌▐░░░░░░░░░░░▌\n"
			"\t\t ▀▀▀▀▀▀▀▀▀█░▌     ▐░▌     ▐░▌ ▀▀▀▀▀▀█░▌▐░▌   ▐░▌ ▐░▌     ▐░▌       ▐░▌▐░█▀▀▀▀▀▀▀▀▀ \n"
			"\t\t          ▐░▌     ▐░▌     ▐░▌       ▐░▌▐░▌    ▐░▌▐░▌     ▐░▌       ▐░▌▐░▌          \n"
			"\t\t ▄▄▄▄▄▄▄▄▄█░▌ ▄▄▄▄█░█▄▄▄▄ ▐░█▄▄▄▄▄▄▄█░▌▐░▌     ▐░▐░▌     ▐░█▄▄▄▄▄▄▄█░▌▐░▌          \n"
			"\t\t▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌      ▐░░▌     ▐░░░░░░░░░░░▌▐░▌          \n"
			"\t\t ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀        ▀▀       ▀▀▀▀▀▀▀▀▀▀▀  ▀           \n"
			"\t\t\n\n\n"
			"\033[0m");
}

void stuff_showDestroyBanner()
{
	printf(	"\033[0;32m"
			"\n\t\t#############################################################################\n"
			"\t\tTRABAJO PRACTICO N-2 ## Alumno: Juan Cruz Tommasi ## Fecha de Entrega: 04 OCT\n"
			"\t\t#############################################################################\n"
			"\n\n\n"
			"\t\t ▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄         ▄ \n"
			"\t\t▐░░░░░░░░░░▌ ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌       ▐░▌\n"
			"\t\t▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀▀▀  ▀▀▀▀█░█▀▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌▐░▌       ▐░▌\n"
			"\t\t▐░▌       ▐░▌▐░▌          ▐░▌               ▐░▌     ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌\n"
			"\t\t▐░▌       ▐░▌▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄▄▄      ▐░▌     ▐░█▄▄▄▄▄▄▄█░▌▐░▌       ▐░▌▐░█▄▄▄▄▄▄▄█░▌\n"
			"\t\t▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌     ▐░▌     ▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░░░░░░░░░░░▌\n"
			"\t\t▐░▌       ▐░▌▐░█▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀█░▌     ▐░▌     ▐░█▀▀▀▀█░█▀▀ ▐░▌       ▐░▌ ▀▀▀▀█░█▀▀▀▀ \n"
			"\t\t▐░▌       ▐░▌▐░▌                    ▐░▌     ▐░▌     ▐░▌     ▐░▌  ▐░▌       ▐░▌     ▐░▌     \n"
			"\t\t▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄█░▌     ▐░▌     ▐░▌      ▐░▌ ▐░█▄▄▄▄▄▄▄█░▌     ▐░▌     \n"
			"\t\t▐░░░░░░░░░░▌ ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌     ▐░▌     ▐░▌       ▐░▌▐░░░░░░░░░░░▌     ▐░▌     \n"
			"\t\t ▀▀▀▀▀▀▀▀▀▀   ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀       ▀       ▀         ▀  ▀▀▀▀▀▀▀▀▀▀▀       ▀      \n"
			"\t\t\n\n\n"
			"\033[0m");
}

void stuff_showModifyBanner()
{
	printf(	"\033[0;32m"
			"\n\t\t#############################################################################\n"
			"\t\tTRABAJO PRACTICO N-2 ## Alumno: Juan Cruz Tommasi ## Fecha de Entrega: 04 OCT\n"
			"\t\t#############################################################################\n"
			"\n\n\n"
			"\t\t ▄▄       ▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄         ▄ \n"
			"\t\t▐░░▌     ▐░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌       ▐░▌\n"
			"\t\t▐░▌░▌   ▐░▐░▌▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌▀▀▀▀█░█▀▀▀▀ ▐░█▀▀▀▀▀▀▀▀▀ ▐░▌       ▐░▌\n"
			"\t\t▐░▌▐░▌ ▐░▌▐░▌▐░▌       ▐░▌▐░▌       ▐░▌    ▐░▌     ▐░▌          ▐░▌       ▐░▌\n"
			"\t\t▐░▌ ▐░▐░▌ ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌    ▐░▌     ▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄█░▌\n"
			"\t\t▐░▌  ▐░▌  ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌    ▐░▌     ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌\n"
			"\t\t▐░▌   ▀   ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌    ▐░▌     ▐░█▀▀▀▀▀▀▀▀▀  ▀▀▀▀█░█▀▀▀▀ \n"
			"\t\t▐░▌       ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌    ▐░▌     ▐░▌               ▐░▌     \n"
			"\t\t▐░▌       ▐░▌▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌▄▄▄▄█░█▄▄▄▄ ▐░▌               ▐░▌     \n"
			"\t\t▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌               ▐░▌     \n"
			"\t\t ▀         ▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀                 ▀      \n"
			"\t\t\n\n\n"
			"\033[0m");
}

void stuff_showReportsMenu()
{
	printf(	"\033[0;32m"
			"\n\t\t#############################################################################\n"
			"\t\tTRABAJO PRACTICO N-2 ## Alumno: Juan Cruz Tommasi ## Fecha de Entrega: 04 OCT\n"
			"\t\t#############################################################################\n"
			"\n\n\n"
			"\t\t ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄ \n"
			"\t\t▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌\n"
			"\t\t▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌ ▀▀▀▀█░█▀▀▀▀ ▐░█▀▀▀▀▀▀▀▀▀ \n"
			"\t\t▐░▌       ▐░▌▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌     ▐░▌     ▐░▌          \n"
			"\t\t▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄█░▌▐░▌       ▐░▌▐░█▄▄▄▄▄▄▄█░▌     ▐░▌     ▐░█▄▄▄▄▄▄▄▄▄ \n"
			"\t\t▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░░░░░░░░░░░▌     ▐░▌     ▐░░░░░░░░░░░▌\n"
			"\t\t▐░█▀▀▀▀█░█▀▀ ▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀▀▀ ▐░▌       ▐░▌▐░█▀▀▀▀█░█▀▀      ▐░▌      ▀▀▀▀▀▀▀▀▀█░▌\n"
			"\t\t▐░▌     ▐░▌  ▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌     ▐░▌       ▐░▌               ▐░▌\n"
			"\t\t▐░▌      ▐░▌ ▐░█▄▄▄▄▄▄▄▄▄ ▐░▌          ▐░█▄▄▄▄▄▄▄█░▌▐░▌      ▐░▌      ▐░▌      ▄▄▄▄▄▄▄▄▄█░▌\n"
			"\t\t▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░▌          ▐░░░░░░░░░░░▌▐░▌       ▐░▌     ▐░▌     ▐░░░░░░░░░░░▌\n"
			"\t\t ▀         ▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀            ▀▀▀▀▀▀▀▀▀▀▀  ▀         ▀       ▀       ▀▀▀▀▀▀▀▀▀▀▀ \n"
			"\t\t\n\n\n"
			"\033[0m");
	printf("\t\t\t\t\tQue operación desea realizar?\n\n"
			"\n\t\t\t\t\t\t1. Listar Empleados por apellido y sector"
			"\n\t\t\t\t\t\t2. Calcular sueldo promedio y cuantos empleados lo superan\n\n");
}

void stuff_showReportBanner()
{
	printf(	"\033[0;32m"
			"\n\t\t#############################################################################\n"
			"\t\tTRABAJO PRACTICO N-2 ## Alumno: Juan Cruz Tommasi ## Fecha de Entrega: 04 OCT\n"
			"\t\t#############################################################################\n"
			"\n\n\n"
			"\t\t███████╗ █████╗ ██╗      █████╗ ██████╗ ██╗   ██╗    \n"
			"\t\t██╔════╝██╔══██╗██║     ██╔══██╗██╔══██╗╚██╗ ██╔╝    \n"
			"\t\t███████╗███████║██║     ███████║██████╔╝ ╚████╔╝     \n"
			"\t\t╚════██║██╔══██║██║     ██╔══██║██╔══██╗  ╚██╔╝      \n"
			"\t\t███████║██║  ██║███████╗██║  ██║██║  ██║   ██║       \n"
			"\t\t╚══════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝       \n"
			"\t\t                                                     \n"
			"\t\t██████╗ ███████╗██████╗  ██████╗ ██████╗ ████████╗   \n"
			"\t\t██╔══██╗██╔════╝██╔══██╗██╔═══██╗██╔══██╗╚══██╔══╝   \n"
			"\t\t██████╔╝█████╗  ██████╔╝██║   ██║██████╔╝   ██║      \n"
			"\t\t██╔══██╗██╔══╝  ██╔═══╝ ██║   ██║██╔══██╗   ██║      \n"
			"\t\t██║  ██║███████╗██║     ╚██████╔╝██║  ██║   ██║      \n"
			"\t\t╚═╝  ╚═╝╚══════╝╚═╝      ╚═════╝ ╚═╝  ╚═╝   ╚═╝      \n"
			"\t\t\n\n\n"
			"\033[0m");
}

void stuff_showPaginateBanner()
{
	printf(	"\033[0;32m"
			"\n\t\t#############################################################################\n"
			"\t\tTRABAJO PRACTICO N-2 ## Alumno: Juan Cruz Tommasi ## Fecha de Entrega: 04 OCT\n"
			"\t\t#############################################################################\n"
			"\n\n\n"
			"\t\t ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄        ▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄ \n"
			"\t\t▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░▌      ▐░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌\n"
			"\t\t▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀▀▀  ▀▀▀▀█░█▀▀▀▀ ▐░▌░▌     ▐░▌▐░█▀▀▀▀▀▀▀█░▌ ▀▀▀▀█░█▀▀▀▀ ▐░█▀▀▀▀▀▀▀▀▀ \n"
			"\t\t▐░▌       ▐░▌▐░▌       ▐░▌▐░▌               ▐░▌     ▐░▌▐░▌    ▐░▌▐░▌       ▐░▌     ▐░▌     ▐░▌          \n"
			"\t\t▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌▐░▌ ▄▄▄▄▄▄▄▄      ▐░▌     ▐░▌ ▐░▌   ▐░▌▐░█▄▄▄▄▄▄▄█░▌     ▐░▌     ▐░█▄▄▄▄▄▄▄▄▄ \n"
			"\t\t▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌▐░░░░░░░░▌     ▐░▌     ▐░▌  ▐░▌  ▐░▌▐░░░░░░░░░░░▌     ▐░▌     ▐░░░░░░░░░░░▌\n"
			"\t\t▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌▐░▌ ▀▀▀▀▀▀█░▌     ▐░▌     ▐░▌   ▐░▌ ▐░▌▐░█▀▀▀▀▀▀▀█░▌     ▐░▌     ▐░█▀▀▀▀▀▀▀▀▀ \n"
			"\t\t▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌     ▐░▌     ▐░▌    ▐░▌▐░▌▐░▌       ▐░▌     ▐░▌     ▐░▌          \n"
			"\t\t▐░▌          ▐░▌       ▐░▌▐░█▄▄▄▄▄▄▄█░▌ ▄▄▄▄█░█▄▄▄▄ ▐░▌     ▐░▐░▌▐░▌       ▐░▌     ▐░▌     ▐░█▄▄▄▄▄▄▄▄▄ \n"
			"\t\t▐░▌          ▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌      ▐░░▌▐░▌       ▐░▌     ▐░▌     ▐░░░░░░░░░░░▌\n"
			"\t\t ▀            ▀         ▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀        ▀▀  ▀         ▀       ▀       ▀▀▀▀▀▀▀▀▀▀▀ \n"
			"\t\t\n\n\n"
			"\033[0m");
}

void stuff_showDestroyed()
{
	printf(	"\033[0;32m"
			"\n\t\t#############################################################################\n"
			"\t\tTRABAJO PRACTICO N-2 ## Alumno: Juan Cruz Tommasi ## Fecha de Entrega: 04 OCT\n"
			"\t\t#############################################################################\n"
			"\n\n\n"
			"\t\t ▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄         ▄ \n"
			"\t\t▐░░░░░░░░░░▌ ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌       ▐░▌\n"
			"\t\t▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀▀▀  ▀▀▀▀█░█▀▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌▐░▌       ▐░▌\n"
			"\t\t▐░▌       ▐░▌▐░▌          ▐░▌               ▐░▌     ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌\n"
			"\t\t▐░▌       ▐░▌▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄▄▄      ▐░▌     ▐░█▄▄▄▄▄▄▄█░▌▐░▌       ▐░▌▐░█▄▄▄▄▄▄▄█░▌\n"
			"\t\t▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌     ▐░▌     ▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░░░░░░░░░░░▌\n"
			"\t\t▐░▌       ▐░▌▐░█▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀█░▌     ▐░▌     ▐░█▀▀▀▀█░█▀▀ ▐░▌       ▐░▌ ▀▀▀▀█░█▀▀▀▀ \n"
			"\t\t▐░▌       ▐░▌▐░▌                    ▐░▌     ▐░▌     ▐░▌     ▐░▌  ▐░▌       ▐░▌     ▐░▌     \n"
			"\t\t▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄█░▌     ▐░▌     ▐░▌      ▐░▌ ▐░█▄▄▄▄▄▄▄█░▌     ▐░▌     \n"
			"\t\t▐░░░░░░░░░░▌ ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌     ▐░▌     ▐░▌       ▐░▌▐░░░░░░░░░░░▌     ▐░▌     \n"
			"\t\t ▀▀▀▀▀▀▀▀▀▀   ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀       ▀       ▀         ▀  ▀▀▀▀▀▀▀▀▀▀▀       ▀      \n"
			"\t\t\n\n\n"
			"\t\t\t\t#############################################################\n"
			"\t\t\t\t###################################################   #######\n"
			"\t\t\t\t###############################################   /~ )   #####\n"
			"\t\t\t\t############################################   _- `~~~', ####\n"
			"\t\t\t\t##########################################  _-~       )  ####\n"
			"\t\t\t\t#######################################  _-~          |  ####\n"
			"\t\t\t\t####################################  _-~            ;  #####\n"
			"\t\t\t\t##########################  __---___-~              |   #####\n"
			"\t\t\t\t#######################   _~   ,,                  ;  `,,  ##\n"
			"\t\t\t\t#####################  _-~    ;'                  |  ,'  ; ##\n"
			"\t\t\t\t###################  _~      '                    `~'   ; ###\n"
			"\t\t\t\t############   __---;                                 ,' ####\n"
			"\t\t\t\t########   __~~  ___                                ,' ######\n"
			"\t\t\t\t#####  _-~~   -~~ _                               ,' ########\n"
			"\t\t\t\t##### `-_         _                              ; ##########\n"
			"\t\t\t\t#######  ~~----~~~   ;                          ; ###########\n"
			"\t\t\t\t#########  /          ;                        ; ############\n"
			"\t\t\t\t#######  /             ;                      ; #############\n"
			"\t\t\t\t#####  /                `                    ; ##############\n"
			"\t\t\t\t###  /                                      ; ###############\n"
			"\t\t\t\t#                                            ################\n"
			"\t\t\t\t#          EMPLOYEE HAS GONE AWAY            ################\n"
			"\033[0m");
}
