#include <stdio.h>
#include <math.h>

#define XSIZE 100
#define YSIZE 100
#define PRINT 0
#define BLOCKS 256
#define WORD_LENGTH 0
#define OFFSET_LENGTH 4
#define OFFSET_BITS 15
#define INDEX_LENGTH 8

int main(void) {

  int x[XSIZE][YSIZE];
  int y[XSIZE][YSIZE];
  int z[XSIZE][YSIZE];

  typedef struct {
    unsigned long tag;
    int valid;
  } Block;



  Block cache[BLOCKS] = {{0,0}};

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
  for(i=0; i<XSIZE; i=i+1) {
    for(j=0; j<YSIZE; j=j+1) {
      r = 0;
      for(k=0; k<XSIZE; k=k+1) {
        r = r + y[i][k] * z[k][j];
      }
      x[i][j] = r;
    }
  }

if (PRINT) {
  /* Initialize x matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
      printf("%d ",x[i][j]);
    }
    printf("\n");
  }
}
  return 0;

}
