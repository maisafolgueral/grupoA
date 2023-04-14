#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 500
#define M 500

int matrix[N][M];
int vector[M];
int result[M];

void printResult() {
  for(int i = 0; i < M; i++) {
    printf("%d ", result[i]);
  }
  printf("\n");
}

void fillVector() 
{
  for(int i = 0; i < N; i++)
  {
    vector[i] = 5;
  }
}

void fillMatrix()
{
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < M; j++)
    {
      matrix[i][j] = 5;
    }
  }
}

int main()
{
  fillVector();
  fillMatrix();

  // Multiplicacao
  for(int i = 0; i < M; i++)
  {
    result[i] = 0;
    for(int j = 0; j < N; j++)
    {
      // Na linha atual da matriz (i),
      // multiplica o elemento da posicao j
      // pelo elemento da posicao j do vetor
      // e soma ao valor no vetor de resultado
      result[i] += matrix[i][j] * vector[j];
    }
  }

  printResult();

  return 0;
}
