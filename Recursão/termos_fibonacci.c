#include <stdio.h>
int s=0;

//sequência de fibonacci
int fibo(int N){
  if(N==1||N==2||N==0)
    return 1;
  else
    return (fibo(N-2)+fibo(N-1));
}

//soma dos N primeiros termos da sequência
int soma(int n){
  int valor;
  if(n==1||n==2)
    s = n;
  else{
    valor = fibo(n);
    soma(n-1);
    s += valor;
  }
  return s;
}

int main(void) {
  int N, i;
  printf("\nDigite um termo desejado: ");
  scanf("%d", &N);
  //mostrando os N termos
  for(i=1; i<=N; i++){
    printf("%d ", fibo(i));
  }
  //mostrando o N- ésimo termo
  printf("\nO %dº termo é %d", N, fibo(N));
  //soma dos N primeiros termos da sequência
  printf("\nA soma dos %d primeiros termos é %d", N, soma(N));
  
  return 0;
}
