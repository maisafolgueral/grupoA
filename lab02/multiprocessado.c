#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{ 
  int i, num, j, fd[2]; // fd[2] - file descriptor (pipe)
  pid_t pid; // Id do processo

  // Executa a syscall pipe() e
  // verifica se houve erro
  if (pipe(fd) < 0) {
    return 1; // erro
  }

  // Entrada do numero para calculo
  printf ("Enter the number: ");
  scanf ("%d", &num);
  j = num;

  pid = fork(); // Cria processo filho
  if (pid < 0) { // Verifica se proc. filho foi criado
    return 2; // erro
  } 
  else if (pid == 0) { // Processo filho
    close(fd[0]); // Fecha leitura do pipe
    for (i=1; j > 1; j = j -1) {
      i=i*j;
    }
    write(fd[1], &i, sizeof(i)); // Envia resultado para saida do pipe (escrita)
    close(fd[1]); // Fecha escrita do pipe
    exit(0); // Finalizado com sucesso
  } 
  else {
    int result;
    close(fd[1]); // Fecha escrita do pipe
    wait(NULL); // Aguarda processo filho terminar a execucao
    read(fd[0], &result, sizeof(result)); // Le resultado do pipe (leitura)
    printf("The factorial of %d is %d\n", num, result);
    close(fd[0]); // Fecha leitura do pipe
  }
}
