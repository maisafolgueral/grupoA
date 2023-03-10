#include <stdio.h>
#include<stdlib.h>
#define NL 3
#define NC 3

void funcaoSubstitui(int matriz[NL][NC]){
	for(int i=0; i<NL; i++){
		for(int j=0; j<NC; j++){
			if(matriz[i][j] < 0){
				matriz[i][j] = abs(matriz[i][j]);
			}
		}
	}
	printf("Módulo da Matriz:\n");
	for(int i=0;i<NL;i++){
   		for(int j=0; j<NC; j++){
       			printf("%d", matriz[i][j]);
   		}
  	printf("\n");
	}
}

int main(void){
	int matriz[NL][NC]={{-2,2,-2},{-3,3,-3},{-4,4,-4}};
	funcaoSubstitui(matriz);
}
