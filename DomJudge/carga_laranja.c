#include <stdio.h>
#include <stdlib.h>

typedef struct no{
  int t;
  int c;
  struct no *prox;
}Prog;

Prog *transf(){
  Prog *aux = malloc(sizeof(Prog));
  scanf("%d", &aux->t);
  scanf("%d", &aux->c);
  aux->prox = NULL;
  return aux;
}

Prog *insere(Prog *h, Prog *p){
  Prog *aux, *antes;
  if(h == NULL)
    return p;
  aux = antes = h;

  while(aux->prox && p->t > aux->t){
    antes = aux;
    aux = aux->prox;
  }

  if(aux == h){
    if(p->t > aux->t){
      p->prox = h->prox;
      h->prox = p;
      return h;
    } else {
      p->prox = h;
      return p;
    }
  }

  if(p->t > aux->t){
    p->prox = aux->prox;
    aux->prox = p;
  }else{
    p->prox = aux;
    antes->prox = p;
  }
  return h;
}

void remover(Prog **, int);
int busca(Prog *, int);

int main(){
  int N, i, inicio = 10001, maior, *res; 
  Prog *lista = NULL, *novo; 
  
  scanf("%d", &N);
  res = malloc(N * sizeof(int));

  for(i = 0; i < N; i++) 
  {
    novo = transf();
    if(novo->t < inicio)
      inicio = novo->t;
    lista = insere(lista, novo);
  }

  i = 0;
  while(lista){
    maior = busca(lista, inicio);
    if(maior == 0){
      inicio = lista->t;
      maior = busca(lista, inicio);
    }
    remover(&lista, maior);
    res[i] = maior;
    i++;
    inicio += maior;
  }

  for(i = 0; i < N; i++){
    printf("%d ", res[i]);
  }
  printf("\n");
  
  return 0;
}

void remover(Prog **h, int carga){
  Prog *aux = *h, *antes;
  if(aux != NULL && aux->c == carga){
    *h = aux->prox;
    free(aux);
    return;
  }
  while(aux != NULL && aux->c != carga){
    antes = aux;
    aux = aux->prox;
  }
  if(aux == NULL)
    return;
  antes->prox = aux->prox;
  free(aux);
}

int busca(Prog *h, int inicio){
  Prog *aux = h;
  int maior = 0;
  while(aux && aux->t <= inicio){
    if(aux->c > maior){
      maior = aux->c;
    }
    aux = aux->prox;
  }
  return maior;
}
