#include <stdio.h>
#include <stdlib.h>

int m[25][25];

void mapa(int, int, int, int, int);
int verifica(int, int, int);

int main(void) {
  int i, j, N, I, C, passos=0;

  scanf("%d %d %d", &N, &I, &C);

  for(i=0; i<N; i++){
    for(j=0; j<N; j++){
      scanf("%d", &m[i][j]);
    }
  }

  mapa(0, I, passos, N, C);
  printf("-1\n");
  
  return 0;
}

void mapa(int li, int col, int passos, int N, int C){
  if(li==N-1 && col==C && m[li][col]==0){
    printf("%d\n", passos);
    exit(0);
  }
  if(!verifica(N, li, col))
    return;
  
  m[li][col] = 1;
  mapa(li+1, col, passos+1, N, C);
  mapa(li, col+1, passos+1, N, C);
  mapa(li, col-1, passos+1, N, C);

  return;
}

int verifica(int N, int li, int col){
  if(li>=0 && col>=0 && li<N && col<N && m[li][col]==0)
    return 1;
  return 0;
}