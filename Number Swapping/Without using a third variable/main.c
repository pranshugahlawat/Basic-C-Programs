#include <stdio.h>

int main(){
    int a = 10;
    int b = 20;
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    return 0;
}

