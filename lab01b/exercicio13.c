#include <stdio.h>

void removeChar(char *Str, int pos) {
  Str[pos] = (char) 0;
}

int main(void) {
  char Str[100];
  int pos = 10;
  
  removeChar(Str, pos);
  printf("Caractere removido da posicao %d => '%c'\n", pos, Str[pos]);
  
  return 0;
}
