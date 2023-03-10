#include <stdio.h>

void transposeMatrix(int matrix[3][2]) 
{
  int matrixT[2][3] = {};
  
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 2; j++)
    {
      matrixT[j][i] = matrix[i][j];
    }
  }
  
  printf("\nMatriz transposta (2x3):\n");
  for(int i = 0; i < 2; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      printf("%d ", matrixT[i][j]);
    }
      printf("\n");
  }
}

int main() {
  int matrix[3][2] = {{1, 5}, {7, 3}, {8, 2}};

  printf("Matriz (3x2): \n");
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 2; j++)
    {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  transposeMatrix(matrix);
}
