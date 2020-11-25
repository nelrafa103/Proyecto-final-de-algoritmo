
char ciudades_disponibles[10][30] = {"Santiago", "La vega", "Moca", "Mao", "San Francisco de Macorís", "Puerto Plata", "Bonao", "Samaná", "Salcedo", "Santo Domingo"};
char separador[20] = "-------------------";
struct Arreglos
{
	int total_ventas[10];
	char nombre;
} Informaciones;

int Registrar_montos()
{
	int x = 0;
	while (x < sizeof(ciudades_disponibles) / sizeof(ciudades_disponibles[0]))
	{
		printf("Ingresa el listado de ventas:\t");
		scanf("%d", &Informaciones.total_ventas[x]);
		x += 1;
	}
	printf("\tListado Ventas por Ciudad\t \n");
	
	printf("\t%s \n",separador);
	x = 0;
	printf("Id ciudad\t");
	printf("Monto vendido\n");
	float monto_mayor[2] = {0,0};
	float monto_menor[2] = {Informaciones.total_ventas[0],0};
	while (x < sizeof(Informaciones.total_ventas) / sizeof(Informaciones.total_ventas[0]))
	{
		printf("%d\t\t\t", Informaciones.total_ventas[x]);
		printf("%d\n", x + 1);
		//printf("%d\n", x + 1);
		if (Informaciones.total_ventas[x] > monto_mayor[1])
		{
			monto_mayor[0] = x + 1;
			monto_mayor[1] = Informaciones.total_ventas[x];
		}
		if (Informaciones.total_ventas[x] < monto_menor[1])
		{  
			monto_menor[0] = x + 1;
			monto_menor[1] = Informaciones.total_ventas[x];
		}
		//printf("%s\n",ciudades_disponibles[x]);
		x += 1;
	}
	printf("%s\n",separador);
    printf("Ciudad con mayor venta:\tId:\t%f\tMonto:\t%f\n",monto_mayor[0],monto_mayor[1]);
	printf("Ciudad con menor venta:\tId:\t%f\tMonto:\t%f\n",monto_menor[0],monto_menor[1]);
	return 0;

}