#include <stdio.h>
int main() {

    int i = 100;

    int *p;
    

    p  = &i;

    printf("address of i is %p", &i);
    printf("\naddress of i is %p", p);

    *p = 200;

    printf("\nvalue of i is %d", i);
    (*p)++;
    printf("\nvalue of i is %d", i);


        


    


    return 0;

}
