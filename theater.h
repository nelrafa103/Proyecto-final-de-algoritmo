
char ciudades_disponibles[10][30] = {"Santiago","La vega","Moca","Mao","San Francisco de Macorís","Puerto Plata","Bonao","Samaná","Salcedo","Santo Domingo"};
struct Arreglos{
  int total_ventas[10];
}Informaciones;

int Registrar_montos(){
  int x = 0;
  while (x < sizeof(ciudades_disponibles) /sizeof(ciudades_disponibles[0]) ){
    printf("Ingresa el listado de ventas:\t");
    scanf("%d",&Informaciones.total_ventas[x]);
    x+= 1;
  }
  printf("\tListado Ventas por Ciudad\t \n");
  char separador[] = "---------------------";
  printf("\t%s \n",separador);
  x = 0;
  printf("Id ciudad\t");
  printf("Monto vendido\n");
  int monto_mayor = 0;
  int monto_menor = 0;
  while (x < sizeof(Informaciones.total_ventas) /sizeof(Informaciones.total_ventas[0]) ){
   printf("\t%d\t\t\t\t",Informaciones.total_ventas[x]);
    printf("%d\n",x + 1);
    if (Informaciones.total_ventas[x] > monto_mayor){
      continue;
    }
   //printf("%s\n",ciudades_disponibles[x]);
   x += 1;
  }
  printf("%s",separador);

  return
}
