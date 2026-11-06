#include <stdio.h>

int add(){
    int a,b;
    printf("\nAddition:");
    printf("\nEnter the first number: ");
    scanf("%d", &a);
    printf("\nEnter the second number: ");
    scanf("%d", &b);
    printf("\nThe sum of %d and %d is %d", a, b, a+b);
    return 0;
}
int subtract(){
    int a,b;
    printf("\nSubtraction:");
    printf("\nEnter the first number: ");
    scanf("%d", &a);
    printf("\nEnter the second number: ");
    scanf("%d", &b);
    printf("\nThe difference of %d and %d is %d", a, b, a-b);
    return 0;
}
int multiply(){
    int a,b;
    printf("\nMultiplication:");
    printf("\nEnter the first number: ");
    scanf("%d", &a);
    printf("\nEnter the second number: ");
    scanf("%d", &b);
    printf("\nThe product of %d and %d is %d", a, b, a*b);
    return 0;
}
int divide(){
    int a,b;
    printf("\nDivision:");
    printf("\nEnter the first number: ");
    scanf("%d", &a);
    printf("\nEnter the second number: ");
    scanf("%d", &b);
    printf("\nThe division of %d and %d is %d", a, b, a/b);
    return 0;
}
int main(){
    int index;
    printf("\nEnter the operation you want to perform:\n");
    printf("\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit\n Enter your choice: ");
    scanf("%d", &index);
    switch (index)
    {
    case 1:
        add();
        main();
    case 2:
        subtract();
        main();
    case 3:
        multiply();
        main();
    case 4:
        divide();
        main();
    case 5:
    printf("Thanks for using the calculator");
        break;
    default:
        printf("Invalid input\n");
        main();
    }
    return 0;
}