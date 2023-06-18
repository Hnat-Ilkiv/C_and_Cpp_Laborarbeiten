#include <stdio.h>
#include <math.h>

int main() {
	double x, y, result;
        printf("Введіть числа (x, y): ");
        scanf("%lf %lf", &x, &y);
        result = log(pow(x,2) + 4*x*y + pow(y,2)) - 12*cos(pow(x*y,4)) + 13*pow(x,6);
        printf("x = %lf, y = %lf => result = %lf\n\n", x, y, result);
        
        return 0;
}
