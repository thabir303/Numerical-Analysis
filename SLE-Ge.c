#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXROW 3
#define MAXCOL 3
#define PI   3.14159


int main (void) {
  int i, j, k;
  //double A[MAXROW][MAXCOL] = { {1,3,2}, {1,2,3}, {2,-1,4}};
  double A[MAXROW][MAXCOL] = { {1,-1,2}, {1,2,3}, {3,-4,-5}};
  //double b[MAXROW] = {17,16,13};
  double b[MAXROW] = {3,5,-13};
  double Ab[MAXROW][MAXCOL+1];
  double M;

  for (i=0; i< MAXROW; i++) {
    for (j=0; j< MAXCOL; j++) {
      Ab[i][j] = A[i][j];
    }
    Ab[i][j] = b[i];
  }

  printf("[ [A] [b] ] :\n");
  for (i=0; i< MAXROW; i++) {
    for (j=0; j< MAXCOL+1; j++) {
      printf("%9.3lf", Ab[i][j] );
    }
    printf("\n");
  }


  for (i=0; i<MAXROW; i++) {
    for (k=i+1; k<MAXROW; k++) {
      M = -Ab[k][i]/Ab[i][i];
      for (j=i; j<MAXCOL+1; j++) {
        Ab[k][j] = Ab[k][j] + M*Ab[i][j];
      }
    }
  }


  printf("[ [A'] [b'] ] :\n");
  for (i=0; i< MAXROW; i++) {
    for (j=0; j< MAXCOL+1; j++) {
      printf("%9.3lf", Ab[i][j] );
    }
    printf("\n");
  }

  return EXIT_SUCCESS;
}
