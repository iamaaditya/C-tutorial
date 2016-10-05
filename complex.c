/* demnostration of struct using concept of complex number */
/* Adi  Wed Oct  5 11:28:18 EDT 2016 */


#include <stdlib.h>
#include <stdio.h>

int main_garbage() {

    float real1, real2;
    float img1, img2;
    
    real1 = 10;
    real2 = 2;

    img1 = 3;
    img2 = 6;


    float real3 = real1 + real2;
    float img3 = img1 + img2;

    printf( "\nreal : %f", real3);
    printf( "\nimgn : %f", img3);

    return 0;
}





struct complex {

    float real;
    float img;

};

typedef struct complex com;

int main(){ 

    com c1, c2, c3;
    /* struct complex c1, c2, c3; */

    c1.real = 10;
    c1.img  = 2;

    c2.real = 10;
    c2.img  = 2;

    c3.real = c1.real + c2.real;
    c3.img  = c1.img  + c2.img;


    printf("\nreal: %f", c3.real);
    printf("\nimgn: %f", c3.img);


    return 0;

}

