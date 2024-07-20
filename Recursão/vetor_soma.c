#include <stdio.h>

int soma_vet(int vet[], int tam);

int main(void) {
  int vet[3],i;
  //preenchendo o vetor
  for(i=0; i<3; i++){
    printf("Digite o %dº valor do vetor: ", i+1);
    scanf("%d", &vet[i]);
  }
  //mostrando o vetor
  for(i=0;i<3;i++){
    printf("%d ", vet[i]);
  }
  
  //somando os elementos do vetor
    printf("\nA soma do vetor é %d", soma_vet(vet,3));

  return 0;
}

int soma_vet(int vet[], int tam){
  if(tam==0)
    return (0);
  else
  return (vet[tam-1] + soma_vet(vet, tam-1));
}
