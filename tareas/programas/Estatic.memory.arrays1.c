#include <stdio.h>

int main(){
	int i, pares[]={2,4,6,8,10,12,14,16,18,20};
	int cuenta;
	
	for(i=0;i<10;i++){
		printf("\t%d\n",pares[i]);
	}
	
	printf("Dame tu número de cuenta: ");
	scanf("%d",&cuenta);
	
	system("cls");
	
	cuenta%=10;
	pares[cuenta]=-1;
	
	for(i=0;i<10;i++){
		printf("\t%d\n",pares[i]);
	}
	
	system("pause");
	system("cls");
	
	return 0;
}
