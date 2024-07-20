void prioridade(Fila **inicio, Fila **fim, int id, int t){
  Fila *novo = malloc(sizeof(Fila)), *aux, *antes;
  novo->idade = id;
  novo->tempo = t;

   if(*inicio == NULL){
    *inicio = novo;
    *fim = novo;
    novo->prox = NULL;
    return;
  }
  if(novo->idade > 59){
    if(novo->idade > (*inicio)->idade){
      novo->prox = *inicio;
      *inicio = novo;
      return;
    }
    aux = (*inicio)->prox;
    antes = (*inicio);
    while(aux != NULL){
      if(novo->idade > aux->idade){
        antes->prox = novo;
        novo->prox = aux;
        return;
      }
      antes = aux;
      aux = aux->prox;
    }
  }
  (*fim)->prox = novo;
  novo->prox = NULL;
  *fim = novo;
}