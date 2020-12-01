
char ciudades_disponibles[10][30] = {"Santiago", "La vega", "Moca", "Mao", "Puerto Plata", "Bonao", "Samaná", "Salcedo", "Santo Domingo", "San Francisco de Macorís"};

char separador[60] = "---------------------------------------------------";

struct Montos
{
	int montos_per_ciudad[10];
	int montos_per_vendedor[10][15];
	int monto_total_per_vendedor[15];
	int totalidad;
} Informaciones;
void Borrar_consola(){
	#ifdef _WIN32 
	  system("cls");
     #endif

    #ifdef __linux__
      system("clear");
     #endif
}
int Registrar_montos()
{

	int i = 1;
	int ciudad_id = 1;
	printf("Listado de ciudades diponibles: \n");
	printf("%s \n", separador);
	while (ciudad_id <= sizeof(ciudades_disponibles) / sizeof(ciudades_disponibles[0]))
	{
		if (strcmp(ciudades_disponibles[ciudad_id - 1], "Mao") == 0)
		{
			printf("\t");
		}
		printf("%d.%s\t\t\t\t", ciudad_id, ciudades_disponibles[ciudad_id - 1]);
		if (ciudad_id % 2 == 0)
		{
			printf("\n");
		}
		ciudad_id += 1;
	}
	char opcion[1];
	int opcion_2 = 0;
	int opcion_3 = 0;
	int opcion_4 = 0;

	while (i == 1)
	{
		printf("\n");
		printf("e para continuar\n");
		printf("s para cerrar\n");
		printf("Digite:\t");
		scanf("%s", &opcion[0]);
		if (strcmp(opcion, "s") == 0)
		{
			break;
		}
		else if (strcmp(opcion, "e") == 0)
		{
			printf("Introduce id de la ciudad:\t");
			scanf("%d", &opcion_2);
			printf("\n");
			printf("Introduce id del empleado:\t");
			scanf("%d", &opcion_3);
			printf("\n");
			printf("Introduce el monto:\t");
			scanf("%d", &opcion_4);
		
			if (opcion_4 < 0){
				printf("\n");
			    printf("No se puede introducir un valor menor a 0\t");
				continue;
			}
			if(opcion_2 > sizeof(ciudades_disponibles) / sizeof(ciudades_disponibles[0]) || (opcion_2) - 1 < 0){
			  printf("\n");
			  printf("No hay ciudad con tal Id\t");
			  continue;
			}
			if(opcion_3 > sizeof(Informaciones.monto_total_per_vendedor) / sizeof(Informaciones.monto_total_per_vendedor[0]) || (opcion_3 - 1) < 0){
			  printf("\n");
			  printf("No hay empleado con tal Id\t");
			  continue;
			}
			printf("\n");
			Informaciones.montos_per_vendedor[opcion_2 - 1][opcion_3 - 1] += opcion_4;
			
		}
	}
}
int Montos_per_ciudad()
{

	int x = 0;
	int i = 0;
	int monto_total;
	for (x = 0; x < sizeof(Informaciones.montos_per_ciudad) / sizeof(Informaciones.montos_per_ciudad[0]); x += 1)
	{
		while (i < 15)
		{
			
			monto_total += Informaciones.montos_per_vendedor[x][i];
			i += 1;
		}

		i = 0;
	
		Informaciones.montos_per_ciudad[x] = monto_total;
		monto_total = 0;
	}
	printf("\tListado Ventas por Ciudad\t \n");
	printf("\t%s \n", separador);
	printf("\t\tMonto vendido\t\t");
	printf("Id ciudad\n");
	x = 0;
	float monto_mayor[2] = {0, 0};
	float monto_menor[2] = {0, 0};
	while (x < sizeof(Informaciones.montos_per_ciudad) / sizeof(Informaciones.montos_per_ciudad[0]))
	{
		printf("\t\t%d\t\t", Informaciones.montos_per_ciudad[x]);
		printf("\t%d\n", x + 1);
		if (Informaciones.montos_per_ciudad[x] > monto_mayor[1])
		{
			monto_mayor[0] = x + 1;
			monto_mayor[1] = Informaciones.montos_per_ciudad[x];
		}
		if (Informaciones.montos_per_ciudad[x] < monto_menor[1])
		{
			monto_menor[0] = x + 1;
			monto_menor[1] = Informaciones.montos_per_ciudad[x];
		}
		x += 1;
	}
	printf("\t%s\n", separador);
	printf("Ciudad con mayor venta:\tId:\t%f\tMonto:\t%f\n", monto_mayor[0], monto_mayor[1]);
	printf("Ciudad con menor venta:\tId:\t%f\tMonto:\t%f\n", monto_menor[0], monto_menor[1]);
	printf("Digite cualquier tecla para continuar\n");
	getchar();
	getchar();
}

