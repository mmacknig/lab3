#include <stdio.h>
#include <math.h>

#define XSIZE 400
#define YSIZE 400
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
      y[i][j] = i + j;
    }
  }

  /* Initialize z matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
	z[i][j] = i + j;
    }
  }


  /* Do matrix multiply */
  unsigned long x0 = (unsigned long) &x[0][0];
  unsigned long y0 = (unsigned long) &y[0][0];
  unsigned long z0 = (unsigned long) &z[0][0];
  x0 = 0;
  y0 = 0;
  z0 = 0;
  long int hits = 0;
  long int misses = 0;
  unsigned long address;
  unsigned long y_offset;
  unsigned long y_index;
  unsigned long y_tag;
  unsigned long z_tag;
  unsigned long z_index;
  unsigned long z_offset;
  unsigned long x_index;
  unsigned long x_offset;
  unsigned long x_tag;

  int xx = 0;
  int yy = 0;
  int zz = 0;

  for(i=0; i<XSIZE; i=i+1) {
    for(j=0; j<YSIZE; j=j+1) {
      r = 0;
      for(k=0; k<XSIZE; k=k+1) {

	address = ((unsigned long) &y[i][k] - y0) >> WORD_LENGTH;
	y_offset = address & OFFSET_BITS;
	y_index = address >> OFFSET_LENGTH;
	y_index = y_index & (BLOCKS-1);
	y_tag = address >> (INDEX_LENGTH + OFFSET_LENGTH);

//	printf("ROW: %d, COLUMN: %d, ADDRESS: %x, SHIFTED: %x\n",i,j,address,address>>4);
//	printf("BLOCK: %lx, WORD: %lx, TAG: %lx\n",y_index, y_offset,y_tag);
//if (y_index == 1) {
//	printf("I: %d, J: %d, K  %d\n",i,j,k);	printf("%x %x\n",y_index, cache[y_index].valid);
//}
        if (cache[y_index].valid ==  1 && cache[y_index].tag == y_tag) {
	   hits++;
	}
	else {
//printf("y: %x %x %x\n",y_index,y_tag,cache[y_index].tag);
	   misses++;
	   cache[y_index].tag = y_tag;
	   cache[y_index].valid = 1;
	}
        address = ((unsigned long) &z[k][j] - z0) >> WORD_LENGTH;
        z_offset = address & OFFSET_BITS;
        z_index = address >> OFFSET_LENGTH;
        z_index = z_index & (BLOCKS-1);
        z_tag = address >> (INDEX_LENGTH + OFFSET_LENGTH);

//	printf("ROW: %d, COLUMN: %d, ADDRESS: %x, SHIFTED: %x\n",i,j,address,address>>4);
//	printf("BLOCK: %lx, WORD: %lx, TAG: %x\n",z_index, z_offset,z_tag);
	
	
        if (cache[z_index].valid ==  1 && cache[z_index].tag == z_tag) {
	   hits++;
	}
	else {
//printf("z: %x %x %x\n",z_index, z_tag, cache[z_index].tag);
	   misses++;
	   cache[z_index].tag = z_tag;
	   cache[z_index].valid = 1;
	}
yy++;
zz++;
        r = r + y[i][k] * z[k][j];

      }
//      printf("i: %d, j: %d\n", i, j);
      address = ((unsigned long) &x[i][j] - x0) >> WORD_LENGTH;
      x_offset = address & OFFSET_BITS;
      x_index = address >> OFFSET_LENGTH;
      x_index = x_index & (BLOCKS-1);
      x_tag = address >> (INDEX_LENGTH + OFFSET_LENGTH);
//      printf("%d, %d, %d, %d",WORD_LENGTH,OFFSET_BITS,OFFSET_LENGTH,INDEX_LENGTH);

//	printf("ROW: %d, COLUMN: %d, ADDRESS: %lx, SHIFTED: %lx\n",i,j,address,address>>4);
//	printf("BLOCK: %lx, WORD: %lx, TAG: %lx\n",x_index, x_offset,x_tag);
	
      if (cache[x_index].valid ==  1 && cache[x_index].tag == x_tag) {
        hits++;
      }
      else {
//printf("x: %d %x %x\n",xx,x_tag, cache[x_index].tag);
        misses++;
        cache[x_index].tag = x_tag;
        cache[x_index].valid = 1;
      }
xx++;
//      printf("INDEX: %x, OFFSET: %x\n",x_index,x_offset);
      x[i][j] = r;
//      printf("%d ",r);
    }
//     printf("\n");
  }
  float rate = (float)misses/((float)hits+(float)misses);
  printf("Hits: %ld\nMisses: %ld\nMiss_Rate: %f\n",hits,misses,rate);

  return 0;

}
