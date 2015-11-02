/* Adi - Oct 7, 2014 */
/* Code which shows simple struct */
#include <stdlib.h>
#include <stdio.h>

/* Struct are used to form complex data types */

struct foo
{
  int x;   // This struct has an integer and 
  float y; // a float
};


int main() {
	
	struct foo var;  // var is a variable of type foo which is a construct
					// hence we have to use the keyword struct

	struct foo* pvar;  // pvar is a pointer which will point to a variable of type foo


	var.x = 5;

	//(&var)->y = 14.3;    // this is not required, but I left this line
							// since I showed in class what this does.
							// if you are curious, go ahead uncomment it and 
							// run the program. don't forget the print the variables

	pvar = &var;  	

	printf("var.x \t\t\t %d \n", var.x);
	printf("(&var)->y \t\t %f \n", (&var)->y);

	pvar->y = 22.4;   // -> is used to access members of struct when called from a pointer
	(*pvar).x = 6;   // if arrow is confusing you could just do this



	printf("var.x \t\t\t %d \n", var.x);
	printf("(&var)->y \t\t %f \n", (&var)->y);

	printf("(*pvar).x \t\t %d \n", (*pvar).x);
	printf("pvar->y \t\t %f \n", pvar->y);


}
