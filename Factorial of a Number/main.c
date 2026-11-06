#include <stdio.h>

int main(){
    printf("Enter a number:\n");
    int i;
    long long int factorial;
    scanf("%d", & i);
    for(factorial = 1; i>0; i--){
        factorial = factorial*i;
    }
    printf("Factorial is: %d", factorial);
    return 0;
}