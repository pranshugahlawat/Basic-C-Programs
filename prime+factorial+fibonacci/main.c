#include <stdio.h>

// Function to check if a number is prime
int isPrimeFunction(){
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if(num % 1 != 0 || num < 0){
        printf("%d is not a valid input.\n", num);
    }
    else if(num == 1){
        printf("%d is not a prime number\n", num);
    }
    else{
        int i;
        for(i = 2; i < num; i++){
            if(num % i == 0){
                printf("%d is not a prime number\n", num);
                break;
            }
        }
        if(i == num){
            printf("%d is a prime number\n", num);
        }
    }
    return 0;
}
// Function to calculate factorial of a number iteratively
int factorialFunction(){
    printf("Enter a number:\n");
    int num;
    long long int factorial = 1;
    scanf("%d", &num);
    if (num < 0) {
        printf("Invalid input. Factorial is not defined for negative numbers.\n");
    } else {
        for(int i = 1; i <= num; i++){
            factorial *= i;
        }
        printf("Factorial is: %lld\n", factorial);
    }
}
// Function to generate Fibonacci series up to N terms
int generateFibonacciSeries(){
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
int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Check if a number is Prime\n");
        printf("2. Calculate Factorial of a number\n");
        printf("3. Generate Fibonacci Series\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                isPrimeFunction();
                break;
            case 2:
                factorialFunction();
                break;  
            case 3:
                generateFibonacciSeries();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}