#include <stdio.h>

int main(void) {
  //Declarando e abrindo os arquivos de entrada e saída
  FILE *c = fopen("codigos.dat", "r");
  FILE *p = fopen("palavras.dat", "r");
  FILE *s = fopen("linhas.dat", "w");

  //Variáveis
  int N, i=0, count_pal, j;
  char str[5][20];

  //Enquanto não estiver no final do arquivo de códigos e palavras, faça...
  while(!feof(c) && !feof(p))
  {
    fscanf(c,"%d", &N); //Lendo e armazenando o código
     if(N > 0) //Se o código lido for positivo, escrevo as próximas palavras
    {
      count_pal = 1; //Iniciando o contador de palavras
      while(count_pal <= N) //Vou escrever as palavras no arquivo "linhas.dat" até que o contador de palavras seja igual a quantidade de palavras (N) fornecida pelo "codigos.dat" 
      {
        //Lendo e escrevendo as palavras de cada linha da variável str
        fscanf(p, "%s", str[i]); 
        fprintf(s, "%s ", str[i]);
        count_pal+=1; //Conto mais uma palavra
        i++; //Mudo pra próxima posição de str[i] 
      } 
      fprintf(s, "\n"); //Após sair do laço while, quer dizer que já foram escritas N palavras, então pulo uma linha 
    }
    if(N < 0) //Se o código lido for negativo, escrevo as palavras anteriores, incluindo ela mesma
    {
      if(N < -3) 
      {
        for(j=i+N; j<i; j++) //Acessa a posição da str que as palavras estão armazenadas (ex: N = -4 --> supondo que está na 7ª posição da str, o vetor str[j] inicia na posição 4 e imprime quatro palavras)
          {
            fprintf(s, "%s ", str[j]); //Imprimindo a palavra em "linhas.dat"
          }
        fprintf(s, "\n"); //Pulo uma linha após escrever as palavras
      }
      else
      {
        for(i=5+N; i<5; i++) //Acessa a posição da str que as palavras estão armazenadas (ex: N = -1 --> o vetor str[i] inicia na posição 4 e imprime uma palavra)
        {
          fprintf(s, "%s ", str[i]); //Imprimindo a palavra em "linhas.dat"
        }
        fprintf(s, "\n"); //Pulo uma linha após escrever as palavras
      }
    }
    if(N == 0) //Se N=0 escrevo uma linha contendo apenas o valor 0
    {
      fprintf(s, "0\n");
    }
  }
  //Se as palavras acabarem mas ainda existirem códigos
  while(!feof(c))
    {
      //Lendo e escrevendo os códigos que sobraram
      fscanf(c, "%d", &N);
      fprintf(s, "%d ", N);
    }
  //Se os códigos acabarem mas ainda existirem palavras
  count_pal = 0; //Reinicio o contador de palavras para usar no while a seguir
  while(!feof(p))
    {
      //Lendo e escrevendo cinco palavras a cada linha, até que as palavras acabem
      fscanf(p, "%s", str);
      fprintf(s, "%s ", str); 
      count_pal++; //Conto mais uma palavra
      if(count_pal>=5) //Se o contador marcar 5 ou mais palavras, então vou pular uma linha e reiniciar a contagem de palavras
      {
        fprintf(s, "\n");
        count_pal=0; //Reiniciando o contador de palavras
      }
    }

  //Fechando os arquivos
  fclose(c);
  fclose(p);
  fclose(s);
  return 0;
}
