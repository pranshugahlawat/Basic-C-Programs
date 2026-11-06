#include <stdio.h>

int main(){
    int num;
    printf("\nEnter the Number:\n");
    scanf("%d", & num);
    if (num>0)
    {
        printf("\nNumber is Positive.");
    }
    else if (num<0)
    {
        printf("\nNumber is Negetive.");
    }
    else
    {
        printf("Number is Zero");
    }
    return 0;
}