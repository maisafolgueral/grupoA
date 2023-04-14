#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 500
#define M 500

int matrix[N][M];
int vector[M];
int result[M];

// Funcao de multiplicacao
void *func(void *row)
{
  // Linha da matriz utilizada pela thread atual
  int curr_row = (long) row;

  result[curr_row] = 0;
  for(int j = 0; j < N; j++) {
    // Na linha atual da matriz (curr_row),
    // multiplica o elemento da posicao j
    // pelo elemento da posicao j do vetor
    // e soma ao valor no vetor de resultado
    result[curr_row] += matrix[curr_row][j] * vector[j];
  }

  return NULL;
}

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
  pthread_t *thread_handles;

  thread_handles = malloc(N*sizeof(pthread_t));

  fillVector();
  fillMatrix();

  for(long i = 0; i < N; i++)
  {
    // Cria thread
    pthread_create(&thread_handles[i], NULL, func, (void*)i);
  }

  for(long i = 0; i < N; i++)
  {
    // Aguarda o termino da thread
    pthread_join(thread_handles[i], NULL);
  }

  free(thread_handles);

  printResult();

  return 0;
}


