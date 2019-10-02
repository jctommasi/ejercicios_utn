#include "arrayPantalla.h"

int pantalla_clear_all(ePantalla array[], int size)
{
    int retorno=-1;
    if(array != NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

int pantalla_checkIfDbHasEntries(ePantalla array[], int size)
{
	int retorno=-1;
	int i;
	if(array!= NULL && size>=0)
	{
		for(i=0;i<size;i++)
		{
			if(array[i].isEmpty==0)
			{
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

int pantalla_findEmpty(ePantalla array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int pantalla_findId(ePantalla array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idPantalla==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int pantalla_searchInt(ePantalla array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].type==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int pantalla_searchString(ePantalla array[], int size, char* valorBuscado, int* indice)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].name,valorBuscado)==0)
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

int pantalla_signup(ePantalla array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(pantalla_findEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idPantalla=*contadorID;
            array[posicion].isEmpty=0;
            utn_getUnsignedInt("\n\n\n\t\t\t\t\t\ttype: ",MSG_DEFAULT_ERROR,1,sizeof(int),1,size,1,&array[posicion].type);
            utn_getName("\t\t\t\t\t\tApellido: ",MSG_DEFAULT_ERROR,1,TEXT_SIZE,1,array[posicion].name);
            utn_getTexto("\t\t\t\t\t\tNombre: ",MSG_DEFAULT_ERROR,1,TEXT_SIZE,1,array[posicion].name);
            utn_getFloat("\t\t\t\t\t\tSalario: ",MSG_DEFAULT_ERROR,1,sizeof(float),0,1,1,&array[posicion].pricePerDay);
            stuff_clearScreen();
            stuff_showSignUpBanner();
            printf(	"\n\n\n\t\t\t\t\t\t######################"
            		"\n\t\t\t\t\t\tALTA SATISFACTORIA"
            		"\n\t\t\t\t\t\t######################"
            		"\n\t\t\t\t\t\tPosicion: %d"
            		"\n\t\t\t\t\t\tID: %d"
            		"\n\t\t\t\t\t\tApellido: %s"
            		"\n\t\t\t\t\t\tNombre: %s"
            		"\n\t\t\t\t\t\ttype: %d"
            		"\n\t\t\t\t\t\tSalario: %f"
            		"\n\t\t\t\t\t\t######################\n",
                   posicion,
				   array[posicion].idPantalla,
				   array[posicion].name,
				   array[posicion].name,
				   array[posicion].type,
				   array[posicion].pricePerDay);
            stuff_sleep(3);
            retorno=0;
        }
    }
    return retorno;
}

int pantalla_destroy(ePantalla array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;

    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\n\n\n\t\t\t\t\t\tID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);

        if(pantalla_findId(array,sizeArray,id,&posicion)==-1)
        {
            printf("\n\n\n"
            		"\t\t\t\t\t\t##############\n"
            		"\t\t\t\t\t\tID INEXISTENTE\n"
            		"\t\t\t\t\t\t##############\n"
            		"\n\n\t\t\t\t\tvolviendo al menu principal ..\n");
            stuff_sleep(2);
        }
        else
        {
        	//antes del borrado, copio los datos para luego mostrar que es lo que se borro
        	ePantalla arrayAux[sizeArray];
        	arrayAux[posicion].idPantalla = array[posicion].idPantalla;
        	arrayAux[posicion].type = array[posicion].type;
        	arrayAux[posicion].pricePerDay = array[posicion].pricePerDay;
        	strcpy(arrayAux[posicion].name,array[posicion].name);
        	strcpy(arrayAux[posicion].name,array[posicion].name);

        	//inicio borrado
            array[posicion].isEmpty=1;
            array[posicion].idPantalla=0;
            array[posicion].type=0;
            array[posicion].pricePerDay=0;
            strcpy(array[posicion].name,"");
            strcpy(array[posicion].name,"");
            retorno=0;

            //informe de borrado
            stuff_clearScreen();
            stuff_employeeGoneAway();
            printf(	"\n\n\n\t\t\t\t\t\t######################"
            		"\n\t\t\t\t\t\tBORRADO SATISFACTORIO"
            		"\n\t\t\t\t\t\t######################"
            		"\n\t\t\t\t\t\tPosicion: %d"
            		"\n\t\t\t\t\t\tID: %d"
            		"\n\t\t\t\t\t\tApellido: %s"
            		"\n\t\t\t\t\t\tNombre: %s"
            		"\n\t\t\t\t\t\ttype: %d"
            		"\n\t\t\t\t\t\tSalario: %f"
            		"\n\t\t\t\t\t\t######################\n",
                   posicion,
				   arrayAux[posicion].idPantalla,
				   arrayAux[posicion].name,
				   arrayAux[posicion].name,
				   arrayAux[posicion].type,
				   arrayAux[posicion].pricePerDay);
            stuff_sleep(6);
        }
    }
    return retorno;
}

int pantalla_destroyMatchedInt(ePantalla array[], int sizeArray, int valorBuscado)
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idPantalla==valorBuscado)
            {
                array[i].isEmpty=1;
                array[i].idPantalla=0;
                array[i].type=0;
                array[i].pricePerDay=0;
                strcpy(array[i].name,"");
                strcpy(array[i].name,"");
            }
        }
        retorno=0;
    }
    return retorno;
}

