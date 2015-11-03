/* Adi - Oct 7, 2014 */
/* program which shows you size of the pointer varaible for different types */

#include <stdio.h>

int main() {
    int    *ip;    /* pointer to an integer */
    double *dp;    /* pointer to a double */
    float  *fp;    /* pointer to a float */
    char   *ch;     /* pointer to a character */

	/* remember the size of the pointer is always the same,
	it does not matter what kind of pointer it is */
    printf("size of int pointer is %lu  \n", sizeof(ip));  // 4
    printf("size of double pointer is %lu \n" , sizeof(dp)); // 8
    printf("size of float pointer is %lu \n", sizeof(fp)); // 4
    printf("size of char pointer is %lu \n", sizeof(ch));  // 1
}
