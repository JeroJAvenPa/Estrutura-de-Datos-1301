#include<stdio.h>
#include<stdlib.h>

int main(){
	int i,j;
    int array[9]={0};
    int **fila,*columna;

    printf("Pls digit your account number\n");
    for (i = 0; i < 9; i++)
    {
        printf("%d >> ",i+1);scanf("%d",&array[i]);
    }
    
    fila = (int**)malloc(sizeof(int)*9);
    if(fila == NULL){
        printf("it wasn't possible to alocate the memory for the array of columns");
        return(1);
    }
    
    for (i = 0; i < 9; i++)
    {
        fila[i]= (int*)malloc(sizeof(int)*array[i]);

        if(fila[i] == NULL){
            printf("it wasn't possible to alocate the memory for line's %d array",i++);
            exit(1);
        }

        for (j = 0; j < array[i]; j++)
        {
            fila[i][j]=array[i];
            printf("|%d",fila[i][j]);
        }
        printf("\n");
    } 
}
