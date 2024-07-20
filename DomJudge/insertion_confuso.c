#include <stdio.h>

void insertion_sort(double *, int, int);

int main(void) {
  int n, k, i;

  scanf("%d %d", &n, &k);
  double num[n];

  for(i=0; i<n; i++){
    scanf("%lf", &num[i]);
  }

  insertion_sort(num, n, k);

  for(i=0; i<n-1; i++){
    printf("%.3f ", num[i]);
  }
  printf("%.3f", num[n-1]);
 
  return 0;
}

void insertion_sort(double *vet, int n, int k){
  int i, j; 
  double aux;
  for(i=1; i<=k; i++){
    aux = vet[i];
    j=i;
    while(j>0 && vet[j-1]>aux){
      vet[j] = vet[j-1];
      j--;
    }
    vet[j] = aux;
  }
  for(i=k+1; i<n; i++){
    aux = vet[i];
    j=i;
    while(j>0 && vet[j-1]<aux){
      vet[j] = vet[j-1];
      j--;
    }
    vet[j]=aux;
  }
}