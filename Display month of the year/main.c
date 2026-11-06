#include <stdio.h>

int main(){
    int month;
    printf("\nEnter the month number: ");
    scanf("%d", &month);
    switch (month)
    {
    case 1:
        printf("\nThis month is January");
        break;
    case 2:
        printf("\nThis month is February");
        break;
    case 3:
        printf("\nThis month is March");
        break;
    case 4:
        printf("\nThis month is April");
        break;
    case 5:
        printf("\nThis month is May");
        break;
    case 6:
        printf("\nThis month is June");
        break;
    case 7:
        printf("\nThis month is July");
        break;
    case 8:
        printf("\nThis month is August");
        break;
    case 9:
        printf("\nThis month is September");
        break;
    case 10:
        printf("\nThis month is October");
        break;
    case 11:
        printf("\nThis month is November");
        break;
    case 12:
        printf("\nThis month is December");
        break;
    default:
        printf("\nInvalid month number");
        break;
    return 0;
}
}