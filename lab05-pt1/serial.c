#include <stdio.h>
#include <math.h>

double f(double x) {
	return exp(x);
}

int main(void) {
  int a = 1;
  int b = 10;
  int n = 6;

  double h = (b-a)/n;
  double approx = (f(a) + f(b))/2.0;
  double x_i;
  for (int i = 1; i <= n-1; i++) {
    x_i = a + i*h;
    approx += f(x_i);
  }
  approx = h*approx;

  printf("Resultado = %.14e\n", approx);
  
  return 0;
}
