#include <stdio.h>

int main(){
	int i, pares[10],digito;
	char cuenta[9];
	system("cls");

	for (i = 0; i < 10; i++)//llenado con 10 primeros pares
        pares[i]= 2*(i+1);

	for(i=9;i>=0;i--)//imprimiendo el arreglo de forma inversa
		printf("|%d",pares[i]);
	printf("|\n");

	printf("\nPls digit your account number >> ");//lectura de numero de cuenta
    gets(cuenta);
    digito = cuenta[8] - '0'; //obteniendo el ultimo digito

	printf("Modifiyng the number at index [%d] for -1\n",digito);

	pares[digito]=-1;//realizando el cambio en el 
	
	for(i=9;i>=0;i--)//imprimiendo el arreglo de forma inversa
		printf("|%d",pares[i]);
	printf("|\n");

	system("pause");
}
