#include <stdio.h>

int fat(int N){
  if(N==1||N==0)
    return (1);
  else
    return (N*fat(N-1));
}

int main(void) {
  int N;
  printf("\nDigite um número: ");
  scanf("%d", &N);
  printf("\n%d! = %d", N, fat(N));
  return 0;
}
