#include <stdio.h>

int main(){
    int i,n;
    printf("\nEnter a number:\n");
    scanf("%d", & n);
    int sum=0;
    for (i=1; i<=n; i++){
        sum = sum+i;
    }
    printf("Sum of First %d Natural Numbers is %d", n, sum);
    return 0;
}