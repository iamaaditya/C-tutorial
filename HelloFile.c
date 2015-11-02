/****************************************************************/
/*Print hello to a file, J. Storer 2014.                        */
/*   Compile with: gcc -ansi -Wall -o HelloFile HelloFile.c     */
/*   Run from a terminal window by doing: ./HelloFile           */
/****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define OutputFileName "FileOut"

int main() {

    FILE *outfile;

    outfile = fopen(OutputFileName,"w");

    if(outfile == NULL) {
         printf("Unable to create output file: %s\n",OutputFileName);
         return -1;
    }

    fprintf(outfile,"Hello\n");
    fclose(outfile);

return 0;
}
