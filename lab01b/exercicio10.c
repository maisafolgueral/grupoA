#include <stdio.h>
#define LIN 3
#define COL 3

void mult(int M[LIN][COL], int num, int isLin) {
  int max = COL; if(isLin == 0) max = LIN;
  for(int i = 0; i < max; i++) {
    if(isLin == 1) {
      M[0][i] *= num;
    } else {
      M[i][0] *= num;
    }
  }
}

int main(void) {
  int num = 2;
  int M[LIN][COL] = {
    { 1, 1, 1 },
    { 1, 1, 1 },
    { 1, 1, 1 }
  };
  
  printf("Multiplicando L1 por %d:\n", num);
  mult(M, num, 1);
  for(int i = 0; i < LIN; i++) {
    for(int j = 0; j < COL; j++) {
      printf("%d ", M[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  printf("Multiplicando C1 por %d:\n", num);
  mult(M, num, 0);
  for(int i = 0; i < LIN; i++) {
    for(int j = 0; j < COL; j++) {
      printf("%d ", M[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  
  return 0;
}
