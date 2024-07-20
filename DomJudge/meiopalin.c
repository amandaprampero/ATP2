#include <stdio.h>
#include <string.h>

int pal(char *palin, int i, int j);

int main(void) {
  int i, j, tam, maior=0;
  char palin[2001];
  scanf("%s", palin);
  tam=strlen(palin);

  for(i=0; i<tam; i++){
    for(j=i+1; j<tam; j++){
      if(pal(palin, i, j) && j-i>maior){
        maior = j-i;
      }
    }
  }
  printf("%d\n", maior+1);
  return 0;
}

int pal(char *palin, int i, int j){
  if(i>j){
    return 1;
  } else if(palin[i]!=palin[j]){
    return 0;
  } else{
    return pal(palin, i+1, j-1);
  }
}