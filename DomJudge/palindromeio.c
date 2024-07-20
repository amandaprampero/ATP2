#include <stdio.h>
#include <string.h>

int cont=0;

int pal(char palin[], int i, int tam){
  int n;
  n=(strlen(palin))-1;

  if(tam<i){
    return cont;
  }
  if(tam==0){
    tam = n;
    return pal(palin, i+1, tam);
  }
    
  else if(palin[i]==palin[tam]){
    if(i != tam){
      cont = cont + 2;
    }
    else{
      cont++;
    }
    return pal(palin, i+1, tam-1);
  }
  else{
    cont = 0;
    return pal(palin, i, tam-1);
  }
}

int main(void) {
  char palin[100];
  int tam, tama;
  scanf("%s", palin);
  tam = strlen(palin);
  tama = tam-1;
  printf("%d", pal(palin, 0, tama));
  return 0;
}