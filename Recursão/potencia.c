#include <stdio.h>

int potencia(int n, int k);

int main() {
  int n, k;
  printf("Digite dois números: ");
  scanf("%d %d", &n, &k);
  printf("Resultado %d", potencia(n,k));
  return 0;
}

int potencia(int n, int k){
  if(n==0)
    return (1);
  else
    return (k*potencia(n-1, k));
}
