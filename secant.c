#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 200
#define F(x)  ( (x)*(x)*(x) + 4*(x)*(x) - 10 )

int main()
{
    int i;
    double x1=2,x2=1.5,x3,x4,tol=1.0e-6;
    double fx1,fx2;

    fx1=F(x1); fx2=F(x2);

    for(i=1;i<MAXN;i++)
    {
        x3=(x1*fx2-x2*fx1)/(fx2-fx1);
        x4=F(x3);
        if(fabs(x4)<=tol)
        {
            printf("Root =%lf,Itr %d",x3,i);
            break;
        }
        x1=x2;
        x2=x3;
        fx1=fx2;
        fx2=x4;
      /*   x1 = x2;
        x2 = x3;
        fx1 = fx2;
        fx2 = fx3; */
    }
}
