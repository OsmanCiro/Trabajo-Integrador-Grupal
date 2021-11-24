void Espacios()
{
	int op;
	do
	{
		system("cls");
		printf("MODULO ESPACIOS\n");
		printf("=================\n");
		printf("\n1.- Iniciar Sesion");
		printf("\n2.- Visualizar Lista de Espera de Turnos (informe)");
		printf("\n3.- Registrar Evolucion del Tratamiento");
		printf("\n\n4.- Cerrar aplicaion");
		printf("\n\nIngrese una opcion: ");
		scanf("%d",&op);
		system("cls");
		switch(op)
		{
			case 1:
				printf("\tInicio de Secion\n");
				printf("\t==================\n\n");
				
				break;
			case 2:
				printf("\tLista de Espara (informe)\n");
				printf("\t===========================\n\n");
				
				break;
			case 3:
				printf("\tRegistro de Tratamiento\n");
				printf("\t=========================\n\n");
				
				break;
			case 4:
				printf("\t****************************************\n");
				printf("\t* Gracias por utilizar nuestro sistema *\n");
				printf("\t****************************************\n");
				break;
			default:
				printf("\t**ERROR**\n\nDebe ingresar una opcion valida");
				getch();
		}
	}
	while (op!=4);
}



















