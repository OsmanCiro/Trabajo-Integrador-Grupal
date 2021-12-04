#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "estructuras.h"

int IniciarSesion(Usuarios us);
void Listado(Clientes cli, Turnos tur);
void Tratamiento(Clientes cli, Turnos tur);

main()
{
	int op,x;
	Usuarios us;
	Profesionales prof;
	Clientes cli;
	Turnos tur;
	
	do
	{
		system("cls");
		printf("\t*********************************\n");
		printf("\t* M O D U L O   E S P A C I O S *\n");
		printf("\t*********************************\n");
		printf("\n\n\n1.- Iniciar Sesion");
		printf("\n\n\n2.- Visualizar Lista de Espera de Turnos (informe)");
		printf("\n\n\n3.- Registrar Evolucion del Tratamiento");
		printf("\n\n\n4.- Cerrar aplicaion");
		printf("\n\n\n\nIngrese una opcion: ");
		scanf("%d",&op);
		system("cls");
		switch(op)
		{
			case 1:
				printf("\tInicio de Secion\n");
				printf("\t==================\n\n");
				x=IniciarSesion(us);
				break;
			case 2:
				printf("\tLista de Espara (informe)\n");
				printf("\t===========================\n\n");
				if(x==1)
				{
					Listado(cli,tur);
				}
				else
				{
					printf("\n\n\t**DEBE INICIAR SESION**");
				}
				break;
			case 3:
				printf("\tRegistro de Tratamiento\n");
				printf("\t=========================\n\n");
				if(x==1)
				{
					Tratamiento(cli,tur);
				}
				else
				{
					printf("\n\n\t**DEBE INICIAR SESION**");
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

int IniciarSesion(Usuarios us)
{
	FILE *arch;
	int ban=0,u=0,c=0,a=0;
	char user[10], cont[10];
	
	arch=fopen("Profesionales.dat","rb");
	if(arch==NULL)
	{
		printf("Debe solicitar en administracion un ususario y una contrasenia");
	}
	else
	{
		printf("Usuario: ");
		_flushall();
		gets(user);
		fread(&us,sizeof(Usuarios),1,arch);
		while(!feof(arch) && ban==0)
		{
			if(strcmp(user,us.Usua)==0)
			{
				u=1;
				printf("Contrasenia: ");
				_flushall();
				gets(cont);
				if(strcmp(cont,us.Cont)==0)
				{
					c=1;
					ban=1;
				}
			}
			fread(&us,sizeof(Usuarios),1,arch);
		}
		if(ban==0)
		{
			printf("\n\nDebe solicitar en administracion un ususario y una contrasenia");
		}
		else
		{
			if(u==0)
			{
				printf("\n\nUsuario incorrecto");
			}
			else
			{
				if(c==0)
				{
					printf("\n\nContrasenia incorrecta");
				}
			}
		}
		fclose(arch);
		return ban;
	}
}

void Listado(Clientes cli, Turnos tur)
{
	FILE *arch2, *arch3;
	int d,m,a,ed;
	
	arch2=fopen("Clientes.dat","rb");
	arch3=fopen("Turnos.dat","rb");
	if(arch3==NULL)
	{
		printf("No hay clientes en espera");
	}
	else
	{
		printf("Ingrese la fecha\n\n");
		printf("Dia: ");
		scanf("%d",&d);
		printf("Mes: ");
		scanf("%d",&m);
		printf("Anio: ");
		scanf("%d",&a);
		system("cls");
		fread(&tur,sizeof(Turnos),1,arch3);
		while(!feof(arch3))
		{
			if(d==tur.Fec.dd && m==tur.Fec.mm && a==tur.Fec.aa)
			{
				fread(&cli,sizeof(Clientes),1,arch2);
				while(!feof(arch2))
				{
					if(tur.DNICliente==cli.DNICliente)
					{
						printf("Apellido y nombre: %s",cli.ApeNom);
						printf("\nD.N.I: %d",cli.DNICliente);
						printf("\nDomicilio: %s - %s",cli.Dom,cli.Loc);
						ed=a-tur.Fec.aa;
						printf("\nEdad: %d",ed);
						printf("\nPeso: %.2f",cli.Peso);
						printf("\nDetalle: %s\n\\n",tur.Detalle);
					}
					fread(&cli,sizeof(Clientes),1,arch2);
				}
			}
			fread(&tur,sizeof(Turnos),1,arch3);
		}
		fclose(arch2);
		fclose(arch3);
	}
}

void Tratamiento(Clientes cli, Turnos tur)
{
	FILE *arch2, *arch3, *aux;
	char NomCli[60], NomProf[60];
	int d,m,a,dni,ban=0;
	
	arch2=fopen("Clientes,dat","r+b");
	printf("Apellido y nombre del cliente: ");
	_flushall();
	gets(NomCli);
	fread(&cli,sizeof(Clientes),1,arch2);
	while(!feof(arch2) && ban==0)
	{
		if(strcmp(NomCli,cli.ApeNom)==0)
		{
			ban=1;
			dni=cli.DNICliente;
			printf("Fecha\n");
			printf("Dia: ");
			scanf("%d",&d);
			printf("\nMes: ");
			scanf("%d",&m);
			printf("\nAnio: ");
			scanf("%d",&a);
			printf("\n\nNombre del Profesinal: ");
			_flushall();
			gets(NomProf);
			printf("\nTratamiento: ");
			_flushall();
			gets(cli.Trat);
			fseek(arch2,-sizeof(Clientes),SEEK_CUR);
			fwrite(&cli,sizeof(Clientes),1,arch2);
		}
		fread(&cli,sizeof(Clientes),1,arch2);
	}
	if(ban==0)
	{
		printf("\n\nEl cliente no existe");
		fclose(arch2);
		return;
	}
	arch3=fopen("Turnos.dat","r+b");
	aux=fopen("auxiliar.dat","w+b");
	fread(&tur,sizeof(Turnos),1,arch3);
	while(!feof(arch3))
	{
		if(dni!=tur.DNICliente)
		{
			fwrite(&tur,sizeof(Turnos),1,aux);
		}
		fread(&tur,sizeof(Turnos),1,arch3);
	}
	fclose(arch3);
	fclose(aux);
	remove("Turnos.dat");
	rename("auxiliar.dat","Turnos.dat");
}





































