#include<stdio.h>

int main() {
    
    int i = 100;

    printf("Enter a number here ");
   
    scanf("%d",&i);

    printf("The number you entered is %d", i);
    printf("\nMemory address of i is %p", &i);

    
}
