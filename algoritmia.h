
char ciudades_disponibles[10][30] = {"Santiago", "La vega", "Moca", "Mao", "San Francisco de Macorís", "Puerto Plata", "Bonao", "Samaná", "Salcedo", "Santo Domingo"};

char separador[60] = "---------------------------------------------------";

struct Arreglos
{
	int montos_per_ciudad[10];
	int montos_per_vendedor[10][200][30];
} Informaciones;

int Registrar_montos()
{
	int ciudad_id = 1;
	printf("Listado de ciudades diponibles: \n ");
	printf("%s \n", separador);
	while (ciudad_id <= sizeof(ciudades_disponibles) / sizeof(ciudades_disponibles[0]))
	{
		if (strlen(ciudades_disponibles[ciudad_id]) > strlen(ciudades_disponibles[9]))
		{
			printf("\t");
		}
		printf("%d.%s\t\t\t", ciudad_id, ciudades_disponibles[ciudad_id]);
		if (ciudad_id % 2 == 0)
		{
			printf("\n");
		}
		ciudad_id += 1;
	}
	printf("%s \n", separador);
/*	int opcion = 0;
	printf("1 --->  Buscar por Id\n");
	printf("2 --->  Buscar por nombre (siempre con mayucula)\n");
	scanf("%d", &opcion);*/
//	ciudad_id = 0;
//	if (opcion == 1){
    //   printf("Introduce el id de la ciudad:\t");
//	   scanf("%d",&ciudad_id);
//	}
	/*else if (opcion == 2)
	{
		char ciudad_seleccionada[30];
		fgets(ciudad_seleccionada, 30, stdin);
		for (ciudad_id= 0; ciudad_seleccionada < sizeof(ciudad_seleccionada) / sizeof(ciudad_seleccionada); ciudad_id += 1)
		{
			if (ciudad_seleccionada == ciudades_disponibles[ciudad_id])
			{
				break;
			}
		}
}*/

	//fgets(Informaciones.vendedores[0][0], 30, stdin);
	//puts(Informaciones.vendedores[0][0]);
	return 0;
}
int Montos_per_ciudad()
{

	//puts(Informaciones.vendedores[0][0]);
	/*	int x = 0;
	printf("\tListado Ventas por Ciudad\t \n");
	printf("\t%s \n", separador);
	printf("Id ciudad\t");
	printf("Monto vendido\n");
	float monto_mayor[2] = {0, 0};
	float monto_menor[2] = {Informaciones.montos_per_ciudad[0], 0};
	while (x < sizeof(Informaciones.montos_per_ciudad) / sizeof(Informaciones.montos_per_ciudad[0]))
	{
		printf("%d\t\t\t", Informaciones.montos_per_ciudad[x]);
		printf("%d\n", x + 1);
		//printf("%d\n", x + 1);
		if (Informaciones.montos_per_ciudad[x] > monto_mayor[1])
		{
			monto_mayor[0] = x + 1;
			monto_mayor[1] = Informaciones.montos_per_ciudad[x];
		}
		if (Informaciones.montos_per_ciudad[x] < monto_menor[1])
		{
			monto_menor[0] = x + 1;
			monto_menor[1] = Informaciones.monto[x];
		}
		//printf("%s\n",ciudades_disponibles[x]);
		x += 1;
	}
	printf("%s\n", separador);
	printf("Ciudad con mayor venta:\tId:\t%f\tMonto:\t%f\n", monto_mayor[0], monto_mayor[1]);
	printf("Ciudad con menor venta:\tId:\t%f\tMonto:\t%f\n", monto_menor[0], monto_menor[1]);
*/
	return 0;
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