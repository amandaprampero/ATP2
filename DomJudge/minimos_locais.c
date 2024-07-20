#include <stdio.h>

int main(){
	int i, j, k, M, N, alfa, beta, minimo;
	
	scanf("%d %d", &N, &M);
	int E[N][N];
	
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			scanf("%d", &E[i][j]);
		}
	}
	
	for(k=0; k<M; k++){
		scanf("%d %d", &alfa, &beta);
		minimo = 2*(N*N);
		for(i=alfa-1; i<=beta-1; i++){
			for(j=alfa-1; j<=beta-1; j++){
				if(E[i][j] < minimo)
				{
					minimo = E[i][j];
				}
			}
		}
		printf("%d\n", minimo);
	}
	
	return 0;
}
