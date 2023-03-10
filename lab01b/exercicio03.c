#include <stdio.h>

int main(void) {
  
  int left = 0; // Start number
  int right = 9; // Max number
  while(left < right) {
    for(int j = 0; j < right; j++) {
      if(j >= left) {
        printf("%d ", j+1);
      }else{
        printf("  ");
      }
    }
    printf("\n");
    left++;
    right--;
  }
  
  return 0;
}
