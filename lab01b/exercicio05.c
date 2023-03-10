#include <stdio.h>
#define LIN 3
#define COL 3

int main(void) {
  int num = 2;
  int M[LIN][COL] = {
    { 1, 1, 1 },
    { 1, 1, 1 },
    { 1, 1, 1 }
  };
  
  printf("Multiplicando L1 por %d:\n", num);
  for(int i = 0; i < COL; i++) M[0][i] *= num;
  for(int i = 0; i < LIN; i++) {
    for(int j = 0; j < COL; j++) {
      printf("%d ", M[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  printf("Multiplicando C1 por %d:\n", num);
  for(int i = 0; i < LIN; i++) M[i][0] *= num;
  for(int i = 0; i < LIN; i++) {
    for(int j = 0; j < COL; j++) {
      printf("%d ", M[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  
  return 0;
}
