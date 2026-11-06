#include <stdio.h>

int main() {
    float celsius, fahrenheit;
    printf("\nEnter temperature in Celsius:\n");
    scanf("%f", &celsius);
    fahrenheit = (celsius)*(9.0/5.0) + 32;
    printf("\nTemperature in Fahrenheit is : %f", fahrenheit);
}