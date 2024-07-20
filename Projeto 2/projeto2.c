#include <stdio.h>

int N; //quantidade de numeros a serem decompostos 
int M; //quantidade de numeros que podem ser usados nas composições
int cont; //contador de combinações
int res[20]; //vetor resultado (maior combinação)
int tamanho = 0;
int maior_res=0;

void ordenacao(int *conjunto);
void decomp(int numero, int *conjunto, int *combinacao, int ind, int tam, int maior);
void insere(int *combinacao, int n);
void apaga(int *combinacao);

int main(void) {
  int i, j, k;
 
  //ENTRADA
  scanf("%d %d", &N, &M); 
  int K[N]; //K numeros que serao decompostos
  int conjunto[M]; //conjunto de M numeros que podem ser usados para decompor um inteiro
  int combinacao[M]; //possibilidade de combinação
  
  for(i=0;i<M;i++){ 
    scanf("%d", &conjunto[i]); 
    }
  ordenacao(conjunto); 
  
  for(i=0;i<N;i++){ 
    scanf("%d", &K[i]); 
    }

  for(i=0; i<N; i++){ //laço para decompor cada numero K
    k=0;
    cont=0; //sempre começo com 0 combinações
  
    for(j=0; j<M; j++){ //no início, o vetor combinacao é nulo
      combinacao[j]=0;
    }

    decomp(K[i], conjunto, combinacao, 0, 0, 0); //chamo a fç para decompor, começando na posição 0 do vetor

    //SAÍDA
    printf("%d ", cont); 
      while(res[k] != 0){
      printf("%d ", res[k]);
      k++;
      }
    printf("\n");
    for(j=0; j<M; j++){ //reinicia o vetor res
      res[j]=0;
    }
    //reinicia variáveis
    tamanho=0;
    maior_res=0;
  }
  return 0;
}

//função para colocar o vetor em ordem crescente
void ordenacao(int *conjunto){
  int i, j, aux;
  for(i=0; i<M-1; i++){
    for(j=i+1; j<M; j++){
      if(conjunto[j]<conjunto[i]){
      aux = conjunto[i];
      conjunto[i] = conjunto[j];
      conjunto[j] = aux;
      }
    }
  }
}

//função que decompõe o nº em sua maior combinação 
void decomp(int numero, int *conjunto, int *combinacao, int ind, int tam, int maior){
  int i=ind, antes=-1, d=0;

  if(numero==0){ //achou uma combinação
    cont++; 
    if((tam > tamanho)|| (tam == tamanho && maior > maior_res)){ //condição para que seja a maior combinação com elem de maior valor
      
      while(combinacao[d] != 0){ //copiar o maior vetor combinacao no vetor res
        res[d] = combinacao[d];
        d++;
      }
      tamanho = tam;
      maior_res = maior;
    }
    //reinicia as variáveis
    tam=0;
    maior=0;
  }

  if(numero<=0){ //não achou uma combinação
    return;
  }

  for(i=ind; i<M; i++){ //laço para percorrer todo o vetor conjunto
    if(conjunto[i] == antes){ //se achar elementos iguais eu pulo pro proximo, pois não pode ter repetição
      continue; 
    }
    
    if(conjunto[i] > maior){ //armazeno o maior elem do conjunto
      maior = conjunto[i];
    }

    insere(combinacao, conjunto[i]); 
    decomp(numero - conjunto[i], conjunto, combinacao, i+1, tam+1, maior); //recursão até achar as combinações
    apaga(combinacao); 

    antes=conjunto[i]; //como vou pro prox elem do vetor, o meu elem atual (conjunto[i]) será o anterior (antes)
  }
}

//função que adiciona no final do vetor um nº que pertence ao meu conjunto 
void insere(int *combinacao, int n){
  int d=0;
  while(combinacao[d] != 0) 
    d++;
  combinacao[d] = n; 
}

//função que apaga o último elem do vetor 
void apaga(int *combinacao){
  int d=0;
  while(combinacao[d] != 0)
    d++;
  combinacao[d-1]=0; 
}
