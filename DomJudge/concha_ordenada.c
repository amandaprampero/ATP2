#include <stdio.h>
#include <string.h>

void shell(char vet[][100], int n);

int main(void) {
  int n, i;

  scanf("%d", &n);
  char palavra[n][100];
  for (i = 0; i < n; i++) {
    scanf("%s", palavra[i]);
  }

  shell(palavra, n);
  
  return 0;
}

void shell(char vet[][100], int n) {
  int i, j, k, l;
  char aux[100];
  k = 1;
  
 while(k <= n/4)
		k = k*2;
	
	while(k != 1){
		k = k/2;
		for(l=0; l<k; l++){
			for(i=l+k; i<n; i++){
				strcpy(aux, vet[i]);
				j=i;
				
				while(j-k >= 0 && strcmp(vet[j-k], aux) > 0)
				{
					strcpy(vet[j], vet[j-k]);
					j-=k;
				}
				strcpy(vet[j], aux);
			}
		}
		
		for(i=0; i<n; i++){
			printf("%s ", vet[i]);
		}
		printf("\n");
	}
}