/***************************************************************************/
/*Ask user to input a string and print it in parentheses, J. Storer, 2014. */
/*   Compile with: gcc -ansi -Wall -o PrintString PrintString.c            */
/*   Run from a terminal window by doing: ./PrintString                    */
/***************************************************************************/
#include <stdio.h>
#define MaxString 100

/*
A string variable s that can hold up to a maximum of n characters is
is a pointer to the first byte of an array of n+1 bytes that is indexed
from 0 to n. s[0], s[1], ... s[n-1] refer to the characters of s if they
are defined. The last character of s by C convention is followed by the
special end of string character \0. If s has n characters, then s[n]='\0',
but if s has fewer than n characters, for example if s = "abc", then
s[0] = 'a'. s[1] = 'b', s[2] = 'c', s[3] = '\0', and it doesn't matter
what is stored in s[4] ... s[n]. Another important special character
is \n, the end of line character, which may be included, for example,
when you read a string from user input. For example, if we read "abc" from
the user, it would probably come in with s[3] = '\n' and s[4] = '\0'.
Note that although we typically use the notation s[0] to refer to the first element
of s, we could also refer to it as *s. The variable s is nothing more
than a pointer to its first element.
*/

/*NOTE:
The \0 string ending is absolutely essential,
and the programmer is often responsible for inserting it
when building strings character-by-character.
*/ 

/*Return the length of a string.*/
/*For an illegal string that does not end with \0, MaxString is returned.*/
/*The type char s[] (equivalent to char *s) does not specify the length of the*/
/*string pointed to by s, it could have any length; this function just starts at*/
/*the beginning and looks for the end of string symbol (but we include the MaxString*/
/*check just in case we have a bug somewhere that made an illegal string).*/
int StringLength(char s[]) {
	int i=0;
	while ( (i<MaxString) && (s[i]!='\0') ) ++i;
	return (i);
}

/*Read a line from a file (or stdin) and remove the ending \n return character.*/
/*Instead of gets, we use fgets that takes two additional arguments,*/
/*a maxium string length and file pointer (which can be "stdin" for the standard input).*/
/*This prevents a warning message that the function gets is "unsafe"*/
/*becasue buffer overflow can be used to write into unauthorized memory*/
/*(unlike fgets that allocates new memory for the maximum string length).*/
int ReadLine(char *s, FILE *fp) {
	int ls;
	if (fgets(s,MaxString,fp) == NULL) s[0]='\0';
	ls=StringLength(s);
	if ( (ls>0) && (s[ls-1]=='\n') ) s[--ls]='\0';
	return(ls);
}

/*Start of main program.*/
int main() {
	char s[MaxString];
	int ls, i;

	printf("\nEnter a string: ");
	
	ls = ReadLine(s,stdin);
	
	if ( ls <= 0 || ls > (MaxString-2)  ) {
		printf("ILLEGAL INPUT\n");
	}
	else {
	   for (i=ls; i>=0; i--) s[i]=s[i-1];    /*shift right (and overwrite the ending \0)*/
	   s[0] = '(';                           /*add left parenthesis*/
	   s[ls+1] = ')';                        /*add right parenthesis*/
	   s[ls+2] = '\0';                       /*add the \0 end of string character*/
	   printf("With () it becomes: %s\n",s); /*print s followed by the newline character*/
	   }
	printf("Bye.\n\n");

return 0;
}
