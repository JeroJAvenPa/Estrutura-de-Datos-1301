#include<stdio.h>
int number, result,i;

int recursivo(int num){//o(2n-1)

    if(num != 0)//si se cumple quiere decir que todavia no terminamos y se vuelve a llamar la funcion
        return(num * recursivo(num-1));//aqui ej num=4 entonces 4 * factorial(3) y entonces se ejecuta factorial(3) y asi
    else// si es 0 significa que ya acabamos y entonces regresamos un 1 para que factoria(0) regrese un 1 y no se cambie el resultado
        return(1);//regresa un 1 a la funcion factorial(x) anterior

}

int main(){
    printf("Pls give me a number:");
    scanf("%d",&number);
    result = recursivo(number);
    printf("The result using recursive (O(2n - 1)) is: %d \n",result);
}