#include<stdio.h>
#include<math.h>
#define F(x) ((x)*(x)*(x)+4*(x)*(x)-10)
#define Df(x) ( 3*(x)*(x) + 8*(x) )

int main()
{
     int i;
     double x0=1.5,x1,x2,tol=1e-6;
     double fx0,dfx0;

     fx0=F(x0);
     dfx0=Df(x0);

     for(i=1;i<200;i++)
     {
         x1=x0-fx0/dfx0;
         x2=F(x1);
         if(fabs(x2)<=tol)
         {
             printf("Root =%lf",x1);
             break;
         }
         x0=x1;
         fx0=x2;
         dfx0=Df(x1);
     }
}
