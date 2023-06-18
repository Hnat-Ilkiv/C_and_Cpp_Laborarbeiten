#include <stdio.h>
#include <math.h>
#include <complex.h>

int main(void)
{
	float x, a, b, h, d, sum;
	int k;
	
printf("Введіть занчення (a, b, h) через пробіл: ");
scanf("%f %f %f", &a, &b, &h);
printf("\n");

	for (a; a <= b; a += h) {
		if (a < 2) {
			x = cos(a) + tan(a);
		} else if (a < 2.7) {
			x = ctan(a) + sin(a);
		} else {
			x = pow(a * log(a), 3);
		}

		printf("\tРезульта розрахунку (x = %.1f): %f\n", a, x);
	} 
    printf("\n");


    printf("Введіть занчення (a, b, h, d) через пробіл: ");
    scanf("%f %f %f %f", &a, &b, &h, &d);
    printf("\n");


	for (a; a <= b; a += h)
	{
		x = 1;
		k = 0;
		sum = 0;
		while (fabs(x) >= d) {
			x = (a * cos(2*k + 1)) / ((2*k - 1)*(2*k + 3));
			sum += x;
			k++;
			//printf("\t\tx = %.3f; sum = %.3f;\n", x, sum);
		}
		printf("\tРезультат обчислень (x = %.1f): %f\n", a, sum);
	}
	
}
