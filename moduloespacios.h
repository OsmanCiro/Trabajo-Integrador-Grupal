void Espacios()
{
	int op,x;
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
				x=IniciarSesion();
				break;
			case 2:
				printf("\tLista de Espara (informe)\n");
				printf("\t===========================\n\n");
				if(x==1)
				{
				//	Lista();
				}
				else
				{
					printf("Debe iniciar sesion");
				}
				break;
			case 3:
				printf("\tRegistro de Tratamiento\n");
				printf("\t=========================\n\n");
				if(x==1)
				{
				//	Tratamiento();
				}
				else
				{
					printf("Debe iniciar sesion");
				}
				break;
			case 4:
				printf("\t****************************************\n");
				printf("\t* Gracias por utilizar nuestro sistema *\n");
				printf("\t****************************************\n");
				break;
			default:
				printf("\t**ERROR**\n\nDebe ingresar una opcion valida");
		}
		getch();
	}
	while (op!=4);
}
int IniciarSesion()
{
	int ban=0,u=0,c=0;
	char user[10], cont[10];
	FILE *arch;
	arch=fopen("Profesionales.dat","rb");
	
	if(arch==NULL)
	{
		printf("Debe solicitar en administracion un ususario y una contraseña");
	}
	else
	{
		printf("Usuario: ");
		_flushall();
		gets(user);
		fread(&reg,sizeof(Registro),1,arch);
		while(!feof(arch) && ban==0)
		{
			if(strcmp(user,reg.user)==0)
			{
				u=1;
				printf("Contraseña: ");
				_flushall();
				gets(cont);
				if(strcmp(cont,reg.cont)==0)
				{
					ban=1;
					c=1;
				}
			}
		}
	}
	if(u==0)
	{
		printf("Usuario incorrecto");
	}
	if(c==0)
	{
		printf("Contraseña incorrecta");
	}
	getch();
	return ban;
}



















