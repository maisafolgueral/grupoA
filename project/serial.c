#include <stdio.h>

long double fat(int n) {
  long double fat = 1;
  for(int i = 1; i <= n; i++) {
    fat = fat * i;
  }
  return fat;
}

long double euler(int nMax) {
  long double soma = 0;
  for (int n = 0; n <= nMax; n++) {
    soma += 1 / fat(n);
  }
  return soma;
}

int main(void) {
  long double resultado = euler(20);
  printf("%.62Lf \n", resultado);
  
  return 0;
}
