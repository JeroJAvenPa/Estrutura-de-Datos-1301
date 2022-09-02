#include<stdio.h>
int number, result,resulti,i;

int recursivo(int num){//o(2n-1)

    if(num != 0)//si se cumple quiere decir que todavia no terminamos y se vuelve a llamar la funcion
        return(num * recursivo(num-1));//aqui ej num=4 entonces 4 * factorial(3) y entonces se ejecuta factorial(3) y asi
    else// si es 0 significa que ya acabamos y entonces regresamos un 1 para que factoria(0) regrese un 1 y no se cambie el resultado
        return(1);//regresa un 1 a la funcion factorial(x) anterior

}

int iterativo(int num){
    int total = 1;
    for(i=1; i <= num; i++)
        total *= i;
    return(total);
}

int main(){
    printf("Pls give me a number:");
    scanf("%d",&number);
    result = iterativo(number);
    resulti = recursivo(number);
    printf("The result using iterative (O(n)) is: %d \n",result);
    printf("The result using recursive (O(2n - 1)) is: %d \n",resulti);
}