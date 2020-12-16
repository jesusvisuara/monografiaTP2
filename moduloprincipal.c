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

void administracion();

	void registrarVeterinario(veterinarios vet);

	void registrarUsuario(usuario reg);
	
	void verAtenciones(turnos turn);
	
	void rankingVeterinarios (veterinarios vet);

void asistente();

	void iniciarSesion(usuario user);

	void registrarMascota(mascota masc);
	
	void registrarTurno(turnos turn, veterinarios vet);
	
	void listarAtenciones(turnos turn);

void consultorio();

	void inicioSesion (veterinarios vet);
	
	void visualizarTurnos (turnos turn);
	
	void registrarEvolucion(mascota masc, turnos turn);



main()
{
	int opc;
	
	while (opc != 4)
	{
		system("CLS");
		
		printf("--Menu de seleccion de modulos--\n\n");
		printf("1.- Modulo de Administracion.\n");
		printf("2.- Modulo de Asistente del veterinario.\n");
		printf("3.- Modulo de Consultorio\n\n");
		printf("4.- Salir.\n\n");
		printf("Seleccione una opcion: ");
		scanf("%d", &opc);
		
		system("CLS");
		
		switch (opc)
		{
			case 1:
				administracion();
				break;
			
			case 2:
				asistente();
				break;
			
			case 3:
				consultorio();
				break;
		}
	}
}

