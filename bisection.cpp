#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#define F(x)  ( (x)*(x)*(x) + 4*(x)*(x) -10)

int main()
{

    int i;
    double a=1.25,b=1.5,tol=1.0e-5,x0;
    double fa,fb,fx0;

    fa=F(a); fb=F(b);

    if(F(a)*F(b)>=0)
       cout<<"No Root\n";

    for(i=1;i<200;i++)
    {
        x0=(a+b)/2;
        fx0=F(x0);

        if(fabs(fx0)<=tol){
            printf("Root = %lf, Itr =%d \n",x0,i);
            return EXIT_SUCCESS;
        }
        if(fa*fx0<0){
            b=x0;
            fb=F(x0);
        } else {
         a=x0;
         fa=F(x0);
        }
    }
    printf("Itr overflow...\n");
    return EXIT_FAILURE;

}
