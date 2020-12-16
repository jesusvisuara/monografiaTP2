#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char cadena[20];

struct fecha
{
	int dia;
	int mes;
	int anio;
};

struct usuario					//Estructura para datos del usuario
{
	char Usuario[10];
	char Contrasenia[10];
	char AyN[60];
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

struct turnos 
{
	int Matricula;
	fecha fec;
	int DNI;
	char DetalledeAtencion[380];
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

void inicioSesion (veterinarios vet);

void visualizarTurnos (turnos turn);

void registrarEvolucion (turnos turn, mascota masc);

main()
{
	usuario user;
	veterinarios vet;
	turnos turn;
	mascota masc;
	
	int opc;
	
	while (opc != 4)
	{
		system("CLS");
		
		printf("1.- Iniciar Sesion.\n");
		printf("2.- Visualizar Lista de Espera de Turnos (informe).\n");
		printf("3.- Registrar Evolucion de la mascota.\n");
		printf("\n4.- Salir.");
		
		printf("\n\nIngrese una opcion: ");
		scanf("%d", &opc);
		
		system("CLS");
		
		switch(opc)
		{
			case 1:
				inicioSesion(vet);
				break;
			
			case 2:
				visualizarTurnos(turn);
				break;
				
			case 3:
				//registrarEvolucion(turn, masc);
				break;
		}
	}
}

void inicioSesion (veterinarios vet)
{
	FILE *puntero1;
	
	puntero1 = fopen("Veterinarios.dat","r+b");
	
	if (puntero1 == NULL)
	{
		printf("Error.");
		exit(0);
	}
	
	int matricula;
	cadena contrasenia;
	
	printf("Ingrese la matricula: ");
	scanf("%d", &matricula);
	
	printf("Ingrese la contraseña: ");
	_flushall();
	gets(contrasenia);
	
	fread(&vet, sizeof(veterinarios), 1, puntero1);
	while(!feof(puntero1))
	{
		if (matricula == vet.Matricula)                 //Compara el usuario que se ingreso con el usuario que esta en el archivo
		{
			if (strcmp(vet.Contrasenia, contrasenia) == 0)
			{
				printf("\nSesion iniciada");
				printf("\nApellido y Nombre: ");
				puts(vet.ApellidoyNombre);
			}
		}
		
		fread(&vet, sizeof(veterinarios), 1, puntero1);
	}
	
	fclose(puntero1);
	
	system("PAUSE");
}

void visualizarTurnos (turnos turn)
{
	printf("Visualizacion de los turnos: \n");
	
	FILE *puntero2;
	
	puntero2 = fopen("Turnos.dat","r+b");
	
	if (puntero2 == NULL)
	{
		printf("Error.");
		exit(0);
	}
	
	fread(&turn, sizeof(turnos), 1, puntero2);
	while(!feof(puntero2))
	{
		printf("\n\nMatricula del veterinario: %d\n", turn.Matricula);
		
		printf("La fecha de atencion es:\n");
		printf("\nDia: %d", turn.fec.dia);
		printf("\nMes: %d", turn.fec.mes);
		printf("\nAnio: %d", turn.fec.anio);
		
		printf("\nDNI del dueño: %d", turn.DNI);
		
		printf("\nDetalle de la atencion: ");
		puts(turn.DetalledeAtencion);
		
		fread(&turn, sizeof(turnos), 1, puntero2);
	}
	
	fclose(puntero2);
	
	system("PAUSE");
}

void registrarEvolucion (turnos turn)
{
	FILE *puntero3;
	
	puntero3 = fopen("Mascotas.dat","r+b");
	
	if (puntero3 == NULL)
	{
		printf("Error.");
		exit(0);
	}
	
	int dni;
	cadena evolucion;
	
	printf("Ingrese el DNI el dueño de la mascota: ");
	scanf("%d", &dni);
	
	
	fread(&turn, sizeof(turnos), 1, puntero3);
	while(!feof(puntero3))
	{
		if (dni == turn.DNI)
		{
			printf("Ingrese un nuevo estado de la evolucion: ");
			gets(evolucion);
			
			//fseek(puntero3, -sizeof(turnos), 0);
			
			strcpy(evolucion,turn.DetalledeAtencion);
			
			fwrite(&turn, sizeof(turnos), 1, puntero3);
		}
		
		fread(&turn, sizeof(turnos), 1, puntero3);
	}
	
	fclose(puntero3);
	
	system("PAUSE");
}

