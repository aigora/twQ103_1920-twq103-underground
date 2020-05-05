#include <stdio.h>

struct TDatos{
	char nombreUsuario [50];
	char contrasenna[20];

};
struct TReserva{
	char pais[20];
	char vehiculo[20];
};


int main(){
	
	FILE * pfichero;
	struct TDatos viajes[400];
	int numero,i;
	char  nDatos=0;
    struct TReserva Infor[400];
    int  contador;
    char pais[20], vehiculo[20];
	char tipo;

	pfichero= fopen("datos.txt", "w");
	
	if(pfichero == NULL){
		printf("No se encuentra el fichero\n");
		return 0;
    }
	while(fscanf(pfichero, "%s %s", viajes[nDatos].nombreUsuario, viajes[nDatos].contrasenna)!= EOF){
		nDatos++;
	}
	
	printf("Bienvenido a underwround travel\n");
	do{
	printf("Introduce un 0 si ya tiene una cuenta o un 1 si desea registrarse\n");
	scanf("%d", &numero);}
	while(numero!=0 && numero !=1);
	if(numero == 0){
		printf(" Usted ya tiene una cuenta, introduce el nombre:\n");
		scanf("%s", viajes[nDatos].nombreUsuario);
		printf("La contrasenna:\n");
		scanf("%s", viajes[nDatos].contrasenna);
			fprintf(pfichero,"Nombre de usuario:%s Contrasenna:%s\n",viajes[nDatos].nombreUsuario,viajes[nDatos].contrasenna);	

	}else if(numero == 1){
			printf("Proceda a registrarse,introduce su nombre de usuario:\n");
		scanf("%s", viajes[nDatos].nombreUsuario);
		printf("Introduce su contrasena:\n");
		scanf("%s", viajes[nDatos].contrasenna);
		fprintf(pfichero,"Nombre de usuario:%s\n Contrasenna:%s\n",viajes[nDatos].nombreUsuario,viajes[nDatos].contrasenna);
		fclose(pfichero);
	}
    printf("Elige el lugar al que desee viajar del catalogo:\n");
    FILE * open;
	open= fopen("Lugares.txt", "r");
    
    if(open == NULL){
        printf("No se encuentra el fichero\n");
        return 0;
    }  
    contador=16;
    for(i=0; i<contador;i++){
    	fscanf(open, "%s", Infor[i].pais);
    	printf("%s\n", Infor[i].pais);
	}
	fclose(open);
	fflush(stdin);
	
	printf("Seleccione un pais de la lista:\n");
	scanf("%s", Infor[contador].pais);
	
	
	printf("Introduce un 1 si desea un vehiculo o un 2 si no lo desea\n");
    scanf("%d", &numero);
    switch(numero){
        case 1:
    		printf("Usted ha seleccionado que desea un vehiculo\n");
    		printf("Escriba tipo de vehiculo: 2 para coche, 3 para avion y 4 para ave\n");
    		scanf("%d", &tipo);
    		switch(tipo){
    			case 2:
    				printf("Ha seleccionado un coche\n");
    				break;
    			case 3:
    				printf("Ha seleccionado un avion\n");
    				break;
    			case 4:
    				printf("Ha seleccionado un ave\n");
    			break;	
    			default:
    				printf("Error: Tiene que ser 2,3, o 4");
			}
    		break;
    	case 2:
    		printf("Usted no desea un vehiculo\n");
    		break;
    	default:
    		printf("error:debe estar entre 2 y 3");
    	
    	
	}
	
	
}


	













	
		
		



	 














