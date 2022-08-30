#include <stdio.h>

typedef struct{
	char nombre[25];
	int edad, calificacion;
} alumno;

int main(){
	alumno alumnos[20];
	int n, i;
	float x=0, y=0;
	
	printf("Introduzca la cantidad de alumnos a registrar: ");
	scanf("%d",&n);
	
	system("cls");
	
	for(i=0; i<n; i++){
		printf("\t\t Alumno %d\n",i+1);
		printf("Introduzca nombre (maximo 25 letras): ");
		fflush(stdin);gets(alumnos[i].nombre);
		printf("Introduzca edad: ");
		scanf("%d",&alumnos[i].edad);
		printf("Introduzca calificación: ");
		scanf("%d",&alumnos[i].calificacion);
		
		system("cls");
	}
	
	for(i=0; i<n; i++){
		x+=alumnos[i].edad;
		y+=alumnos[i].calificacion;
	}
	
	x=(float)x/n;
	y=(float)y/n;
	
	printf("Promedio de edades: %f\n", x);
	printf("Promedio grupal: %f", y);
	
	system("pause");system("cls");
	
	printf("\t\tAlumnos: ");
	for(i=n-1; i>=0; i--){
		printf("%d. %s\n",n-i,alumnos[i].nombre);
	}
	
	system("pause");system("cls");
	
	return 0;
}
