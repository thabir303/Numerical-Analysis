#include<stdio.h>
#include<math.h>
#define maxN 200
#define F(x) ((x)*(x)*(x)+4*(x)*(x)-10)
#define g(x) sqrt((10-(x)*(x)*(x))/4)

int main()
{
    double x0,x1,val,tol=1e-6;
    printf("Enter initial guess?\n");
    scanf("%lf",&x0); //according to pdf,x0=1.5

    printf("Iter       x0          \t   x1     \t  g(x0)      \t  f(x1)\n");
    printf("-------------------------------------------------------------------\n");
    int i;
    for(i=1; i<maxN; i++)
    {
        x1=g(x0);
        val=F(x1);
        if(fabs(val)<=tol)
        {
            printf("%d\t%lf\t%lf\t%lf\t%lf\n",i,x0,x1,g(x0),F(x1));
            printf("Approximate Root=%lf\n",x1);
            break;
        }
        printf("%d\t%lf\t%lf\t%lf\t%lf\n",i,x0,x1,g(x0),F(x1));
        x0=x1;
    }
    if(i==maxN) printf("Iteration overflow\n");
}
