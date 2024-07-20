#include <stdio.h>

int inverte(int N);

int main(void) {
  int N;
  printf("Digite um número: ");
  scanf("%d", &N);
  inverte(N);
  return 0;
}

int inverte(int N){
  if(N/10==0){
    printf("%d", N%10);
    //ou:
    //if(N==0)
    //return N;
  }
  else{
    printf("%d", N%10);
    inverte(N/10);
  }
  return 0; 
}
