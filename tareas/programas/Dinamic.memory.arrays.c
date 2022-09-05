#include<stdio.h>
#include<stdlib.h>

int main(){
    int *even,i,digito;
    char cuenta[9];

    printf("Pls digit your account number >> ");//lectura de numero de cuenta
    gets(cuenta);
    digito = cuenta[8] - '0';

    even = (int*)malloc(sizeof(int)*10);//inicializacion de arreglo dinamico 
    if(even == NULL){//verificacion de alocacion de memoria
        printf("It wasn't possible to alocate the memory for the dynamic array");
        return(1);
    }
    
    for (i = 0; i < 10; i++)//llenado con 10 primeros pares
        even[i]= 2*(i+1);

    for(i = 9; i > -1; i--)//impresion inversa del arreglo
        printf("|%d",even[i]);
    printf("|\n\n Modifiyng the number at index [%d] for -1 \n\n",digito);

    even[digito] = -1; //cambio del digito solicitado por -1
    
    for(i = 9; i > -1; i--)//impresion inversa del arreglo
        printf("|%d",even[i]);
    printf("|\n");

    getchar();
    
}