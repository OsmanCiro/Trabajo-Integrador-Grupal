struct Fecha
{
	int dd,mm,aa;
};
struct Usuarios
{
	char Usua[10], Cont[10], ApeNom[10];
};
struct Profesionales
{
	char ApeNom[60],Tel[25];
	int IDProf,DNI;
};
struct Clientes
{
	char ApeNom[60], Dom[60], Loc[60], Tel[25], Trat[380];
	int DNICliente;
	Fecha FecNac;
	float Peso;
};
struct Turnos
{
	int IDProf, DNICliente;
	Fecha Fec;
	char Detalle[381];
};