int Montos_per_vendedor()
{
	int i = 0;
	int monto_total = 0;
	int x = 0;
	for (int z = 0; z < 15; z++)
	{
		while (i < sizeof(Informaciones.montos_per_vendedor) / sizeof(Informaciones.montos_per_vendedor[0]))
		{
			while (x < 15)
			{
				if (z == x)
				{
					monto_total += Informaciones.montos_per_vendedor[i][x];
				}
				x += 1;
			}
			x = 0;

			i += 1;
		}
		i = 0;
		Informaciones.monto_total_per_vendedor[z] = monto_total;
		monto_total = 0;
	}

	i = 0;
	printf("\tListado de ventas por empleados\t \n");
	printf("\t%s \n", separador);
	printf("\t\tMonto vendido\t\t");
	printf("\t\tId empleado\n");
	float monto_mayor[2] = {0, 0};
	float monto_menor[2] = {0, 0};
	while (i < sizeof(Informaciones.monto_total_per_vendedor) / sizeof(Informaciones.monto_total_per_vendedor[0]))
	{
		printf("\t\t%d\t", Informaciones.monto_total_per_vendedor[i]);
		printf("\t\t\t\t%d\n", i + 1);

		if (Informaciones.monto_total_per_vendedor[x] > monto_mayor[1])
		{
			monto_mayor[0] = x + 1;
			monto_mayor[1] = Informaciones.monto_total_per_vendedor[x];
		}
		if (Informaciones.monto_total_per_vendedor[x] < monto_menor[1])
		{
			monto_menor[0] = x + 1;
			monto_menor[1] = Informaciones.monto_total_per_vendedor[x];
		}
		i += 1;
	}
	for(int r = 0; r < sizeof(Informaciones.monto_total_per_vendedor) / sizeof(Informaciones.monto_total_per_vendedor[0]); r+= 1){
      Informaciones.totalidad += Informaciones.monto_total_per_vendedor[r];
	}
	printf("\t%s\n", separador);
	printf("\tMonto total:");
    printf("\t%d\n", Informaciones.totalidad);
	printf("\t%s\n", separador);
	printf("Empleado con mayor venta:\tId:\t%f\tMonto:\t%f\n", monto_mayor[0], monto_mayor[1]);
	printf("Empleado con menor venta:\tId:\t%f\tMonto:\t%f\n", monto_menor[0], monto_menor[1]);

	printf("Digite cualquier tecla para continuar\n");
	getchar();
	getchar();
}

char Menu(void)
{
	char opcion[1];
	printf("%s\n\n", separador);
	printf("Sistema de control de ventas\n");
	printf("%s \n\n", separador);
	printf("1 --->  Registrar Ventas\n");
	printf("2 --->  Listado Ventas Por Ciudad\n");
	printf("3 --->  Ventas Realizadas por Vendedor\n");
	printf("4 --->  Matriz Ventas Vendedor por Ciudades\n");
	printf("s --->  Salir\n");
	printf("Digite opcion:\t");
	scanf("%s", &opcion[0]);
	
	return opcion[0];
}
int Matriz_ventas()
{ 	
	
	int x = 0;



	int i = 0;
	int monto_total = 0;
	for (int z = 0; z < 15; z++)
	{
		while (i < sizeof(Informaciones.montos_per_vendedor) / sizeof(Informaciones.montos_per_vendedor[0]))
		{
			while (x < 15)
			{
				if (z == x)
				{
					monto_total += Informaciones.montos_per_vendedor[i][x];
				}
				x += 1;
			}
			x = 0;

			i += 1;
		}
		i = 0;
		Informaciones.monto_total_per_vendedor[z] = monto_total;
		monto_total = 0;
	}
	x = 0;
	i = 0;
	printf("\t\t\t\t\tId de ciudades visitadas\t\t\t\t\t\n");
	printf("Id empleado");
    for(int i = 0; i < sizeof(Informaciones.montos_per_vendedor) / sizeof(Informaciones.montos_per_vendedor[0]); i+= 1){
      printf("\t%4d",i + 1);
	}
	printf("\tTotal");
	printf("\n");
	 
	for(i = 0; i < 15; i+= 1){
	  printf("\t%d",i + 1);
      while(x < 10){
       printf("\t%4d",Informaciones.montos_per_vendedor[x][i]);
	   x+= 1;
	   }	
	   x = 0;
	   printf("\t%4d",Informaciones.monto_total_per_vendedor[i]);
	   printf("\n");
	
	}
	printf("\n");
	printf("Digite cualquier tecla para continuar\n");
	getchar();
	getchar();
}
int empresa()
{  
	Borrar_consola();
	char opcion_1[1];
	opcion_1[0] = Menu();
	if (strcmp(opcion_1, "s") != 0)
	{
		if (strcmp(opcion_1, "1") == 0)
		{
			int registrar = Registrar_montos();
			return empresa();
		}
		if (strcmp(opcion_1, "2") == 0)
		{
			int montos_per_ciudad = Montos_per_ciudad();

			return empresa();
		}
		if (strcmp(opcion_1, "3") == 0)
		{
			int montos_per_vendedor = Montos_per_vendedor();

			return empresa();
		
		}

		if (strcmp(opcion_1, "4") == 0)
		{
			int matriz_de_vendedores = Matriz_ventas();

			return empresa();
		
		}
		else
		{
			return 0;
		}
	}
}