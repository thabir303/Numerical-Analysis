

#include <stdio.h>
#include <math.h>

double eigenValues[10];
double uMatrix[10][10];
double vMatrix[10][10];
double sMatrix[10][10];
double matrix[10][10];
double transMatrix[10][10];
double AA_T[10][10];
double A_TA[10][10];

void calculateEigenvaluesAndEigenvectors(int size, int x)
{
    int n, i, j, p, q, flag;
    double a[10][10], d[10][10], s[10][10], s1[10][10], s1t[10][10];
    double temp[10][10], theta, zero = 1e-5, max, pi = 3.141592654;

    n = size;

    if (x == 0)
    {
        for (i = 0; i < n; i++)
        {

            for (j = 0; j < n; j++)
            {
                a[i][j] = AA_T[i][j];
            }
        }
    }
    else
    {

        for (i = 0; i < n; i++)
        {

            for (j = 0; j < n; j++)
            {
                a[i][j] = A_TA[i][j];
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            d[i][j] = a[i][j];
            if (i == j)
                s[i][j] = 1;
            else
                s[i][j] = 0;
        }
    }

    do
    {
        flag = 0;
        p = 0;
        q = 1;
        max = fabs(d[p][q]);

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i != j)
                {
                    if (max < fabs(d[i][j]))
                    {
                        max = fabs(d[i][j]);
                        p = i;
                        q = j;
                    }
                }
            }
        }

        if (d[p][p] == d[q][q])
        {
            if (d[p][q] > 0)
                theta = pi / 4;
            else
                theta = -pi / 4;
        }
        else
        {
            theta = 0.5 * atan(2 * d[p][q] / (d[p][p] - d[q][q]));
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i == j)
                {
                    s1[i][j] = 1;
                    s1t[i][j] = 1;
                }
                else
                {
                    s1[i][j] = 0;
                    s1t[i][j] = 0;
                }
            }
        }

        s1[p][p] = cos(theta);
        s1t[p][p] = s1[p][p];

        s1[q][q] = cos(theta);
        s1t[q][q] = s1[q][q];

        s1[p][q] = -sin(theta);
        s1[q][p] = sin(theta);

        s1t[p][q] = s1[q][p];
        s1t[q][p] = s1[p][q];

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                temp[i][j] = 0;
                for (p = 0; p < n; p++)
                    temp[i][j] += s1t[i][p] * d[p][j];
            }
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                d[i][j] = 0;
                for (p = 0; p < n; p++)
                    d[i][j] += temp[i][p] * s1[p][j];
            }
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                temp[i][j] = 0;
                for (p = 0; p < n; p++)
                    temp[i][j] += s[i][p] * s1[p][j];
            }
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
                s[i][j] = temp[i][j];
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i != j)
                    if (fabs(d[i][j]) > zero)
                        flag = 1;
            }
        }
    }
    while (flag == 1);


    for (int i = 0; i < n; i++)
    {
        eigenValues[i] = d[i][i];
    }

    if (x == 0)
    {
        for (j = 0; j < n; j++)
        {
            for (i = 0; i < n; i++)
            {
                uMatrix[i][j] = s[i][j];
            }
        }
    }
    else
    {
        for (j = 0; j < n; j++)
        {
            for (i = 0; i < n; i++)
            {
                vMatrix[i][j] = s[i][j];
            }
        }
    }
}

int main()
{

    int row, col;
    printf("Enter the row of the matrix: ");
    scanf("%d", &row);

    printf("Enter the column of the matrix: ");
    scanf("%d", &col);

    printf("Enter the elements row wise:\n");
    for (int i = 0; i < row; i++)
    {
        for (int ii = 0; ii < col; ii++)
        {
            scanf("%lf", &matrix[i][ii]);
        }
    }

    printf("\nThe given Matrix is : \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf(" %8.4lf", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            transMatrix[i][j] = matrix[j][i];
        }
    }

    printf("\nTranspose matrix of the given matrix is :\n");
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            printf(" %8.4lf", transMatrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            AA_T[i][j] = 0;
            for (int k = 0; k < col; k++)
            {
                AA_T[i][j] += matrix[i][k] * transMatrix[k][j];
            }
        }
    }

    printf("\nThe AA^T Matrix is:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            printf(" %8.4lf", AA_T[i][j]);
        }
        printf("\n");
    }

    calculateEigenvaluesAndEigenvectors(row, 0);

    printf("\nThe U Matrix is :\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            printf(" %8.4lf", uMatrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < row; i++)
    {
        eigenValues[i] = sqrt(eigenValues[i]);
    }

    for (int j = 0; j < row ; ++j)
    {
        for (int i = 0; i < row - j - 1; ++i)
        {
            if (eigenValues[i] < eigenValues[i + 1])
            {
                double  temp = eigenValues[i];
                eigenValues[i] = eigenValues[i + 1];
                eigenValues[i + 1] = temp;
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == j)
            {
                sMatrix[i][j]=eigenValues[i];
            }
        }
    }

    printf("\nThe S Matrix is:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf(" %8.4lf", sMatrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            for (int k = 0; k < col; k++)
            {
                A_TA[i][j] += transMatrix[i][k] * matrix[k][j];
            }
        }
    }

    printf("\nThe A^TA Matrix is:\n");
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf(" %8.4lf", A_TA[i][j]);
        }
        printf("\n");
    }

    calculateEigenvaluesAndEigenvectors(col, 1);

    printf("\nThe V Matrix is:\n");
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf(" %8.4lf", vMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

