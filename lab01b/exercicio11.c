#include <stdio.h>

void printMatrix(int matrix[3][3])
{
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

void sumMatrix(int matrix[3][3]) 
{
  for(int i = 0; i < 2; i++) 
  {
    for(int j = 0; j < 3; j++) 
    {
      matrix[1][i] = matrix[0][i] + matrix[1][i];
      i++;
    }
  }
}

void multiplicationMatrix(int matrix[3][3]) 
{
  for(int i = 0; i < 2; i++) 
  {
    for(int j = 0; j < 3; j++) 
    {
      matrix[1][i] = matrix[0][i] * matrix[1][i];
      i++;
    }
  }
}

int main(void) {
  int matrix[3][3] = {{4, 1, 9}, {8, 3, 6}, {2, 7, 0}};

  printf("Matriz: \n");
  printMatrix(matrix);

  printf("\nMatriz com a soma da L1 e L2 na linha 2: \n");
  sumMatrix(matrix);
  printMatrix(matrix);

  printf("\nMatriz com a multiplicacao da L1 e L2 na linha 2: \n");
  multiplicationMatrix(matrix);
  printMatrix(matrix);
}
