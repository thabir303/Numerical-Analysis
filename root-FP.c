#include <stdio.h>
#include <math.h>

double f(double x) {
    return x*x*x + 4*x*x - 10;
}

int main() {
    double x0 = 1.5;
    double tolerance = pow(10, -6);
    int max_iterations = 100;

    double x1 = f(x0);
    int i;
    for (i = 0; i < max_iterations; i++) {
        printf("Iteration %d: x = %f\n", i, x1);
        if (fabs(x1 - x0) < tolerance) {
            break;
        }
        x0 = x1;
        x1 = f(x1);
    }

    printf("Solution: x = %f\n", x1);
    return 0;
}
