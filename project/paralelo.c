#include <stdio.h>
#include <omp.h>
#include <gmp.h>

// Global end of calculus
#define N_MAX 5000

// Set precicion of digits
#define PRECISION 1000000U

// Global result of calculus
mpf_t global_euler;

void euler() 
{
  // Start of calculus
  int n;
  
  // Define variables of GMP lib to do the calculus
  mpf_t local_euler, division, factorial;

  // Precision set to unsigned int => {number}{unsigned = U}
  mpf_set_default_prec(PRECISION);

  // Initialize the variables to do the calculus
  mpf_init(local_euler);
  mpf_init(division);
  mpf_init_set_ui(factorial, 1); // Set 1 to factorial
  
  int nro_thread = omp_get_thread_num();
  int total_threads = omp_get_num_threads();

  // Define range of calculus
  int maxPorThread = N_MAX / total_threads;
  int inicio = (nro_thread * maxPorThread) + 1;
  int fim = (nro_thread+1) * maxPorThread;

  /*
  The second thread should have the last factorial
  calculated by the first thread. Then, we continue
  the factorial calculus.
  (Only works for 2 threads)
  */
  if(nro_thread == 1)
  {
    for(n = 1; n <= inicio-1; n++) 
    {
      // Calculate n!
      mpf_mul_ui(factorial, factorial, n);
    }
  }

  // Calculate Euler constant
  for(n = inicio; n <= fim; n++) 
  {
    // Calculate n!
    mpf_mul_ui(factorial, factorial, n);

    // Calculate 1/n!
    mpf_ui_div(division, 1, factorial);

    // Add the result of 1/n! to euler
    mpf_add(local_euler, local_euler, division);
  }

  # pragma omp critical
  mpf_add(global_euler, global_euler, local_euler);

  /*
  Below, free memory allocated to variables
  
  This is used, because GMP allocates memory in heap. 
  Then, we need to free this memory.
  */
  mpf_clear(local_euler);
  mpf_clear(division);
  mpf_clear(factorial);
}

int main(void) 
{
  // Set pointer to a file
  FILE *fp;

  // Set number of threads
  int cont_thread = 2;

  // Precision set to unsigned int => {number}{unsigned = U}
  mpf_set_default_prec(PRECISION);
  
  // Initialize the variables to do the calculus
  mpf_init_set_ui(global_euler, 1); // Set 1 to euler

  # pragma omp parallel num_threads(cont_thread)
  euler();

  // Write the result to a file
  fp = fopen("output.txt", "w");
  if (fp == NULL) {
      printf("Error opening file!\n");
      return 1;
  }
  gmp_fprintf(fp, "%.10000Ff\n", global_euler);
  fclose(fp);

  mpf_clear(global_euler);
  
  return 0;
}
