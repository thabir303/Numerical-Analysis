#include<stdio.h>
#include<math.h>
#define max 200
int main()
{
    float x[max+1],sinx[max+1],cosx[max+1];
    float a=0,b=2*3.1416;
    int n=max;
    float sum=0;
    x[0]=sum;
    for(int i=0;i<max;i++)
   {   
       float p=(b/max);
       sum=sum+p;
       x[i]=sum;      
   }
   for(int i=0;i<max;i++){
   sinx[i]=sin(x[i]);
   cosx[i]=cos(x[i]);}
   ///printf("%f \n",x[i]);
   printf("x,sin(x),cos(x)\n");  
   for(int i=0;i<max;i++)
printf("%lf, %lf, %lf\n",x[i],sinx[i],cosx[i]);
printf("\n");
}
    




