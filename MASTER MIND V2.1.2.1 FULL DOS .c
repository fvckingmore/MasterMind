/*PROYECTO MASTER MIND V2
-------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define barras "\n--------------------------------\n"

void juego();
void asig_color();
void encabezado();
void muestra();
void acierto();
void cont();
void win();
void earchi();

FILE *archivo;

int op,cu[3],c[3],ac,ap,intentos=1;
char l;

/*-------------------------------------------------------------------------------*/

int main(){ //PRINCIPAL
	
	asig_color();
	//getch();
	earchi();

	do{
		
		juego();	
		
	}while(op!=0);

	fclose;

return 0;	
}

/*-------------------------------------------------------------------------------*/

void encabezado(){ //TITULO E INSTRUCCIONES
	
	printf("||°BIENVENIDO A MASTER MIND°||\n");
	printf(barras);
	printf("\nVerde => V\tAzul => A\tBlanco => B\tNegro => N\tRojo => R\n");
	printf(barras);
	printf("\nIngrese una combinacion de 3 colores uno por uno: \n\n");	
}

/*-------------------------------------------------------------------------------*/

void asig_color(){ //ASIGNACION DE COLORES
	
	int i,j,B;
	
	srand(time(NULL));
	
	for(i=0;i<=2;i++){
			
		do{
			B=0;
			c[i]=rand()%(5-1+1)+1;
			
			if(i>0){ //Entra despues de la primera posicion
				
				for(j=0;j<i;j++){
						
					if(c[i]==c[j]){ //Evalua la posicion anterior con la actual, si son iguales entonces B=1
						
						B=1; //Si B=1 se repite el ciclo y le vuelve asignar otro valor
					} //Repite hasta que los valores de las posiciones sean diferentes
				}
				
			}
		}while(B!=0);
	}
	
	/*for(i=0;i<=2;i++){ //TEST ROOM MUESTRA DE COLORES SOLO DE PRUEBA
			
			printf("%d\t",c[i]); //DEPURACION
	}*/
}

/*-------------------------------------------------------------------------------*/

void juego(){ //ENTRADA DE COLORES DEL USUARIO
	
	int i,j,B;
	
	encabezado();
	
	for(i=0;i<=2;i++){
		
		do{
		
			printf("Color #%d => ",i+1); scanf("%c",&l); fflush(stdin);
			
			switch(l){
			
				case 'V':
				case 'v': cu[i]=1; B=0; break; 
				
				case 'A':
				case 'a': cu[i]=2; B=0; break; 
				
				case 'B':
				case 'b': cu[i]=3; B=0; break; 
				
				case 'N':
				case 'n': cu[i]=4; B=0; break; 
				
				case 'R':
				case 'r': cu[i]=5; B=0; break; 
				
				default: printf("Opcion incorrecta, vuelva a intentar\n"); 
						 getch(); B=1; /*system("cls");*/ break;
			}
			
			if(i>=1 && B==0){ //Para que el usuario no repita los colores
				
				for(j=0;j<i;j++){
						
					if(cu[i]==cu[j]){ 
						
						printf("No puede ingresar un mismo color, vuelva a intentar");
						getch(); B=1; system("cls"); 
					} 
				}
				
			}
			
			if(B==1){
				encabezado();
			}
			
		}while(B!=0);	
	}
	
	/*for(i=0;i<=2;i++){ //TEST ROOM MUESTRA DE COLORES SOLO DE PRUEBA
			
		printf("%d\t",cu[i]); //DEPURACION
	}*/
	
	printf("\n\n");
	muestra();
	acierto();
	
	if(ap==3 && ac==3){
		win(&op);
	}
	else{
		cont(&op);
	}
}

/*-------------------------------------------------------------------------------*/

void muestra(){ //MUESTRA LOS COLORES DEL USUARIO
				
	int i;
	
	printf("-Usted eligio la siguiente combinacion de colores: \n\n");
	fprintf(archivo,"-Usted eligio la siguiente combinacion de colores: \n\n");
	
	for(i=0;i<=2;i++){
		
		switch(cu[i]){
			
			case 1: printf("Verde\t"); 
					fprintf(archivo,"Verde\t"); break;
			case 2: printf("Azul\t"); 
					fprintf(archivo,"Azul\t"); break;	
			case 3: printf("Blanco\t");
					fprintf(archivo,"Blanco\t"); break;	
			case 4: printf("Negro\t"); 
					fprintf(archivo,"Negro\t"); break;	
			case 5: printf("Rojo\t");
					fprintf(archivo,"Rojo\t"); break;		
		}
	}
	
}

/*-------------------------------------------------------------------------------*/

void acierto(){
	
	int i,j,B;
	char ch;
	
	ac=0;ap=0;
	
	for(i=0;i<=2;i++){
		
		for(j=0;j<=2;j++){
			
			if(c[j]==cu[i]){
				
				ac++;
				
				if(j==i){
					
					ap++;	
				}
			}
		}
		
	}
	
	printf(barras);
	fprintf(archivo,barras);
	
	printf("\n-Ha acertado %d colores\n-Ha acertado %d posiciones\n\n",ac,ap);
	fprintf(archivo,"\n-Ha acertado %d colores\n-Ha acertado %d posiciones\n\n",ac,ap);
	
	if(ap<3 && ac<3){
		
		printf("\n-Sigue intentando\n");
		fprintf(archivo,"\n-Sigue intentando\n");
	}	
}

/*------------------------------------------------------------------------------------*/

void cont(int *op){ /*SE ENCARGA DE IMPRIMIR LA OPCION AL JUGADOR SI QUIERE CONTINUAR O SALIR*/
	
	char opcion; 
	
	printf(barras);
	
	do{
	
		printf("\n¿Desea continuar?\n\n \tSi => S \t|| \tNo => N\n\nOpcion => "); scanf("%c",&opcion); fflush(stdin);

		switch(opcion){
			
			case 's':
			case 'S': *op=1; printf(barras); printf("\n"); intentos++; break;
			
			case 'n':
			case 'N': *op=0; printf(barras); printf("\n"); break;
			
			default: printf("Opcion incorrecta, vuelva a intentar"); *op=2; getch(); system("cls"); break;
		}
	}while(*op==2);
	
	
	if(*op==0) {
		
		printf(barras); printf("\n¡Perdiste, has salido del juego!");
		fprintf(archivo,barras); fprintf(archivo,"\n¡Perdiste, has salido del juego!");
	}
}

/*-----------------------------------------------------------------------------------------*/

void win(int *op){ //Si la combinacion del usuario es igual al del programa llamara a esta funcion que imprimira el siguiente mensaje
 //en el programa y en el archivo
 
	printf(barras);
	fprintf(archivo,barras);
	
	printf("\nFelicitaciones, HAS GANADO!!\n\nHas realizado %d intentos",intentos);
	fprintf(archivo,"\nFelicitaciones, HAS GANADO!!");
	
	*op=0;
	getch();	
}

/*-------------------------------------------------------------------------------------------*/

void earchi(){ //Esta funcion se encarga de crear el archivo y escribir el encabezado en el.
	
	archivo=fopen("Registro.txt","w");
	fprintf(archivo,"\n||°BIENVENIDO A MASTER MIND°||\n");
	fprintf(archivo,barras); 
	fprintf(archivo,"\nVerde => V\tAzul => A\tBlanco => B\tNegro => N\tRojo => R\n");
	fprintf(archivo,barras);
	fprintf(archivo,"\nIngrese una combinacion de 3 colores uno por uno: \n\n");
}
