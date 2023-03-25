#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

void child(int* sharedMemory)
{
  // Execucao no processo filho
  sharedMemory[0] += 2; // Altera valor na memoria compartilhada
}

int main(void)
{
  int ShmID; // ID do segmento de memoria compartilhada
  int *ShmPTR; // Ponteiro para o segmento de memoria compart.
  pid_t pid; // ID do processo
  int status;

  // Cria segmento de memoria compartilhada
  ShmID = shmget(IPC_PRIVATE, 1*sizeof(int), IPC_CREAT | 0666);
  if (ShmID < 0) exit(1); // Erro ao criar

  // Acopla o segmento de memoria compartilhada ao 
  // espaco de enderecamento do processo
  ShmPTR = (int *)shmat(ShmID, NULL, 0);
  if ((int) *ShmPTR == -1) exit(1);

  ShmPTR[0] = 1; // Define valor na memoria compartilhada
  printf("Valor inicial = %d\n", ShmPTR[0]);

  
  pid = fork(); // Cria processo filho
  if (pid < 0) { // Verifica se processo filho foi criado
    exit(1); // Erro
  }
  else if (pid == 0) { // Processo filho
    child(ShmPTR);
    exit(0);
  }
  else { // Processo pai
    wait(&status); // Espera processo filho terminar
    ShmPTR[0] *=4; // Altera valor na memoria compartilhada
    printf("Valor final = %d\n", ShmPTR[0]);
    shmdt((void *) ShmPTR); // Desacopla o segmento de memoria compartilhada do espaco de enderecamento do processo
    shmctl(ShmID, IPC_RMID, NULL); // Remove o segmento de memoria compartilhada
    exit(0);
  }
  
  return 0;
}
