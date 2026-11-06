#include <stdio.h>

int main(){
    int a = 0;
    int b = 1;
    printf("%d \t%d \t", a, b);
    for(int i = 2; i < 10; i++){
        int c = a + b;
        printf("%d \t", c);
        a = b;
        b = c;
    }
    return 0;
}