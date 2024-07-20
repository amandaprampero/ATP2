#include <stdio.h>

int bolas(int N){
  
  if(N==1)
    return (1);
  else
    return (N*N + bolas(N-1));
}

int main(void) {
  int N;
  printf("\nNúmero de camadas: ");
  scanf("%d", &N);
  printf("\n%d bolas no total.", bolas(N));
  return 0;
}
