#include <stdio.h>
#include <gmp.h>

int main()
{
    // Set pointer to a file
    FILE *fp;
  
    // Start and end of calculus
    int n, nMax; 

    // Define variables of GMP lib to do the calculus
    mpf_t euler, division, factorial;

    // Precision set to unsigned int => {number}{unsigned = U}
    mpf_set_default_prec(5500000U);
  
    // Initialize the variables to do the calculus
    mpf_init_set_ui(euler, 1); // Set 1 to euler
    mpf_init(division);
    mpf_init_set_ui(factorial, 1); // Set 1 to factorial

    // Calculate Euler constant
    for(n = 1, nMax = 300000; n <= nMax; n++) 
    {
      // Calculate n!
      mpf_mul_ui(factorial, factorial, n);

      // Calculate 1/n!
      mpf_ui_div(division, 1, factorial);

      // Add the result of 1/n! to euler
      mpf_add(euler, euler, division);
    }

    // Write the result to a file
    fp = fopen("output.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    gmp_fprintf(fp, "%.3000000Ff\n", euler);
    fclose(fp);
 
    /*
    Below, free memory allocated to variables
    
    This is used, because GMP allocates memory in heap. 
    Then, we need to free this memory.
    */
    mpf_clear(euler);
    mpf_clear(division);
    mpf_clear(factorial);

    return 0;
}
