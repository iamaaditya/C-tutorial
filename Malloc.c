/*************************************************************************/
/*An example showing how to do dynamic memory allocation with malloc.    */
/*Ask for n, allocate a string of length n, store the first n characters */
/*of the alphabet in a string, and then print the string.                */
/*J. Storer 2014.                                                        */
/*   UNIX compile with: gcc -ansi -Wall -o Malloc Malloc.c               */
/*   Run from a UNIX terminal window by doing: ./Malloc                  */
/*************************************************************************/
#include <stdio.h>  /*Always start with this.*/
#include <stdlib.h> /*When using malloc or exit, also need this.*/
int main() {
	int i,n;

	/*
	The function malloc asks the operating system for a contiguous portion
	of memory of the specified number of bytes and returns a pointer to it.
	This statement declares and initializes a string variable s to point to
	the first of 1000 allocated bytes.
	*/
	char *s =  malloc(1000);

	/*Malloc fails by returning a NULL pointer; always check for this.*/
	if (s==NULL) {
		printf("Malloc failed."); 
		exit(1);
	}

	/*
	If we are done with some allocated memory, we can use the function
	free to let the operating system know so the memory can be reused.
	Just for this example, lets undo what we just did by freeing
	the memory we just allocated for s.
	*/
	free(s);

	/*The variable s still exists, but no longer points to any valid memory.
	Lets go ahead and do something useful with it.
	This statement initializes s to point to the first of n+1 allocated bytes
	that can be used to hold a string consisting of up to n characters
	followed by the special end of string character \0.
	Since n can never be any bigger than 26, for this little example
	we could have just declared s to be an array of length 27.
	But in general, it is very useful to be able to allocate memory when needed,
	and not be restricted to knowing in advance how much will be needed.
	*/
	printf("\nInput a number between 1 and 26: ");
	scanf("%d", &n);
	
	s =  (char *) malloc(n+1); /* Note: +1 */

	if (s==NULL) {
		printf("Malloc failed."); 
		exit(1);
	}

	if ( n<1 || n>26 ) {
		printf("ERROR - illegal input\n\n"); 
		exit(1);
	}

	/*Fill in s with the first n characters of the alphabet and print it.*/
	for (i=0; i<n; i++) 
		s[i] = (char) ( ((int) 'A') + i);

	s[n] = '\0';
	printf("The first %d characters of the alphabet are: %s\n\n",n,s);

	return 0;
}
