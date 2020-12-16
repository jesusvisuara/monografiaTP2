#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct usuario					//Estructura para datos del usuario
{
	char Usuario[10];
	char Contrasenia[10];
	char AyN[60];
};

struct fecha
{
	int dia;
	int mes;
	int anio;
};

struct mascota
{
	char ApellidoyNombre[60];
	char Domicilio[60];
	int DNI;
	char Localidad[60]; 
	fecha fec;
	float Peso;
	int Telefono;
};

struct turnos 
{
	int Matricula;
	fecha fec;
	int DNI;
	char DetalledeAtencion[380];
};

struct veterinarios				//Estructura para datos del veterinario
{
	char ApellidoyNombre[60];
	int Matricula;
	int Dni;
	int Telefono;
	char Contrasenia[20];
	int CantidaddePacientes;
};

void iniciarSesion(usuario user);

void registrarMascota(mascota masc);

void registrarTurno(turnos turn);

void listarAtenciones(turnos turn, veterinarios vet);

main()
{
	usuario user;		//user se usa para ingresar la cuenta
	usuario reg;
	mascota masc;
	turnos turn;
	veterinarios vet;
	
	int opc;

	while (opc != 5)
	{
		system("CLS");
		
		printf("1) Iniciar sesion\n");
		printf("2) Registrar mascota\n");
		printf("3) Registrar Turno\n");
		printf("4) Listado de atenciones por veterinario y fecha\n");
		printf("5) Salir\n");
		
		printf("Ingrese una opcion: ");
		scanf("%d", &opc);
		
		system("CLS");
		
		switch (opc)
		{
			case 1:
				//iniciarSesion(user);
				break;
			
			case 2:
				registrarMascota(masc);
				break;
			
			case 3:
				registrarTurno(turn);
				break;
			
			case 4:
				listarAtenciones(turn, vet);
				break;
		}
	}
	
	
	
}

void iniciarSesion(usuario user, usuario reg)
{
	FILE *puntero1;
	
	puntero1 = fopen("Usuarios.dat","r+b");
	
	if (puntero1 == NULL)
	{
		printf("Error.");
		exit(0);
	}
	
	printf("Ingrese el usuario: ");
	_flushall();
	gets(user.Usuario);
	
	printf("Ingrese la contraseña: ");
	_flushall();
	gets(user.Contrasenia);
	
	printf("Ingrese el apellido y nombre: ");
	_flushall();
	gets(user.AyN);
	
	fread(&user, sizeof(usuario), 1, puntero1);
	while(!feof(puntero1))
	{
		if (strcmp(user.Usuario, reg.Usuario) == 0)                 //Compara el usuario que se ingreso con el usuario que esta en el archivo
		{
			if (strcmp(user.Contrasenia, reg.Contrasenia) == 0)
			{
				printf("\nSesion iniciada");
				printf("\n\nUsuario: ");
				puts(user.Usuario);
				printf("\nApellido y Nombre: ");
				puts(user.AyN);
			}
		}
		
		fread(&user, sizeof(usuario), 1, puntero1);
	}
	
	system("PAUSE");
}

void registrarMascota(mascota masc)
{
	FILE *puntero2;
	
	puntero2 = fopen("Mascotas.dat","a+b");
	
	if (puntero2 == NULL)
	{
		printf("Error.");
		exit(0);
	}
	
	printf("Ingrese apellido y nombre del dueño: ");
	_flushall();
	gets(masc.ApellidoyNombre);
	
	printf("Ingrese el domicilio: ");
	_flushall();
	gets(masc.Domicilio);
	
	printf("Ingrese el dni del dueño: ");
	scanf("%d", &masc.DNI);
	
	printf("Ingrese la localidad: ");
	_flushall();
	gets(masc.Localidad);
	
	printf("Ingrese la fecha de nacimiento:\n");
	printf("\nDia: ");
	scanf("%d", &masc.fec.dia);
	
	printf("\nMes: ");
	scanf("%d", &masc.fec.mes);
	
	printf("\nAnio: ");
	scanf("%d", &masc.fec.anio);
	
	printf("Ingrese el peso de la mascota: ");
	scanf("%f", &masc.Peso);
	
	printf("Ingrese el telefono: ");
	scanf("%d", &masc.Telefono);
	
	fwrite(&masc, sizeof(mascota), 1, puntero2);
	
	fclose(puntero2);
	
	system("PAUSE");
}

void registrarTurno(turnos turn)
{
	FILE *puntero3;
	
	puntero3 = fopen("Turnos.dat","a+b");
	
	if (puntero3 == NULL)
	{
		printf("Error.");
		exit(0);
	}
	
	printf("Ingrese la matricula del veterinario: ");
	scanf("%d", &turn.Matricula);
	
	printf("Ingrese la fecha en la que se realizara el turno:\n");
	printf("\nDia: ");
	scanf("%d", &turn.fec.dia);
	
	printf("\nMes: ");
	scanf("%d", &turn.fec.mes);
	
	printf("\nAnio: ");
	scanf("%d", &turn.fec.anio);
	
	printf("Ingrese el DNI del dueño: ");
	scanf("%d", &turn.DNI);
	
	printf("Ingrese el detalle de atencion: ");
	_flushall();
	gets(turn.DetalledeAtencion);
	
	fwrite(&turn, sizeof(turnos), 1, puntero3);
	
	fclose(puntero3);
	
	system("PAUSE");
}

void listarAtenciones(turnos turn, veterinarios vet)
{
	FILE *puntero4;
	FILE *puntero5;
	
	puntero4 = fopen("Turnos.dat","r+b");
	puntero5 = fopen("Veterinarios.dat","r+b");
	
	if (puntero4 == NULL)
	{
		printf("Error.");
		exit(0);
	}
	
	if (puntero5 == NULL)
	{
		printf("Error.");
		exit(0);
	}
	
	fread(&turn, sizeof(turnos), 1, puntero4);
	fread(&vet, sizeof(veterinarios), 1, puntero5);
	
	while(!feof(puntero4) and !feof(puntero5))
	{
		printf("Apellido y Nombre del veterinario: ");
		puts(vet.ApellidoyNombre);
		
		printf("Matricula del veterinario: %d\n", turn.Matricula);
		
		printf("La fecha de atencion es:\n");
		printf("\nDia: %d", turn.fec.dia);
		printf("\nMes: %d", turn.fec.mes);
		printf("\nAnio: %d", turn.fec.anio);
		
		printf("\nDNI del dueño: %d", turn.DNI);
		
		printf("\nDetalle de la atencion: ");
		puts(turn.DetalledeAtencion);
		
		fread(&turn, sizeof(turnos), 1, puntero4);
		fread(&vet, sizeof(veterinarios), 1, puntero5);
	}
	
	
	fclose(puntero4);
	fclose(puntero5);
	
	system("PAUSE");
}