void administracion()
{
	int opc;
	
	veterinarios vet;
	usuario reg;
	mascota masc;
	turnos turn;
	
	while (opc != 5)
	{
		system("CLS");
		
		printf("--Modulo Administracion--\n\n");
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
			
			case 4:
				rankingVeterinarios(vet);
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
	
	printf("Ingrese la contraseña de su cuenta: ");
	_flushall();
	gets(vet.Contrasenia);
	
	fwrite(&vet,sizeof(veterinarios),1,puntero1);
	printf("Se registro correctamente el usuario.\n");

	fclose(puntero1);
	
	system("PAUSE");
}

void registrarUsuario (usuario reg)
{
	// Apertura del archivo 
	FILE *puntero2;
	
	puntero2 = fopen("Usuarios.dat","a+b");
	if (puntero2 == NULL)
	{
		printf("Error.");
		exit(0);
	}
	
	printf("Condiciones para registrar un usuario:\n\n");
	printf("*1*El usuario debe tener 6 caracteres como minimo y 10 como maximo\n");
	printf("////*2*El usuario no debe estar registrado anteriormente\n");
	printf("*3*El usuario debe comenzar con una letra minuscula\n");
	printf("*4*El usuario debe tener al menos 2 letras mayusculas\n");
	printf("*5*El usuario debe tener como maximo 3 digitos\n\n");
	printf("Ingrese el nombre de usuario: ");
	_flushall();
	gets(reg.Usuario);
	
	int longitud = strlen(reg.Usuario);
	int i, contMay = 0, contDig = 0;
	
	if (longitud < 6 or longitud > 10)
	{
		printf("El usuario no cumple con la condicion 1.\n");
	}
	else
	{
		if (reg.Usuario[0] < 97 or reg.Usuario[0] > 122)
		{
			printf("El usuario no cumple con la condicion 3.\n");
		}
		else
		{
			// Cuenta la cantidad de mayusculas
			for(i=0; i<longitud; i++)
			{
				if (reg.Usuario[i] > 65 and reg.Usuario[i] < 90)
				{
					contMay = contMay + 1;
				}
			}
			
			if (contMay < 2)
			{
				printf("El usuario no cumple con la condicion 4.\n");
			}
			else
			{
				// Cuenta la cantidad de mayusculas
				for(i=0; i<longitud; i++)
				{
					if (reg.Usuario[i] > 48 and reg.Usuario[i] < 57)
					{
						contDig = contDig + 1;
					}
				}
				
				if (contDig < 3)
				{
					printf("El usuario no cumple con la condicion 5.\n");
				}
				else
				{
					// Ingreso de la contraseña
					printf("Condiciones para registrar una contraseña:\n\n");
					printf("*1*La contraseña debe tener al menos una letra mayuscula, una letra minuscula y un numero\n");
					printf("*2*No puede contener ningun caracter de puntuacion, ni acentos, ni espacios. Solo caracteres alfanumericos\n");
					printf("*3*Debe tener entre 6 y 32 caracteres\n");
					printf("*4*No debe tener mas de 3 caracteres numericos consecutivos\n");
					
					printf("*5*No debe tener 2 caracteres consecutivos que refieran a letras alfabéticamente consecutivas (ascendentemente).\n");
					printf("Este criterio es válido tanto para letras mayúsculas,minúsculas o combinación de ambas.\n\n");
					
					printf("Ingrese el nombre de usuario: ");
					
					printf("Ingrese la contraseña: ");
					_flushall();
					gets(reg.Contrasenia);
					
					int longitudContra = strlen(reg.Contrasenia);
					bool band1, band2, band3, band4, band5;
					
					for (i=0;i<longitudContra;i++)
					{
						if (reg.Contrasenia[i] >= 48 and reg.Contrasenia[i] <= 57)
						{
							band1 = true;
						}
						
						if (reg.Contrasenia[i] >= 65 and reg.Contrasenia[i] <= 90)
						{
							band2 = true;
						}
						
						if (reg.Contrasenia[i] >= 97 and reg.Contrasenia[i] <= 122)
						{
							band3 = true;
						}
					}
					
					if (band1 != true or band2 != true or band3 != true)
					{
						printf("El usuario no cumple con la condicion 1.\n");
					}
					else
					{
						for(i=0;i<longitudContra;i++)
						{
							if ((reg.Contrasenia[i] >= 48 and reg.Contrasenia[i] <= 57) or (reg.Contrasenia[i] >= 65 and reg.Contrasenia[i] <= 90) or (reg.Contrasenia[i] >= 97 and reg.Contrasenia[i] <= 122))
							{
								band4 = true;
							}
							
						}
						
						if (band4 == false)
						{
							printf("El usuario no cumple con la condicion 2.\n");
						}
						else
						{
							if (longitudContra < 6 or longitudContra > 32)
							{
								printf("El usuario no cumple con la condicion 3.\n");
							}
							else
							{
								int contNum = 0;
								
								for(i=0;i<longitudContra;i++)
								{
									if (reg.Contrasenia[i] >= 48 and reg.Contrasenia[i] <= 57)
									{
										contNum = contNum + 1;
									}
								}
								
								if (contNum > 3)
								{
									printf("El usuario no cumple con la condicion 4.\n");
								}
								else
								{
									/*
									
									for(i=0;i<longitudContra-1;i++)
									{
										if (reg.Contrasenia[i+1] == reg.Contrasenia[i]+1)
										{
											band5 = true;
										}
										else
										{
											band5 = false;
										}
									}
									
									*/
									
									//
									band5 = false;
									//
									
									
									if (band5 == true)
									{
										printf("El usuario no cumple con la condicion 5.\n");
									}
									else
									{
										printf("Ingrese el apellido y nombre: ");
										_flushall();
										gets(reg.AyN);
										
										fwrite(&reg, sizeof(usuario), 1, puntero2);
									}
								}
							}
						}
					}
					
				}
			}
		}
	}
	
	
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

void rankingVeterinarios (veterinarios vet)
{
	printf("Se visualizaran la cantidad de turnos de los veterinarios:\n\n");
	
	FILE *puntero4;
	
	puntero4 = fopen("Veterinarios.dat","r+b");
	
	fread(&vet, sizeof(veterinarios), 1, puntero4);
	while (!feof(puntero4))
	{
		printf("\n\nNombre del veterinario: ");
		puts(vet.ApellidoyNombre);
		
		printf("Cantidad de turnos: %d\n", vet.CantidaddePacientes);
		
		fread(&vet, sizeof(veterinarios), 1, puntero4);
	}
	
	fclose(puntero4);
	
	system("PAUSE");
	
	int N, i;
	
	puntero4 = fopen("Veterinarios.dat","r+b");
	
	fread(&vet, sizeof(veterinarios), 1, puntero4);
	while(!feof(puntero4))
	{
		N = N + 1;
		
		fread(&vet, sizeof(veterinarios), 1, puntero4);
	}
	
	fclose(puntero4);
	
	/*
	
	puntero4 = fopen("Veterinarios.dat","r+b");
	
	fread(&vet, sizeof(veterinarios), 1, puntero4);
	
	int aux, pos;
	
	
	for(i=0;i<N;i++)  Este es el metodo de insercion, no funciona porque no se tiene la cantidad de elementos del vector y no se puede declarar como variable;
	{
		aux=V[i];
		pos = i;
		
		while ((pos > 0) and (V[pos-1] > aux))
		{
			V[pos]=V[pos-1];
			pos--;
		}
		V[pos] = aux;
	}
	
	*/
	
}


void asistente()
{
	usuario user;		//user se usa para ingresar la cuenta
	mascota masc;
	turnos turn;
	veterinarios vet;
	
	int opc;

	while (opc != 5)
	{
		system("CLS");
		
		printf("--Modulo del Asistente--\n\n");
		printf("1) Iniciar sesion\n");
		printf("2) Registrar mascota\n");    //Se tiene que realizar la opcion 2 para hacer la 3
		printf("3) Registrar Turno\n");
		printf("4) Listado de atenciones por veterinario y fecha\n");
		printf("5) Salir\n");
		
		printf("Ingrese una opcion: ");
		scanf("%d", &opc);
		
		system("CLS");
		
		switch (opc)
		{
			case 1:
				iniciarSesion(user);
				break;
			
			case 2:
				registrarMascota(masc);
				break;
			
			case 3:
				registrarTurno(turn, vet);
				break;
			
			case 4:
				listarAtenciones(turn);
				break;
		}
	}
}

void iniciarSesion(usuario user)
{
	bool encontrado = false;
	
	cadena nombreUsuario;
	cadena contrasenia;
	
	FILE *puntero1;
	
	puntero1 = fopen("Usuarios.dat","r+b");
	
	if (puntero1 == NULL)
	{
		printf("Error.");
		exit(0);
	}
	
	printf("Ingrese el usuario: ");
	_flushall();
	gets(nombreUsuario);
	
	printf("Ingrese la contraseña: ");
	_flushall();
	gets(contrasenia);
	
	fread(&user, sizeof(usuario), 1, puntero1);
	while(!feof(puntero1))
	{
		if(strcmp(user.Contrasenia, contrasenia) == 0)
		{
			if (strcmp(user.Usuario, nombreUsuario) == 0) 
			{
				encontrado = true;
				
				printf("\nSesion iniciada");
				printf("\n\nUsuario: ");
				puts(user.Usuario);
				printf("\nApellido y Nombre: ");
				puts(user.AyN);
			}
		}
		
		fread(&user, sizeof(usuario), 1, puntero1);
	}
	
	if (encontrado == false)
	{
		printf("Usuario o contraseña incorrectos.\n");
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

void registrarTurno(turnos turn, veterinarios vet)
{
	int matriculaAux;
	
	FILE *puntero3;
	
	puntero3 = fopen("Turnos.dat","a+b");
	
	if (puntero3 == NULL)
	{
		printf("Error.");
		exit(0);
	}
	
	printf("Ingrese la matricula del veterinario que atendera a la mascota: ");
	scanf("%d", &turn.Matricula);
	
	matriculaAux = turn.Matricula;
	
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
	
	printf("Se registro el turno, con el veterinario de legajo: %d\n", turn.Matricula);
	fclose(puntero3);
	
	FILE *arch;
	
	arch = fopen("Veterinarios.dat","r+b");
	
	
	//Busqueda del veterinario
	bool busqueda = false;
	
	fread(&vet, sizeof(veterinarios), 1, arch);
	while(!feof(arch) and busqueda == false)
	{
		if (matriculaAux == vet.Matricula)
		{
			busqueda = true;
			
			vet.CantidaddePacientes = vet.CantidaddePacientes + 1;
			
			fseek (arch, -sizeof(veterinarios), SEEK_CUR);
			
			fwrite(&vet, sizeof(veterinarios), 1, arch);
		}
		else
		{
			fread(&vet, sizeof(veterinarios), 1, arch);
		}
	}
	
	fclose(arch);
	
	system("PAUSE");
}

void listarAtenciones(turnos turn)
{
	FILE *puntero4;
	
	puntero4 = fopen("Turnos.dat","r+b");
	
	if (puntero4 == NULL)
	{
		printf("Error.");
		exit(0);
	}
	
	fread(&turn, sizeof(turnos), 1, puntero4);
	
	while(!feof(puntero4))
	{
		printf("\n\nMatricula del veterinario: %d\n", turn.Matricula);
		
		printf("La fecha de atencion es:\n");
		printf("\nDia: %d", turn.fec.dia);
		printf("\nMes: %d", turn.fec.mes);
		printf("\nAnio: %d", turn.fec.anio);
		
		printf("\nDNI del dueño: %d", turn.DNI);
		
		printf("\nDetalle de la atencion: ");
		puts(turn.DetalledeAtencion);
		
		fread(&turn, sizeof(turnos), 1, puntero4);
	}
	
	
	fclose(puntero4);
	
	system("PAUSE");
}


void consultorio()
{
	usuario user;
	veterinarios vet;
	turnos turn;
	mascota masc;
	
	int opc;
	
	while (opc != 4)
	{
		system("CLS");
		
		printf("--Modulo Consultorio Veterinario--\n\n");
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
				registrarEvolucion(masc, turn);
				break;
		}
	}
}

void inicioSesion (veterinarios vet)
{
	bool encontrado = false;
	
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
	while(!feof(puntero1) and encontrado == false)
	{
		if(matricula == vet.Matricula)
		{
			if(strcmp(vet.Contrasenia, contrasenia) == 0)
			{
				encontrado = true;
				
				printf("\nSesion iniciada");
				printf("\nApellido y Nombre: ");
				puts(vet.ApellidoyNombre);
			}
		}
		
		fread(&vet, sizeof(veterinarios), 1, puntero1);
	}
	
	if (encontrado == false)
	{
		printf("Usuario o contraseña incorrectos\n");
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

void registrarEvolucion(mascota masc, turnos turn)
{
	FILE *puntero3;  //turnos
	FILE *puntero4;  //Mascotas
	
	puntero3 = fopen("Turnos.dat","r+b");
	if (puntero3 == NULL)
	{
		printf("Error.");
		exit(0);
	}
	
	puntero4 = fopen("Mascotas.dat","r+b");
	if (puntero3 == NULL)
	{
		printf("Error.");
		exit(0);
	}
	
	int dni;
	
	printf("Ingrese el DNI el dueño de la mascota: ");
	scanf("%d", &dni);
	
	fread(&masc, sizeof(mascota), 1, puntero4);
	while(!feof(puntero4))
	{
		if (dni == masc.DNI)
		{
			printf("\n\nApellido y nombre: ");
			puts(masc.ApellidoyNombre);
			printf("Domicilio: ");
			puts(masc.Domicilio);
			printf("DNI: %d\n", masc.DNI);
			printf("Localidad: ");
			puts(masc.Localidad);
			printf("Fecha de nacimiento DEL ANIMALITO: ");
			printf("\nDia: %d", masc.fec.dia);
			printf("\nMes: %d", masc.fec.mes);
			printf("\nAnio: %d", masc.fec.anio);
			printf("\nPeso de la mascota: %.2f", masc.Peso);
			printf("\nTelefono del dueño de la mascota: %d", masc.Telefono);
		}
		
		fread(&masc, sizeof(mascota), 1, puntero4);
	}
	
	fclose(puntero4);
	
	fread(&turn, sizeof(turnos), 1, puntero3);
	while(!feof(puntero3))
	{
		if (dni == turn.DNI)
		{
			printf("\nIngrese un nuevo estado de la evolucion: ");
			_flushall();
			gets(turn.DetalledeAtencion);
		
			fseek(puntero3, -sizeof(turnos), 1);
			
			fwrite(&turn, sizeof(turnos), 1, puntero3);
		}
		
		fread(&turn, sizeof(turnos), 1, puntero3);
	}
	
	fclose(puntero3);
	
	system("PAUSE");
}


