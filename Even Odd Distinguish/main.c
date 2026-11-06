#include <stdio.h>

int main(){
    int num;
    printf("\nEnter the Number:\n");
    scanf("%d", & num);
    if (num%2==0)
    {
        printf("Number is Even");
    }
    else
    {
        printf("Number is Odd");
    }
    return 0;
}