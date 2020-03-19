#include <stdio.h>

int main(){
	
	char nombre1[50],nombre2[50], contrasena1[50],contrasena2[50],tipo;
	int numero,vehiculo;
	printf("Bienvenido a underground travel\n");
	printf("Introduce un 0 si ya tiene una cuenta o un 1 si desea registrarse\n");
	scanf("%d", &numero);

    switch(numero){
    	case 0:
		printf(" Usted ya tiene una cuenta, introduce el nombre:\n");
		scanf("%s", nombre1);
		printf("La contraseña:\n");
		scanf("%s", contrasena1);
		break;
		case 1:
		printf("Proceda a registrarse:Introduce su nombre de usuario:\n");
		scanf("%s", nombre2);
		printf("Introduce su contrasena:\n");
		scanf("%s", contrasena2);
		break;	
		default:
			printf("Error: debe estar entre 0 y 1");
			
    }
    printf("Introduce un 2 si desea un vehiculo o un 3 si no lo desea\n");
    scanf("%d", &numero);
    switch(numero){
    	case 2:
    		printf("Usted ha seleccionado que desea un vehiculo\n");
    		printf("Escriba tipo de vehiculo: 4 para coche, 5 para avion y 6 para ave\n");
    		scanf("%d", &tipo);
    		switch(tipo){
    			case 4:
    				printf("Ha seleccionado un coche\n");
    				break;
    			case 5:
    				printf("Ha seleccionado un avion\n");
    				break;
    			case 6:
    				printf("Ha seleccionado un ave\n");
    			break;	
    			default:
    				printf("Error: Tiene que ser 4,5, o 6");
			}
    		break;
    	case 3:
    		printf("Usted no desea un vehiculo\n");
    		break;
    	default:
    		printf("error:debe estar entre 2 y 3");
    	
    	
	}
	printf("Elija un continente: 7(America), 8(Europa), 9(Africa), 10(Asia), 11(Oceania), 12(Antartida)\n");
	scanf("%d", &numero);
	switch(numero){
		case 7:
			printf("Usted ha decidido viajar a America");
			break;
		case 8:
			printf("Usted ha decidio viajar a Europa");
			break;
		case 9:
			printf("Usted ha decidio viajar a Africa");
			break;
		case 10:
			printf("Usted ha decidido viajar a Asia");
			break;
		case 11:
			printf("Usted ha decidido viajar a Oceania");
			break;
		case 12:
			printf("Usted ha decidido viajar a la Antartida");
			break;
		default:
			printf("Error: Valores entre 7 y 12");
		
	}
	

   
}
}
