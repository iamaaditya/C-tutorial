#include <stdio.h>

int main(){
    int i = 99;
    int *i_pointer;
    i_pointer = &i;

    printf("Memory address of i is %p", &i);
    printf("\nValue of i_pointer is  %p", i_pointer);

    printf("\nvalue of i is %d", i);
    printf("\nvalue of i is %d", *i_pointer);

}
