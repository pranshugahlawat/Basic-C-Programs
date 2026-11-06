#include <stdio.h>

int main(){
    int a, b, c;
    printf("\nEnter the first number: ");
    scanf("%d", &a);
    printf("\nEnter the second number: ");
    scanf("%d", &b);
    printf("\nEnter the third number: ");
    scanf("%d", &c);
    int max = a;
    if (b > max) {
        max = b;
    }
    else if (c > max) {
        max = c;
    }
    printf("\nThe maximum number is: %d", max);
    return 0;
}