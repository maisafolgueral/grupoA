#include <stdio.h>
#include <omp.h>

long double fat(int n) 
{
  long double fat = 1;
  for(int i = 1; i <= n; i++) 
  {
    fat = fat * i;
  }
  return fat;
}

void euler(int nMax, long double *resultado) 
{
  int nro_thread = omp_get_thread_num();
  int total_threads = omp_get_num_threads();

  // Define a parte do calculo desta thread
  int maxPorThread = nMax / total_threads;
  int inicio = nro_thread * maxPorThread;
  int fim = ((nro_thread+1) * maxPorThread) - 1;
  if(nro_thread+1 == total_threads) fim += 1;

  long double soma = 0;
  for (int n = inicio; n <= fim; n++) 
  {
    soma += 1 / fat(n);
  }

  # pragma omp critical
  *resultado += soma;
}

int main(void) 
{
  long double resultado = 0.0;
  int cont_thread = 2;

  # pragma omp parallel num_threads(cont_thread)
  euler(30, &resultado);
  
  printf("%.62Lf\n", resultado);
  
  return 0;
}
