#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//quantidade de valores BigInt
#define tam 200000

typedef struct biggo {
  int high;
  int low;
} BigInt;

void quicksort(BigInt *, int, int);
void troca(BigInt *, BigInt *);
int mediana(BigInt *, int, int, int);

int main(void) {
  BigInt vet[tam];
  int i;
  clock_t t; //conta o tempo
  //abrindo os arquivos para leitura dos dados e outro para escrita da resposta
  FILE *fp = fopen("bigint.dat", "r");
  FILE *res = fopen("quick.dat", "w");

  if (fp == NULL) { //arquivo não existe
    return 0;
  } else {
    for (i = 0; i < tam; i++) {
      fscanf(fp, "%d %d", &vet[i].high, &vet[i].low); //lê os dados do arquivo
      if (vet[i].high < 0) { //transforma os nº negativos em positivos para ordenar corretamente
        vet[i].low = (-1) * vet[i].low;
      }
    }
    t = clock(); //começa a contar o tempo
    quicksort(vet, 0, tam-1); //ordena os nº do bigint.dat
    t = clock() - t; //para de contar o tempo
    double time = ((double)t) / CLOCKS_PER_SEC; //pega o tempo por segundos
    printf("%f", time); //mostra o tempo da ordenação
    for (i = 0; i < tam; i++) {
      if (vet[i].high < 0) { //volta os nº negativos
        vet[i].low = (-1) * vet[i].low;
      }
      fprintf(res, "%d %d\n", vet[i].high, vet[i].low); //imprime os valores ordenados no arquivo quick.dat
    }
  }

  return 0;
}

void quicksort(BigInt *vet, int inicio, int fim){
  int i, pivo, bigger;
  if(fim>inicio){
    pivo = mediana(vet, inicio, (inicio+fim)/2, fim); //escolhe o pivo pela mediana de 3
    troca(&vet[pivo], &vet[fim]); //coloca o pivo no fim para facilitar as comparações
    bigger = inicio;
    for(i=bigger; i<fim; i++){
      //verifica o high, se for igual, verefica o low
      if (vet[i].high < vet[fim].high || (vet[i].high == vet[fim].high && vet[i].low < vet[fim].low)){
        troca(&vet[i], &vet[bigger]); //troca o bigger com um elemento menor que o pivo
        bigger++;
      }
    }
    troca(&vet[bigger], &vet[fim]); //coloca o pivo no lugar certo
    quicksort(vet, inicio, bigger-1); //recursão para a parte de baixo do vet
    quicksort(vet, bigger+1, fim); //recursão para a parte de cima do vet
  }
}

void troca(BigInt *valor1, BigInt *valor2) {
  BigInt aux;
  aux = *valor1;
  *valor1 = *valor2;
  *valor2 = aux;
}

int mediana(BigInt *vet, int inicio, int meio, int fim){
  //se o high do inicio, meio e fim são diferentes, só comparo a parte high
  //se algum high do inicio, meio e fim é igual, comparo a parte low
  //feitas as comparações, a função retorna a posição que contém a mediana entre os tres valores (inicio, meio e fim)
  if(((vet[inicio].high > vet[meio].high && vet[inicio].high < vet[fim].high) || (vet[inicio].high < vet[meio].high && vet[inicio].high > vet[fim].high)) || (vet[fim].high < vet[inicio].high && vet[inicio].high == vet[meio].high && vet[meio].low > vet[inicio].low) || (vet[meio].high < vet[fim].high && vet[inicio].high == vet[fim].high && vet[inicio].low < vet[fim].low) || ((vet[inicio].low > vet[meio].low && vet[inicio].low < vet[fim].low) || (vet[inicio].low < vet[meio].low && vet[inicio].low > vet[fim].low))){
    return (inicio);
  }
  if(((vet[meio].high > vet[inicio].high && vet[meio].high < vet[fim].high) || (vet[meio].high < vet[inicio].high && vet[meio].high > vet[fim].high)) || (vet[fim].high > vet[inicio].high && vet[inicio].high == vet[meio].high && vet[meio].low > vet[inicio].low) || (vet[inicio].high < vet[fim].high && vet[fim].high == vet[meio].high && vet[meio].low < vet[fim].low) || ((vet[meio].low > vet[inicio].low && vet[meio].low < vet[fim].low) || (vet[meio].low < vet[inicio].low && vet[meio].low > vet[fim].low))){
    return(meio);
  }

    return(fim);
}
