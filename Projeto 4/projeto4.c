#include <stdio.h>
#include <stdlib.h>

typedef struct no{
  int identificador;
  int tempo_chegada;
  int atendimento;
  struct no *prox;
}No;

void inserir_fila(No **, int, int, int);
void imprimir(No *);
void atendimento(No *, int);
int menor_tempo(int *, int, int *);

int main(void) {
  No *fila = NULL;
  int N; //nº de elem na fila
  int M; //nº de atendentes
  int i, I, O, C; //ident, chegada, atendimento

  scanf("%d %d", &N, &M);

  for(i=0; i<N; i++){
    scanf("%d %d %d", &I, &O, &C);
    inserir_fila(&fila, I, O, C);
  }
  atendimento(fila, M);
  return 0;
}

void inserir_fila(No **fila, int id, int chega, int atend){
  No *aux, *novo = malloc(sizeof(No));
  novo->identificador = id;
  novo->tempo_chegada = chega;
  novo->atendimento = atend;
  novo->prox = NULL;

  if(*fila == NULL) //fila vazia
    *fila = novo;
  else{
    if(chega == 0){ //se chega no inicio, coloco o identificador em ordem crescente
      aux = *fila;
      while(aux->prox && novo->identificador > aux->prox->identificador)
        aux = aux->prox;
      novo->prox = aux->prox;
      aux->prox = novo;
    }
    else{ //se o tempo de chegada for diferente de zero, o coloco em ordem crescente (por tempo de chegada)
      aux = *fila;
      //se os tempos são iguais, coloco primeiro o de menor identificador
      while((aux->prox && novo->tempo_chegada > aux->prox->tempo_chegada)||(aux->prox && novo->tempo_chegada == aux->prox->tempo_chegada && novo->identificador > aux->prox->identificador))
        aux = aux->prox;
      novo->prox = aux->prox;
      aux->prox = novo;
    }
  }
}

//função para encontrar o tempo total de cada caixa de atendimento
void atendimento(No *fila, int M){
  int i, menor, tempo[M]; //vetor dos tempos finais
  
  for(i=0; i<M; i++){ //tempo inicial
    tempo[i] = fila->atendimento;
    fila = fila->prox;
  }

  while(fila){
    i = menor_tempo(tempo, M, &menor); //função retorna o índice do vetor que possuiu o menor tempo de atendimento (será o caixa livre)
    if(fila->tempo_chegada < tempo[i]){ //se chegou antes do atendimento acabar
      tempo[i] += fila->atendimento;
      fila = fila->prox;
    }else{ //se chegou e o caixa está livre
      tempo[i] = fila->tempo_chegada + fila->atendimento;
      fila = fila->prox;
    }
  }
  for(i=0; i<M; i++){
    printf("%d ", tempo[i]);
  }
}

//função que verifica qual caixa está livre
int menor_tempo(int *vet, int tam, int *menor){
  int i, indice=0;
  *menor = *vet;
  for(i=1; i<tam; i++){
    if(*(vet + i) < *menor){
      *menor = *(vet + i);
      indice = i;
    }
  }
  return indice;
}
