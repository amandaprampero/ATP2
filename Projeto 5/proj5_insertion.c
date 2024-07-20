#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//quantidade de valores BigInt
#define tam 200000

typedef struct biggo {
  int high;
  int low;
} BigInt;

void insertionsort(BigInt *vet, int n){
  int i, j;
  BigInt aux;
  for(i=1;i<n;i++){ 
    aux = vet[i]; 
    j=i;
    while(j>0 && vet[j-1].high > aux.high){ //faz a ordenação de acordo com o high, se ele é diferente 
      vet[j] = vet[j-1];
      j--;
    }
    vet[j] = aux;
  }

  for(i=1;i<n;i++){
    aux = vet[i];
    j=i;
    while(j>0 && vet[j-1].high == aux.high && vet[j-1].low > aux.low){ //caso a parte high seja igual, ordena de acordo com a parte low
      vet[j] = vet[j-1];
      j--;
    }
    vet[j] = aux;
  }
}

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
    for (i = 0; i < tam; i++) { //lê os dados do arquivo
      fscanf(fp, "%d %d", &vet[i].high, &vet[i].low);
      if (vet[i].high < 0) { //transforma os nº negativos em positivos para ordenar corretamente
        vet[i].low = (-1) * vet[i].low;
      }
    }
    t = clock(); //começa a contar o tempo
    insertionsort(vet, tam); //ordena
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