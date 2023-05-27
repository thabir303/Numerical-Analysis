#include<stdio.h>
#define row 11
#define col 4
#define B_row 11
#define B_col 1
int t_row=col,t_col=row;
int main()
{
    double A[row][col]= { 1,0,0,0,
                          1,0.2,0.04,0.008,
                          1,0.4,0.16,0.064,
                          1,0.6,0.36,0.216,
                          1,0.8,.64,.512,
                          1,1,1,1,
                          1,1.2,1.44,1.728,
                          1,1.4,1.96,2.744,
                          1,1.6,2.56,4.096,
                          1,1.8,3.24,5.832,
                          1,2,4,8
                        };

    double B[B_row][B_col]= {1,1.04,1.16,1.36,1.64,2.0,2.44,2.96,3.56,4.24,5};

    double AT[col][row];

    for(int i=0; i<t_row; i++)
    {
        for(int j=0; j<t_col; j++)
        {
            AT[i][j]=A[j][i];
        }
    }
    printf("\n\nA Matrix is :\n");

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("%lf  ",A[i][j]);
        }
        printf("\n");
    }

    printf("\n\nB matrix is :\n");
    for(int i=0; i<B_row; i++)
    {
        for(int j=0; j<B_col; j++)
        {
            printf("%lf  ",B[i][j]);

        }
        printf("\n");
    }



    printf("Transpose Matrix(AT) is:\n");
    for(int i=0; i<t_row; i++)
    {
        for(int j=0; j<t_col; j++)
        {
            printf("%lf  ",AT[i][j]);
        }
        printf("\n");

    }

    double mulA[t_row][col];

    for(int i=0; i<t_row; i++)
    {
        for(int j=0; j<col; j++)
        {
            mulA[i][j]=0;

            for(int k=0; k<row; k++)
            {
                mulA[i][j]+=AT[i][k]*A[k][j];
            }
        }
    }

    printf("\n\nMultiplication Matrix is(AT*A) :\n");
    for(int i=0; i<t_row; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("%lf  ",mulA[i][j]);
        }

        printf("\n");

    }


    double mulB[t_row][B_col];
    for(int i=0; i<t_row; i++)
    {
        for(int j=0; j<B_col; j++)
        {
            mulB[i][j]=0;
            for(int k=0; k<B_row; k++)
            {
                mulB[i][j]+=AT[i][k]*B[k][j];
            }

        }
    }

    printf("\n\nMultiplication Matrix(AT*B) is :\n");

    for(int i=0; i<t_row; i++)
    {
        for(int j=0; j<B_col; j++)
        {
            printf("%lf  ",mulB[i][j]);
        }

        printf("\n");

    }
    int i,j;
    double obM[t_row][col+1];
    for( i=0; i<t_row; i++)
    {
        for(j=0; j<col; j++)
        {
            obM[i][j]=mulA[i][j];
        }

        obM[i][j]=mulB[i][0];
    }

    printf("\n\nAugmented Matrix is :\n");
    for(i=0; i<t_row; i++)
    {
        for(j=0; j<col+1; j++)
        {
            printf("%lf  ",obM[i][j]);
        }

        printf("\n");
    }

    double M,L;
    int k;

    for (i=0; i<t_row; i++)
    {
        L = obM[i][i];
        for (j=i; j<col+1; j++)
        {
            obM[i][j] = obM[i][j]/L;
        }

        for (k=0; k<t_row; k++)
        {
            if (k != i)
            {
                M = -obM[k][i];
                for (j=i; j<col+1; j++)
                {
                    obM[k][j] = obM[k][j] + M*obM[i][j];
                }
            }
        }
    }
    printf("\n\nDiagonal Matrix is :\n");
    for(i=0; i<t_row; i++)
    {
        for(j=0; j<col+1; j++)
        {
            printf("%lf  ",obM[i][j]);
        }

        printf("\n");
    }

    printf("\n\nFinal answer (X)= \n");
    for(int i=0; i<t_row; i++)
    {
        for(int j=col; j<col+1; j++)
        {
            printf("%lf    ",obM[i][j]);
        }
        printf("\n");

    }
    printf("\n");
}
