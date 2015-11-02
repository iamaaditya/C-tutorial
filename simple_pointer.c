#include <stdio.h>

int main(){
    int i;
    int *i_pointer;
    i_pointer = &i;

    printf("Memory address of i is %ld", i_pointer);

}
