#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M_ROW 11
#define M_COL 4

int i, j, k;
double A[M_ROW][M_ROW] ;
double b[M_ROW] ;
double x[M_ROW],fx[M_ROW],At[M_ROW][M_ROW],AAt[M_ROW][M_ROW];
void multiplication(double a[M_ROW][M_ROW],double b[M_ROW][M_ROW], int m, int n,double c[M_ROW][M_ROW]);
int main (void)
{

    printf("Enter the value of x & f(x) :\n");
    for(int i=0; i<M_ROW; i++)
    {
        scanf("%lf",&x[i]);
        scanf("%lf",&fx[i]);

    }

    printf("Let's create the matrix :\n");


    for(i =0; i<M_ROW; i++)
    {
        A[i][0]=1;
    }

    for(int i=1; i<M_ROW; i++)
    {
        for(int j=1; j<M_COL; j++)
        {
            A[i][j]=pow(x[i],j);
        }
    }

    for (i=0; i< M_ROW; i++)
    {
        for (j=0; j< M_COL; j++)
        {
            printf(" %lf ", A[i][j] );
        }
        printf("\n");
    }

    printf("Transpose of the matrix :\n");
    for(int i=0; i<M_ROW; i++)
    {
        for(int j=0; j<M_COL; j++)
        {
            At[j][i]=A[i][j];
        }
    }
    for (i=0; i< M_COL; i++)
    {
        for (j=0; j< M_ROW; j++)
        {
            printf(" %lf ", At[i][j] );
        }
        printf("\n");
    }
    printf("MULTIPLICATION :\n");
    multiplication(At,A,M_COL,M_ROW,AAt);

    for(int i=0; i<M_COL; i++)
    {
        for(int j=0; j<M_COL; j++)
        {
            printf(" %lf ",AAt[i][j]);
        }
        printf("\n");
    }

    printf("Create column matrix :\n");
    double sum=0;
    for(int i=0; i<M_COL; i++)
    {
        for(int j=0; j<M_ROW; j++)
        {
            sum= sum+At[i][j]*fx[j];
        }
        b[i]=sum;
        sum=0;
    }
    for(int i=0; i<M_COL; i++)
    {
        printf("\n%lf ",b[i]);
    }

    double Ab[M_COL][M_COL+1];
    double M, L;

    for (i=0; i< M_COL; i++)
    {
        for (j=0; j< M_COL; j++)
        {
            Ab[i][j] = AAt[i][j];
        }
        Ab[i][j] = b[i];
    }

    printf("[ [A] [b] ] :\n");
    for (i=0; i< M_COL; i++)
    {
        for (j=0; j< M_COL+1; j++)
        {
            printf("%9.3lf", Ab[i][j] );
        }
        printf("\n");
    }


    for (i=0; i<M_COL; i++)
    {
        L = Ab[i][i];
        for (j=i; j<M_COL+1; j++)
        {
            Ab[i][j] = Ab[i][j]/L;
        }

        for (k=0; k<M_COL; k++)
        {
            if (k != i)
            {
                M = -Ab[k][i];
                for (j=i; j<M_COL+1; j++)
                {
                    Ab[k][j] = Ab[k][j] + M*Ab[i][j];
                }
            }
        }
    }


    printf("[ [A'] [b'] ] :\n");
    for (i=0; i< M_COL; i++)
    {
        for (j=0; j< M_COL+1; j++)
        {
            printf("%9.3lf", Ab[i][j] );
        }
        printf("\n");
    }
    printf("So,the value of corresponding coefficients B0, B1, B2, B3 are :");

    for (i=0; i< M_COL; i++)
    {
        printf("%9.3lf ", Ab[i][M_COL] );
    }
    return EXIT_SUCCESS;
}
void multiplication(double a[M_ROW][M_ROW],double b[M_ROW][M_ROW], int m, int n,double c[M_ROW][M_ROW])
{
    double sum =0;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<n; k++)
            {
                c[i][j]=a[i][k]*b[k][j];
                sum=sum+c[i][j];

            }
            c[i][j]=sum;
            sum=0;
        }
    }
}

