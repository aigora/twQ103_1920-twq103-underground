#include <stdio.h>
#include <string.h>
struct TDatos{
	char nombreUsuario [50];
	char contrasenna[20];

};
struct TReserva{
	int pais[20];
	char vehiculo[20];
	
};
void menu(){
	printf("Introduce una opcion\n");
	printf("0-->Iniciar sesion\n");
	printf("1-->Registrarse\n");
}
void banner(){
	printf("*********************************\n");
	printf("*BIENVENIDO A UNDERGROUND TRAVEL*\n");
	printf("*********************************\n");
	printf("\n");
	printf("Disfruta de las oportunidades que te da underground travel para disfrutar de un destino de vacaciones perfecto\n");
	printf("\n");
}
void transporte(){
	printf("Introduce una opcion\n");
	printf("0 -->Deseo un vehiculo\n");
	printf("1 -->No deseo un vehiculo\n ");
	
}
int main(){
	
	FILE * pfichero;
	struct TDatos viajes[400];
	int numero,i,longitud;
	char  nDatos=0;
	int fin,contador=0,horario;
    struct TReserva Infor[400];
    int  tipo,eleccion,lugar;
    char pais[20], vehiculo[20];
	
system("Color B5");
	pfichero= fopen("datos.txt", "a");
	
	if(pfichero == NULL){
		printf("No se encuentra el fichero\n");
		return 0;
    }
	while(fscanf(pfichero, "%s %s", viajes[nDatos].nombreUsuario, viajes[nDatos].contrasenna)!= EOF){
		nDatos++;
	}
	banner();
	do{
	   menu();
	   scanf("%d", &numero);}
	while(numero!=0 && numero !=1);
	if(numero == 0){
		do{
		printf("Usted ya tiene una cuenta\n");
		printf("Introduce el nombre de usuario:\n");
		fflush(stdin);
		scanf("%s",viajes[nDatos].nombreUsuario);
		printf("\n");
		printf("Introduce la contrasenna(debe tener mas de 6 digitos):\n");
		fflush(stdin);
		scanf("%s", viajes[nDatos].contrasenna);
		printf("\n");
		longitud = strlen(viajes[nDatos].contrasenna);
		if(longitud<6){
			printf("La contrasenna tiene que ser mayor que 8 caracteres\n");
			printf("\n");
	 }
	    }while(longitud<6);
		fprintf(pfichero,"Nombre de usuario:%s Contrasenna:%s\n",viajes[nDatos].nombreUsuario,viajes[nDatos].contrasenna);
		printf("Usuario y contrasenna correcta\n");	
	}else if(numero == 1){
		do{
		printf("Proceda a registrarse,introduce su nombre de usuario:\n");
		scanf("%s", viajes[nDatos].nombreUsuario);
		printf("\n");
		printf("Introduce su contrasena:(debe tener mas de 6 caracteres):\n");
		scanf("%s", viajes[nDatos].contrasenna);
		printf("\n");
		longitud = strlen(viajes[nDatos].contrasenna);
		if(longitud<6){
		printf("La contrasenna tiene que ser mayor que 6 caracteres\n");
	}
	}while(longitud<6);
	    printf("Su cuenta ha sido creada con exito\n");
	    printf("\n");
		fprintf(pfichero,"Nombre de usuario:%s\n Contrasenna:%s\n",viajes[nDatos].nombreUsuario,viajes[nDatos].contrasenna);
		fclose(pfichero);
	} 
	
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	//LUGAR AL QUE SE QUIERA VIAJAR
    printf("Elige el lugar al que desee viajar del catalogo(Poniendo el numero que le corresponda):\n");
    printf("\n");
    FILE * open;
	open= fopen("lugares.txt", "r");
    
    if(open == NULL){
        printf("No se encuentra el fichero\n");
        return 0;
    }
    while (fscanf(open, "%s", Infor[contador].pais)!= EOF){
		contador++;
    }
    fclose(open);
    for(i=0; i<contador;i++){
    	printf("%s", Infor[i].pais);
    	printf("\t");
	}
	printf("\n");
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	fflush(stdin);
	do{
	printf("Numero:\n");
	scanf("%d",&lugar);
	printf("\n");
	if(lugar>contador){
		printf("El pais no se encuentra en la lista\n");
	}
	}while(lugar >contador );
	//TRANSPORTE
	do{
	transporte();
	fflush(stdin);
	scanf("%d", &eleccion);
	printf("\n");
	}while(eleccion!= 0 && eleccion!=1);
	switch(eleccion){
		case 0:
    		printf("Usted ha seleccionado que desea un vehiculo\n");
    		printf("Seleccione una opcion\n");
    		printf("C --> COCHE\n");
    		printf("A --> AVION\n");
    		printf("V --> AVE\n");
    		fflush(stdin);
    		scanf("%c", &tipo);
    		printf("\n");
    		switch(tipo){
    			case 'C':
    				printf("Ha seleccionado un coche\n");
    				printf("\n");
				   break;
    			case 'A':
    				printf("Ha seleccionado un avion\n");
    				printf("\n");
				   break;
    			case 'V':
    				printf("Ha seleccionado un ave\n");
    				printf("\n");
			 break;
    			default:
    				printf("Error: Tiene que ser C,A, o V\n");
			}
			//HORARIO DEL TRANSPORTE
			do{
			printf("Introduzca la franja horaria deseada: \n");
			printf("--HORARIOS---\n");
	        printf("|9 -->9:00h |\n");
	        printf("|14-->14:00h|\n");
	        printf("|21-->21:00h|\n");
	        fflush(stdin);
	        scanf("%d", &horario);
	        printf("\n");
			}while( horario!= 9 && horario != 14 && horario!= 21);
    		break;
    	case 1:
    		printf("Usted no desea un vehiculo\n");
    		break;
    	default:
    		printf("error:debe estar entre 0 y 1");
    	
	}
	
	printf("Disfruta del viaje, tu reserva ha sido guardada\n");
	printf("***********************************************************\n");
	printf("Seleccione una opcion\n");
	printf("1 --> Salir\n");
	printf("2 --> Inicio\n");
	scanf("%d", &fin);
	if(fin == 1){
		printf("Hasta pronto\n");
	}
	else if(fin == 2 ){
		banner();
	
	}
}




	
