#include<stdio.h>
int number, result, i;

int factorial(int num){
    int total = 1;
    for(i=1; i <= num; i++)
        total *= i;
    return(total);
}

int main(){
    printf("Pls give me a number:");
    scanf("%d",&number);
    result = factorial(number);
    printf("The result using iterative (O(n)) is: %d \n",result);
}