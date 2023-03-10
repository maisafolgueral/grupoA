#include <stdio.h>

int getCharPos(char *string, char caractere) {
  int pos = -1;
  int currentPos = 0;
  
  while (string[currentPos] != '\0') {
    if (string[currentPos] == caractere) {
      pos = currentPos;
      break;
    }
    currentPos++;
  }
  
  return pos;
}

int main(void) {
  char *string = "Mackenzie";
  char caractere = 'k';
  printf("Posicao = %d\n", getCharPos(string, caractere));
  return 0;
}
