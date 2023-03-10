#include <stdio.h>

int main(void){
	int N1, N2, N3, ME, MA;
	N1 = 5; N2 = 6; N3 = 7; ME = 9;
	MA =  (N1 +(N2*2) +(N3*3) + ME)/7;
	if (MA >= 9){
		printf("A\n");
	}
	else if (MA >= 7.5 && MA < 9){
                printf("b\n");
        }
        else if (MA >= 6 && MA < 7.5){
                printf("C\n");
        }
        else if (MA >= 4 && MA < 69){
                printf("D\n");
        }
	else{
		printf("E\n");
	}
}
