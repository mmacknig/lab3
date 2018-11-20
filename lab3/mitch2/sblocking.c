#include <stdio.h>
#include <math.h>

#define XSIZE 10
#define YSIZE 10
#define PRINT 0
#define B 4

int main(void) {

  int x[XSIZE][YSIZE];
  int y[XSIZE][YSIZE];
  int z[XSIZE][YSIZE];

  int i, j, im, jm, ii, jj, k, kk, q, k1;
  
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
      y[i][j] = i + j + 2;
    }
  }

  /* Initialize z matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
	z[i][j] = i + j + 2;
    }
  }

  /* Do matrix multiply */
  for(i=0; i<XSIZE; i=i+B) {
    im = i + B;
    if (im >= XSIZE) {
      im = XSIZE;
    }
    for(j=0; j<YSIZE; j=j+B) {
      jm = j +B;
      if (jm >= XSIZE) {
        jm = XSIZE;
      }
      for (ii = i; ii < im; ii=ii+1) { 
        for (jj = j; jj < jm; jj=jj+1) { 
	printf("%d ",(ii+1)*(jj+1));
          for(k1=0; k1<(XSIZE/B + (XSIZE%B>0)); k1=k1+1) {
            r = 0;
            kk = k1*B;
       	    if((kk+B) < XSIZE) {
	      q = kk + B;
	    }
	    else {
	      q = XSIZE;
	    }
	    for(k=kk; k<q; k=k+1) {
              r = r + y[ii][k]*z[k][jj];
	    }
            x[ii][jj] = x[ii][jj] + r;
          }

        }
printf("\n");
      }
printf("\n");
    }
  }

  /* Initialize x matrix */
  if (PRINT) {
    for(i=0; i<XSIZE; i++) {
      for(j=0; j<YSIZE; j++) {
        printf("%d ",x[i][j]);
      }
        printf("\n");
    }
    for(i=0; i<XSIZE; i++) {
      for(j=0; j<YSIZE; j++) {
        printf("%d ",z[i][j]);
      }
      printf("\n");
    }
  }

  return 0;
}

