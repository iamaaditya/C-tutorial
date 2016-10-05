#include<stdio.h>

int main(){

    int x[10];
    int i;

    for(i=0;i<10;i++) {
        x[i] = 99;
    }

    printf(" what should be printed here %d", x[-1]);

}

