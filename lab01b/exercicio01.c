#include <stdio.h>

int main(void) { 
  int matrix[3][3] = {{2, 9, 5}, {1, 8, 2}, {3, 0, 6}}; 
  int lowerValue = matrix[0][0];
  int lineLowerValue = 0;

  printf("Matriz: \n");
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  
  for(int i = 0; i < 3; i++) 
  {
    for(int j = 0; j < 3; j++)
    {
      if(matrix[i][j] < lowerValue)
      {
        lowerValue = matrix[i][j];
        lineLowerValue = i+1;
      }
    }
  }
  printf("Linha com menor valor: %d", lineLowerValue);
}
