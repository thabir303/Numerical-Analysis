#include <stdio.h>
#include <math.h>
#define N 3
#define EPS 1e-9
#define f1(x, y, z) ((85 - 3 * (y) + 2 * (z)) / 15)
#define f2(x, y, z) ((51 - 2 * (x) -z) / 10)
#define f3(x, y, z) ((5 - (x) + 2 * (y)) / 8)

int a[N][N], b[N], x[N], nx[N], e[N];

int main()
{
    double x0 = 0, y0 = 0, z0 = 0, x1, y1, z1, e1, e2, e3;

    int cnt = 0;

    while (1)
    {

        x1 = f1(x0, y0, z0);
        y1 = f2(x0, y0, z0);
        z1 = f3(x0, y0, z0);

        e1 = fabs(x1 - x0);
        e2 = fabs(y1 - y0);
        e3 = fabs(z1 - z0);

        cnt++;

        if (e1 < EPS && e2 < EPS && e3 < EPS)
        {
            printf("X: %lf, Y: %lf, Z: %lf\n", x1, y1, z1);
            printf("itr: %d\n", cnt);
            break;
        }

        else
        {
            x0 = x1;
            y0 = y1;
            z0 = z1;
        }

    }
}

