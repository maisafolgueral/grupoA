#include <stdio.h>
#include <string.h>

int main(void) 
{
  char nameOne[20] = "Luiza";
  char nameTwo[20] = "Ana";

  if(strcmp(nameOne, nameTwo) == 0) 
    printf("Sao palavras iguais");
  else if(strcmp(nameOne, nameTwo) > 0)
    printf("Ordem alfabetica: \n%s \n%s", nameTwo, nameOne);
  else if(strcmp(nameOne, nameTwo) < 0)
    printf("Ordem alfabetica: \n%s \n%s", nameOne, nameTwo);

  return 0;
}
