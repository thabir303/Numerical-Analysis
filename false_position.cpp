#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#define MAXN 200
#define F(x)  ( 3*(x) -cos(x) - 1 )

int main()
{

    int i;
    double a=0,b=1,x0,tol=1.0e-5;
    double fa,fb,fx0;

    fa=F(a);
    fb=F(b);


    if(fa*fb>=0)
    {
        printf("No Root..\n");
        return EXIT_FAILURE;
    }

    for(i=1; i<MAXN; i++)
    {

        x0=(a*fb-b*fa)/(fb-fa);
        fx0=F(x0);

        if(fabs(fx0)<=tol)
        {

            printf("Root = %lf, Itr =%d \n",x0,i);
            return EXIT_SUCCESS;
        }
        if(fa*fx0<0)
        {
            b=x0;
            fb=F(x0);
        }
        else
        {
            a=x0;
            fa=F(x0);
        }
    }
    printf("Itr overflow..\n");
    return EXIT_FAILURE;

}
