#include <stdio.h>
#include <stdlib.h>

int count = 0;
int AUX; 
int countd[3];
int **pino;

void Hanoi(int ori, int dest, int aux, int N, int K){

  if(count<K){
  if( N == 1 ){
     AUX = pino[ori][countd[ori]-1];
     pino[ori][countd[ori]-1] = pino[dest][countd[dest]];
     pino[dest][countd[dest]] = AUX;
     count += 1;
     if (countd[ori] != 0)
          countd[ori]--;
       countd[dest]++;
  }else{
    Hanoi(ori, aux, dest, N-1, K);
    Hanoi(ori, dest, aux, 1, K);
    Hanoi(aux, dest, ori, N-1, K);
  }
 }
}

int main(){
  int N, K, i, j, flag=0, x=0;
 
  scanf("%d %d", &N, &K);

  pino = malloc(3*sizeof(int));
  for (i = 0; i<3; i++)
  {
      pino[i] = malloc(N*sizeof(int));
  }

  for(j=N;j>0;j--){
       pino[0][x] = j;
       pino[1][x] = 0;
       pino[2][x] = 0;
       x++;
    }
  
  countd[0] = N;
  countd[1] = 0;
  countd[2] = 0;
  
  Hanoi(0, 2, 1, N, K);

   for (i = 0; i<3; i++)
  {
    for (j=N-1; j>=0; j--)
    {
      if (pino[i][j] != 0)
      {
        printf("%d ", pino[i][j]);
        flag = 1;
      }
    }
    if (flag == 0)
      printf("0");
    flag = 0;
    printf("\n");
  }
   free(pino[0]);
   free(pino[1]);
   free(pino[2]);
   free(pino);
  return 0;
}