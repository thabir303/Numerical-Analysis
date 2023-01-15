#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 10

int main (void) {
  int i;
  double x[MAXN + 1]={ 0.0,0.2,0.4,0.6,0.8,1.0,1.2,1.4,1.6,1.8,2.0 };
  double f[MAXN + 1]={ 1.0,1.04,1.16,1.36,1.64,2.0,2.44,2.96,3.56,4.24,5.0 };
  double df[MAXN + 1];
  
  df[0] = ( f[1] - f[0] )/( x[1] - x[0] );  
  for (i=1; i< MAXN; i++)
    df[i] = ( f[i+1] - f[i-1] )/( x[i+1] - x[i-1] );  
  df[i] = ( f[i] - f[i-1] )/( x[i] - x[i-1] );  

  printf("- - - - - - - - - - - - - - - - - - - -\n");
  printf("  i    x[i]       f[i]       df[i]\n");
  printf("- - - - - - - - - - - - - - - - - - - -\n");
  for (i=0; i<= MAXN; i++)
    printf("%3d %10lf %10lf %10lf\n",i,x[i],f[i],df[i] );
  printf("- - - - - - - - - - - - - - - - - - - -\n");

   return EXIT_SUCCESS;
}
