#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int i,j,ncuenta[9]={0},**fila;
    char cuenta[9];

    printf("Pls digit your account number >> ");
    gets(cuenta);
    for(i=0; i < strlen(cuenta);i++)
        ncuenta[i] = cuenta[i] - '0';

    fila = (int**)malloc(sizeof(int)*9);
    if(fila == NULL){
        printf("it wasn't possible to alocate the memory for the array of columns");
        return(1);
    }
    
    for (i = 0; i < 9; i++)
    {
        fila[i]= (int*)malloc(sizeof(int)*ncuenta[i]);

        if(fila[i] == NULL){
            printf("it wasn't possible to alocate the memory for line's %d array",i++);
            exit(1);
        }

        for (j = 0; j < ncuenta[i]; j++)
        {
            fila[i][j]=ncuenta[i];
            printf("|%d",fila[i][j]);
        }
        printf("|\n");
    } 
}
