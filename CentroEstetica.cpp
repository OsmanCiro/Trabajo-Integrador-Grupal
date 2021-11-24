#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void Espacios()
{
	
}
void Recepcion()
{
	
}
void Administracion()
{
	
}

/* Estas funciones solo estan para que el programa no de errores
una vez que incorporemos las librerias eliminaremos las funciones */

main()
{
	int op;
	
	do
	{
		system("cls");
		printf("CENTRO DE ESTETICA\n");
		printf("====================\n");
		printf("\n1.- Modulo Espacios");
		printf("\n2.- Modulo Recepcion");
		printf("\n3.- Modulo Admnistracion");
		printf("\n\n4.- Cerrar aplicacion");
		printf("\n\nIngrese una Opcion: ");
		scanf("%d",&op);
		system("cls");
		switch(op)
		{
			case 1:
				Espacios();
				break;
			case 2:
				Recepcion();
				break;
			case 3:
				Administracion();
				break;
			case 4:
				printf("\t****************************************\n");
				printf("\t* Gracias Por Utilizar Nuestro Sistema *\n");
				printf("\t****************************************\n\n");
				break;
				default:
					printf("\n\t**ERROR**\n\n(Debe ingresar una opcion valida)");
		}
		getch();
	}
	while(op!=4);
}
