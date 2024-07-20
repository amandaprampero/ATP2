#include <stdio.h>

int fibo(int N){
  if(N==1||N==2)
    return 1;
  else
    return (fibo(N-2)+fibo(N-1));
}

int main(void) {
  int N;
  printf("\nDigite um termo desejado: ");
  scanf("%d", &N);
  printf("O termo é: %d", fibo(N));
  return 0;
}
