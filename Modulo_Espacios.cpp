#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


main()
{
	int op;
	
	do
	{
		system("cls");
		printf("Modulo Espacios\n");
		printf("=================\n");
		printf("\n1.- Iniciar Sesion");
		printf("\n2.- Visualizar Lista de Espera de Turnos (informe)");
		printf("\n3.- Registrar Evolucion del tratamiento");
		printf("\n\n4.- Cerrar la aplicacion");
		printf("\n\nIngrese una opcion: ");
		scanf("%d",&op);
		system("cls");
		switch(op)
		{
			case 1:
				printf("\tIniciar Sesion\n");
				printf("\t==============\n\n");
				
				break;
			case 2:
				printf("\tTurnos en Espera\n");
				printf("\t==============\n\n");
				
				break;
			case 3:
				printf("\tRegistrar Evolucion\n");
				printf("\t==============\n\n");
				
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