int pantalla_modify(ePantalla array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;

    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\n\t\t\t\t\t Ingrese el ID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(pantalla_findId(array,sizeArray,id,&posicion)==-1)
        {
            printf("\n\n\n"
            		"\033[0;31m"
            		"\t\t\t\t\t\t##############\n"
            		"\t\t\t\t\t\tID INEXISTENTE\n"
            		"\t\t\t\t\t\t##############\n"
            		"\n\n\t\t\t\t\tvolviendo al menu principal ..\n"
            		"\033[0m");
            stuff_sleep(2);
        }
        else
        {
            do
            {
            	stuff_clearScreen();
            	stuff_showModifyBanner();

                printf( "\n\t\t\t\t\tSE HA ENCONTRADO EL EMPLEADO:"
                		"\033[0;31m"
                		"\n\n\t\t\t\t\t\t=================="
                		"\n\t\t\t\t\t\tPosicion: %d"
                		"\n\t\t\t\t\t\tID: %d"
                		"\n\t\t\t\t\t\t=================="
                		"\n\t\t\t\t\t\tA - type: %d"
                		"\n\t\t\t\t\t\tB - Salario: %f"
                		"\n\t\t\t\t\t\tC - Apellido: %s"
                		"\n\t\t\t\t\t\tD - Nombre: %s\n"
                		"\033[0m",
                       posicion,
					   array[posicion].idPantalla,
					   array[posicion].type,
					   array[posicion].pricePerDay,
					   array[posicion].name,
					   array[posicion].name);

                utn_getChar(MSG_MODIFY_CHOOSE, MSG_ERROR_MODIFY_CHOOSE,'A', 'Z', 3, &opcion);

                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt(MSG_MODIFY_TYPE,MSG_ERROR_MODIFY_TYPE,1,sizeof(int),1,sizeArray,1,&array[posicion].type);
                        break;
                    case 'B':
                        utn_getFloat(MSG_MODIFY_PRICEPERDAY,MSG_ERROR_MODIFY_PRICEPERDAY,1,sizeof(float),0,1,1,&array[posicion].pricePerDay);
                        break;
                    case 'C':
                        utn_getName(MSG_MODIFY_SURNAME,MSG_ERROR_MODIFY_SURNAME,1,TEXT_SIZE,1,array[posicion].name);
                        break;
                    case 'D':
                        utn_getTexto(MSG_MODIFY_NAME,MSG_ERROR_MODIFY_NAME,1,TEXT_SIZE,1,array[posicion].name);
                        break;
                    case 'S':
                        break;
                    default:
                        printf(MSG_DEFAULT_ERROR);
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

int pantalla_sortByString(ePantalla array[],int size)
{
    int retorno=-1;
    int i, j;

    char nameAux[TEXT_SIZE];
    int idAux;
    int isemptyAux;
    int typeAux;
    float pricePerDayAux;

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(nameAux,array[i].name);
            idAux=array[i].idPantalla;
            isemptyAux=array[i].isEmpty;

            typeAux=array[i].type;
            pricePerDayAux=array[i].pricePerDay;
            strcpy(nameAux,array[i].name);


            j = i - 1;
            while ((j >= 0) && strcmp(nameAux,array[j].name)<0)
            {
                strcpy(array[j + 1].name,array[j].name);
                array[j + 1].idPantalla=array[j].idPantalla;
                array[j + 1].isEmpty=array[j].isEmpty;

                array[j + 1].type=array[j].type;
                array[j + 1].pricePerDay=array[j].pricePerDay;
                strcpy(array[j + 1].name,array[j].name);

                j--;
            }
            strcpy(array[j + 1].name,nameAux);
            array[j + 1].idPantalla=idAux;
            array[j + 1].isEmpty=isemptyAux;

            array[j + 1].type=typeAux;
            array[j + 1].pricePerDay=pricePerDayAux;
            strcpy(array[j + 1].name,nameAux);
        }

        for (i = 1; i < size; i++)
        {
            strcpy(nameAux,array[i].name);
            idAux=array[i].idPantalla;
            isemptyAux=array[i].isEmpty;

            typeAux=array[i].type;
            pricePerDayAux=array[i].pricePerDay;
            strcpy(nameAux,array[i].name);


            j = i - 1;
            while ((j >= 0) && typeAux < array[j].type)
            {
                strcpy(array[j + 1].name,array[j].name);
                array[j + 1].idPantalla=array[j].idPantalla;
                array[j + 1].isEmpty=array[j].isEmpty;

                array[j + 1].type=array[j].type;
                array[j + 1].pricePerDay=array[j].pricePerDay;
                strcpy(array[j + 1].name,array[j].name);

                j--;
            }
            strcpy(array[j + 1].name,nameAux);
            array[j + 1].idPantalla=idAux;
            array[j + 1].isEmpty=isemptyAux;

            array[j + 1].type=typeAux;
            array[j + 1].pricePerDay=pricePerDayAux;
            strcpy(array[j + 1].name,nameAux);
        }
        retorno=0;
    }
    return retorno;
}

int pantalla_paginate(ePantalla array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
    	printf(	"#########################################################################################################################\n"
    			"|\tID\t|\ttype\t|\t\tSALARIO\t\t\t|\tAPELLIDO\t|\tNOMBRE\t\t|\n"
    			"#########################################################################################################################\n");
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
            	printf("|\t%d\t|\t%d\t|\t\t%f\t\t|\t%s\t\t\n",
                       array[i].idPantalla,
					   array[i].type,
					   array[i].pricePerDay,
					   array[i].name);
        }
        retorno=0;
        stuff_sleep(5);
    }
    return retorno;
}

int pantalla_info_getpricePerDayMedia(ePantalla arrayEmployee[], int size)
{
	int i;

	int employeesUpperMediapricePerDay = 0;
	float pricePerDayProm = 0;
    int retorno = -1;
    float pricePerDayAcum = 0;
    int contpricePerDay = 0;

    if(arrayEmployee!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(arrayEmployee[i].isEmpty==0)
            {
            	pricePerDayAcum = pricePerDayAcum + arrayEmployee[i].pricePerDay;
            	contpricePerDay++;
            }
        }

        pricePerDayProm = pricePerDayAcum / contpricePerDay;

        for(i=0;i<size;i++)
        {
        	if(arrayEmployee[i].pricePerDay > pricePerDayProm)
        	{
        		employeesUpperMediapricePerDay++;
        	}
        }
        printf("\n\t\tEl salario promedio es de: %f con un total de %i empleados que superan la media", pricePerDayProm, employeesUpperMediapricePerDay);
        retorno = 0;
    }
    return retorno;
}
