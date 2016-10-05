/*******************************************************************/
/*A simple example of using the scanf function to read an integer. */
/*Add two integers.                                                */
/*J. Storer, 2014.                                                 */
/*   UNIX compile with: gcc  -ansi -Wall -o Integers Integers.c    */
/*   Run from a UNIX terminal window by doing: ./Integers          */
/*******************************************************************/
#include <stdio.h>

/*
The scanf function can be used to read formatted input.
You give it the type of the item to be read and a variable
into which it the item is to be placed. Because this variable needs to
be modified by the scanf function, you need to pass a pointer to it,
which is done by preceding it with & in the call.
*/

int main () {
int integer1, integer2;

printf("\nEnter an integer: ");
scanf("%d", &integer1);

printf("value of integer1 is %d \n", integer1);
printf("Enter an second integer: ");
scanf("%d", &integer2);

printf("value of integer1 is %d \n", integer1);
printf("The sum of these two integers is: %d\n\n", integer1 + integer2);

return 0;
}

