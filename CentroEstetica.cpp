#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "estructuras.h"
#include "moduloespacios.h"
#include "modulorecepcionista.h"
#include "moduloadministracion.h"

main()
{
	int op;
	FILE *arch,*arch1,*arch2,*arch3;
	
	arch=fopen("Recepcionista.dat","a+b");
	arch1=fopen("Profesionales.dat","a+b");
	arch2=fopen("Clientes.dat","a+b");
	arch3=fopen("Turnos.dat","a+b");
	fclose(arch);
	fclose(arch1);
	fclose(arch2);
	fclose(arch3);
	
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
