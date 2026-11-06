#include <stdio.h>

int main(){
    int marks;
    printf("Enter your marks (in %%): ");
    scanf("%d", &marks);
    if(marks >= 100){
        printf("Enter a valid input");
    }else if(marks >= 95){
        printf("A+");
    }else if(marks >= 90){
        printf("A");
    }else if(marks >= 85){
        printf("B+");
    }else if(marks >= 80){
        printf("B");
    }else if(marks >= 75){
        printf("C+");
    }else if(marks >= 70){
        printf("C");
    }else if(marks >= 65){
        printf("D+");
    }else if(marks >= 60){
        printf("D");
    }else if(marks >= 55){
        printf("E+");
    }else if(marks >= 50){
        printf("E");
    }else{
        printf("F");
    }
    return 0;
}