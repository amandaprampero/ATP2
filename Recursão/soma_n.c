#include <stdio.h>
//Somando números até N
int soma(int N){
  if(N==1)
    return 1;
  else
    return (N + soma(N-1));
}

int main(void) {
  int N;
  printf("\nDigite um número: ");
  scanf("%d", &N);
  printf("Soma: %d", soma(N));
  return 0;
}
