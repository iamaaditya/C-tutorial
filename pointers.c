#include <stdio.h>

int main(){
    int i;  // ordinary integer variable
    int *p; // a pointer variable, which will point to integer 
            // but remember like I said in class, all pointers are themselves of size int (becuase they store memroy location, an integer value

    i = 3;  // simple value assignment to a variable

    p = &i; // this step gives the address of variable i to p

    printf("Address of variable i, using i is %p \n", &i);
    printf("Address of variable i, using p is %p \n", p);

    printf("Value of variable i, using i is %d \n", i);
    printf("Value of variable i, using p is %d \n", *p);

}

