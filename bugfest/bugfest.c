//bugfest.c --- Find the many defects in this program to read and echo
//lines of text on hte console

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static const int BFRSIZE = 256;


int main(void) {

  char *bfr;

  //Loop reading lines for stdin and printing info about each to stdout
  while((bfr = malloc(BFRSIZE)) != NULL) {
    fgets(bfr,sizeof(BFRSIZE),stdin);
    int nChars = strlen(bfr);
    printf("nchars=%d, bfr=%s\n", nChars, bfr);
  }

  //Check for error condition
  if (feof(stdin)) {
    perror("Error reading stdin: ");
    return -1;
  }

  //Finished
  free(bfr);
  bfr[0] = 0;
  return 0;

}


  
      

      

  
