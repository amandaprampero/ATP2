#include <stdio.h>

int main(void) {
  //variáveis
  int n, x, y, i, soma;

  //Entrada
  scanf("%d", &n);
  
  //Saída
  for(i=0; i<n; i++){
     scanf("%d %d", &x, &y);
     soma = x + y;
    
    if(soma%2==0)
       printf("A\n");
    else
       printf("B\n");  
  }
  
  return 0;
}