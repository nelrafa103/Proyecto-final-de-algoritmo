#include <stdio.h>
#include <stdlib.h>

#define VERDADERO 1

int main()
{
    int opcion;
    int idciudad[10];
    int idvendedor[15];
    double montovendido[20][8];
    int indice, ciudadmontomayor=-1, ciudadmontomenor=-1, montomayor=0, montomenor=0, suma=0, montoporciudad=0, montociudad=-1, ciudadesvisitades=0;

     


   do 
   {
       printf("Menu de Opciones\n");
       char separador[] = "---------------------";
       printf("\t%s \n",separador);
       printf("1. Registrar ventas\n");
       printf("2. Listado de ventas por ciudad\n");
       printf("3. Ventas realizadas por vendedor\n");
       printf("4. Matriz ventas por cuidades\n");
       printf("5. Salir\n");
       scanf("%d\n", &opcion);
       system("cls");

       switch (opcion)
       {
       case 1:
         for(indice=0; indice<=10; indice++)
         {
           printf("Idtroduzca ID de vendedor\n");
           scanf("%d", &idvendedor[indice]);
           printf("ID    CUIDAD\n");
           printf("\t%s \n", separador);
           printf("1.    Santiago\n 2.    La vega\n 3.    Moca\n 4.    Santo Domingo\n 5.    Mao\n 6.    San Francisco de Macorís\n 7.    Puerto Plata\n 8.    Bonao\n 9.    Samaná\n 10.    Salcedo\n");
           printf("Introduzca ID de cuidad\n");
           scanf("%d", &idciudad[indice]);
           printf("Digite monto vendido en cuidad\n");
           scanf("%lf", &montovendido[indice]);
           system("cls");

           if (idvendedor[indice]>15)
           {
               printf("ERROR ID VENDEDOR NO ENCONTRADO\n");
               system("cls");
           }
           if (idciudad[indice]>10)
           {
               printf("ERROR ID CUIDAD NO ENCONTRADA\n");
               system("cls");
           }
         }
           break;

        case 2:
        for(indice=0; indice<=10; indice++)
        {
        printf("Listado de ventas por ciudad\n");
        printf("\t%s \n",separador);
        printf("ID CIUDAD      MONTO VENDIDO\n");
         if(indice==0)
        {
            montociudad=indice;
            montoporciudad=montovendido[indice];
        }
        else if(idciudad[indice]==idciudad[indice])
        {
            montoporciudad=montoporciudad+montovendido[indice];
            montociudad=indice;
        }
        else if(idciudad[indice]!=idciudad[indice])
        {
            montoporciudad=montovendido[indice];
            montociudad=indice;
        }
        suma=suma+montovendido[montociudad];
        printt("%-14d %10lf\n", idciudad[indice], montovendido[montociudad]);
        printf("\t%s \n", separador);
        printf("Total de ventas %10lf\n", suma);
        if (indice == 0)
        {
            ciudadmontomayor=indice;
            ciudadmontomenor=indice;
            montomayor=montovendido[montociudad];
            montomenor=montovendido[montociudad];
        }
        else if (montovendido[montociudad]>montomayor)
        {
            montomayor=montovendido[montociudad];
            ciudadmontomayor=indice;
        }
        else if(montovendido[montociudad]<montomenor)
        {
            montomenor=montovendido[montociudad];
            ciudadmontomenor=indice;
        }
        printf("\nCiudad con mayor venta: ID: %d, Venta %lf\n", idciudad[ciudadmontomayor], montovendido[ciudadmontomayor]);
        printf("\nCuidad con menor venta: ID: %d, Venta %lf\n", idciudad[ciudadmontomenor], montovendido[ciudadmontomenor]);
        system("cls");
        }
        case 3:
        for(indice=0; indice<=10; indice++)
        {
            if(idvendedor[indice]==idvendedor[indice])
            {
            ciudadesvisitades++;
            }
            else if (idvendedor[indice]!= idvendedor[indice])
            {
                ciudadesvisitades=1;
            }

        }

        printf("Listado de ventas por vendedor\n");
        printf("\t%s \n",separador);
        printf("ID VENDEDOR   CIUDADES VISITADAS  MONTO VENDIDO\n");
        printf("\t%s \n", separador);
        printf("%-14d 10%d 20%lf", idvendedor[indice], ciudadesvisitades,montovendido[montociudad]);
        printf("\t%s \n", separador);
        printf("Total general 20%lf", suma);


       default:

       printf("LA OPCION INTRODUCIDA ES INCORRECTA");
           break;
       }
       

   }
   while (opcion!=5);

   return 0;
    
}