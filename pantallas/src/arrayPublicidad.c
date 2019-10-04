#include "arrayPublicidad.h"

int publicidad_clear_all(ePublicidad array[], int size)
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

int publicidad_checkIfDbHasEntries(ePublicidad array[], int size)
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

int publicidad_findEmpty(ePublicidad array[], int size, int* posicion)
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

int publicidad_findId(ePublicidad array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idPublicidad==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int publicidad_searchInt(ePublicidad array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].cuit==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int publicidad_searchString(ePublicidad array[], int size, char* valorBuscado, int* indice)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].archive,valorBuscado)==0)
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

int publicidad_signup(ePublicidad array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(publicidad_findEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idPublicidad=*contadorID;
            array[posicion].isEmpty=0;
            utn_getUnsignedInt("\n\n\n\t\t\t\t\t\tCuit: ",MSG_DEFAULT_ERROR,1,sizeof(int),1,size,1,&array[posicion].cuit);
            utn_getTexto("\t\t\t\t\t\tArchivo: ",MSG_DEFAULT_ERROR,1,TEXT_SIZE,1,array[posicion].archive);
            utn_getUnsignedInt("\n\n\n\t\t\t\t\t\tDias: ",MSG_DEFAULT_ERROR,1,sizeof(int),1,size,1,&array[posicion].dias);
            stuff_clearScreen();
            stuff_showSignUpBanner();
            printf(	"\n\n\n\t\t\t\t\t\t######################"
            		"\n\t\t\t\t\t\tALTA SATISFACTORIA"
            		"\n\t\t\t\t\t\t######################"
            		"\n\t\t\t\t\t\tPosicion: %d"
            		"\n\t\t\t\t\t\tID: %d"
            		"\n\t\t\t\t\t\tFile: %s"
            		"\n\t\t\t\t\t\tDias: %d"
            		"\n\t\t\t\t\t\tCuit: %d"
            		"\n\t\t\t\t\t\t######################\n",
                   posicion,
				   array[posicion].idPublicidad,
				   array[posicion].archive,
				   array[posicion].cuit,
				   array[posicion].dias);
            stuff_sleep(3);
            retorno=0;
        }
    }
    return retorno;
}

int publicidad_destroy(ePublicidad array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;

    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\n\n\n\t\t\t\t\t\tID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);

        if(publicidad_findId(array,sizeArray,id,&posicion)==-1)
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
        	ePublicidad arrayAux[sizeArray];
        	arrayAux[posicion].idPublicidad = array[posicion].idPublicidad;
        	arrayAux[posicion].cuit = array[posicion].cuit;
        	arrayAux[posicion].dias = array[posicion].dias;
        	strcpy(arrayAux[posicion].archive,array[posicion].archive);

        	//inicio borrado
            array[posicion].isEmpty=1;
            array[posicion].idPublicidad=0;
            array[posicion].cuit=0;
            array[posicion].dias=0;
            strcpy(array[posicion].archive,"");
            retorno=0;

            //informe de borrado
            stuff_clearScreen();
            stuff_showDestroyed();
            printf(	"\n\n\n\t\t\t\t\t\t######################"
            		"\n\t\t\t\t\t\tBORRADO SATISFACTORIO"
            		"\n\t\t\t\t\t\t######################"
            		"\n\t\t\t\t\t\tPosicion: %d"
            		"\n\t\t\t\t\t\tID: %d"
            		"\n\t\t\t\t\t\tApellido: %s"
            		"\n\t\t\t\t\t\tNombre: %d"
            		"\n\t\t\t\t\t\tcuit: %d"
            		"\n\t\t\t\t\t\t######################\n",
                   posicion,
				   arrayAux[posicion].idPublicidad,
				   arrayAux[posicion].archive,
				   arrayAux[posicion].cuit,
				   arrayAux[posicion].dias);
            stuff_sleep(6);
        }
    }
    return retorno;
}

int publicidad_destroyMatchedInt(ePublicidad array[], int sizeArray, int valorBuscado)
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idPublicidad==valorBuscado)
            {
                array[i].isEmpty=1;
                array[i].idPublicidad=0;
                array[i].cuit=0;
                array[i].dias=0;
                strcpy(array[i].archive,"");
            }
        }
        retorno=0;
    }
    return retorno;
}

int publicidad_modify(ePublicidad array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;

    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\n\t\t\t\t\t Ingrese el ID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(publicidad_findId(array,sizeArray,id,&posicion)==-1)
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
                		"\n\t\t\t\t\t\tA - cuit: %d"
                		"\n\t\t\t\t\t\tB - Salario: %d"
                		"\n\t\t\t\t\t\tC - Apellido: %s"
                		"\033[0m",
                       posicion,
					   array[posicion].idPublicidad,
					   array[posicion].cuit,
					   array[posicion].dias,
					   array[posicion].archive);

                utn_getChar(MSG_MODIFY_CHOOSE, MSG_ERROR_MODIFY_CHOOSE,'A', 'Z', 3, &opcion);

                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt(MSG_MODIFY_CUIT,MSG_ERROR_MODIFY_CUIT,1,sizeof(int),1,sizeArray,1,&array[posicion].cuit);
                        break;
                    case 'B':
                        utn_getUnsignedInt(MSG_MODIFY_DIAS,MSG_ERROR_MODIFY_DIAS,1,sizeof(int),1,sizeArray,1,&array[posicion].dias);
                        break;
                    case 'C':
                        utn_getTexto(MSG_MODIFY_FILE,MSG_ERROR_MODIFY_FILE,1,TEXT_SIZE,1,array[posicion].archive);
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

