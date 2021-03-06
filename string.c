/* Adi - Oct 7, 2014 */
/* This code shows more meaning full use of structs */
/* Also you will get to see how pointers can be used to store strings */

#include <stdio.h>
#include <string.h>

/* custom data type */
struct Addresses {
    char firstLine[50] ;
    char lastLine[50] ;
    /*struct Addresses *WOAh;  */
    /* I am commenting this code. I left it just so that you can remember why we had
    this and how it allowed us to use the struct Addresses which is still under build 
    process */

};

/* if you want to print variable which is not the primitive type, you have to tell
the compiler how to print those */
void printAddress(struct Addresses address_to_print) {
    printf("\n %s \n %s \n", address_to_print.firstLine, address_to_print.lastLine);
}

int main()
{


    struct Addresses address;

    /* use strcpy to copy const string to variable */
    strcpy(address.firstLine, "Brandeis University");
    strcpy(address.lastLine, "112 South Street");
    

    printAddress(address);
    /* I hope you can now appreciate why structs are useful when used as 
    complex data types. It helps write clean code */

}
