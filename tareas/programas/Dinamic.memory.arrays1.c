#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//estructura usada para hacer el registro
typedef struct estudiante{
        char nombre[25];
        int calificacion;
        int edad;
}es;
    
int main(){
    int students,i;
    float prom=0,ages=0;
    es *est;
    //cuantos alumnos
    printf("How many students you wish to register >> ");
    scanf("%d",&students);
    //inicializacion de estructura
    est = malloc(sizeof(es)*students);
    if(est == NULL){
        printf("it wasn't possible to allocate the void array");
        return(1);
    }
    //lectura de datos
    for(i=0;i<students;i++){
        printf("\t---Alumno %d---\nNombre: ",i+1);
        fflush(stdin);
        gets(est[i].nombre);
        printf("Edad: ");
        scanf("%d",&est[i].edad);
        ages += est[i].edad;
        printf("Calificacion: ");
        scanf("%d",&est[i].calificacion);
        prom += est[i].calificacion;
    }
    //promedios
    prom /= students;
    ages /= students;

    //impresion
    printf("| Name\t| Age\t| Grade\t|\n ----------------------------------\n");
    for(i=students-1;i>=0;i--){
        printf("|%s\t",est[i].nombre);
        printf("|%d\t",est[i].edad);
        printf("|%d\t",est[i].calificacion);
        printf("|\n");
    }

    printf("\nThe average of grades is %.2f",prom);
    printf("\nThe average age is %.2f",ages);
}