int publicidad_sortByString(ePublicidad array[],int size)
{
    int retorno=-1;
    int i, j;

    char archiveAux[TEXT_SIZE];
    int idAux;
    int isemptyAux;
    int cuitAux;
    float diasAux;

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(archiveAux,array[i].archive);
            idAux=array[i].idPublicidad;
            isemptyAux=array[i].isEmpty;
            cuitAux=array[i].cuit;
            diasAux=array[i].dias;

            j = i - 1;
            while ((j >= 0) && strcmp(archiveAux,array[j].archive)<0)
            {
                strcpy(array[j + 1].archive,array[j].archive);
                array[j + 1].idPublicidad=array[j].idPublicidad;
                array[j + 1].isEmpty=array[j].isEmpty;
                array[j + 1].cuit=array[j].cuit;
                array[j + 1].dias=array[j].dias;

                j--;
            }
            strcpy(array[j + 1].archive,archiveAux);
            array[j + 1].idPublicidad=idAux;
            array[j + 1].isEmpty=isemptyAux;
            array[j + 1].cuit=cuitAux;
            array[j + 1].dias=diasAux;

        }

        for (i = 1; i < size; i++)
        {
            strcpy(archiveAux,array[i].archive);
            idAux=array[i].idPublicidad;
            isemptyAux=array[i].isEmpty;

            cuitAux=array[i].cuit;
            diasAux=array[i].dias;


            j = i - 1;
            while ((j >= 0) && cuitAux < array[j].cuit)
            {
                strcpy(array[j + 1].archive,array[j].archive);
                array[j + 1].idPublicidad=array[j].idPublicidad;
                array[j + 1].isEmpty=array[j].isEmpty;

                array[j + 1].cuit=array[j].cuit;
                array[j + 1].dias=array[j].dias;
                strcpy(array[j + 1].archive,array[j].archive);

                j--;
            }
            strcpy(array[j + 1].archive,archiveAux);
            array[j + 1].idPublicidad=idAux;
            array[j + 1].isEmpty=isemptyAux;

            array[j + 1].cuit=cuitAux;
            array[j + 1].dias=diasAux;
        }
        retorno=0;
    }
    return retorno;
}

int publicidad_paginate(ePublicidad array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
    	printf(	"#########################################################################################################################\n"
    			"|\tID\t|\tcuit\t|\t\tSALARIO\t\t\t|\tAPELLIDO\t|\tNOMBRE\t\t|\n"
    			"#########################################################################################################################\n");
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
            	printf("|\t%d\t|\t%d\t|\t\t%d\t\t|\t%s\t\t\n",
                       array[i].idPublicidad,
					   array[i].cuit,
					   array[i].dias,
					   array[i].archive);
        }
        retorno=0;
        stuff_sleep(5);
    }
    return retorno;
}

int publicidad_info_getdiasMedia(ePublicidad arrayEmployee[], int size)
{
	int i;

	int employeesUpperMediadias = 0;
	float diasProm = 0;
    int retorno = -1;
    float diasAcum = 0;
    int contdias = 0;

    if(arrayEmployee!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(arrayEmployee[i].isEmpty==0)
            {
            	diasAcum = diasAcum + arrayEmployee[i].dias;
            	contdias++;
            }
        }

        diasProm = diasAcum / contdias;

        for(i=0;i<size;i++)
        {
        	if(arrayEmployee[i].dias > diasProm)
        	{
        		employeesUpperMediadias++;
        	}
        }
        printf("\n\t\tEl salario promedio es de: %f con un total de %i empleados que superan la media", diasProm, employeesUpperMediadias);
        retorno = 0;
    }
    return retorno;
}

int publicidad_sortByCuit(ePublicidad arrayPublicidad[], int size)
{
    int retorno=-1;
    int i, j;

    ePublicidad arrayAux;

    char archiveAux[TEXT_SIZE];
    int idPantallaAux;
    int idPublicidadAux;
    int isemptyAux;
    int cuitAux;
    int diasAux;
    int isSorted = 0;

	if(arrayPublicidad!= NULL && size>=0)
	{
		while (isSorted != 1)
		{
			isSorted = 1;
			for(i=0;i<size-1;i++)
			{
				j = i + 1;

				arrayAux = arrayPublicidad[i];

				if(arrayPublicidad[i].cuit < arrayPublicidad[j].cuit)
				{

					arrayPublicidad[i] = arrayPublicidad[j];
					arrayPublicidad[j] = arrayAux;
					isSorted = 0;
				}

			}
		}
	}

	return retorno;
}


int publicidad_getClient_mayorDeudor(ePublicidad arrayPublicidad[],ePantalla arrayPantalla[], int sizePubli, int sizePant)
{
	int i,j, auxCuit;
	int retorno = -1;
	int cuitDeudor = 0;
	float cuitDeudaTotal = 0;

	publicidad_sortByCuit(arrayPublicidad, sizePubli);

	for (i = 0; i < sizePubli; i++)
    {
		if(arrayPublicidad[i].cuit != auxCuit)
		{
			auxCuit = arrayPublicidad[i].cuit;
			for (j = 0; j < sizePubli; j++)
			{

			}
		}

    }
	return retorno;
}

