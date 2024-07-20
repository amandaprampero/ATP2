#include <stdio.h>

int buscabinaria(int *, int, int, int);
int n;

int main(void) {
  int m, i, val;

  scanf("%d", &n);
  int vet[n];
  for (i = 0; i < n; i++) {
    scanf("%d", &vet[i]);
  }
  scanf("%d", &m);
  int res[m];
  for (i = 0; i < m; i++) {
    scanf("%d", &val);
    res[i] = buscabinaria(vet, 0, n/2, val);
  }
  for (i = 0; i < m; i++) {
    printf("%d ", res[i]);
  }
  return 0;
}

int buscabinaria(int *vet, int min, int max, int val) {
  int mid;
  if (val == vet[min])
    return (min);
  if (val == vet[max])
    return (max);
  if (max >= min) {
        mid = min + (max - min) / 2;
 
        if (vet[mid] == val){
          return mid;
        }
      
        if (vet[mid] > val){
          return buscabinaria(vet, min, mid - 1, val);
        } 
        return buscabinaria(vet, mid + 1, max, val);
  }else {
      min = n / 2, max = n;
      while (min <= max) {
          mid = min + (max - min) / 2;
          if (val == vet[mid]) {
			       return mid;
          } else if (val < vet[mid]) {
			         min = mid + 1;
          }else {
			       max = mid - 1;
          }
      }
      return -1;
  }
}