#include <stdio.h>
#include <math.h>

#define XSIZE 100
#define YSIZE 100

int main(void) {

  int x[XSIZE][YSIZE];
  int y[XSIZE][YSIZE];
  int z[XSIZE][YSIZE];

  int i, j, k;
  
  int r;

  /* Initialize x matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
      x[i][j] = 0;
    }
  }

  /* Initialize y matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
      y[i][j] = i + j;
    }
  }

  /* Initialize z matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
	z[i][j] = i + j;
    }
  }

  /* Print x columns */

  printf("\nPrinting X elements Column-wise\n");

  for(i=0; i<XSIZE && i < 10; i++) {
    printf("%x ",&x[i][0]);
  }

  printf("\n\nPrinting X elements Row-wise\n");

  for(j=0; j<YSIZE && j < 10; j++) {
    printf("%x ",&x[0][j]);
  }
  
  printf("\n\nPrinting Y elements Column-wise\n");

  /* Print x columns */
  for(i=0; i<XSIZE && i < 10; i++) {
    printf("%x ",&y[i][0]);
  }

  printf("\n\nPrinting Y elements Row-wise\n");

  for(j=0; j<YSIZE && j < 10; j++) {
    printf("%x ",&y[0][j]);
  }
  
  printf("\n\nPrinting Z elements Column-wise\n");

  /* Print x columns */
  for(i=0; i<XSIZE && i < 10; i++) {
    printf("%x ",&z[i][0]);
  }

  printf("\n\nPrinting Z elements Row-wise\n");

  for(j=0; j<YSIZE && j < 10; j++) {
    printf("%x ",&z[0][j]);
  }
  
  printf("\n\n");


  printf("X_Address: %x\nY_Address: %x\nZ_Address: %x\n",&x[0][0],&y[0][0],&z[0][0]);

  /* Do matrix multiply */
  for(i=0; i<XSIZE; i=i+1) {
    for(j=0; j<YSIZE; j=j+1) {
      r = 0;
      for(k=0; k<XSIZE; k=k+1) {
        r = r + y[i][k] * z[k][j];
      }
      x[i][j] = r;
    }
  }
}
