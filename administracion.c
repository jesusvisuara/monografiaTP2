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

struct veterinarios				//Estructura para datos del veterinario
{
	char ApellidoyNombre[60];
	int Matricula;
	int Dni;
	int Telefono;
	char Contrasenia[20];
	int CantidaddePacientes;
};

struct usuario					//Estructura para datos del usuario
{
	char Usuario[10];
	char Contrasenia[10];
	char AyN[60];
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

void registrarVeterinario(veterinarios vet);

void registrarUsuario(usuario reg);

void verAtenciones(turnos turn);

main()
{
	int opc;
	
	veterinarios vet;
	usuario reg;
	mascota masc;
	turnos turn;
	
	while (opc != 5)
	{
		system("CLS");
		
		printf("1) Registrar veterinario\n");
		printf("2) Registrar usuario asistente\n");
		printf("3) Atenciones por veterinarios\n");
		printf("4)  // Fuera de servicio -- Ranking de veterinarios por atenciones\n");
		printf("5) Salir\n");
		
		printf("Ingrese una opcion: ");
		scanf("%d", &opc);
		
		system("CLS");
		
		switch (opc)
		{
			case 1:
				registrarVeterinario(vet);
				break;
			
			case 2:
				registrarUsuario(reg);
				break;
			
			case 3:
				verAtenciones(turn);
				break;
		}
	}
}

void registrarVeterinario (veterinarios vet)
{
	FILE *puntero1;
	
	puntero1 = fopen("Veterinarios.dat","a+b");  //Veterinarios.dat guarda los veterinarios registrados

	printf("Ingrese los siguientes datos: ");
	printf("\nApellido y nombre: ");
	_flushall();
	gets(vet.ApellidoyNombre);
	printf("\nDNI: ");
	scanf("%d",&vet.Dni);
	printf("\nMatricula: ");
	scanf("%d",&vet.Matricula);
	printf("\nTelefono: ");
	scanf("%d", &vet.Telefono);
	
	cadena contrasenia;
	
	printf("Ingrese la contraseña de su cuenta: ");
	_flushall();
	gets(contrasenia);
	
	strcpy(contrasenia,vet.Contrasenia);
	
	fwrite(&vet,sizeof(veterinarios),1,puntero1);
	fclose(puntero1);
	
	system("PAUSE");
}

void registrarUsuario (usuario reg)
{
	FILE *puntero2;
	
	puntero2 = fopen("Usuarios.dat","a+b");
	
	printf("Ingrese el usuario: ");
	_flushall();
	gets(reg.Usuario);
	printf("Ingrese la contraseña: ");
	_flushall();
	gets(reg.Contrasenia);
	printf("Ingrese el apellido y nombre: ");
	_flushall();
	gets(reg.AyN);
	
	fwrite(&reg, sizeof(usuario), 1, puntero2);
	
	fclose(puntero2);
	
	system("PAUSE");
}

void verAtenciones (turnos turn)
{
	FILE *puntero3;
	
	puntero3 = fopen("Turnos.dat","r+b");
	if (puntero3 == NULL)
	{
		printf("Error.");
		exit(0);
	}
	else
	{
		int busqueda;
		
		printf("Ingrese la matricula del veterinario: ");
		scanf("%d", &busqueda);
		
		fread(&turn, sizeof(turnos), 1, puntero3);
		while(!feof(puntero3))
		{
			if (busqueda == turn.Matricula)
			{
				printf("\n\nFecha del turno:\n\nDia: %d\n", turn.fec.dia);
				printf("Mes: %d\n", turn.fec.mes);
				printf("Anio: %d\n\n", turn.fec.anio);
				
				printf("DNI del dueño: %d\n", turn.DNI);
				printf("Detalle de atencion: ");
				puts(turn.DetalledeAtencion);
			}
			
			fread(&turn, sizeof(turnos), 1, puntero3);
		}
		
		fclose(puntero3);
	}
		
	
	system("PAUSE");
}


