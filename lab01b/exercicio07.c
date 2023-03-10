#include <stdio.h>
#include <string.h>

typedef struct{
	int idade;
	float peso;
	float altura;
}Pessoa;

int main(void) {
	Pessoa pessoas[3];
	pessoas[0].idade = 5; pessoas[0].peso = 55; pessoas[0].altura = 1.65;
	pessoas[1].idade = 6; pessoas[1].peso = 65; pessoas[1].altura = 1.75;
	pessoas[2].idade = 7; pessoas[2].peso = 75; pessoas[2].altura = 1.85;
	char nomes[3][20] = {"Pedrinho", "Joaozinho", "Fulaninho"};
	for(int i=0; i<3; i++) {
		printf("Nome: %s, Idade: %d, Peso %.2f, Altura: %.2f\n",nomes[i],pessoas[i].idade, pessoas[i].peso,pessoas[i].altura);
	}
}
