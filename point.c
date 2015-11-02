/* Adi - Oct 7, 2014 */
/* program which shows you the use of the sizeof operator */

#include <stdio.h>

int main(){
    int x = 100;
    double y = 10.900;

    /* sizeof oeprator can print the size of a variable or a data type */
    printf("size of x is %lu \n", sizeof(x));
    printf("size of y is %lu", sizeof(y));

    return 0;
}
