/*********************************************************************/
/*An example of using the scanf function to read formatted input.    */
/*Add, subtract, multiply, or divide  a real number from an integer. */
/*J. Storer, 2014.                                                   */
/*   UNIX compile with: gcc  -ansi -Wall -o Numbers Numbers.c        */
/*   Run from a UNIX terminal window by doing: ./Numbers             */
/*********************************************************************/
#include <stdio.h>

/*
The scanf function can be used to read formatted input.
You give it the type of the item to be read and a variable
into which it the item is to be placed. Because this variable needs to
be modified by the scanf function, you need to pass a pointer to it,
which is done by preceding it with & in the call.
*/

int main () {
int integer, d;
float RealNumber, result;
char operation;

printf("\nEnter an integer: ");
scanf("%d", &integer);

printf("Enter one of the operations +, -, *, /: ");

scanf(" %c", &operation);

printf("Enter a real number: ");
scanf("%f", &RealNumber);

switch (operation) {
     case '+':
          result = integer + RealNumber;
          break;
     case '-':
          result = integer - RealNumber;
          break; 
     case '*':
          result = integer * RealNumber;
          break;
     case '/':
          result = integer / RealNumber;
          break;
     default:
          result=0; 
     }     
 
printf("How many decimal places to print? ");
scanf("%d", &d);

printf("The result is %.*f\n", d, result);
printf("The rounded down to an integer is %d\n\n", (int)result);

return 0;
}
