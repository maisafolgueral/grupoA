#include <stdio.h>

void insert(char *Str, int pos, char caractere) {
  Str[pos] = caractere;
}

int main(void) {
  char Str[100];
  int pos = 10;
  char caractere = 'b';
  
  insert(Str, pos, caractere);
  printf("Caractere iserido na posicao %d = '%c'\n", pos, Str[pos]);
  
  return 0;
}
